#ifndef FIND_FUNCTION_HPP
#define FIND_FUNCTION_HPP

//Searches a given array, with size given for a value
//and returns the index of that value
template<typename T>
size_t index_of(const T* array, size_t size, T searchFor)
{
        for (size_t x = 0; x < size; x++)
        {
                if (array[x] == searchFor)
                {
                        return x;
                }
        }
        return -1;
}

template<typename T>
size_t last_index_of(const T* array, size_t size, T searchFor)
{
        for (size_t x = size - 1; x != (size_t)-1; x--)
        {
                if (array[x] == searchFor)
                {
                        return x;
                }
        }
        return -1;
}
#endif

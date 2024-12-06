#include "Stack.hpp"

Stack::Stack(unsigned int bytes)
// bytes -> amount of bytes that can be stored in Stack
{
    if (bytes <= 0)
    {
        size = free_bytes = 0;
    }
    else
    {
        size = free_bytes = bytes;
        start = (char*)malloc(size);
    }
}

Stack::~Stack()
{
    free(start);
}

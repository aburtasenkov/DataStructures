#include <stdlib.h>
#include <iostream>

class Stack{
public:
    Stack() {}
    Stack(unsigned int bytes);
    ~Stack();

    template<typename value_type>
    value_type* alloc(value_type& val);

    template<typename value_type>
    value_type get();
private:
    unsigned int size = 0;
    unsigned int free_bytes = 0;
    char* start;
};

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

template<typename value_type>
value_type* Stack::alloc(value_type& val)
// Put val on top of the stack
{
    if (sizeof(val) > free_bytes)
        return nullptr;
    
    char* end = start + (size - free_bytes);

    value_type* last_obj = (value_type*)end;
    *last_obj = val;

    free_bytes -= sizeof(val);

    return last_obj;
}

template<typename value_type>
value_type Stack::get()
// get first sizeof(value_type) bytes from top of the Stack
{
    value_type* obj = (value_type*)(start + (size - free_bytes) - sizeof(value_type));
    free_bytes += sizeof(value_type);
    return *obj;
}
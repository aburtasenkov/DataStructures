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

template<typename value_type>
value_type* Stack::alloc(value_type& val)
// Put val on top of the stack
{
    if (sizeof(val) > free_bytes)
        return nullptr;
    
    char* end_byte = start + (size - free_bytes);

    value_type* end = (value_type*)end_byte;
    *end = val;

    free_bytes -= sizeof(val);

    return end;
}

template<typename value_type>
value_type Stack::get()
// get first sizeof(value_type) bytes from top of the Stack
{
    value_type* obj = (value_type*)(start + (size - free_bytes) - sizeof(value_type));
    free_bytes += sizeof(value_type);
    return *obj;
}
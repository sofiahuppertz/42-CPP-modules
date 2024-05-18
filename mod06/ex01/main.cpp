#include "dec/Serializer.class.hpp"
#include <iostream>

int main( void )
{
    Data original_data = {"Hello World", 42};

    uintptr_t raw = Serializer::serialize(&original_data);

    Data *deserializedData = Serializer::deserialize(raw);

    std::cout << &original_data << std::endl;
    std::cout << deserializedData << std::endl;
    std::cout << original_data.str_a << std::endl;
    std::cout << deserializedData->str_a << std::endl;
    std::cout << original_data.int_a << std::endl;
    std::cout << deserializedData->int_a << std::endl;
}
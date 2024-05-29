#include "dec/Serializer.class.hpp"
#include <iostream>

#include <iostream>
#include <string>
#include <cstdint>
#include <string>

int main(void)
{
    std::string reset = "\033[0m";
    std::string brightCyan = "\033[96m";
    std::string brightGreen = "\033[92m";
    std::string brightYellow = "\033[93m";
    std::string brightMagenta = "\033[95m";

    // Step 1: Create original data
    Data original_data = {"Hello World", 42};
    std::cout << brightCyan << "Step 1: Created original data" << reset << std::endl;
    std::cout << brightGreen << "Original Data Address: " << &original_data << reset << std::endl;

    // Step 2: Serialize the original data
    uintptr_t raw = Serializer::serialize(&original_data);
    std::cout << brightCyan << "Step 2: Serialized the original data" << reset << std::endl;
    std::cout << brightGreen << "Serialized Raw Data: " << raw << reset << std::endl;

    // Step 3: Deserialize the raw data
    Data *deserializedData = Serializer::deserialize(raw);
    std::cout << brightCyan << "Step 3: Deserialized the raw data" << reset << std::endl;
    std::cout << brightGreen << "Deserialized Data Address: " << deserializedData << reset << std::endl;

    // Step 4: Print and compare original and deserialized data
    std::cout << brightCyan << "Step 4: Comparing original and deserialized data" << reset << std::endl;

    std::cout << brightYellow << "Original Data String: " << brightMagenta << original_data.str_a << reset << std::endl;
    std::cout << brightYellow << "Deserialized Data String: " << brightMagenta << deserializedData->str_a << reset << std::endl;

    std::cout << brightYellow << "Original Data Integer: " << brightMagenta << original_data.int_a << reset << std::endl;
    std::cout << brightYellow << "Deserialized Data Integer: " << brightMagenta << deserializedData->int_a << reset << std::endl;

    // Step 5: Let's conver the pointer deserializedData to a string pointer;
    std::string *str = reinterpret_cast<std::string *>(deserializedData);
    std::cout << brightCyan << "Step 5: Converted the pointer deserializedData to a string pointer. This allows to access the first member of the struct only because it has the same adress ad the struct itself." << reset << std::endl;
    std::cout << brightGreen << "String Pointer: " << str << reset << std::endl;
    std::cout << brightYellow << "String: " << brightMagenta << *str << reset << std::endl;


    int *int_ptr = reinterpret_cast<int *>(deserializedData);
    std::cout << brightCyan << "Step 6: Converted the pointer deserializedData to an integer pointer (Dangerous operation)" << reset << std::endl;
    std::cout << brightGreen << "Integer Pointer: " << int_ptr << reset << std::endl;
    std::cout << brightYellow << "Integer: " << brightMagenta << *int_ptr << reset << std::endl;



    return 0;
}

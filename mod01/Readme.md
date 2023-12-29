# Module 1: C++ Key Concepts and Exercises

## Key C++ Concepts:

### New & Delete
- **New:** Dynamically allocates memory on the heap, returning a pointer to the allocated block.
- **Delete:** Deallocates memory previously allocated by `new`.

### Scope
The region of the code where a variable or function is accessible. Variables leave their scope and memory is freed upon exiting the scope, triggering destructors.

### References and Pointers
- **Syntax:** Pointers use `*` and `→` for access, while references use the same syntax as normal variables.
- **Nullability:** Pointers can be null; references always refer to an existing variable.
- **Reassignment:** References cannot be reassigned; pointers can be.
- **Indirection:** Pointers support multiple levels of indirection; references provide one level.

### Switch Statement
A control mechanism allowing variable values to change program execution flow, serving as an efficient alternative to multiple if-else statements.

## Exercises

### Ex00
Introduction to `new` and `delete` keywords, and the concept of scope.

### Ex01
Using the Zombie class to create a Zombie Horde function. This involves dynamic memory allocation for a class array, setter function calls, and array deletion.

### Ex02
Exploration of pointers and references, focusing on their value output.

### Ex03
Implementation of classes with references and pointers, highlighting their differences.

### Ex04
Utilization of the string class and its member functions to replace text in a string, demonstrating C++ efficiency.

### Ex05
Creation of private member functions and a public function that iterates through them using the `this` pointer. Features the complain member function.

### Ex06
Adaptation of the Hard class to implement complaints using a switch statement, introducing the concept of switch statements and fall-through logic.

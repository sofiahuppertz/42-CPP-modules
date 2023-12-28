# C++ Key Concepts and Exercises

## Key C++ Concepts:

### Namespaces
Namespaces provide a scope to identifiers like types, functions, variables, etc. Multiple namespace blocks with the same name are allowed. The `std` namespace includes entities provided by the C++ Standard Library, accessed with the `std::` prefix.

### Classes
Classes are blueprints for creating objects. They define a set of attributes and methods common to all objects of that type. Class members can be public, private, or protected, with different accessibility.

### Stdio Streams
Main types include `cin` (standard input), `cout` (standard output), `cerr` (standard error), and `clog` (standard logging). The `<<` operator sends data to the output stream, while `>>` is used for input.

### Static
In different contexts, `static` can mean different things. Within a function, it retains variable value between calls. In class members, it implies shared attributes or methods among all class instances. For global scope, it restricts visibility to the current file.

### Const
The `const` keyword specifies immutability of a variable after initialization. It can be used with pointers and class member functions to denote unchangeable data or object states.

## Exercises

### Ex00
This exercise introduces namespaces and stdio streams.

### Ex01
Create a simple phonebook program. This exercise introduces creating classes, constructors, destructors, and methods for setting and getting values.

### Ex02
Implement methods of the “Account” class. This exercise demonstrates the interaction of different class members in object-oriented programming.

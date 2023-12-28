# Module 02: Key C++ Concepts

In this module, we explore fundamental concepts in C++ programming, including Polymorphism, Operator Overloading, and the Orthodox Canonical Class Form.

## Polymorphism
Polymorphism is a principle in object-oriented programming that allows objects of different types to be treated as objects of a common, more general type. It enables a single method or operator to perform different operations based on the type of the object it acts upon.

## Overloading
Overloading is a concept where one function name can have multiple functionalities, determined by the number and types of arguments. It is a form of polymorphism that allows functions to behave differently based on their arguments.

## Operator Overloading
In C++, operator overloading allows different operators to be used for performing operations on user-defined data types. This feature enables operators to have different implementations based on their arguments, enhancing the intuitiveness of the interface.

## Orthodox Canonical Class Form
A good practice in class declaration, the Orthodox Canonical Class Form includes four key methods as per C++98 standards:
- Default constructor
- Copy constructor
- Destructor
- Copy assignment operator

Example:
```cpp
class MyClass {
public:
    MyClass(); // Default constructor
    MyClass(const MyClass& other); // Copy constructor
    ~MyClass(); // Destructor
    MyClass& operator=(const MyClass& other); // Copy assignment operator
};

​
# Computer Science Concepts
Understanding how computers represent and process different types of numerical data is crucial.

### Integers
Integers represent whole numbers, both positive and negative, including zero, and are stored in computers using the binary system. For example, `1010` in binary represents the decimal number `10`.

### Floating Points
Floating point numbers handle a larger range of values, including fractions and very large or small numbers. They're represented in binary scientific notation with a mantissa, exponent, and sign, but can sometimes result in rounding errors.

### Precision and Accuracy
- **Integers**: Provide perfect accuracy within their range.
- **Floating-Point Numbers**: Offer fine-grained precision but may lead to small rounding errors.

### Fixed Point Numbers
Fixed-point numbers are useful for calculations requiring predictable accuracy. They are efficient, especially in systems like financial calculations.

### Binary Space Partitioning (BSP)
BSP is a method for recursively dividing space into halves, used in 3D graphics, collision detection, and ray tracing.

## Project Exercises
**Ex00**: A simple class representing a fixed-point number in Orthodox Canonical Form.

**Ex01**: Enhanced functionality with construction from int or float and conversion capabilities. Overloading of the insertion operator for Fixed type.

**Ex02**: Overloading various operators and functions (min, max). Arithmetic operations are performed on raw bits to align with the fixed-point representation.

**Ex03**: Application of the fixed-point class in a program determining if a point is within a triangle. This includes a Point class with Fixed coordinates and a boolean function `Bsp()` to check the point's position relative to a triangle.

The program operates through the terminal console.

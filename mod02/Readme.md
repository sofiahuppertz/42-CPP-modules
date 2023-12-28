### Module 02


## Polymorphism, operator overloading and Orthodox Canonical class form

### Key C++ concepts:
***Polymorphism:*** a principle in object-oriented programming that allows objects of different types to be treated as objects of a more general common type. It enables the same method or operator to perform different operations based on the type of the object it is acting upon.
***Overloading:***  a concept in programming where one function name can have multiple functionalities, depending on the argument list. The function to be used for a particular call is determined by the number of arguments and their types. In a way, operator overloading can be seen as a form of polymorphism.
***Operator Overloading:*** a feature in C++ where different operators can be used to perform an operation on user-defined data types. This allows operators to have a different implementation based on their arguments, providing a more intuitive interface for users.
***Orthodox Canonical Class Form:*** Good practice for class declaration. By the standard of C++98 it includes four key methods: the default constructor, copy constructor, destructor, and copy assignment operator
class MyClass {
public:
    // Default constructor
    MyClass();

    // Copy constructor
    MyClass(const MyClass& other);

    // Destructor
    ~MyClass();

    // Copy assignment operator
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            // Copy logic here
        }
        return *this;
    }
};

​
###Computer Science concepts:
<i>How computers represent and process different types of numerical data<i>
***Integers: Integers are a type of numerical data that represent whole numbers, both positive and negative, including zero. In computers, they are represented in binary. Binary is a base-2 number system that uses only two numbers: 0 and 1. Each digit in a binary number is referred to as a bit. A binary integer might look something like this: 1010, which is the binary representation for the decimal number 10.
Floating Points: Floating point numbers are used to represent real numbers and are stored in the computer as binary fractions. They can handle a much larger range of values compared to integers, with the ability to represent fractions and very large or very small numbers. A floating point number is typically represented in scientific notation in binary, with a mantissa, exponent, and sign. Due to their nature, floating point numbers can sometimes lead to rounding errors.

💡
When dealing with numerical data, it is important to understand the concepts of precision and accuracy, especially in relation to integers and floating-point numbers. Integers offer perfect accuracy within their defined range. Arithmetic operations with integers are generally reliable because integers precisely represent whole numbers.
On the other hand, floating-point numbers represent values with fine-grained precision. However, this comes with the trade-off of potential small rounding errors during arithmetic operations, which can accumulate, potentially leading to wrong outputs.
Fixed Point Numbers: a method of representing real numbers in computer systems using a fixed number of digits before and after the decimal point. Fixed-point numbers are used when a predictable accuracy is required. They are especially useful in systems where consistent and exact results are necessary, such as in financial calculations. Additionally, fixed point arithmetic can often be executed faster and requires less memory than floating point arithmetic, making it a more efficient choice in certain scenarios.


Binary Space Partitioning: Binary Space Partitioning (BSP) is a method in computer science for recursively dividing a space into two halves. This process is often used in 3D computer graphics, collision detection, and ray tracing. BSP trees can efficiently determine where an object is in relation to a plane, making them highly useful for tasks such as rendering scenes from different camera positions. The process of creating a BSP tree is as follows: First, a node is chosen from the objects in the space. This node is used as a partitioning plane, dividing the space into two halves. Each half is then recursively divided until the partitioning process is complete. The result is a tree data structure where each node represents a distinct partition of the space. (This concept isn’t required for this project)

Ex00\
For this exercise we made a very simple class that represents a useless fixed point number. This class is written in the Orthodox Canonical Form and has 1 getter and 1 setter ( to handle the fixed-point number’s raw bits).
Ex01\
Now the class becomes “utilizable”. We can construct our fixed-point from an int or a float, and convert it to either of these types. We have also overloaded the insertion std:: operator so that it can handle a Fixed type variable. It will stream to the output stream Fixed.toFloat(). 
Ex02\
Here we overload a lot of operators and two functions (min, max with const and without const variables). I decided to perform arithmetic operations on raw bits, because it aligns with fixed-point numbers (treated as integers). 

Ex03\
Module 02 culminates with the application of our fixed-point class in a practical program. This program determines whether a given point lies within a specified triangle. To achieve this, we created a Point class, composed of Fixed coordinates. In addition, we devised a boolean function named Bsp(). Although not directly related to Binary Space Partitioning, this function determines if a point P resides within a triangle ABC. The program operates via the terminal console.

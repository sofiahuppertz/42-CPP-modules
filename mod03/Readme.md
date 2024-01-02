# Module 03
<p><i>Inheritance</i></p>

## Key C++ Concepts

### Inheritance
Inheritance in C++ is a mechanism where a new class, called the derived class, is created from an existing class, known as the base class. The derived class inherits the properties and behaviors (methods and variables) of the base class but can also have additional features of its own. This concept facilitates code reusability and simplifies the management of complex applications. Derived classes can override base class methods to provide specific functionality.

### Access Specifiers
Access specifiers in C++ determine how the members of a base class are accessible to a derived class. There are three types:
1. **`public`**: Public and protected members of the base class remain public and protected in the derived class.
2. **`protected`**: Public members of the base class become protected in the derived class.
3. **`private`**: Public and protected members of the base class become private in the derived class.

### Difference between Inheritance and Composition
- **Inheritance**: Suitable for modeling "is-a" relationships, often used when polymorphism is needed.
- **Composition**: Ideal for "has-a" relationships, encourages loose coupling and enhances maintainability.

### Virtual Inheritance
Virtual inheritance is used to prevent multiple instances of a base class in a derived object in multiple inheritance scenarios, ensuring a single, shared instance of the base class.

### Virtual Functions
Virtual functions allow derived classes to provide specific implementations for methods declared in the base class, facilitating polymorphism and dynamic binding.

## Computer Science, Object-Oriented Programming, and C++ Concept

### The Diamond Problem
The Diamond Problem arises in multiple inheritance situations in C++, where a class inherits from two classes that both inherit from a common base class. This creates ambiguity, especially if the derived class inherits multiple instances of the base class's members. C++ addresses this issue through virtual inheritance.

## C++ Exercises

### Ex00: ClapTrap Class
In this exercise, we create a ClapTrap class representing a combat game character with private attributes and public member functions.

### Ex01: ScavTrap Class
Derived from ClapTrap, ScavTrap overrides the attack() method and methods of the Canonical Orthodox Form. It introduces a new method, guardGate(), and implements public setters and getters due to the inaccessibility of private attributes from the base class.

### Ex02: FragTrap Class
Derived from ClapTrap, FragTrap is similar to ScavTrap but with different initialization values and a new member function, “highFiveGuys”.

### Ex03: DiamondTrap Class and the Diamond Problem
This exercise introduces the DiamondTrap class, derived from both FragTrap and ScavTrap. It demonstrates the application of virtual inheritance to solve the Diamond Problem. The class uses virtual keywords for intermediate classes and overridden functions. It features a unique handling of private attributes and a 'whoAmI' function to distinguish between DiamondTrap and ClapTrap names.

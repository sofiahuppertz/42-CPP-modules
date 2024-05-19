# C++ Module 05: Repetition and Exceptions

## Overview
This module focuses on implementing our own exceptions derived from the standard exception class, and using them with try/catch/throw statements.

## Key Concepts
- **Exceptions**: In C++, exceptions are a more explicit alternative to if/else statements for handling exceptional circumstances that disrupt the normal flow of a program. They provide a robust mechanism to prevent the program from crashing when potential errors occur, by transferring control to a specific part of the program designed to handle the error.
- **Concepts from Previous Modules**: Abstract classes, inheritance, using `const` and `static` keywords, orthodox canonical form, function pointers, and loops to avoid nasty if/else statements for scalability.

## Exercises

### Ex00: Bureaucrat Class and Exceptions Derived from Exception Standard Class
The `Bureaucrat` class can throw exceptions, which are caught by outer functions.

### Ex01: Adding Form Class Which Also Uses Exceptions
The `Form` class has `const` member attributes, which cannot be reassigned after initialization. The `Form` and `Bureaucrat` classes are dependent on each other.

### Ex02: Form Becomes Abstract (AForm)
To avoid repetition, we check requirements that are common in the base class function `execute` which then calls each form's concrete `execute` function. This is a more elegant and efficient way than checking requirements in each derived function.

```cpp
void AForm::execute(Bureaucrat const &executor) {
    try {
        if (executor.getGrade() > getGradeToExecute()) {
            throw GradeTooLowException();
        }
        if (!getIsSigned()) {
            throw FormNotSignedException();
        }
        execute(executor);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        local_failure();
    }
}
``````

Execute() and local_failure() are pure virtual in AForm… but it’s fine to call them because AForm is an abstract class…

Each derived functions has it’s own execute() and local_failure() implementation, according to the subject’s requirements.

The target attribute is passed to the constructor of any derived class of AForm. Because I want to avoid repetition, I made target a private member of AForm, and created getters and setters for it.

### Ex03:
In this exercise we create an Intern class, which can create 
based on a string. For this we use abstract class function pointers that return concrete derived classes. It is constructed in a way that would make it extremely easy to add a new derived class and allow for interns to return them… Way better than having an if/else long block
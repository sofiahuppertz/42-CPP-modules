Module 05
# C++ Repetition and Exceptions
## Overview
This module focuses on implementing our own exceptions derived from the standard exception class, and using them with try/catch/throw statements.
## Key concepts
Exceptions: In C++, exceptions are a more explicit alternative to if/else statements for handling exceptional circumstances that disrupt the normal flow of a program. They provide a robust mechanism to prevent the program from crashing when potential errors occur, by transferring control to a specific part of the program designed to handle the error.
Concepts from previous modules: Abstract classes, Inheritance, Using const and static keyword, orthodox canonical form, function pointers and loops to avoid nasty if/else statements, for scalability…
## Exercices
Ex00: Bureaucrat class and Exceptions derived from Exception standard class. Bureaucrat class can throw exceptions, which are by outer functions.
Ex01: Adding Form class which also uses exceptions. Form has const member attributes, which cannot be reassigned after initialization. Form and Bureaucrat classes are dependent on each other.
Ex02: Form becomes abstract, so “AForm”. To avoid repetition, we check requirements which are common in the base class function “check_and_execute” which calls then each function’s execute concrete function. This is a more elegant and efficient way than checking requirements in each function.
void AForm::check_and_execute(Bureaucrat const &executor)
{
    try {
        if (executor.getGrade() >  getGradeToExecute())
        {
            throw GradeTooLowException();
        }
        if (getIsSigned() == "False")
        {
            throw FormNotSignedException();
        }
        execute(executor);
    } catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        failure();
    }
    return ;
}
​
execute() and failure() are pure virtual in AForm… but it’s fine to call them because AForm is an abstract class…
Each derived functions has it’s own execute() and failure() implementation, according to the subject’s requirements.
The target attribute is passed to the constructor of any derived class of AForm. Because I want to avoid repetition, I made target a private member of AForm, and created getters and setters for it.
Ex03: In this exercise we create an Intern class, which can create forms based on a string. For this we use abstract class function pointers that return concrete derived classes. It is constructed in a way that would make it extremely easy to add a new derived class and allow for interns to return them… Way better than having an if/else long block.
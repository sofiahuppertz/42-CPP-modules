#include "../dec/ShrubberyCreationForm.class.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ): AForm("ShrubberyCreationForm", 145, 137) {
    setTarget("default");
    std::cout << "Calling ShrubberyCreationForm constructor." << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target): AForm("ShrubberyCreationForm", 145, 137) {

    setTarget(_target);
    std::cout << "Calling ShrubberyCreationForm constructor." << std::endl;
    return ;
}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other): AForm(other) {

    setTarget(other.getTarget());
    std::cout << "Calling ShrubberyCreationForm copy constructor." << std::endl;
    return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {

   setTarget(other.getTarget());
    std::cout << "Calling ShrubberyCreationForm assignment operator." << std::endl;
    return *this;
}


ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
    std::cout << "Calling ShrubberyCreationForm destructor." << std::endl;
    return ;
}

void ShrubberyCreationForm::local_execute ( Bureaucrat const &executor ) const
{
    std::ofstream ofs;
    std::string filename;
    
    (void)executor;
    std::cout << "ShrubberyCreationForm execute() called." << std::endl;
    filename = getTarget() + "_shrubbery";
    ofs.open(filename.c_str(), std::ios::out | std::ios::app);
    if (ofs.is_open()) {
        ofs << "       /\\       " << std::endl;
        ofs << "      /  \\      " << std::endl;
        ofs << "     /____\\     " << std::endl;
        ofs << "    /\\    /\\    " << std::endl;
        ofs << "   /  \\  /  \\   " << std::endl;
        ofs << "  /____\\/____\\  " << std::endl;
        ofs << "      ||||      " << std::endl;
        ofs.close();
    }
    return;
}

void ShrubberyCreationForm::local_failure( void ) const
{
    return;
}
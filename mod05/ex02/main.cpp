#include "dec/Bureaucrat.class.hpp"
#include "dec/ShrubberyCreationForm.class.hpp"
#include "dec/RobotomyRequestForm.class.hpp"
#include "dec/PresidentialPardonForm.class.hpp"

int main( void )
{
    /* Test 1 : Executing Shruberry Creation Form */
    std::cout << ANSIColors::BRIGHT_BACKGROUND_MAGENTA  << ANSIColors::WHITE << std::endl << "Leonardo Da Feeling, a bureaucrat by day and an artist by night. He will execute the schrubbery creation Form. " << ANSIColors::RESET << std::endl << std::endl;
    Bureaucrat LeonardoDaFeeling("Leonardo Da Feeling", 15);
    ShrubberyCreationForm ShrubberyForm("I_want_vacation");
    std::cout << "\t" << LeonardoDaFeeling << std::endl;
    std::cout << "\t"  << ShrubberyForm << std::endl;
    LeonardoDaFeeling.signForm(ShrubberyForm);
    LeonardoDaFeeling.executeForm(ShrubberyForm);
    std::cout << std::endl;

    /*Test 2 : Robotomization Form */
    std::cout << ANSIColors::BRIGHT_BACKGROUND_MAGENTA  << ANSIColors::WHITE << std::endl << "Kim Card-Ashian, loves playing with her barbies. This time she will robotmize-them. " << ANSIColors::RESET << std::endl << std::endl;
    Bureaucrat KimCardAshian("Kim Card-Ashian", 45);
    RobotomyRequestForm RobotomyForm("Botox Barbie");
    std::cout << "\t" << KimCardAshian << std::endl;
    std::cout << "\t" << RobotomyForm << std::endl;
    KimCardAshian.signForm(RobotomyForm);
    KimCardAshian.executeForm(RobotomyForm);
    std::cout << std::endl;

    /* Test 3: Executing Presidential Pardon Form */
    std::cout << ANSIColors::BRIGHT_BACKGROUND_MAGENTA  << ANSIColors::WHITE << std::endl << "Xavier Niel, himself, allowed a student to be pardonned after being black-holed, with the Presidential Pardon Form. " << ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::BRIGHT_BACKGROUND_MAGENTA  << ANSIColors::WHITE << std::endl << "He was very busy buying carrefour, so he asked the staff to do it, but because of their grade they could only sign it." << ANSIColors::RESET << std::endl << std::endl;
    Bureaucrat XavierNiel("Xavier Niel", 1);
    Bureaucrat Staff("Staff", 25);
    PresidentialPardonForm PresidentialForm("Lazy Student");
    std::cout << "\t" << XavierNiel << std::endl;
    std::cout << "\t" << Staff << std::endl;
    std::cout << "\t" << PresidentialForm << std::endl;
    Staff.signForm(PresidentialForm);
    Staff.executeForm(PresidentialForm);
    XavierNiel.executeForm(PresidentialForm);
    return 0;


}
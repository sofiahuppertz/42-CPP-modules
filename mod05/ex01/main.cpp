#include "dec/Bureaucrat.class.hpp"

int main ( void )
{
    /* Example where signing goes well. */
    
    std::cout << ANSIColors::BRIGHT_BACKGROUND_MAGENTA  << ANSIColors::WHITE << std::endl << "This example will show effective form signing. " << ANSIColors::RESET << std::endl << std::endl;
    Bureaucrat SirPapperPusher3("Sir PapperPusher the 3rd", 3);
    Form NinjaSurvey("Ninja Survey", 13, 4);
    std::cout << SirPapperPusher3 << std::endl;
    std::cout << NinjaSurvey << std::endl;
    SirPapperPusher3.signForm(NinjaSurvey);

    /* Example where signing goes wrong. */

    std::cout << ANSIColors::BRIGHT_BACKGROUND_MAGENTA  << ANSIColors::WHITE << std::endl << "This example will show effective mechanism to prevent the wrong person from signing a form. " << ANSIColors::RESET << std::endl << std::endl;
    Bureaucrat SamSCam("Sam S. Cam", 150);
    Form OfficialUnofficialPaperwork("Official Unofficial Paperwork", 54, 1);
    std::cout << SamSCam << std::endl;
    std::cout << OfficialUnofficialPaperwork << std::endl;
    SamSCam.signForm(OfficialUnofficialPaperwork);
    return 0;

}
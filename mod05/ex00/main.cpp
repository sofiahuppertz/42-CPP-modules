#include "dec/Bureaucrat.class.hpp"

int main ( void )
{

    /* Test 1: Calling constructor with invalid grade */
    try
    {
        std::cout << ANSIColors::BACKGROUND_MAGENTA << " We will try to create a Bureaucrat with a grade of 0. " << ANSIColors::RESET << std::endl << std::endl;
        Bureaucrat MichealScott("Michael Scott", 0);
        std::cout << MichealScott << std::endl;
        MichealScott.incrementGrade(1);
    }
    catch (const std::exception& e)
    {
        std::cout << ANSIColors::BACKGROUND_RED << "\tException caught:" << ANSIColors::RESET << ANSIColors::RED << " " << e.what() << ANSIColors::RESET << std::endl;
    };

    /* Test 2: Calling decrement grade too much. */
    try
    {
        std::cout << std::endl <<  ANSIColors::BACKGROUND_MAGENTA << " Now we will call decrement grade until an exception is thrown. How fun! " <<  ANSIColors::RESET << std::endl << std::endl;
        Bureaucrat PamBeesly("Pam Beesly", 140);
        for (int i = 0; i < 11; i++)
        {
            PamBeesly.decrementGrade(1);
            std::cout << "\t" <<  PamBeesly << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << ANSIColors::BACKGROUND_RED << "\tException caught:" << ANSIColors::RESET << ANSIColors::RED << " " << e.what() << ANSIColors::RESET << std::endl;
    };

    /* Test 3: Calling increment grade too much. */
    try
    {
        std::cout << std::endl <<  ANSIColors::BACKGROUND_MAGENTA << " Now we will call increment our bureaucrat's grade with an insanely cool number. " <<  ANSIColors::RESET << std::endl << std::endl;
        Bureaucrat ArthurDent("Arthur Dent", 10);
        std::cout << "\t" << ArthurDent << std::endl;
        std::cout << ANSIColors::BACKGROUND_YELLOW << "\tCan you guess the number? " << ANSIColors::RESET << std::endl << std::endl;
        // make a 3 ... 2 ... 1 ... guess!
        for (int i = 0; i < 3; i++)
        {
            std::cout << ANSIColors::BACKGROUND_YELLOW << "\t" << 3 - i << "... " << ANSIColors::RESET << std::endl;
            sleep(1);
        }

        ArthurDent.incrementGrade(42);
    }
    catch (const std::exception& e)
    {
        std::cout << ANSIColors::BACKGROUND_RED << "\tException caught:" << ANSIColors::RESET << ANSIColors::RED << " " << e.what() << ANSIColors::RESET << std::endl;
    };

    std::cout << std::endl << ANSIColors::CYAN <<"\t   #          #####"<< std::endl;
    std::cout <<"\t  #      #  #     # "<< std::endl;
    std::cout <<"\t #      #        #  "<< std::endl;
    std::cout <<"\t#      #   #####    "<< std::endl;
    std::cout <<"\t#######  #     "<< std::endl;
    std::cout <<"\t     #  #       " << std::endl;
    std::cout <<"\t    #  #######    " << ANSIColors::RESET << std::endl;

    return 0;
}
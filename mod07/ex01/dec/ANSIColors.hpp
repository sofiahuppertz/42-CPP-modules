#ifndef ANSICOLORS_HPP
#define ANSICOLORS_HPP

#include <string>
#include <unistd.h>

// ANSI escape codes
class ANSIColors {

    public:
        // Regular text colors
        static const std::string RESET;
        static const std::string BLACK;
        static const std::string RED;
        static const std::string GREEN;
        static const std::string YELLOW;
        static const std::string BLUE;
        static const std::string MAGENTA;
        static const std::string CYAN;
        static const std::string WHITE;

        // Bright text colors
        static const std::string BRIGHT_BLACK;
        static const std::string BRIGHT_RED;
        static const std::string BRIGHT_GREEN;
        static const std::string BRIGHT_YELLOW;
        static const std::string BRIGHT_BLUE;
        static const std::string BRIGHT_MAGENTA;
        static const std::string BRIGHT_CYAN;
        static const std::string BRIGHT_WHITE;

        // Background colors
        static const std::string BACKGROUND_BLACK;
        static const std::string BACKGROUND_RED;
        static const std::string BACKGROUND_GREEN;
        static const std::string BACKGROUND_YELLOW;
        static const std::string BACKGROUND_BLUE;
        static const std::string BACKGROUND_MAGENTA;
        static const std::string BACKGROUND_CYAN;
        static const std::string BACKGROUND_WHITE;

        // Bright background colors
        static const std::string BRIGHT_BACKGROUND_BLACK;
        static const std::string BRIGHT_BACKGROUND_RED;
        static const std::string BRIGHT_BACKGROUND_GREEN;
        static const std::string BRIGHT_BACKGROUND_YELLOW;
        static const std::string BRIGHT_BACKGROUND_BLUE;
        static const std::string BRIGHT_BACKGROUND_MAGENTA;
        static const std::string BRIGHT_BACKGROUND_CYAN;
        static const std::string BRIGHT_BACKGROUND_WHITE;
};  


# endif

#ifndef BRAIN_CLASS_H
# define BRAIN_CLASS_H

#include <iostream>
#include <string>

class Brain {
    public:
        Brain(void);
        Brain ( const Brain &other);
        ~Brain(void);

        Brain &operator=(const Brain &other);

        std::string ideas[100];
};

#endif
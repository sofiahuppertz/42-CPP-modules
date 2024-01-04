
#ifndef MATERIASOURCE_CLASS_H
# define MATERIASOURCE_CLASS_H

# include "IMateriaSource.class.hpp"
# include <iostream>
# include <string>

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource( void );
        MateriaSource( const MateriaSource &other );
        virtual ~MateriaSource( void );

        MateriaSource &operator=( const MateriaSource &other );

        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
};


#endif
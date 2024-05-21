#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

    public:

        MutantStack( void );
        MutantStack (MutantStack const & src);
        virtual ~MutantStack( void );
        MutantStack & operator=(MutantStack const & rhs);

        // Iterator implementation
        typedef typename std::stack<T, Container>::container_type::iterator iterator;
        

        iterator begin( void );
        iterator end( void );
        iterator rbegin( void );
        iterator rend( void );

};

#include "../def/Mutantstack.tpp"  
#endif
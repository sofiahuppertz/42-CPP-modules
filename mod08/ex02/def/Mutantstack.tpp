// MutantStack.tpp

template <class T, class Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}

template <class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& src) : std::stack<T, Container>(src) {}

template <class T, class Container>
MutantStack<T, Container>::~MutantStack() {}

template <class T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack<T, Container>& rhs) {
    if (this != &rhs) {
        this->c = rhs.c;
    }
    return *this;
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
    return this->c.begin();
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
    return this->c.end();
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::rbegin() {
    return this->c.rbegin();
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::rend() {
    return this->c.rend();
}
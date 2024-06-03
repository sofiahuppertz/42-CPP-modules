# Module Overview

In this module, we explore the Standard Template Library (STL) in C++, focusing on containers and the Algorithm Library. Although our code must remain compatible with C++98, we can leverage a variety of functions and containers provided by the STL.

## Key Concepts

### Container
In C++, a container is a class used to store and manage collections of objects. These objects can be of any type, and each container is a class template.

### Class Template
A class template provides a specification for generating classes based on parameters. The syntax is:
```cpp
template <class T> 
class className { /* ... */ };
```

### Vector
A vector in C++ is a dynamic array that can grow or shrink its size at runtime. It provides efficient element access by index and appending elements. However, insertions or deletions in the middle or at the beginning are slower due to the need to shift elements.

### Deque
A deque (double-ended queue) combines the advantages of a vector and a list. It allows efficient insertion and deletion at both ends and provides fast access to elements.

### List
A list in C++ is a doubly-linked list that enables efficient insertions, deletions, and movement of elements anywhere within the list.

### Iterators
Iterators in C++ allow access to elements in a container, similar to pointers. They facilitate traversal, access, modification, and deletion of elements within containers, acting as a bridge between containers and algorithms.

### Container Adaptors
Container adaptors provide a different interface for interacting with encapsulated containers. There are three types:
- **Stack**: Last-In-First-Out (LIFO) structure.
- **Queue**: First-In-First-Out (FIFO) structure.
- **Priority Queue**: Elements are sorted by priority, with the highest priority element at the front.

### Algorithm Library
The Algorithm Library is a collection of functions designed for use on ranges of elements (sequences accessed through iterators or pointers). It includes functions for searching, sorting, modifying, and performing various operations on containers.

## Exercises

### Ex00: Easyfind

The `easyfind` function searches for an integer value within a given container.

```cpp
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
    {
        throw NotFoundException();
    }
    return it;
}
```

- `typename T` allows `T` to be any container type.
- `T::iterator` is an iterator for the container type `T`.
- `container.begin()` and `container.end()` are iterators to the start and end of the container.
- `std::find` searches for the value within the range defined by the iterators.

### Ex01: Span

The `Span` class utilizes vectors and the Algorithm Library to manage a collection of integers and compute the shortest and longest spans.

```cpp
class Span {
public:
    Span(void);
    Span(unsigned int N);
    Span(const Span &other);
    ~Span(void);

    Span &operator=(const Span &other);

    // Member functions
    void addNumber(int n);
    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    unsigned int shortestSpan(void) const;
    unsigned int longestSpan(void) const;

    // Getters
    unsigned int getCapacity(void) const;
    unsigned int getSize(void) const;

private:
    std::vector<int> storage;
};
```

Pseudocode for span calculations:
```cpp
// 1. Sort the range.
// 2. For the shortest span, find the minimum difference between consecutive elements.
// 3. For the longest span, calculate the difference between the first and last elements.
```

### Ex03: MutantStack

The `MutantStack` class template extends `std::stack` to provide iterator access to the underlying container.

```cpp
template <class T, class Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
public:
    MutantStack(void);
    MutantStack(MutantStack const &src);
    virtual ~MutantStack(void);
    MutantStack &operator=(MutantStack const &rhs);

    // Iterator implementation
    typedef typename std::stack<T, Container>::container_type::iterator iterator;

    iterator begin(void);
    iterator end(void);
    iterator rbegin(void);
    iterator rend(void);
};

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
    return this->c.begin();
}
```

### Stack Container Adapter

A stack is a container adapter providing a LIFO data structure, encapsulating another container. The `MutantStack` class breaks the stack abstraction, allowing iterator access to the underlying container's elements.

## Useful Links for Documentation

- [C++ Algorithm Library](https://cplusplus.com/reference/algorithm/)
- [STL Reference](https://cplusplus.com/reference/stl/)

## Conclusion

This module introduces the powerful features of the STL, enabling efficient management and manipulation of collections in C++. By leveraging containers, iterators, and the Algorithm Library, we can write more flexible and robust code.
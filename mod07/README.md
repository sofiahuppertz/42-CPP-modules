```markdown
# Template Programming in C++

## Overview

This module introduces us to templates and two new keywords: `typename` and `template`.

## Concepts

Templates in C++ are a powerful tool for generic programming. They allow us to create a function or a class that can work with any data type by passing the data type as parameters to templates. The `typename` and `template` keywords are used to define templates.

Class templates in C++ allow classes to have members that use template parameters as types. Function templates allow for the creation of functions that can work with any data type.

### Function Template Example

```cpp
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
```

This function can swap values of any data type. The `typename` keyword is used to specify that `T` is a placeholder for any data type.

### Class Template Example

```cpp
template <typename T>
class Box {
    private:
        T content;
    public:
        Box(T content) : content(content) {}
        T getContent() { return content; }
};
```

In this example, `Box` is a class template that can be used to create objects that hold any type of content. The `typename` keyword is again used to specify that `T` is a placeholder for any data type.

## Exercises

### Ex00: Coding `swap()`, `min()`, and `max()` Template Functions

1. Implement a `swap` function template.
2. Implement a `min` function template.
3. Implement a `max` function template.

### Ex01: Iter()

Create a function template `iter()` that takes a function template parameter and applies it to each element of an array.

### Ex02: Template Class `Array`

1. Implement a template class `Array` that can create arrays of any type.
2. Overload the subscript operator `[]`.
3. Throw an exception if trying to access the array out of bounds.

## Conclusion

Understanding and utilizing templates in C++ can significantly enhance your programming capabilities. They provide the flexibility of working with any data type, thereby reducing the need for code redundancy. Class templates allow for the creation of classes that can handle any data type, while function templates enable the creation of functions that can work with any data type.

As with any other programming feature, the effective use of templates requires practice. The exercises provided will help you gain practical experience with using templates.

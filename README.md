# MyVector Class

The `MyVector` class is a custom implementation of a dynamic array (similar to `std::vector` in C++). It supports various operations like adding, inserting, removing, and accessing elements. This project demonstrates a simplified implementation of vector-like functionality in C++ with proper memory management.

## Features

- **Dynamic Capacity**: The vector doubles its capacity when full, ensuring efficient memory usage.
- **Basic Operations**: 
  - `push_back()`: Adds elements to the end of the vector.
  - `pop_back()`: Removes the last element.
  - `insert()`: Inserts an element at a specified position.
  - `erase()`: Removes an element at a specified index.
  - `at()`: Safely access elements with bounds checking.
  - `clear()`: Clears all elements from the vector.
- **Bounds Checking**: Provides safe element access with exception handling (throws `std::range_error`).

## Class Methods Overview

### Constructors:
- `MyVector(size_t capacity = MyVector::DEFAULT_CAPACITY)`: Creates a vector with an optional initial capacity.
- `MyVector(const MyVector& other)`: Copy constructor to create a deep copy of another vector.

### Destructors:
- `~MyVector()`: Destructor that handles memory cleanup.

### Operators:
- `operator= (const MyVector& rhs)`: Assignment operator for deep copying.
- `operator[] (size_t index)`: Accesses elements without bounds checking.
  
### Accessors:
- `size()`: Returns the number of valid elements in the vector.
- `capacity()`: Returns the current capacity of the vector.
- `empty()`: Checks if the vector is empty.
- `at(size_t index)`: Accesses an element with bounds checking.

### Mutators:
- `reserve(size_t new_capacity)`: Reserves additional capacity for future elements.
- `push_back(const T& element)`: Adds a new element to the end of the vector.
- `pop_back()`: Removes and returns the last element in the vector.
- `insert(size_t index, const T& element)`: Inserts an element at a specific index.
- `erase(size_t index)`: Removes an element at a specific index.
- `clear()`: Clears the vector, resetting its size to zero.

## Example Usage

```cpp
#include "MyVector.hpp"

int main() {
    CPSC131::MyVector::MyVector<int> vec;

    vec.push_back(10);
    vec.push_back(20);

    std::cout << "First element: " << vec[0] << std::endl;
    std::cout << "Second element: " << vec[1] << std::endl;

    vec.insert(1, 15);
    std::cout << "Element at index 1 after insert: " << vec[1] << std::endl;

    vec.pop_back();
    std::cout << "Size after pop_back: " << vec.size() << std::endl;

    return 0;
}

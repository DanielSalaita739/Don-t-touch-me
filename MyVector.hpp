/**********************************
* Name: Daniel Salaita
* CWID: 871482501
* Email: dsalaita0@csu.fullerton.edu
**********************************/

#include <cassert>
#include <iostream>
#include <string>
#include <stdexcept> // For std::range_error

namespace CPSC131::MyVector {

template <typename T>
class MyVector
{
public:
    /*******************
     * Static constants
     ******************/
    static constexpr size_t DEFAULT_CAPACITY = 64;
    static constexpr size_t MINIMUM_CAPACITY = 8;

    /*****************************
     * Constructors / Destructors
     ****************************/

    // Normal constructor
    MyVector(size_t capacity = MyVector::DEFAULT_CAPACITY)
        : size_(0), capacity_(capacity)
    {
        if (capacity_ < MINIMUM_CAPACITY) {
            capacity_ = MINIMUM_CAPACITY;
        }
        elements_ = new T[capacity_];
    }

    // Copy constructor
    MyVector(const MyVector& other)
        : size_(other.size_), capacity_(other.capacity_)
    {
        elements_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            elements_[i] = other.elements_[i];
        }
    }

    // Destructor
    ~MyVector()
    {
        delete[] elements_;
    }

    /************
     * Operators
     ************/

    // Assignment operator
    MyVector& operator=(const MyVector& rhs)
    {
        if (this == &rhs) return *this;

        delete[] elements_;

        size_ = rhs.size_;
        capacity_ = rhs.capacity_;
        elements_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            elements_[i] = rhs.elements_[i];
        }

        return *this;
    }

    // Operator overload to access elements at given index
    T& operator[](size_t index) const
    {
        if (index >= size_) throw std::range_error("Index out of bounds");
        return elements_[index];
    }

    /************
     * Accessors
     ************/

    // Return the number of valid elements
    size_t size() const
    {
        return size_;
    }

    // Return the capacity of the internal array
    size_t capacity() const
    {
        return capacity_;
    }

    // Check if the vector is empty
    bool empty() const
    {
        return size_ == 0;
    }

    // Access an element at a specific index with bounds checking
    T& at(size_t index) const
    {
        if (index >= size_) throw std::range_error("Index out of bounds");
        return elements_[index];
    }

    /***********
     * Mutators
     ***********/

    // Reserve additional capacity
    void reserve(size_t new_capacity)
    {
        if (new_capacity <= capacity_) return;
        changeCapacity(new_capacity);
    }

    // Set an element at a specific index
    T& set(size_t index, const T& element)
    {
        if (index >= size_) throw std::range_error("Index out of bounds");
        elements_[index] = element;
        return elements_[index];
    }

    // Add an element to the end of the vector
    T& push_back(const T& element)
    {
        if (size_ == capacity_) {
            changeCapacity(capacity_ * 2); // Double capacity when full
        }
        elements_[size_] = element;
        ++size_;
        return elements_[size_ - 1];
    }

    // Remove the last element in the vector
    T pop_back()
    {
        if (empty()) throw std::range_error("Vector is empty");
        T removed_element = elements_[--size_];
        return removed_element;
    }

    // Insert an element at a specific index
    T& insert(size_t index, const T& element)
    {
        if (index > size_) throw std::range_error("Index out of bounds");
        if (size_ == capacity_) {
            changeCapacity(capacity_ * 2);
        }
        for (size_t i = size_; i > index; --i) {
            elements_[i] = elements_[i - 1];
        }
        elements_[index] = element;
        ++size_;
        return elements_[index];
    }

    // Erase an element at a specific index
    T erase(size_t index)
    {
        if (index >= size_) throw std::range_error("Index out of bounds");
        T removed_element = elements_[index];
        for (size_t i = index; i < size_ - 1; ++i) {
            elements_[i] = elements_[i + 1];
        }
        --size_;
        return removed_element;
    }

    // Clear the vector
    void clear()
    {
        size_ = 0;
    }

private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    T* elements_ = nullptr;

    // Change the capacity of the vector
    void changeCapacity(size_t new_capacity)
    {
        if (new_capacity < size_) throw std::range_error("New capacity too small");
        T* new_elements = new T[new_capacity];
        for (size_t i = 0; i < size_; ++i) {
            new_elements[i] = elements_[i];
        }
        delete[] elements_;
        elements_ = new_elements;
        capacity_ = new_capacity;
    }
};

} // namespace CPSC131::MyVector

int main() {
    // Example usage of MyVector
    CPSC131::MyVector::MyVector<int> vec; // Create a vector of integers

    vec.push_back(10);   // Add an element
    vec.push_back(20);   // Add another element

    std::cout << "First element: " << vec[0] << std::endl;   // Output the first element
    std::cout << "Second element: " << vec[1] << std::endl;  // Output the second element

    vec.insert(1, 15);   // Insert element at index 1
    std::cout << "Element at index 1 after insert: " << vec[1] << std::endl;

    vec.pop_back(); // Remove the last element
    std::cout << "Size after pop_back: " << vec.size() << std::endl;

    return 0; // Return success
}


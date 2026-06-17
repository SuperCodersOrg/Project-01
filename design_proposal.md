# Project 01 – Design Proposal
## Project Objective

The objective of this project is to design a reusable and memory-safe Data Structure Library consisting of DynamicArray, LinkedList, and HashMap implementations.

The proposed design supports explicit memory ownership, predictable performance, and maintainability. For the Design choices i evaluated multiple alternatives for each data structure and selected the one with best tradeoff keeping in mind that later on we will be using these data structures in our upcoming projects like redis lite and ensuring that the selected approach best satisfies the upcoming project requirements.


# Section 1 – Public API
The proposed design extends the suggested interface with several modifications and utility operations 
## DynamicArray 
Methods - 
```cpp
DynamicArray() //construct empty array
void append(int value) //append element
void insert(int index, int value) //insert at position
void remove(int index) //remove element
bool get(int index, int& value) const //return value by reference to avoid sentinel values and returns boolean to handle cases with invalid index 
void set(int index, int value) // added to distinguish modification from insertion operations
void reserve(int newCapacity) //preallocate storage when the expected size is known reducing reallocations
void popBack() //remove last element
void clear() //remove all elements
int size() const //return element count
int capacity() const //return allocated capacity
bool isEmpty() const //check whether empty 
~DynamicArray() //destructor
DynamicArray(const DynamicArray&) //copy constructor
DynamicArray& operator=(const DynamicArray&) //assignment operator
```
Utility functions such as `popBack()`,` clear()`,` capacity()`, and `isEmpty()` improve the usability and completeness of the Data Structure.

---

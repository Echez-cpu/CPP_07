#include <iostream>
#include "../includes/Array.hpp"


#include <iostream>
#include "Array.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

// Define a simple class for testing with complex types
class TestClass {
    private:
        int _value;
    
    public:
        TestClass() : _value(0) {}
        TestClass(int val) : _value(val) {}
        TestClass(const TestClass &other) : _value(other._value) {}

        TestClass &operator=(const TestClass &other) {
            if (this != &other)
                this->_value = other._value;
            return *this;
        }

        void print() const {
            std::cout << _value;
        }
};

void testSimpleType() {
    std::cout << GREEN << "Testing with Simple Type (int)" << RESET << std::endl;
    
    Array<int> numbers(5);
    std::cout << "Size: " << numbers.size() << std::endl;

    for (int i = 0; i < numbers.size(); i++) {
        numbers[i] = (i + 1) * 10;
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }

    try {
        std::cout << numbers[10] << std::endl; // Should throw an exception
    } catch (const std::exception &e) {
        std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }
}

void testComplexType() {
    std::cout << GREEN << "\nTesting with Complex Type (TestClass)" << RESET << std::endl;

    Array<TestClass> objects(3);
    objects[0] = TestClass(100);
    objects[1] = TestClass(200);
    objects[2] = TestClass(300);

    std::cout << "Stored objects: ";
    for (int i = 0; i < objects.size(); i++) {
        objects[i].print();
        std::cout << " ";
    }
    std::cout << std::endl;

    try {
        objects[5].print(); // Should throw an exception
        std::cout << std::endl;
    } catch (const std::exception &e) {
        std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }
}

void testConstArray() {
    std::cout << GREEN << "\nTesting Read-Only Access on Const Array" << RESET << std::endl;

    const Array<int> constArray(3);
    for (int i = 0; i < constArray.size(); i++) {
        std::cout << "constArray[" << i << "] = " << constArray[i] << std::endl;
    }

    // Uncommenting this should cause a compilation error
    // constArray[0] = 42;
}

void testCopyAssignment() {
    std::cout << GREEN << "\nTesting Copy Constructor and Assignment Operator" << RESET << std::endl;

    Array<int> original(3);
    for (int i = 0; i < original.size(); i++) {
        original[i] = i * 5;
    }

    Array<int> copy(original); // Copy Constructor
    Array<int> assigned;
    assigned = original; // Assignment Operator

    std::cout << "Original: ";
    for (int i = 0; i < original.size(); i++) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Copy: ";
    for (int i = 0; i < copy.size(); i++) {
        std::cout << copy[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Assigned: ";
    for (int i = 0; i < assigned.size(); i++) {
        std::cout << assigned[i] << " ";
    }
    std::cout << std::endl;

    // Modifying original should not affect copy or assigned
    original[0] = 999;
    std::cout << "After modifying original[0] = 999" << std::endl;
    std::cout << "Original[0]: " << original[0] << std::endl;
    std::cout << "Copy[0]: " << copy[0] << std::endl;
    std::cout << "Assigned[0]: " << assigned[0] << std::endl;
}

int main() {
    testSimpleType();
    testComplexType();
    testConstArray();
    testCopyAssignment();
    return 0;
}







/*#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    std::cout << "We got here" << std::endl; // remember to delete numbers
    return 0;
}*/

#include "../includes/inter.hpp"

template <typename T>
void iter(T* address, size_t len, void (*func)(T& element)) {
    for (size_t i = 0; i < len; ++i) {
        func(address[i]);
    }
}


template <typename T>
void printValue(T& element) {
    std::cout << element << " ";
}

template <typename T>
void squareValue(T& element) {
    element = element * element;
}


template <>  // called a specialization
void squareValue<std::string>(std::string& element) {
    element = BLUE + element + RESET;
}


int main(void) {
    
    int arr1[] = {1, 2, 3, 4, 5};
    size_t len1 = sizeof(arr1) / sizeof(arr1[0]);

    std::cout << "Array before iteration (printValue): ";
    iter(arr1, len1, printValue);
    std::cout << std::endl;

    iter(arr1, len1, squareValue);
    std::cout << "Array after iteration (squareValue): ";
    iter(arr1, len1, printValue);
    std::cout << std::endl;

    std::string arr2[] = {"Hello", "world", "iter"};
    size_t len2 = sizeof(arr2) / sizeof(arr2[0]);

    std::cout << "Array after iteration (printValue): ";
    iter(arr2, len2, printValue);
    std::cout << std::endl;
    iter(arr2, len2, squareValue);
    std::cout << "Array after iteration (squareValue, with color): ";    
    iter(arr2, len2, printValue);
    std::cout << std::endl;
    return 0;
}

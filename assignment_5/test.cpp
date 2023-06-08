#include <iostream>

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[5];

    int* ptr = arr1;  // Assigning pointer to arr1

    // Print elements of arr1 using the pointer
    for (int i = 0; i < 5; i++) {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;

    ptr = arr2;  // Switching the pointer to arr2
    for (int i=0; i<5;i++)
        ptr[i] = i+6;
    // Print elements of arr2 using the same pointer
    for (int i = 0; i < 5; i++) {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
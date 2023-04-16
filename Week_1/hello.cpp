#include <iostream>
#include <cstdio>
using namespace::std;
// using std::cout;
// using std::endl;

struct node {
    int data;
    node *next;
};

int getElement(int arr[], int position) {
    return arr[position];
}

int main()
{
    int eger = 42;
    float ing = 3.14;
    char mander = 'c';
    long long int longNumber = 9999999999; // int is optional to specify
    short int y = 65535;
    bool isTrue = false; // talk about truthiness and falsiness...
    void *empty;

    int *int_ptr = &eger;
    // if(eger) {
    //     cout << "eger (" << eger << ") is truthy!" << endl << endl;
    //     printf("eger (%i), is truthy, ing: %f, mander");
    // } else{
    //     cout << "eger (" << eger << ") is truthy!" << endl << endl;
    // }

    // arrays
    int numbers[] = {2,4,6,8};
    int numbers2[10] = {0}; // indicies 0-9
    
    numbers2[0] = 24;
    
    for(int i = 0; i < sizeof numbers/sizeof numbers[0]; ++i) {
        cout << "numbers["<< i <<"]: " << numbers[i                                ] << endl;
    }

    for(int i = 0; i < sizeof(numbers2)/sizeof numbers2[0]; ++i) {
        cout << "numbers2["<< i <<"]: " << numbers2[i] << endl;
    }
    int result = getElement(numbers, 1);
    // int result = getElement(numbers, 10000000);
    cout << "result of getElement(numbers, 3): "<< result << endl;
    cout << "numbers[0]: " << numbers[0] << endl;
    cout << "numbers2[0]: " << numbers2[0] << endl;

    // struct part during declaration of a variable is optional
    struct node node0{0, nullptr};
    struct node node1{1, nullptr};

    cout << "node0.data: " << node0.data << endl;
    cout << "node0.next: " << node0.next << endl;

cout << "node1.data: " << node1.data << endl;
    cout << "node1.next: " << node1.next << endl;

    cout << "Hello World" << endl;
    cout << "Goodbye" << endl << endl;
    return 0;
}
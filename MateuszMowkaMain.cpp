// CppProgrammingWSB.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>

using namespace std;

void pointer_basics(void)
{
    int m = 10;
    int n;
    int o;
    int* z = &m; //Points to m

    cout << "Pointer : Show the basic declaration of pointers:" << endl;
    cout << "-------------------------------------------------" << endl;
    printf("m = %i, n and o are two integer vars. z is an integer\n", m);
    printf("z stores address of m = %p\n", z);
    printf(
        "Other addresses are:\n" \
        "&m stores addres of m = 0x%p\n"\
        "&n stores addres of n = 0x%p\n"\
        "&o stores addres of o = 0x%p\n"\
        "&z stores addres of z = 0x%p\n",
        &m, &n, &o, &z
    );
    return;
}

//Excersise two: 
void swap(int *a, int *b)
{
    int buff = *a; //Buff holds value under address of a
    *a = *b; //Now under address of a we hava value of what's under address of b
    *b = buff; //Assign value from under a to b
}

//Excersise three:
int input_2_array(int arr_size)
{
    int* my_arr = NULL;
    my_arr = new int[arr_size]; //When I used malloc I got all sorts of errors in VS, worked on Linux though
    if (my_arr) {
        for (int i = 0; i < arr_size; i++) {
            cout << "Your number: " << endl;
            scanf_s("%i", my_arr + i);
        }
        for (int i = 0; i < arr_size; i++) {
            cout << *(my_arr+i) << " ";
        }
        cout << endl;
        for (int i = arr_size - 1; i >= 0; i--) {
            cout << *(my_arr + i) << " "; //Do the other way around
        }
        delete[] my_arr; //When I used free() i got errors in VS studio, gcc on ubuntu was fine.
        my_arr = NULL;
        return 1;
    }
    return 0;
}

//Excersize four
void sort_array(int* array_of_ints, size_t arr_size)
{
    //This f-ction does bubble sorting
    bool sorted = false;
    while (!sorted) { //Loop enter
        sorted = true; //Assume we are sorted
        for (unsigned int i = 0; i < arr_size - 1; i++) { //must be size - 1 so we don't go out of bounds
            if (*(array_of_ints + i) < *(array_of_ints + i + 1)) { //compare element and the one next to it
                swap(array_of_ints + i, array_of_ints + i + 1); //Swap places if needed
                sorted = false; //We swapped so carry on iterating
            }
        } //If there were no swaps the sorted var stays true and will end the while loop
    }
}

void print_arr(int* to_print, size_t size) {
    for (unsigned int i = 0; i < size; i++) {
        cout << to_print[i] << " ";
    }
    cout << endl;
}

int main()

{   
    size_t arr_size;
    int a = 10;
    int b = 20;
    int my_array[] = { 99, 92, 75, 12, 98, 102, 1, 5, 8, 16, 56, 64, 85, 93, 11, 6, 34, 46 };
    //Ex 1:
    pointer_basics();    
    //Ex 2:
    printf("Var a: %i, var b: %i\n", a, b);
    swap(&a, &b);
    printf("Var a: %i, var b: %i\n", a, b);
    //Ex 3:
    input_2_array(10);
    //Ex 4:   
    arr_size = sizeof(my_array) / sizeof(int);
    print_arr(my_array, arr_size);
    sort_array(my_array, arr_size);
    print_arr(my_array, arr_size);

    return 0;
}




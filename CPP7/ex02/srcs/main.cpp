#include "Array.hpp"
#include <string>
#include <iostream>

#define SIZE 10

// #include <sstream>
// class Person {
//     public:
//         static unsigned int index;
//         std::string name;
//         Person(){
//             unsigned int n = this->index;
//             std::ostringstream oss;
//             oss << n;
//             std::string str = oss.str();
//             this->name = "No Name" + str;
//             this->index++;
//         }
// };
// unsigned int Person::index = 0;

int main () {

    std::cout << "\n[ USAGE EXAMPLE ]" << std::endl;
    Array<int> a(SIZE);

    for (int i = 0; i < SIZE; i++){
        a[i] = i;
    }
    for (int i = 0; i < SIZE; i++){
        std::cout << a[i];
        if (i != SIZE-1) std::cout << ", ";
    }
    std::cout << std::endl;

	std::cout << "\n[ COPY EXAMPLE ]" << std::endl;
    Array<int>b = a;
    
    a[0] = 99; // changing the first element of a
    for (int i = 0; i < SIZE; i++){
        std::cout << b[i];
        if (i != SIZE-1) std::cout << ", ";
    }
    std::cout << std::endl;

    // std::cout << "\n[ COMPLEX TYPE EXAMPLE ]" << std::endl;
    // Array<Person> p(10);
    //  for (int i = 0; i < SIZE; i++){
    //     std::cout << p[i].name << std::endl;
    // }

    return 0;
}

// #include <iostream>
// #include <Array.hpp>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     // //SCOPE
//     // {
//     //     Array<int> tmp = numbers;
//     //     Array<int> test(tmp);
//     // }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     // try
//     // {
//     //     numbers[-2] = 0;
//     // }
//     // catch(const std::exception& e)
//     // {
//     //     std::cerr << e.what() << '\n';
//     // }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
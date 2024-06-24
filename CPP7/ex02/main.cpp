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

#include <iter.hpp>

void sumElement(int& a) {
    a++;
}

int main () {
    int *a = new int[10];
    char *b = new char[10];

    for (int i = 0; i < 10; i++){
        a[i] = i;
    }
    for (int i = 0; i < 10; i++){
        b[i] = i + 'a';
    }

    std::cout << "\n[ INT EXAMPLE ]" << std::endl;
    iter(a, 10, sumElement);
    iter(a, 10, printElement<int>);

    std::cout << "\n[ CHAR EXAMPLE ]" << std::endl;
    iter(b, 10, printElement<char>);

    delete []a;
    delete []b;

    return 0;
}

#include <iostream>

int main() {
    int N;

    std::cout << "Entrez un nombre : ";
    std::cin >> N;

    while (N != 0) {
        std::cout << "Hello World" << std::endl;
        N--;
    }

    return 0;
}

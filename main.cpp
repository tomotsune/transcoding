#include <iostream>
#include "binary_number.h"

using namespace std;

int main() {
    binary_number b{};


    std::cout << "please select:" << std::endl;
    std::cout << "1. from dec" << std::endl;
    std::cout << "2. from_original" << std::endl;
    std::cout << "3. from_one_compliment" << std::endl;
    std::cout << "4. from_two_compliment" << std::endl;
    int i{};
    std::cin >> i;
    switch (i) {
        case 2:
            std::cin >> i;
            b.from_original(i);
            break;
        case 3:
            cin >> i;
            b.from_one_compliment(i);
            break;
        case 4:
            cin >> i;
            b.from_two_compliment(i);
            break;
        case 1:
            cin >> i;
            b.from_dec(i);
            break;
    }
    std::cout << "please select:" << std::endl;
    std::cout << "1. to dec" << std::endl;
    std::cout << "2. to_original" << std::endl;
    std::cout << "3. to_one_compliment" << std::endl;
    std::cout << "4. to_two_compliment" << std::endl;
    cin >> i;
    switch (i) {
        case 2:
            for (const auto &item : b.to_original()) {
                std::cout << (int) item << " ";
            }
            std::cout << std::endl;
            break;
        case 3:
            for (const auto &item : b.to_one_compliment()) {
                std::cout << (int) item << " ";
            }
            std::cout << std::endl;
            break;
        case 4:
            for (const auto &item : b.to_two_compliment()) {
                std::cout << (int) item << " ";
            }
            std::cout << std::endl;
            break;
        case 1:
            1;
            std::cout << b.to_dec() << std::endl;
            break;
    }


    return 0;
}

#include <iostream>
#include "binary_number.h"
int main() {
    binary_number b{};
    b.from_dec(-7);
    std::cout<<b<<std::endl;
    for (const auto &item : b.to_original()) {
        std::cout<<(int)item<<" ";
    }
    std::cout<<std::endl;
    for (const auto &item : b.to_one_compliment()) {
        std::cout<<(int)item<<" ";
    }
    std::cout<<std::endl;
    for (const auto &item : b.to_two_compliment()) {
        std::cout<<(int)item<<" ";
    }
    return 0;
}

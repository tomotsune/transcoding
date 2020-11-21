//
// Created by tomot on 2020/11/21.
//

#ifndef TRANSCODING_BINARY_NUMBER_H
#define TRANSCODING_BINARY_NUMBER_H

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

typedef unsigned char byte;
class binary_number {
private:
    int bin;
public:
    void from_dec(const int& dec);
    [[nodiscard]] int to_dec()const;
    [[nodiscard]] std::vector<byte> to_original()const;
    void from_original(int const& o);
    [[nodiscard]] std::vector<byte> to_one_compliment()const;
    void from_one_compliment(const int& one);
    [[nodiscard]] std::vector<byte>to_two_compliment()const;
    void from_two_compliment(const int& two);

    friend std::ostream &operator<<(std::ostream &os, const binary_number &number);

};


#endif //TRANSCODING_BINARY_NUMBER_H

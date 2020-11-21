//
// Created by tomot on 2020/11/21.
//



#include <cmath>
#include "binary_number.h"

/**
 * 使用参数w表示权重.
 * @return 二进制数
 */
void binary_number::from_dec(const int &dec) {
    int temp{dec}, w{1};
    while (temp) {
        bin += temp % 2 * w;
        temp /= 2;
        w *= 10;
    }
}

int binary_number::to_dec() const {
    int dec{}, temp{bin}, w{1};
    while (bin) {
        dec += temp % 10 * w;
        temp /= 10;
        w *= 2;
    }
}

std::vector<byte> binary_number::to_original() const {
    std::vector<byte> v{};
    int temp{bin>0?bin:-bin};
    while (temp) {
        v.push_back(temp % 10);
        temp /= 10;
    }
    while(v.size()<8)v.push_back(0);
    v[7] = bin > 0 ? 0 : 1;
    std::reverse(v.begin(), v.end());
    return v;
}

void binary_number::from_original(const int &o) {
    int temp{o};
    for (int i = 0; i < 7; ++i) {
        bin += temp % 10 * std::pow(10, i);
        temp /= 10;
    }
    bin = o / pow(10, 8) > 0 ? -bin : bin;
}

std::vector<byte> binary_number::to_one_compliment() const {
    if (bin>0)return to_original();
    auto v{to_original()};
    for (auto iterator = v.begin() + 1; iterator != v.end(); ++iterator) {
        *iterator = !*iterator;
    }
    return v;
}

void binary_number::from_one_compliment(const int &one) {
    if (!(one / std::pow(10, 8)))from_original(one);
    std::vector<int> v;
    int temp{one}, w{1}, result{};
    while (one) {
        result += !(one % 10) * w;
        temp /= 10;
        w *= 10;
    }
    from_original(result);
}

std::vector<byte> binary_number::to_two_compliment() const {
    if(bin>0)return to_original();
    auto v = to_one_compliment();
    if (v[7] == 0) v[7] = 1;
    else {
        for (auto iterator = v.rbegin(); iterator != v.rend(); ++iterator) {
            if (*iterator) {
                *iterator = 0;
            } else {
                *iterator = 1;
                break;
            }
        }
    }
    return v;
}

void binary_number::from_two_compliment(const int &two) {
    from_one_compliment(two-1);
}

std::ostream &operator<<(std::ostream &os, const binary_number &number) {
    os << "bin: " << number.bin;
    return os;
}








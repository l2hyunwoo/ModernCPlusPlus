//
// Created by Hyun Woo Lee on 2021/08/15.
//

#include "iostream"
#include "vector"
#include "array"

using namespace std;


class IPv4 {
private:
    array<char, 4> ipAddress;

public:
    constexpr IPv4() : ipAddress{{0}} {}

    constexpr IPv4(char const first, char const second, char const third, char const fourth) :
            ipAddress{{first, second, third, fourth}} {}

    explicit constexpr IPv4(unsigned long ip) :
            ipAddress{{static_cast<char>((ip >> 24) & 0xFF),
                              static_cast<char>((ip >> 16) & 0xFF),
                              static_cast<char>((ip >> 8) & 0xFF),
                              static_cast<char>(ip & 0xFF)}} {}

    IPv4(IPv4 const &other) noexcept: ipAddress(other.ipAddress) {}

    IPv4 &operator=(IPv4 const &other) noexcept {
        ipAddress = other.ipAddress;
        return *this;
    }
};

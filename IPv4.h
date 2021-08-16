//
// Created by Hyun Woo Lee on 2021/08/15.
//

#include <sstream>
#include "array"

using namespace std;


class IPv4 {
private:
    array<unsigned char, 4> ipAddress;

public:
    constexpr IPv4() : ipAddress{{0}} {}

    constexpr IPv4(unsigned char const first, unsigned char const second, unsigned char const third, unsigned char const fourth) :
            ipAddress{{first, second, third, fourth}} {}

    explicit constexpr IPv4(unsigned long ip) :
    ipAddress{{static_cast<unsigned char>((ip >> 24) & 0xFF),
               static_cast<unsigned char>((ip >> 16) & 0xFF),
               static_cast<unsigned char>((ip >> 8) & 0xFF),
               static_cast<unsigned char>(ip & 0xFF)}} {}

    IPv4(IPv4 const &other) noexcept: ipAddress(other.ipAddress) {}

    IPv4 &operator=(IPv4 const &other) noexcept {
        ipAddress = other.ipAddress;
        return *this;
    }

    string to_string() const {
        stringstream sstr;
        sstr << *this;
        return sstr.str();
    }

    constexpr unsigned long to_ulong() const noexcept {
        return (static_cast<unsigned long>(ipAddress[0]) << 24) |
               (static_cast<unsigned long>(ipAddress[1]) << 16) |
               (static_cast<unsigned long>(ipAddress[2]) << 8) |
               (static_cast<unsigned long>(ipAddress[3]));
    }

    friend ostream &operator<<(ostream &os, const IPv4 &printObject) {
        os << static_cast<int>(printObject.ipAddress[0]) << "."
           << static_cast<int>(printObject.ipAddress[1]) << "."
           << static_cast<int>(printObject.ipAddress[2]) << "."
           << static_cast<int>(printObject.ipAddress[3]);
        return os;
    }

    friend istream &operator>>(istream &is, IPv4 &inputObject) {
        char sep1, sep2, sep3;
        int first, second, third, fourth;
        is >> first >> sep1 >> second >> sep2 >> third >> sep3 >> fourth;
        if (sep1 == '.' && sep2 == '.' && sep3 == '.')
            inputObject = IPv4(first, second, third, fourth);
        else
            is.setstate(ios_base::failbit);

        return is;
    }
};

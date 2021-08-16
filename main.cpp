#include <iostream>
#include "IPv4.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    IPv4 address(168, 192, 0, 1);
    cout << address << endl;
    return 0;
}

#include <iostream>
#include "version.hpp"

int build_version() {
    return VERSION;
}

int main() {
    std::cout << "build " << build_version() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

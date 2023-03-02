#include "output.h"
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <windows.h>

void printVString(std::vector<std::string> const& a) {
    std::cout << "All Files to be encrypted: " << std::endl;

    for (int i = 0; i < a.size(); i++) {
        std::cout << a.at(i) << " /// ";
    }
}

void printVPath(std::vector<std::filesystem::path> const& a) {
    std::cout << "All Files to be encrypted: " << std::endl;

    for (int i = 0; i < a.size(); i++) {
        std::cout << a.at(i) << " /// ";
    }
}

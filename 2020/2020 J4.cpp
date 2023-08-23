#include <iostream>
#include <string>

bool is_cyclic_shift(const std::string& text, const std::string& pattern) {
    for (size_t i = 0; i < text.length(); ++i) {
        std::string shifted = text.substr(i) + text.substr(0, i);
        if (shifted == pattern) {
            return true;
        }
    }
    return false;
}

int main() {
    std::string text, pattern;
    std::cin >> text >> pattern;

    if (is_cyclic_shift(text, pattern)) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

class fileRAII {
public:
    explicit fileRAII(const std::string& filename, bool binary = false) {
        if (binary) {
            file.open(filename, std::ios::binary);
        } else {
            file.open(filename);
        }
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file");
        }
    }

    std::string readFile() {
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        return content;
    }

    ~fileRAII() {
        if (file.is_open()) {
            file.close();
        }
    }

private:
    std::ifstream file;
};
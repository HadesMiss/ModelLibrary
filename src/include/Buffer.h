#pragma once
#include <memory>
#include <string>
#include "common.h"
#include <vector>

class Buffer{
public:
    DISALLOW_COPY_AND_MOVE(Buffer);
    Buffer() = default;
    ~Buffer() = default;

    const std::string &bufStr();
    const char* c_str() const;
    void set_buf(const std::vector<char>& buf);

    size_t Size() const;
    void Append(const char* _str, int _size);
    void Clear();
    void castTostring(std::vector<char> &charVector);
    const std::vector<char> bufOrigin() const;

private:
    std::string buf_;
    std::vector<char> bufRe;
};
#include "Buffer.h"
#include "iostream"


const std::string &Buffer::bufStr() {buf_ = std::string(bufRe.data(), bufRe.size()); return buf_;}

const char* Buffer::c_str() const {return bufRe.data();}
const std::vector<char> Buffer::bufOrigin() const {return bufRe;}

void Buffer::set_buf(const std::vector<char> &buf){
    bufRe = buf;
}

size_t Buffer::Size() const { return bufRe.size(); }

void Buffer::Append(const char* str, int size){
    bufRe.insert(bufRe.end(), str, str + size);
}

void Buffer::Clear(){bufRe.clear();}

void Buffer::castTostring(std::vector<char> &charVector){
    //buf_.append(charVector.data(), charVector.size());
    //std::cout<<buf_<<std::endl;
}
#include "Buffer.h"
#include "iostream"

const std::string &Buffer::buf() const{return buf_;}

const char *Buffer::c_str() const {return buf_.c_str();}

void Buffer::set_buf(const std::string &buf){
    buf_ = buf;
}

size_t Buffer::Size() const { return buf_.size(); }

void Buffer::Append(const char* str, int size){
    for(int i = 0; i < size; i++){
        if(str[i] == '\0'){
            break;
        }
        buf_.push_back(str[i]);
    }
}

void Buffer::Clear(){buf_.clear();}
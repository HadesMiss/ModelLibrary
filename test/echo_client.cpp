#include "pine.h"
#include <iostream>
#include <fstream>

std::string readFile(bool isBinary = true) {
    std::string path = "../build/frontend/build/logo192.png";
    if(isBinary == true){
        std::ifstream file(path, std::ios::binary);
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
        return content;
    }
    else{
        std::ifstream file(path);
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
        return content;
    }

}

int main() {
  Socket *sock = new Socket();
  sock->Create();
  sock->Connect("127.0.0.1", 1234);

  Connection *conn = new Connection(sock->fd(), nullptr);

  while (true) {
    std::string input = readFile();
    std::cout<<"dgrdgrgdr"<<std::endl;
    std::cout<<input<<std::endl;
    std::cout<<"dasgdgdg"<<std::endl;
    conn->set_send_buf(input);
    conn->Write();
    if (conn->state() == Connection::State::Closed) {
      printf("\n conn closed");
      conn->Close();
      printf("\n conn closed");
      break;
    }
    conn->Read();
    std::cout << "Message from server: " << conn->read_buf()->c_str() << std::endl;
  }

  delete conn;
  delete sock;
  return 0;
}
#include "../class/Netconnection.h"


Netconnection::Netconnection():address ("localhost"),port(9876){

}

bool Netconnection::connect(){


  std::string name = "qqch";
  sf::TcpSocket socket;
  sf::Socket::Status status = socket.connect(address, port);
  if (status != sf::Socket::Done){
      return 0;
  }
  else {
    void* pname = &name;
    if (socket.send(pname, name.length()) != sf::Socket::Done){
    // erreur...
    }
  }
  return 1;

}

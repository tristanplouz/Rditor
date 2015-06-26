#include "../class/Netconnection.h"


Netconnection::Netconnection():address ("localhost"),port(9876){
  socket.setBlocking(false);
}

bool Netconnection::connect(){

  /*char data[100];
  std::size_t received;
  std::string name = "qqch";
  sf::Socket::Status status = socket.connect(address, port);
  if (status != sf::Socket::Done){
      return 0;
  }
  void* pname = &name;
  if (socket.send(pname, name.length()) != sf::Socket::Done){
  // erreur...
  }
  if (socket.receive(data, 100, received) == sf::Socket::Done){
      // erreur...
  }*/
  sf::Packet packet;
  packet<<"0 my name";

  if ( socket.send(packet,address,port) != sf::Socket::Done){
  return 0;
  }

  return 1;
}

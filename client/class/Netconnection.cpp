#include "../class/Netconnection.h"


Netconnection::Netconnection():address ("localhost"),port(9876){
  socket.setBlocking(false);
}

bool Netconnection::connect(){

  sf::Packet packet;
  username = "my anme";
  std::string data = "0" + username;
  packet<<data;

  if ( socket.send(packet,address,port) != sf::Socket::Done){
    return 0;
  }

  return 1;
}

bool Netconnection::send(int type, std::string data){

  sf::Packet packet;
  packet<<std::to_string(type)+ data;

  if ( socket.send(packet,address,port) != sf::Socket::Done){
    return 0;
  }

  return 1;
}

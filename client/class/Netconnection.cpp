#include "../class/Netconnection.h"


Netconnection::Netconnection():address ("localhost"),port(5000){
  socket.setBlocking(false);
  room=1;
}

bool Netconnection::connect(){

  sf::Packet packet;
  username = "my anme";
  std::string data = "1" + username;
  packet<<data;

  if ( socket.send(packet,address,port) != sf::Socket::Done){
    return 0;
  }

  return 1;
}

bool Netconnection::send(int type, int room, std::string data){
  if(connected){
    sf::Packet packet;
    packet<<std::to_string(type)+std::to_string(room)+ data;

    if ( socket.send(packet,address,port) != sf::Socket::Done){
      return 0;
    }
  }
  return 1;
}

#include "../class/Netconnection.h"
#include <iostream>


Netconnection::Netconnection(){
  socket.setBlocking(false);
}

bool Netconnection::connect(){

  if(!connected){
    sf::Packet packet;
    address =sf::IpAddress(ip);
    //address =sf::IpAddress(ip);
    std::string data = "1"+std::to_string(room) + username;
    packet<<data;

    if ( socket.send(packet,address,port) == sf::Socket::Done){
      return 1;
    }
  }
  return 0;

}

bool Netconnection::send(int type, std::string data){
  if(connected){
    sf::Packet packet;
    packet<<std::to_string(type)+std::to_string(room)+ data;

    if ( socket.send(packet,address,port) != sf::Socket::Done){
      return 0;
    }
  }
  return 1;
}

/*bool Netconnection::receiveData(){

  char data[100];
  std::size_t received;
  unsigned short remotePort;
  sf::IpAddress sender;
  if(socket.receive(data, 100, received, sender, remotePort)==sf::Socket::Done){

    return 1;

  }

  return 0;
}*/

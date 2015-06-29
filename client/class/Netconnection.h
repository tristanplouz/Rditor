#ifndef DEF_NETCONECTION
#define DEF_NETCONECTION

#include <SFML/Network.hpp>

//Class gerant la connextion reseau
/*
type de message client/server
0:deconnection
1:connection
2:chat
3:Modification texte
*/
class Netconnection {

	public:
		Netconnection();
		bool connect();
		bool send(int type,int room,std::string data);
		bool connected=false;
		int room;

	private:
		sf::UdpSocket socket;
		sf::IpAddress address;
		std::string username;
		int port;

};

#endif

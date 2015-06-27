#ifndef DEF_NETCONECTION
#define DEF_NETCONECTION

#include <SFML/Network.hpp>

//Class gerant la connextion reseau
/*
type de message client/server
0:connection
1:chat
2:modification
*/
class Netconnection {

	public:
		Netconnection();
		bool connect();
		bool send(int type,std::string data);

	private:
		sf::UdpSocket socket;
		sf::IpAddress address;
		std::string username;
		int port;

};

#endif

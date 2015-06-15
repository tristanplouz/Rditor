#ifndef DEF_NETCONECTION
#define DEF_NETCONECTION

#include <SFML/Network.hpp>

//Class gerant la connextion reseau
class Netconnection {

	public:
		Netconnection();
		bool connect();

	private:
		sf::TcpSocket socket;
		std::string address;
		int port;

};

#endif

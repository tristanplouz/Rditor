#ifndef DEF_NETCONECTION
#define DEF_NETCONECTION

#include <SFML/Network.hpp>

class Netconnection {

	public:
		Netconnection();
		bool connect();

	private:
		std::string address;
		int port;

};

#endif

#include "connect.hh"

Connection::Connection(): mySocket(0) { }

Connection::~Connection() {
	if(mySocket) close(mySocket);
}
		
bool Connection::Send() {
	if(myBuffer) {
		write(mySocket, myBuffer, strlen(myBuffer));
		delete [] myBuffer; myBuffer = NULL;
		return true;
	}
	return false;
}

bool Connection::Recv() {
	int result;
}

#include "iostream"

#include "Controller.h"


int main() {

	// Here is the decription of the logger application:
	// Generally this program will be run until the user has interupted the program

	// 1. the application starts and does three things in the same time!
	//     a. Wait for logs to come (as JSON)
	//     b. checks if our elastic search server is live or not
	//     c. Writs the changes to a new file and (naybe send them to a new server)
	// 
	// 2. This application is paralel with three threads
	// 3. Will save the logs to another file if the server was offline
	
	Controller cntr;
	cntr.operate();
	
	return 0;
}

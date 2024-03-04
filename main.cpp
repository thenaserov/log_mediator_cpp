#include "iostream"

#include "Controller.h"
#include "curl/curl.h"
#include <string>
#include <fstream>
#include <sstream>


void TestCase1()
{
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://elstc.emapna.com/");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST);
        // Read the contents of sample.json
        std::ifstream file("sample.json");
        if (file.is_open()) {
            std::stringstream buffer;
            buffer << file.rdbuf();
            std::string json_data = buffer.str();
            // Set the POST data
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data.c_str());
            // Set the username and password for HTTP authentication
            curl_easy_setopt(curl, CURLOPT_USERPWD, "elastic:6aR1h77pUl6kU9PQZ2tS");
            // Set the POST request type
            curl_easy_setopt(curl, CURLOPT_POST, 1L);
            // Perform the request
            res = curl_easy_perform(curl);
            // Check for errors
            if (res != CURLE_OK) {
                std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            }
            // Cleanup
            curl_easy_cleanup(curl);
        }
        else {
            std::cerr << "Error opening sample.json" << std::endl;
        }
    }
}

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
	
//	Controller cntr;
//	cntr.operate();
	

    
	TestCase1();
    // system("curl -X POST https://elstc.emapna.com -u elastic:6aR1h77pUl6kU9PQZ2tS -H \"Content - Type: application / json\" -d @sample.json");

	return 0;
}

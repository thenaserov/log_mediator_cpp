/*
Assuming that you have added C++ REST SDK to your project successfully:
This is how you can POST a JSON to your http://localhost:9200 server
Easy AF
  */


#include <cpprest/http_client.h>
#include <cpprest/json.h>
#include <iostream>

using namespace web;
using namespace web::http;
using namespace web::http::client;

int main() {
    // Create an HTTP client to communicate with the Elasticsearch server
    http_client client(U("http://localhost:9200"));

    // Define the Elasticsearch index and type
    utility::string_t index = U("myindex");
    utility::string_t type = U("mytype");

    // Create a JSON object with the data to be sent to Elasticsearch
    json::value data;
    data[U("name")] = json::value::string(U("John Doe"));
    data[U("age")] = json::value::number(30);

    // Create a request to index the data in Elasticsearch
    http_request request(methods::POST);
    request.set_request_uri(U("/").append(index).append(U("/").append(type)));
    request.set_body(data);

    // Send the request to the Elasticsearch server
    client.request(request).then([](http_response response) {
        if (response.status_code() == status_codes::OK) {
            std::cout << "Data successfully sent to Elasticsearch\n";
        } else {
            std::cout << "Error: " << response.status_code() << "\n";
        }
    }).wait();

    return 0;
}

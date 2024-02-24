#include "HeartBeat.h"

HeartBeat::HeartBeat()
{
}

HeartBeat::~HeartBeat()
{
}

bool HeartBeat::ping(std::string address)
{
	std::string data = "ping " + address;
	if (system(data.c_str()) == 0) {
		return true;
	} else {
		return false;
	}
}

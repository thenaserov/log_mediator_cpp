#include "Controller.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

Controller::Controller()
{
}

std::vector<std::string> Controller::readLogsFromFile(std::string path)
{
	_log_file_reader.setPath(path);
	_log_file_reader.openFileRead();
	return _log_file_reader.readLines();
}

void Controller::writeLogsToFile(std::string path, std::vector<std::string> logs)
{
	_log_file_writer.setPath(path);
	_log_file_writer.openFileWrite();
	_log_file_writer.writeLines(logs);
}

void Controller::setElasticServerAddress(std::string address)
{
	_elastic_server_address = address;	
}

void Controller::getLog()
{
	while (1) {
		auto logsLineByLine = readLogsFromFile("rawLog.txt");
		for (auto a: logsLineByLine)
			std::cout << a << std::endl;
        #ifdef _WIN32
            Sleep(1000);
        #else
            sleep(1);
        #endif
        auto log = _log_gen.getLogAsString();
		std::vector<std::string> logg = { log };
		writeLogsToFile("ss.txt", logg);
	}
}

void Controller::checkConnection()
{
	auto start = std::chrono::steady_clock::now();
	while (true) {
		auto end = std::chrono::steady_clock::now();
		auto diff = end - start;
		if (std::chrono::duration_cast<std::chrono::seconds>(diff).count() >= 1) {
			_hb.ping("192.168.1.1");
			start = std::chrono::steady_clock::now();
		}
	}
}

void Controller::doLog()
{
	while (1) {

	}
}

void Controller::logToFile()
{

}

void Controller::logToServer()
{
}

void Controller::operate()
{
	_thread_heartbeat = std::thread(&Controller::checkConnection, this);
	_thread_log_check = std::thread(&Controller::getLog, this);
	_thread_heartbeat.join();
	_thread_log_check.join();
}

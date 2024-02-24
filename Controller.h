#pragma once
#include "FileOperator.h"
#include "HeartBeat.h"
#include <vector>
#include <thread>
#include <mutex>

class Controller{

public:
	Controller();
	std::vector<std::string> readLogsFromFile(std::string path);

	// _thread_log_check
	void getLog();

	// heartbeat
	void checkConnection();

	// _thread_do_log
	void doLog();

	void logToFile();
	void logToServer();

	// main
	void operate();

private:
	FileOperator _file_operator;
	HeartBeat _hb;
	std::mutex _mtx;
	std::thread _thread_heartbeat;
	std::thread _thread_log_check;
	std::thread _thread_do_log;

protected:
};

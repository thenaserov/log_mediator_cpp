#include "FileOperator.h"

FileOperator::FileOperator()
{
}

FileOperator::~FileOperator()
{
}

bool FileOperator::isOpen()
{
	return _file.is_open();
}

void FileOperator::openFileRead()
{
	_file.open(_path, std::ios::in);
}

void FileOperator::openFileWrite()
{
	_file.open(_path, std::ios::out);
}

std::vector<std::string> FileOperator::readLines()
{
	std::string text;
	while (std::getline(_file, text)) {	
		_lines.push_back(text);
	}
	auto lines = _lines;
	_lines.clear();
	_file.close();
	return lines;
}

void FileOperator::writeLines(std::vector<std::string>& lines)
{
	for (auto &line : lines)
		_file << line;
	_file.close();
}

void FileOperator::setPath(std::string& path)
{
	_path = path;
}

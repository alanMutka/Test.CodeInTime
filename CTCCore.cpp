#include "CTCCore.h"

#include <regex>

//Default constructor
CTCCore::CTCCore() {

}

bool CTCCore::loadSourceFile(std::string fileName) {

	try
	{
		std::ifstream ifs(fileName);
		for (std::string line; std::getline(ifs, line); )
		{
			std::cout << line;
			this->_sourceLines.push_back(trim(line));
		}
		std::cout << "LOADED SOURCE:" << fileName << std::endl;
	}
	catch (const std::exception& e)
	{
		return false;
	}
	return true;
}

bool CTCCore::loadSourceValidationFiles(std::string dirPath) {

	int fileCounter = 0;

	char fileName[250];
	
	std::cout << "LOADING VALIDATION:";
	while (true) {
		try
		{
			sprintf_s(fileName, "WEBSOCKET_%06d.txt", fileCounter);
			std::ifstream ifs(dirPath + "\\" + fileName);
			if (ifs.is_open() == false) break;
			std::vector<std::string> validLines;
			int lineCounter = 0;
			for (std::string line; std::getline(ifs, line); )
			{
				//the first line has the file name
				if (lineCounter == 0) {
					std::size_t found = line.find(":");
					if (found != std::string::npos) {
						_valudationLinesFileName.push_back(line.substr(found+1));
					}
				}
				else validLines.push_back(trim(line));
				lineCounter++;
			}
			this->_validationLinesData.push_back(validLines);
			std::cout << "L:" << fileName << std::endl;
			fileCounter++;
		}
		catch (const std::exception& e)
		{
			break;
		}
	}//end of while
	return true;
}

const std::string WHITESPACE = " \n\r\t\f\v";

std::string CTCCore::ltrim(const std::string& s)
{
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == std::string::npos) ? "" : s.substr(start);
}

std::string CTCCore::rtrim(const std::string& s)
{
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string CTCCore::trim(const std::string& s) {
	return rtrim(ltrim(s));
}
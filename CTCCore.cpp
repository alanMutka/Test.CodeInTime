#include "CTCCore.h"

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
			this->_sourceLines.push_back(line);
		}
	}
	catch (const std::exception& e)
	{
		return false;
	}
	return true;
}

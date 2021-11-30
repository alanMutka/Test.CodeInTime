#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class CTCCore
{
public:
	CTCCore();

	bool loadSourceFile(std::string fileName);


private:
	// lines from the SOURCE file
	std::vector<std::string> _sourceLines;
	//list of indexed linking to the main eventLinesIndex
	std::vector <int> _sourceLinesIndexed;
	//lines from the event file
	std::vector<std::vector<std::string>> _eventLines;

};


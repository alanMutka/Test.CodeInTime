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
	bool loadSourceValidationFiles(std::string dirPath);


private:
	// lines from the SOURCE file - final exam file
	std::vector<std::string> _sourceLines;
	//list of indexed linking to the main eventLinesIndex
	std::vector <int> _sourceLinesIndexed;
	//VSCODE source lines for every file/package
	std::vector<std::vector<std::string>> _validationLinesData;
	//VSCODE file names for the validation file sources
	std::vector<std::string> _valudationLinesFileName;


	//methods
	std::string ltrim(const std::string& s);
	std::string rtrim(const std::string& s);
	std::string trim(const std::string& s);

};


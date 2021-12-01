// CodeInTime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CTCCore.h"
#include <filesystem>

//for getMyDocumentPath
#include <windows.h>
#include <shlobj.h> 

#pragma comment(lib, "shell32.lib")

HRESULT getMyDocumentPath(std::string& pathUserData, std::string& pathLogs, std::string& pathSettings) {

    CHAR my_documents[MAX_PATH];
    HRESULT result = SHGetFolderPathA(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, my_documents);

    if (result != S_OK)
    {
        std::cout << "Error: " << result << "\n";
    }
    else
    {
        pathUserData = std::string(my_documents);
    }

    //std::cout << "User path: " << pathUserData << "\n";

    pathUserData = pathUserData + "\\AssessMeControl";
    pathLogs = pathUserData + "\\Logs";
    pathSettings = pathUserData + "\\Settings";
    return result;
}

std::string getCurrentDirectoryOnWindows()
{
    const unsigned long maxDir = 260;
    char currentDir[maxDir];
    GetCurrentDirectory(maxDir, currentDir);
    return std::string(currentDir);
}

int main()
{
    CTCCore* ctcCore = new CTCCore();
    //Load the source file

    //todo - create here relative path to the project DIR, we should also add it here?

    std::string currentDir = getCurrentDirectoryOnWindows();

    

    ctcCore->loadSourceFile(currentDir + "\\Testers\\TESTING1\\Jack.java");
    ctcCore->loadSourceValidationFiles(currentDir + "\\Testers\\TESTING1\\VSCODE");

    //loading websocket events files

    
}



// lib.h

#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <string>
#include <clocale>
#include <ctime>
#include <fstream>
#include <thread>

// Define export/import macro
#ifdef _LIBRARY_BUILD
    #define LIB_API __declspec(dllexport)  // When building the DLL, export symbols
#else
    #define LIB_API __declspec(dllimport)  // When linking to the DLL, import symbols
#endif

enum class ILEVEL
{
	LOW,
	MEDIUM,
	HIGH
};

class LIB_API Lib
{
public:
	Lib(std::string fileName, ILEVEL defaultILevel);

	void setILevel(ILEVEL level);

	std::string Log(std::string text);

	std::string getTime();

	std::string getStringLevel(ILEVEL defILevel);

	void setDefultLevel(ILEVEL level);
	


private:

	std::string fileName;
	ILEVEL defaultILevel;

};

#endif

#pragma once

#include "lib.h"


Lib::Lib(std::string fileName, ILEVEL defaultILevel) : 
	fileName(fileName), defaultILevel(ILEVEL::MEDIUM)
{
	setDefultLevel(defaultILevel);

	std::ofstream File(fileName, std::ios::app);

	if (!File.is_open()) {
		std::cerr << "File cannot be open!" << std::endl;
	}
	std::string text;

	do
	{
		text = Lib::Log(text);
		if (text != "exit")
		{
			File << text << "\t" << Lib::getStringLevel(Lib::defaultILevel) << "\t" << Lib::getTime() << std::endl;
		}
	} while (text!="exit");
	
	File.close();
}



void Lib::setILevel(ILEVEL level)
{
	Lib::defaultILevel = level;
}

std::string Lib::Log(std::string text)
{
	
	std::cout << "Enter message \t";
	std::cin >> text;
	return text;
}

std::string Lib::getTime()
{
	std::time_t now = std::time(nullptr);

	std::string stringTime = std::ctime(&now);

	return stringTime;
}

std::string Lib::getStringLevel(ILEVEL defILevel)
{
	switch (defILevel)
	{
	case ILEVEL::LOW: return "LOW";
		break;
	case ILEVEL::MEDIUM: return "MEDIUM";
		break;
	case ILEVEL::HIGH: return "HIGH";
		break;
	default: return "MEDIUM";
		break;
	}
}

void Lib::setDefultLevel(ILEVEL level)
{
	Lib::defaultILevel = level;
};


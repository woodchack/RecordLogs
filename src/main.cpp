#include "Lib.h"


int main(int argc, char** argv)
{
	std::string fileName = argv[1];
	ILEVEL level;

	switch (argv[2][0])
	{
	case('L') :
			level = ILEVEL::LOW;
			break;
	case('M') :
			level = ILEVEL::MEDIUM;
			break;
	case('H') :
			level = ILEVEL::HIGH;
			break;
		default: level = ILEVEL::MEDIUM;
			break;
	}


	Lib test(fileName, level);
	

	return 0;
}
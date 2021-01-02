#include "Input.h"


int getInput()
{
	char intermediate;
	int iterator = 0;
	int input = 0;
	std::cin >> intermediate;
	std::cin.ignore(1000, '\n');

	for (char i = '1'; i <= '9'; i++)
	{
		iterator++;
		if (intermediate == i)
		{
			input = iterator;
			break;
		}
	}
	return input;
}

int getGameOverInput()
{
	static std::string response;

	if (response.empty() || (response != "yes" && response != "no"))
	{
		std::cin >> response;
	}

	if(response != "yes" && response != "no")
	{
		return 0;
	}
	else if (response == "yes")
	{
		return 1;
	}
	else if (response == "no")
	{
		return 2;
	}
}

#include<iostream>
#include"TextRenderer.h"
#include"Input.h"
#include"Raster.h"

void init(Raster& raster, TextRenderer& text, int& rounds, int& input, bool& changeRole, bool& running, char& Player)
{
	raster.clearRaster();
	text.writeText(text.getWelcomeT());
	raster.DrawRaster();
	rounds = 0;
	input = 0;
	changeRole = true;
	running = true;
	Player = 'X';
}

int main() 
{
	Raster raster;
	TextRenderer text;

	char Player;
	int input;
	int rounds;
	bool changeRole;

	bool running;

	init(raster, text, rounds, input, changeRole, running, Player);

	while (running)
	{
		text.writeText(text.getInputT(), Player);
		input = getInput();
		if (input != 0)
		{
			if (raster.getCaseValue(input) == 'X' || raster.getCaseValue(input) == 'O')
			{
				text.writeText(text.getFilledT());
				changeRole = false;
			}
			else
			{
				raster.setCase(input, Player);
				raster.DrawRaster();
				changeRole = true;
			}
		}
		else
		{
			text.writeText(text.getInvallidT());
			changeRole = false;
		}

		char gameOver = raster.isGameOver(rounds);
		if (gameOver == 'W' || gameOver == 'D')
		{
			text.writeText((gameOver == 'W') ? text.getWonT() : text.getDrawT(), Player);
			text.writeText(text.getRestartT());

			while (getGameOverInput() == 0)
			{
				text.writeText(text.getInvallidT());
			}

			if (getGameOverInput() == 1)
			{
				init(raster, text, rounds, input, changeRole, running, Player);
			}
			else if (getGameOverInput() == 2)
			{
				running = false;
			}
		}
		else if(changeRole)
		{
			if (Player == 'X')
			{
				Player = 'O';
			}
			else
			{
				Player = 'X';
			}
		}
	}

	return 0;
}

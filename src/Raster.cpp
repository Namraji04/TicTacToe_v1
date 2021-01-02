#include "Raster.h"

Raster::Raster()
{
	clearRaster();
}

void Raster::setCase(const int& pos, const char& player)
{
	m_Raster[pos - 1] = player;
}

void Raster::clearRaster()
{
	char iterator = '1';
	for (int i = 0; i < 9; i++)
	{
		m_Raster[i] = iterator;
		iterator++;
	}
}

void Raster::DrawRaster() const
{
	for (int i = 0; i < 3; i++)
	{
		if (i == 0) 
		{ 
			std::cout << " ___________ " << std::endl; 
		}
		std::cout << "| " << m_Raster[i * 3] << " | " << m_Raster[(i * 3) + 1] << " | " << m_Raster[(i * 3) + 2] << " |" << std::endl;
		std::cout << "|___|___|___|" << std::endl;
		
	}
}

const char& Raster::getCaseValue(const char& index) const
{
	return m_Raster[index - 1];
}

char Raster::isGameOver(int& rounds)
{
	//amount of rounds
	rounds++;
	//all cases filled
	if (rounds >= 9)
	{
		return 'D';
	}
	//enough cases filled to be able to win
	else if(rounds>=5)
	{
		//number stand for wich case
		//in each combiation where 1 is involved it is the smallest 
		//in each combiation where 5 is involved it is in the middle 
		//in each combiation where 9 is involved it is the highest 
		for (int i = 1; i <= 9; i += 4)
		{
			if (*this == i)
			{
				return 'W';
			}
		}
	}
	return 0;
}

bool Raster::operator==(const int index)
{
	//only 1, 5 or 9 are valid input
	if(index != 1 && index != 5 && index != 9)
	{
		//give error
		std::cout << "ERROR: invalid index for checking if player won" << std::endl;
		return false;
	}

	//these variables we be offset for the three different cases
	int Variable1;
	int Variable2;
	//each number stands for the sort of combination
	//			1 = horizontal combination
	//          2 = diagonal combination (/)
	//			3 = vertical combimation
	//			4 = diagonal combination (\)
	for (int i = 1; i <= 4; i++)
	{
		if (index == 1 && i != 2)
		{
			Variable1 = 1 * i;
			Variable2 = 2 * i;
		}
		else if (index == 5)
		{
			Variable1 = 1 * i;
			Variable2 = -1 * i;
		}
		else if (index == 9 && i != 2)
		{
			Variable1 = -1 * i;
			Variable2 = -2 * i;
		}

		if (this->m_Raster[index-1] == this->m_Raster[(index + Variable1)-1] && this->m_Raster[(index + Variable1)-1] == this->m_Raster[(index + Variable2)-1])
		{
			return true;
		}
	}

	return false;
}
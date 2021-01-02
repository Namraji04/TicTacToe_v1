#pragma once
#include <iostream>

class Raster 
{
public:
	Raster();
	void setCase(const int& pos, const char& player);
	void clearRaster();
	void DrawRaster() const;
	const char& getCaseValue(const char& index) const;
	char isGameOver(int& rounds);
	bool operator==(const int third);

private:
	unsigned char m_Raster[9];

};


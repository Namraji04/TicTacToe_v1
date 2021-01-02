#include "TextRenderer.h"

void TextRenderer::writeText(const String& text, const char& Player)
{
	if (Player == 'X')
	{
		PlayerT = "Player1";
	}
	else
	{
		PlayerT = "Player2";
	}
	setChangeables();
	std::cout << text << std::endl;
}
void TextRenderer::writeText(const String& text)
{
	std::cout << text << std::endl;
}

void TextRenderer::setChangeables()
{
	InputT = String(PlayerT + ", wich case do you want to fill");
	WonT = String(PlayerT + " won!!");
}

//*****Getters*****//
const String& TextRenderer::getWelcomeT() const
{
	return WelcomeT;
}
const String& TextRenderer::getInputT() const
{
	return InputT;
}
const String& TextRenderer::getFilledT() const
{
	return FilledT;
}
const String& TextRenderer::getWonT() const
{
	return WonT;
}
const String& TextRenderer::getDrawT() const
{
	return DrawT;
}
const String& TextRenderer::getRestartT() const
{
	return RestartT;
}
const String& TextRenderer::getInvallidT() const
{
	return InvallidT;
}


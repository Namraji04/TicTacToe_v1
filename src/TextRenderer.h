#pragma once
#include<iostream>

using String = std::string;

class TextRenderer
{
private:
	String PlayerT = String("Player1");
	String WelcomeT = String("\n\nWelcome to TIC TAC TOE:\n\tPlayer1 = X\n\tPlayer2 = O");
	String InputT = String(PlayerT + ", wich case do you want to fill");
	String FilledT = String("this case is already filled, try again");
	String WonT = String(PlayerT + " won!!");
	String DrawT = String("Nobody has won!!");
	String RestartT = String("Do you want to play again?");
	String InvallidT = String("invalid input, try again");

	void setChangeables();

public:
	void writeText(const String& text, const char& Player);
	void writeText(const String& text);
	const String& getWelcomeT() const;
	const String& getInputT() const;
	const String& getFilledT() const;
	const String& getWonT() const;
	const String& getDrawT() const;
	const String& getRestartT() const;
	const String& getInvallidT() const;


};

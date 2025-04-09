#pragma once
#include "globals.hpp"


class Note
{
public:
	Note();
	Note(float startPos, float setAngle, float setDuration, float setRotSpeed, bool setDeadzone);
	~Note() = default;
	void setNote(float, float, float, float, bool);

	void update();
	void drawTo(sf::RenderWindow&);
private:
	float pos, //position of the note in the level, in terms of seconds and NOT pixels
		angle, //angle the note enters the screen at
		duration, //how many seconds the note lasts
		rotationSpeed; //how fast the note rotates
	bool deadzone; //if the note needs the catcher to pass through the deadzone first
	sf::CircleShape circ;
};
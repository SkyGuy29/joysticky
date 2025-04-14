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
	float pos, //position of the note in the level, in terms of beats
		angle, //angle the note enters the screen at, set in terms of degrees (converted to radians)
		duration, //how many seconds the note lasts, in terms of beats
		rotationSpeed; //how fast the note rotates, set in terms of degrees per second (converted to radians)
	bool deadzone; //if the note needs the catcher to pass through the deadzone first
	sf::CircleShape circ;
};
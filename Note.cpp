#include "Note.h"


Note::Note()
{
	circ.setRadius(50 * WINDOW_SCALE);
	circ.setFillColor(sf::Color::Green);
	circ.setOrigin(circ.getRadius(), circ.getRadius());
}


Note::Note(float startPos, float setAngle, float setDuration, float setRotSpeed, bool setDeadzone)
{
	circ.setRadius(10 * WINDOW_SCALE);
	circ.setFillColor(sf::Color::Green);
	circ.setOrigin(circ.getRadius(), circ.getRadius());

	setNote(startPos, setAngle, setDuration, setRotSpeed, setDeadzone);
}


void Note::setNote(float startPos, float setAngle, float setDuration, float setRotSpeed, bool setDeadzone)
{
	pos = startPos;
	angle = setAngle;
	duration = setDuration;
	rotationSpeed = setRotSpeed;
	deadzone = setDeadzone;
}


static constexpr float fix = 50;

void Note::update()
{
	pos -= fix * SCROLL_SPEED / FPS / BPM;
}


void Note::drawTo(sf::RenderWindow& window)
{
	constexpr float res = 100;

	//theoretical "1" spot in terms of beats, the scale used by internal positioning
	//multiplied by a position value to find the physical spot of the position
	sf::Vector2f one(fix * SCROLL_SPEED * WINDOW_SCALE * cos(angle) / BPM,
		fix * SCROLL_SPEED * WINDOW_SCALE * sin(angle) / BPM);

	for (int i = 0; i < res; i++)
	{
		//move and draw along the note line
		circ.setPosition(lerp(WINDOW_CENTER + one * pos, WINDOW_CENTER + one * (pos + duration), i / res));
		window.draw(circ);
	}
}

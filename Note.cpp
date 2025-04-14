#include "Note.h"


Note::Note()
{
	circ.setRadius(50 * WINDOW_SCALE);
	circ.setFillColor(sf::Color::Green);
	circ.setOrigin(circ.getRadius(), circ.getRadius());
}


Note::Note(float startPos, float setAngle, float setDuration, float setRotSpeed, bool setDeadzone)
{
	circ.setRadius(25 * WINDOW_SCALE);
	circ.setFillColor(sf::Color::Green);
	circ.setOrigin(circ.getRadius(), circ.getRadius());

	setNote(startPos, setAngle, setDuration, setRotSpeed, setDeadzone);
}


void Note::setNote(float startPos, float setAngle, float setDuration, float setRotSpeed, bool setDeadzone)
{
	pos = startPos;
	angle = rad(setAngle);
	duration = setDuration;
	rotationSpeed = setRotSpeed;
	deadzone = rad(setDeadzone);
}


//THESE TWO FUNCTIONS TOOK ACTUAL DAYS TO MAKE
void Note::update()
{
	pos -= BPM / FPS / 60.f;
}


void Note::drawTo(sf::RenderWindow& window)
{
	constexpr float res = 100;
	constexpr float beatLength = SCROLL_SPEED * 60.f / BPM;
	const sf::Vector2f catcherEdge(WINDOW_CENTER.x + CATCHER_RAD * cos(angle),
		WINDOW_CENTER.y + CATCHER_RAD * sin(angle));

	for (int i = 0; i < res; i++)
	{
		if (pos + duration * i / res > 0)
		{
			//move and draw along the note line
			circ.setPosition(lerp(sf::Vector2f(catcherEdge.x + pos * beatLength * cos(angle),
				catcherEdge.y + pos * beatLength * sin(angle)),
				sf::Vector2f(catcherEdge.x + (pos + duration) * beatLength * cos(angle),
					catcherEdge.y + (pos + duration) * beatLength * sin(angle)), i / res));
			window.draw(circ);
		}
	}
}

#pragma once


class Note
{
public:
	Note();
	~Note() = default;
	void update(const sf::RenderWindow&);
	void drawTo(sf::RenderWindow&);
private:
	float startTime, startAngle, duration, rotationSpeed;
	bool deadzone;
};


#include "Catcher.h"


Catcher::Catcher()
{
	constexpr float catchWidth = 0.5; //width of the catch area, 1 is quarter circle
	constexpr int res = 15; //value to adjust how many points to use to draw the catcher, number is not exactly the number of points but scales directly with it, lowest is 1
	outline.setRadius(CATCHER_RAD * 1.05);
	outline.setOrigin(outline.getRadius(), outline.getRadius()); //center of circle
	outline.setPosition(sf::Vector2f(WINDOW_CENTER.x, WINDOW_CENTER.y)); //center of the window
	outline.setFillColor(sf::Color::Transparent);
	outline.setOutlineColor(sf::Color::White);
	outline.setOutlineThickness(5);
	outline.setPointCount(40);

	middle.setRadius(CATCHER_RAD * 0.75);
	middle.setOrigin(middle.getRadius(), middle.getRadius());
	middle.setPosition(sf::Vector2f(WINDOW_CENTER.x, WINDOW_CENTER.y));
	middle.setFillColor(sf::Color::Transparent);
	middle.setOutlineColor(sf::Color::White);
	middle.setOutlineThickness(5);
	middle.setPointCount(40);

	catcher.setOrigin(0, 0);
	catcher.setPosition(sf::Vector2f(WINDOW_CENTER.x, WINDOW_CENTER.y));
	catcher.setPointCount(res * 2 + 2); //needs to be even because there are two circular edges
	catcher.setFillColor(sf::Color::Cyan);
	//catcher.setFillColor(sf::Color::Transparent);
	//catcher.setOutlineColor(sf::Color::Cyan);
	//catcher.setOutlineThickness(5);

	//ConvexShape REALLY seems to hate me doing this
	for (int i = 0; i <= res; i++)
	{
		const float angle = static_cast<float>(i) / (catcher.getPointCount() - 2) * PI * catchWidth //angles are subdivided based on i
		- (PI / 4 * catchWidth - PI ); //doing this so that it faces up, the 0 value for the rotation setup I made

		//inside points, first half of points
		catcher.setPoint(i, sf::Vector2f(CATCHER_RAD * 0.825 * cos(angle),CATCHER_RAD * 0.825 * sin(angle)));

		//outside points, second half of points
		catcher.setPoint(catcher.getPointCount() - 1 - i, //start at the end and count backwards
			sf::Vector2f(CATCHER_RAD * cos(angle),CATCHER_RAD * sin(angle))); 
	}

	//for (int i = 0; i < catcher.getPointCount(); i++)
	//	std::cout << i << ": " << catcher.getPoint(i).x << ", " << catcher.getPoint(i).y << std::endl;
}


void Catcher::update(const sf::RenderWindow& window)
{
	/*
	if (prevMousePos != mousePos(window))
		catcher.setRotation(180 / PI * angleOf(prevMousePos, mousePos(window)));
	else
		catcher.setRotation(180 / PI * angleOf(catcher.getPosition(), mousePos(window)));
	prevMousePos = mousePos(window);
	 */
	catcher.setRotation(180 / PI * angleOf(catcher.getPosition(), mousePos(window)));
}


void Catcher::drawTo(sf::RenderWindow& window)
{
	window.draw(outline);
	if (distBetween(middle.getPosition(), mousePos(window)) > middle.getRadius() + middle.getOutlineThickness())
	{
		window.draw(catcher);	
		middle.setOutlineColor(sf::Color::White);
	}
	else
		middle.setOutlineColor(sf::Color::Cyan);
	window.draw(middle);
}

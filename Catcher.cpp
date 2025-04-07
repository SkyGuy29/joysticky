#include "Catcher.h"


Catcher::Catcher()
{
	constexpr float catchWidth = 0.5; //width of the catch area, 1 is quarter circle
	constexpr float spacing = 10; //distance between catcher edges and circle edges
	constexpr int res = 15; //value to adjust how many points to use to draw the catcher, number is not exactly the number of points but scales directly with it, lowest is 1
	outline.setRadius(250 * WINDOW_SCALE);
	outline.setOrigin(outline.getRadius(), outline.getRadius()); //center of circle
	outline.setPosition(sf::Vector2f(WINDOW_SIZE.x * WINDOW_SCALE / 2, WINDOW_SIZE.y * WINDOW_SCALE / 2)); //center of the window
	outline.setFillColor(sf::Color::Transparent);
	outline.setOutlineColor(sf::Color::White);
	outline.setOutlineThickness(5);

	middle.setRadius(170 * WINDOW_SCALE);
	middle.setOrigin(middle.getRadius(), middle.getRadius());
	middle.setPosition(sf::Vector2f(WINDOW_SIZE.x * WINDOW_SCALE / 2, WINDOW_SIZE.y * WINDOW_SCALE / 2));
	middle.setFillColor(sf::Color::Transparent);
	middle.setOutlineColor(sf::Color::White);
	middle.setOutlineThickness(5);

	catcher.setOrigin(0, 0);
	catcher.setPosition(sf::Vector2f(WINDOW_SIZE.x * WINDOW_SCALE / 2, WINDOW_SIZE.y * WINDOW_SCALE / 2));
	catcher.setPointCount(res * 2 + 2); //needs to be even because there are two circular edges
	//catcher.setFillColor(sf::Color::Cyan);
	catcher.setFillColor(sf::Color::Transparent);
	catcher.setOutlineColor(sf::Color::Cyan);
	catcher.setOutlineThickness(5);

	const float insRadius = middle.getRadius() + middle.getOutlineThickness() + spacing * WINDOW_SCALE; //radius of the inside edge
	const float outRadius = outline.getRadius() - catcher.getOutlineThickness() - spacing * WINDOW_SCALE; //radius of the outside edge

	for (int i = 0; i <= res; i++)
	{
		const float angle = static_cast<float>(i) / (catcher.getPointCount() - 2) * PI * catchWidth //ok so hopefully all of this makes sense
		- (PI / 4 * catchWidth - PI ); //doing this so that it faces up, the 0 value for the rotation setup I made

		//inside points, first half of points
		catcher.setPoint(i, sf::Vector2f(insRadius * cos(angle),	insRadius	* sin(angle)));

		//outside points, second half of points
		catcher.setPoint(catcher.getPointCount() - 1 - i, //start at the end and count backwards
			sf::Vector2f(outRadius * cos(angle),	outRadius * sin(angle))); 
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

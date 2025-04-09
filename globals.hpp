#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>


static constexpr auto PI = 3.1415926535897932;
static constexpr float WINDOW_SCALE = 0.7;
static const sf::Vector2i WINDOW_SIZE(1920, 1080);
static const sf::Vector2f WINDOW_CENTER(WINDOW_SIZE.x * WINDOW_SCALE / 2.f, WINDOW_SIZE.y * WINDOW_SCALE / 2.f);
static constexpr int FPS = 60;
static constexpr float SCROLL_SPEED = 100;
static constexpr float BPM = 60;


//returns the distance between two points.
static float distBetween(const sf::Vector2f point1, const sf::Vector2f point2)
{
    const sf::Vector2f d = point1 - point2;
    return hypotf(d.x, d.y);
}


//returns a point based on an ease in ease out movement setup, as long as t increases at a constant rate
//t MUST be between 0 and 1 for proper easing
static sf::Vector2f lerp(const sf::Vector2f point1, const sf::Vector2f point2, const float t)
{
    const sf::Vector2f d = point2 - point1;
    return {point1.x + d.x * t, point1.y + d.y * t};
}


//uses the law of cosines to create an angle given three points.
//the three points are used to create a triangle, and it finds an angle in that triangle.
//the angle returned is the one that corresponds to the first parameter/point here.
//the order of the last two does not matter.
static float lawOfCos(const sf::Vector2f p1, const sf::Vector2f p2, const sf::Vector2f p3)
{
	const double a = distBetween(p1, p2), b = distBetween(p1, p3), c = distBetween(p2, p3);

    //the law in states that (the angle opposite of c) = acos((a*a + b*b - c*c) / (2ab))
    return acos((a * a + c * c - b * b) / (2 * a * c));
}


//returns the position of the mouse relative to the window,
//this is basically a rename since its one line of code lol
static sf::Vector2f mousePos(const sf::RenderWindow& window)
{
    return sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
}


//returns the angle of the right triangle created by the x and y values of the given points.
static float angleOf(const sf::Vector2f p1, const sf::Vector2f p2)
{
    const sf::Vector2f d = p1 - p2;
    float theta;

    //assigning a value to theta
    if (d.x != 0) //preventing division by 0
    {
        theta = atan(d.y / d.x); //find angle

        if (d.x < 0) //if its negative...
            theta += PI; //add pi to get the angles past the range of atan(), angles > pi/2
    }
    else if (d.y < 0) //exactly vertical, p1 above p2
        theta = -PI / 2;
    else //p2 above p1 (iirc LOL)
        theta = PI / 2;

    return theta;
}
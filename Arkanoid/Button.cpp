#include "Button.h"
#include <iostream>

Button::Button(
	const sf::Vector2f position, 
	const sf::Vector2f size,
	const std::string content
) : label(Label(20, content))
{
	shape.setSize(size);
	shape.setPosition(sf::Vector2f(position.x - size.x / 2.f, position.y - size.y / 2.f));
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(5);

	label.centerRelativily(shape);
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(shape);
	label.draw(window);
}

void Button::update(sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	if (contains(sf::Vector2f(mousePos.x, mousePos.y)))
	{
		shape.setFillColor(HOVER_COLOR);
	}
	else
	{
		shape.setFillColor(IDLE_COLOR);
	}
}

void Button::handleEvent(sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Button::Left) 
	{
		if (contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) && callback) 
		{
			callback();
		}
	}
}

void Button::setCallback(std::function<void()> callback)
{
	this->callback = callback;
}

bool Button::contains(const sf::Vector2f& point) const
{
	return shape.getGlobalBounds().contains(point);
}


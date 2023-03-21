#include "Button.h"
#include <iostream>

Button::Button(const sf::Vector2f position, const sf::Vector2f size, const sf::Font& font, const std::string content)
{
	shape.setSize(size);
	shape.setPosition(sf::Vector2f(position.x - size.x / 2.f, position.y - size.y / 2.f));
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(5);

	text.setString(content);
	text.setFont(font);
	text.setCharacterSize(shape.getSize().y * TEXT_SIZE_FACTOR);
	text.setFillColor(IDLE_COLOR);
	text.setOutlineColor(OUTLINE_COLOR);
	text.setOutlineThickness(2);

	centerText();
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(shape);
	window.draw(text);
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

void Button::centerText()
{
	sf::FloatRect textRect = text.getGlobalBounds();

	float originX = textRect.left + textRect.width / 2.f;
	float originY = textRect.top + textRect.height / 2.f;

	text.setOrigin(originX, originY);

	float positionX = shape.getGlobalBounds().left + shape.getGlobalBounds().width / 2.f;
	float positionY = shape.getGlobalBounds().top + shape.getGlobalBounds().height / 2.f;

	text.setPosition(positionX, positionY);
}

bool Button::contains(const sf::Vector2f& point)
{
	return shape.getGlobalBounds().contains(point);
}


#include <SFML/Graphics.hpp>
#include <functional>
#include "Label.h"

#ifndef BUTTON_H
#define BUTTON_H

class Button {
public:
    Button(const sf::Vector2f position, const sf::Vector2f size, const std::string text);

    void draw(sf::RenderWindow& window);
    void update(sf::RenderWindow& window);
    void handleEvent(sf::Event& event);

    void setCallback(std::function<void()> callback);

private:
    sf::RectangleShape shape;

    Label label;

    bool contains(const sf::Vector2f& point) const;

    std::function<void()> callback;

    const sf::Color IDLE_COLOR = sf::Color::White;
    const sf::Color HOVER_COLOR = sf::Color(197, 197, 197);
    const sf::Color OUTLINE_COLOR = sf::Color::Black;
};

#endif
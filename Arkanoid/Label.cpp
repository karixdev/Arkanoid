#include "Label.h"
#include "FontManager.h"

Label::Label(float size, std::string content)
{
    text.setFont(FontManager::getFont("Fonts/arcade.ttf"));

    text.setCharacterSize(size);
    text.setString(content);

    text.setFillColor(DEFAULT_COLOR);

    text.setOutlineColor(OUTLINE_COLOR);
    text.setOutlineThickness(OUTLINE_THICKNESS);

    text.setPosition(0, 0);
}

Label::Label(float size, std::string content, sf::Color color)
{
    text.setFont(FontManager::getFont("Fonts/arcade.ttf"));

    text.setCharacterSize(size);
    text.setString(content);

    text.setFillColor(color);

    text.setOutlineColor(OUTLINE_COLOR);
    text.setOutlineThickness(OUTLINE_THICKNESS);

    text.setPosition(0, 0);
}

void Label::setPosition(sf::Vector2f position)
{
    sf::FloatRect textBounds = text.getLocalBounds();

    float posX = position.x - textBounds.width / 2.f;
    float posY = position.y - textBounds.height / 2.f;

    text.setPosition(sf::Vector2f(posX, posY));
}

void Label::centerRelativily(sf::RectangleShape rect)
{
    sf::FloatRect textBounds = text.getLocalBounds();

    text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    text.setPosition(rect.getPosition() + 0.5f * rect.getSize());
}

void Label::draw(sf::RenderWindow& window)
{
    window.draw(text);
}



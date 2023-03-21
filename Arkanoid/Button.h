#include <SFML/Graphics.hpp>
#include <functional>

class Button {
public:
    Button(const sf::Vector2f position, const sf::Vector2f size, const sf::Font& font, const std::string text);

    void draw(sf::RenderWindow& window);
    void update(sf::RenderWindow& window);
    void handleEvent(sf::Event& event);

    void setCallback(std::function<void()> callback);

private:
    sf::RectangleShape shape;
    sf::Text text;

    void centerText();

    bool contains(const sf::Vector2f& point);

    std::function<void()> callback;

    const sf::Color IDLE_COLOR = sf::Color::White;
    const sf::Color HOVER_COLOR = sf::Color(197, 197, 197);
    const sf::Color OUTLINE_COLOR = sf::Color::Black;

    const float TEXT_SIZE_FACTOR = .7f;
};
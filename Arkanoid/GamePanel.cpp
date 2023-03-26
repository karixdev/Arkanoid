#include "GamePanel.h"
#include "WindowConfig.h"

GamePanel::GamePanel() :
	pointsLabel(Label(80.f, "0"))
{
	stripe.setFillColor(sf::Color::Black);
	stripe.setSize(sf::Vector2f(WindowConfig::WINDOW_WIDTH, 10.f));
	stripe.setPosition(sf::Vector2f(0.f, 75.f + 5.f));

	pointsLabel.setPosition(sf::Vector2f(300.f, 10.f));
}

void GamePanel::draw(sf::RenderWindow& window)
{
	window.draw(stripe);
	pointsLabel.draw(window);
}

void GamePanel::setPoints(int points)
{
	pointsLabel.setText(std::to_string(points));
	pointsLabel.setPosition(sf::Vector2f(300.f, 10.f));
}

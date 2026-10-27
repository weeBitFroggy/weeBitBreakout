#include "Brick.h"

Brick::Brick(float x, float y, float width, float height)
    : _isDestroyed(false)
{
    _shape.setPosition(x, y);
    _shape.setSize(sf::Vector2f(width, height));
    _shape.setFillColor(sf::Color::White);
}

void Brick::render(sf::RenderWindow& window)
{
    if (!_isDestroyed) {
        window.draw(_shape);
    }
}

sf::FloatRect Brick::getBounds() const
{
    return _shape.getGlobalBounds();
}

void Brick::damage(float dmg)
{
    _health = _health - dmg;
    if (_health <=0)
    {
        _isDestroyed = true;
    }

    int colour = _health;
    _shape.setFillColor(sf::Color{ 255, ((uint8_t)colour), ((uint8_t)colour) });
}

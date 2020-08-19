
#include "Particle.hpp"

#include <stdlib.h>
#include <iostream>

Particle::Particle()
{
    id = ++particles_created;

    int r = (256), g = (256), b = (256);

    particleCircle.setRadius(1);
    particleCircle.setFillColor(sf::Color(r, g, b, 255));
    particleCircle.setPosition(400, 400);
}

Particle::Particle(int window_width, int window_height)
{

    id = ++particles_created;

    this->window_width = window_width;
    this->window_height = window_height;

    this->x_pos = rand() % (window_width);
    this->y_pos = rand() % (window_height);

    this->x_speed = 2 * (((2.0 * rand()) / RAND_MAX) - 1);
    this->y_speed = 2 * (((2.0 * rand()) / RAND_MAX) - 1);

    particleCircle.setRadius(2);
    setColor(255, 255, 255);
    setPosition(this->x_pos, this->y_pos);
    //printPosition();
}

Particle::~Particle() {}

int Particle::getParticles_created() {
    return particles_created;
}

void Particle::updatePosition()
{
    if (x_pos <= 0 || x_pos >= window_width - 10)
        x_speed = -1 * (2 * (((2.0 * rand()) / RAND_MAX) - 1));

    if (y_pos <= 0 || y_pos >= window_height - 10)
        y_speed = -1 * (2 * (((2.0 * rand()) / RAND_MAX) - 1));

    x_pos += x_speed;
    y_pos += y_speed;
    //std::cout << "PID[" << id << "] x_speed = " << x_speed << " || y_speed = " << y_speed << std::endl;

    setPosition(this->x_pos, this->y_pos);
}

void Particle::setColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b)
{
    sf::Uint32 color = 0;

    color += r;
    color <<= 8;
    color += g;
    color <<= 8;
    color += b;
    color <<= 8;
    color += 0xFF;

    particleCircle.setFillColor(sf::Color(color));
}

void Particle::printPosition()
{
    std::cout << "\nPID[" << this->id << "] ";
    std::cout << "Position = (" << particleCircle.getPosition().x << ", "
        << particleCircle.getPosition().y << ")" << std::endl;
    std::cout << "X_speed = " << x_speed << ", Y_speed = " << y_speed << std::endl;
}

void Particle::setPosition(int x_pos, int y_pos) {
    particleCircle.setPosition(x_pos, y_pos);
}

void Particle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(Particle::particleCircle, states);
}

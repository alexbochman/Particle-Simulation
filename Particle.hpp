
#include <SFML/Graphics.hpp>

#ifndef PARTICLE_H
#define PARTICLE_H

class Particle : public sf::Drawable
{
private:
    int id;
    int window_width;
    int window_height;
    int x_pos;
    int y_pos;
    double x_speed;
    double y_speed;

    sf::CircleShape particleCircle;
    static int particles_created;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
    Particle();
    Particle(int screenWidth, int screenHeight);
    ~Particle();

    static int getParticles_created();
    sf::CircleShape getParticleCircle;

    void printPosition();
    void updatePosition();
    void setPosition(int x_pos, int y_pos);
    void setColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b);
};

#endif

// Shift + Alt + A to toggle block comment

#include <iostream>
#include <string.h>
#include <math.h>
#include "Particle.hpp"

using namespace std;

int Particle::particles_created = 0;

int main()
{
    const int PARTICLE_COUNT = 100;
    const int window_width = sf::VideoMode::getDesktopMode().width != 1920 ? 800 : sf::VideoMode::getDesktopMode().height;
    const int window_height = sf::VideoMode::getDesktopMode().height != 1080 ? 600 : sf::VideoMode::getDesktopMode().height;

    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "---- Particle Simulation ----");
    vector<Particle> particle_vector;

    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(700, 500));
    particle_vector.reserve(PARTICLE_COUNT);

    for (int i = 0; i < PARTICLE_COUNT; i++)
        particle_vector.push_back(Particle(window_width, window_height));

    while (window.isOpen())
    {
        for (sf::Event event; window.pollEvent(event);)
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Space)
                window.close();

        // Clear Screen before update
        window.clear(sf::Color::Black);

        // Update Particles here
        sf::Time elapsed = clock.getElapsedTime();
        unsigned char red = (1 + sin(elapsed.asMilliseconds() * 0.0012)) * 128;
        unsigned char green = (1 + sin(elapsed.asMilliseconds() * 0.0015)) * 128;
        unsigned char blue = (1 + sin(elapsed.asMilliseconds() * 0.0018)) * 128;

        for (int i = 0; (unsigned)i < particle_vector.size(); i++)
        {
            particle_vector.at(i).setColor(red, green, blue);
            particle_vector.at(i).updatePosition();
        }

        // draw everything here...
        for (int i = 0; i < PARTICLE_COUNT; i++)
            window.draw(particle_vector.at(i));

        // end the current frame
        window.display();
    }

    std::cout << "\nMAIN: Particles created = " << Particle::getParticles_created() << endl
        << endl;

    return 0;
}

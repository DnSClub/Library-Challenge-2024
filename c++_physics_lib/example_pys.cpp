#include <iostream>
#include "DNS_Laws_Of_Physics.hpp"

int main() {
    //create a physics world
    DNS_PhysicsEngine::PhysicsWorld world;

    //create a particle with an initial position (0, 0), initial velocity (0, 0), and mass 1.0
    DNS_PhysicsEngine::Particle particle(DNS_PhysicsEngine::Vector2D(0, 0), DNS_PhysicsEngine::Vector2D(0, 0), 1.0);

    //add the particle to the world
    world.addParticle(particle);

    //define a force vector (e.g., gravity)
    DNS_PhysicsEngine::Vector2D gravity(0, -9.81);

    //simulate for 10 seconds, updating every 0.1 seconds
    double simulationTime = 10.0;
    double timeStep = 0.1;

    for (double t = 0; t < simulationTime; t += timeStep) {
        //apply gravity to all particles in the world
        world.applyGlobalForce(gravity);

        //update the world
        world.update(timeStep);

        //get the position of the first particle
        DNS_PhysicsEngine::Particle& p = world.particles[0];
        std::cout << "Time: " << t << "s, Position: (" << p.position.x << ", " << p.position.y << ")" << std::endl;
    }

    return 0;
}
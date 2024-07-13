#define DNS_LAWS_OF_PHYSICS

#include <vector>

namespace DNS_PhysicsEngine {
    
    struct Vector2D {
        double x;
        double y;

        //constructors
        Vector2D() : x(0), y(0) {}
        Vector2D(double x, double y) : x(x), y(y) {}

        //vector addition
        Vector2D operator+(const Vector2D& v) const {
            return Vector2D(x + v.x, y + v.y);
        }

        //vector subtraction
        Vector2D operator-(const Vector2D& v) const {
            return Vector2D(x - v.x, y - v.y);
        }

        //scalar multiplication
        Vector2D operator*(double scalar) const {
            return Vector2D(x * scalar, y * scalar);
        }

        //scalar division
        Vector2D operator/(double scalar) const {
            return Vector2D(x / scalar, y / scalar);
        }
    };

    class Particle {
    public:
        Vector2D position;
        Vector2D velocity;
        Vector2D acceleration;
        double mass;

        //constructors
        Particle() : position(), velocity(), acceleration(), mass(1.0) {}
        Particle(const Vector2D& position, const Vector2D& velocity, double mass)
            : position(position), velocity(velocity), acceleration(), mass(mass) {}

        //apply force to the particle
        void applyForce(const Vector2D& force) {
            Vector2D forceAcc = force / mass;
            acceleration = acceleration + forceAcc;
        }

        //update the particle's position and velocity
        void update(double deltaTime) {
            velocity = velocity + acceleration * deltaTime;
            position = position + velocity * deltaTime;
            acceleration = Vector2D(0, 0);//reset acceleration after each update
        }
    };

    class PhysicsWorld {
    public:
        std::vector<Particle> particles;

        //add particle to the world
        void addParticle(const Particle& particle) {
            particles.push_back(particle);
        }

        //apply a global force to all particles
        void applyGlobalForce(const Vector2D& force) {
            for (auto& particle : particles) {
                particle.applyForce(force);
            }
        }

        //update all particles
        void update(double deltaTime) {
            for (auto& particle : particles) {
                particle.update(deltaTime);
            }
        }
    };

}
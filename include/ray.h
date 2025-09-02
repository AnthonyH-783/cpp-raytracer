#ifndef RAY_H
#define RAY_H

#include "vec3.h"
/**
 * A ray class representing a ray in 3D space.
 * A ray is defined by an origin point and a direction vector.
 * This class includes methods to access the origin and direction,
 * as well as a method to compute a point along the ray at a given parameter t.
 */
class ray {
  public:
    // Default constructor
    ray() {} 
    // Parameterized constructor
    ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}
    // Accessor methods
    const point3& origin() const  { return orig; }
    const vec3& direction() const { return dir; }
    point3 at(double t) const {
        return orig + (t * dir);
    }

  private: // Data members
    point3 orig;
    vec3 dir;
};

#endif
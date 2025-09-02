#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>
/**
 * A color class representing RGB colors using three components.
 * This class is an alias for the vec3 class, which provides basic vector operations.
 * It includes a utility function to write the color to an output stream in a format
 * suitable for PPM image files.
 */
using color = vec3; // color is just an alias for vec3, but useful for clarity in the code.

// Write the color to an output stream in PPM format.
void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Translate the [0,1] component values to the byte range [0,255].
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    // Write out the pixel color components.
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif
#include <iostream>
#include "../include/color.h"
#include "../include/vec3.h"

int main() {

    // Image

    int image_width = 256;
    int image_height = 256;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
           // Generate a gradient color based on pixel position
           auto r = double(i) / (image_width - 1);
           auto g = double(j) / (image_height - 1);
           auto b = 0.0;
           // Create a color object and write it to the output
           color pixel_color(r, g, b);
           write_color(std::cout, pixel_color);
        }
    }
     std::clog << "\rDone.                 \n";
}
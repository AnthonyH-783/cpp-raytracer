#include <iostream>
#include "../include/color.h"
#include "../include/vec3.h"
#include "../include/ray.h"



// Function that determines whethere a ray r hits a sphere
// centered at 'center' with radius 'radius'
bool hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = -2.0 * dot(r.direction(), oc);
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    return (discriminant > 0);

}
//Function implementing blue-to white gradient
// Based on ray direction. Formula: (1 - a) * start_value + a * end_value
// where a is in the range [0,1]
color ray_color(const ray& r) {
    if(hit_sphere(point3(0,0,-1), 0.5, r)) {
        return color(1,0,0); // Red color for sphere hit
    }
    vec3 unit_direction = r.direction();
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);


}

int main() {

    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // Calculate image height based on aspect ratio
    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Camera
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    
    auto viewport_width =  (double(image_width) / image_height) * viewport_height;
    auto camera_center = point3(0, 0, 0);

    // Calculate the vectors across the horizontal and vertical viewport edges
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // Calculate the vertical and horizontal offsets between pixels
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // Calculate location of upper left pixel
    auto viewport_upper_left = camera_center // (0,0,0)
        - vec3(0, 0, focal_length) // move the viewport in front of the camera
        - (viewport_u / 2) // shift left by half the viewport width
        - (viewport_v / 2); // shift up by half the viewport height
    // Calculate location of center of upper left pixel
    auto pixel00_loc = viewport_upper_left + (pixel_delta_u / 2) + (pixel_delta_v / 2);



    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
           // Compute the ray for the current pixel
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);
            // Get the color for the ray
            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color); // Write the color to the output file
           
        }
    }
     std::clog << "\rDone.                 \n";
}
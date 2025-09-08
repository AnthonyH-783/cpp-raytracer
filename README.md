# cpp-raytracer
A minimal ray tracer that mainly generates spheres in 3D space, with a modular abstract design to extent to other geometric shapes.\
It takes into account the physics of different materials based on different interactions between light and particular materials. \
(For instance, lambertian materials, metals, and dielectrics each scatter light differently, requiring different physics equations)

Note: The final output is a ppm file, which can be viewed with any online ppm viewer
## 1. Setup
- **Requirements**: C++17 or later, CMake, and a compatible compiler (g++/clang/MSVC).
### Build & Run
```bash
# Clone and enter
git clone https://github.com/AnthonyH-783/cpp-raytracer.git
cd cpp-raytracer
cmake -B build
cmake --build build
```
Then, using the command prompt, navigate to cpp-raytracer/build/Debug, and run:
```
CppRayTracer.exe > image.ppm
```
The above command will execute main.cpp, which creates a ppm image inside the image folder.
The ppm image can be viewed using an online ppm viewer

## 2. Showcase output
You can test the full capability of the model by running the following in main.cpp: \
(Note that it is a heavy rendering that may take up to 8 hours on an average laptop)
```
#include <iostream>
#include "../include/camera.h"
#include "../include/hittable_list.h"
#include "../include/sphere.h"
#include "../include/material.h"





int main() {

    hittable_list world;

        auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            auto choose_mat = random_double();
            point3 center(a + 0.9*random_double(), 0.2, b + 0.9*random_double());

            if ((center - point3(4, 0.2, 0)).length() > 0.9) {
                shared_ptr<material> sphere_material;

                if (choose_mat < 0.8) {
                    // diffuse
                    auto albedo = color::random() * color::random();
                    sphere_material = make_shared<lambertian>(albedo);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                } else if (choose_mat < 0.95) {
                    // metal
                    auto albedo = color::random(0.5, 1);
                    auto fuzz = random_double(0, 0.5);
                    sphere_material = make_shared<metal>(albedo, fuzz);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                } else {
                    // glass
                    sphere_material = make_shared<dielectric>(1.5);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }

    auto material1 = make_shared<dielectric>(1.5);
    world.add(make_shared<sphere>(point3(0, 1, 0), 1.0, material1));

    auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    world.add(make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));

    auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    world.add(make_shared<sphere>(point3(4, 1, 0), 1.0, material3));

    camera cam;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 1200;
    cam.samples_per_pixel = 500;
    cam.max_depth         = 50;

    cam.vfov     = 20;
    cam.lookfrom = point3(13,2,3);
    cam.lookat   = point3(0,0,0);
    cam.vup      = vec3(0,1,0);

    cam.defocus_angle = 0.6;
    cam.focus_dist    = 10.0;

    cam.render(world);
}
```

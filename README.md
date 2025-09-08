# cpp-raytracer
A minimal ray tracer implementing surface normals, sphere intersections, and abstracted object handling, inspired by Ray Tracing in One Weekend.
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

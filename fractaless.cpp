#include <iostream>
#include <fstream>
#include <complex>

using namespace std;

const int width = 800;
const int height = 800;
const int max_iterations = 1000;

int mandelbrot(double real, double imag) {
    complex<double> c(real, imag);
    complex<double> z(0, 0);
    int iterations = 0;

    while (abs(z) < 2.0 && iterations < max_iterations) {
        z = z * z + c;
        iterations++;
    }

    return iterations;
}

void save_bitmap(const string& filename, const unsigned char* data) {
    ofstream file(filename, ios::out | ios::binary);

    file.put('B').put('M');
    file.put(0x36).put(0).put(0).put(0);
    file.put(0).put(0).put(0).put(0);
    file.put(0x28).put(0).put(0).put(0);
    file.put(char(width)).put(char(width >> 8)).put(char(width >> 16)).put(char(width >> 24));
    file.put(char(height)).put(char(height >> 8)).put(char(height >> 16)).put(char(height >> 24));
    file.put(1).put(0);
    file.put(24).put(0);
    file.put(0).put(0).put(0).put(0);
    file.put(0).put(0).put(0).put(0);
    file.put(0).put(0).put(0).put(0);
    file.put(0).put(0).put(0).put(0);
    file.put(0).put(0).put(0).put(0);
    file.put(0).put(0).put(0).put(0);

    file.write(reinterpret_cast<const char*>(data), width * height * 3);
}

int main() {
    unsigned char image[width * height * 3];

    double x_min = -2.0, x_max = 1.0, y_min = -1.5, y_max = 1.5;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double real = x_min + (x_max - x_min) * x / (width - 1);
            double imag = y_min + (y_max - y_min) * y / (height - 1);

            int value = mandelbrot(real, imag);
            int color = (value % 256);

            image[y * width * 3 + x * 3] = color;
            image[y * width * 3 + x * 3 + 1] = color;
            image[y * width * 3 + x * 3 + 2] = color;
        }
    }

    save_bitmap("mandelbrot.bmp", image);

    cout << "Imagen de Mandelbrot generada y guardada como mandelbrot.bmp" << endl;

    return 0;
}


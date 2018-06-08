#include <iostream>
#include <time.h>
#include "mlp.hpp"
#include "png.hpp"

int main(int argc, char** argv){

	srand(time(NULL));

	png::image <png::rgb_pixel> png_image (argv[1]);

	int size = png_image.get_width()*png_image.get_height();

	Perceptron* p = new Perceptron(3, size, 256, 1);

	double* image = new double[size];

	for(int i = 0; i < png_image.get_width(); i++){
		for(int j = 0; j < png_image.get_height(); j++){
			image[i*png_image.get_width()+j] = 1;
		}
	}

	double value = (*p) (image);

	std::cout << value << std::endl;

	delete[] image;
	delete p;
	return 0;
}

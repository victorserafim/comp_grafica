//OUTRA FORMA DE ABRIR O ARQUIVO

/**
***
***	Author:		Nilton Jose Rizzo
***	Date:			08/01/2019
***	Git:			git@gitlab.com:ufrrj/opencv.git
***	LICENSE:		see LICENSE file
***
***
***	OpenCV How-to by examples
***
*** Functions from OpenCV:
***
***   imread		Read image from file
***	namedWindow	Create a new window do show a image
***   imshow		Show Image on Window
***   waitkey		Wait a key pressed 
***
*** Methods
***
***	Mat::empty()	Return true if image is empty, else return false
***
***	In vi/vim editors use tabstop=3
***	In geany editor use preferences->Editor->Ident
***		set width to 	3
***		type				tab
**/

#include <iostream>
#include <fstream>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

/**
*** Open the namespaces
**/
using namespace std;
using namespace cv;

////</
/// Global Variables
int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;
int MAX_KERNEL_LENGTH = 31;

Mat image; Mat dst;
char window_name[] = "Smoothing Demo";



////>/

int main(int argc, char ** argv ) {

////</



/// Load the source image
    const char* filename = argc >=2 ? argv[1] : "../imagens/imagem_01.jpg"; ///<---AQUI

    image = imread( samples::findFile( filename ), IMREAD_COLOR );
    if (image.empty())
    {
        printf(" Error opening image\n");
        printf(" Usage:\n %s [image_name-- default lena.jpg] \n", argv[0]);
        return EXIT_FAILURE;
    } 

//src: imagem de origem
//dst: imagem de destino
//d: The diameter of each pixel neighborhood. -> O diâmetro de cada vizinhança de pixel.
//σColor: Desvio padrão no espaço de cores.
//σSpace: Desvio padrão no espaço de coordenadas (em termos de pixel).

bilateralFilter ( image, image, 30, 30, 15 );
           
    //<---AQUI
////>/

	// Create a window for display.
	namedWindow( window_name, WINDOW_AUTOSIZE); 
	// Show our image inside it.
	imshow( window_name, image );                

	waitKey(0);			// Wait for any key was pressed and return
							// the key code pressed or -1 if no key pressed
							// Parameter
							// =0 - Wait for until key pressed
							// >0 - Wait by N miliseconds and return
	return 0;

}

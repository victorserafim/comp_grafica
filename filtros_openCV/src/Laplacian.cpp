#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

Mat destino;
Mat destino_gray_Lpla, dst_Lpla;

    int kernel_size_Laplacian = 3;
    int scale_Laplacian = 1;
    int delta_Laplacian = 0;
    int ddepth = CV_16S;

void Laplacian_Funcao();

int main( int argc, char** argv )
{
    // Declare the variables we are going to use
    
    
    const char* window_name = "Laplace Demo";
    const char* imageName = argc >=2 ? argv[1] : "../imagens/imagem_01.jpg";
    destino = imread( samples::findFile( imageName ), IMREAD_COLOR ); // Load an image
    // Check if image is loaded fine
    if(destino.empty()){
        printf(" Error opening image\n");
        printf(" Program Arguments: [image_name -- default lena.jpg] \n");
        return -1;
    }


    Laplacian_Funcao ();


    waitKey(0);
    return 0;
}

void Laplacian_Funcao () {
    // Reduce noise by blurring with a Gaussian filter ( kernel size = 3 )
    GaussianBlur( destino, destino, Size(3, 3), 0, 0, BORDER_DEFAULT );
    cvtColor( destino, destino_gray_Lpla, COLOR_BGR2GRAY ); // Convert the image to grayscale_Laplacian
    Mat abs_dst_Lpla;
    Laplacian( destino_gray_Lpla, dst_Lpla, ddepth, kernel_size_Laplacian, scale_Laplacian, delta_Laplacian, BORDER_DEFAULT );
    // converting back to CV_8U
    convertScaleAbs( dst_Lpla, abs_dst_Lpla );
    imshow( "Laplace", abs_dst_Lpla );
}

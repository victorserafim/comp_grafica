#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
  cv::CommandLineParser parser(argc, argv,
                               "{@input   |image.jpg|imagem usada}"
                               "{ksize   k|1|ksize (aperte 'K' para aumentar o valor)}"
                               "{scale   s|1|scale (aperte 'S' para aumentar o valor)}"
                               "{delta   d|0|delta (aperte 'D' para aumentar o valor)}"
                               "{help    h|false|aparece o help}");
  cout << "Filtro Sobel em OpenCV\n\n";
  parser.printMessage();
  cout << "Aperte 'R' para resetar \nPressione 'ESC' para sair do programa.\n ";
  
  // Declarei todas as variáveis que usei aqui
  Mat image,src, src_gray;
  Mat grad;
  const String window_name = "Sobel";
  int ksize = parser.get<int>("ksize");
  int scale = parser.get<int>("scale");
  int delta = parser.get<int>("delta");
  int ddepth = CV_16S;
  String imageName = parser.get<String>("@input");
  
  // Da um load na imagem de uma forma diferente que eu achei pela internet
  image = imread( samples::findFile( imageName ), IMREAD_COLOR );
  
  // Faz um check se a imagem ta certo
  if( image.empty() )
  {
    printf("Error opening image: %s\n", imageName.c_str());
    return EXIT_FAILURE;
  }
  for (;;)
  {
    // Remove noise com blur do filtro Gaussian
    GaussianBlur(image, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
    
    // Converte imagem para P&B
    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;
    Sobel(src_gray, grad_x, ddepth, 1, 0, ksize, scale, delta, BORDER_DEFAULT);
    Sobel(src_gray, grad_y, ddepth, 0, 1, ksize, scale, delta, BORDER_DEFAULT);
    
    // converte de volta para CV_8U
    convertScaleAbs(grad_x, abs_grad_x);
    convertScaleAbs(grad_y, abs_grad_y);
    addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
    imshow(window_name, grad);
    char key = (char)waitKey(0);
    if(key == 27)
    {
      return EXIT_SUCCESS;
    }
    if (key == 'k' || key == 'K')
    {
      ksize = ksize < 30 ? ksize+2 : -1;
    }
    if (key == 's' || key == 'S')
    {
      scale++;
    }
    if (key == 'd' || key == 'D')
    {
      delta++;
    }
    if (key == 'r' || key == 'R')
    {
      scale =  1;
      ksize = -1;
      delta =  0;
    }
  }
  return EXIT_SUCCESS;
}
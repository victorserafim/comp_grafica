#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;
Mat destino;
Mat erosion_dst, dilation_dst;

int erosion_elem = 2; /*Element:    0 = Rect     1 = Cross     2 = Ellipse    */ 
/* Kernel size: 2n +1 */
int erosion_size = 21;
int dilation_elem = 2; /*Element:    0 = Rect     1 = Cross     2 = Ellipse    */ 
int dilation_size = 21;

//max_elem = 2 (0,1,2); em ambos: erosion_elem e dilation_elem
//max_kernel_size = 21; em ambos: erosion_size e dilation_size
void Erosion( int, void* );
void Dilation( int, void* );
int main( int argc, char** argv )
{
  CommandLineParser parser( argc, argv, "{@input | ../imagens/imagem_01.jpg | input image}" ); //<--- AQUI
  destino = imread( samples::findFile( parser.get<String>( "@input" ) ), IMREAD_COLOR );
  if( destino.empty() )
  {
    cout << "Could not open or find the image!\n" << endl;
    cout << "Usage: " << argv[0] << " <Input image>" << endl;
    return -1;
  }
  namedWindow( "Erosion Demo", WINDOW_AUTOSIZE );
  namedWindow( "Dilation Demo", WINDOW_AUTOSIZE );

  Erosion( 0, 0 );
  Dilation( 0, 0 );
  waitKey(0);
  return 0;
}

//!// Variáveis de alteração de Erosion:  erosion_elem e erosion_size 
void Erosion( int, void* )
{
  int erosion_type = 0;
  if( erosion_elem == 0 ){ erosion_type = MORPH_RECT; }
  else if( erosion_elem == 1 ){ erosion_type = MORPH_CROSS; }
  else if( erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }
  Mat element = getStructuringElement( erosion_type,
                       Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                       Point( erosion_size, erosion_size ) );
  erode( destino, erosion_dst, element );
  imshow( "Erosion Demo", erosion_dst );
}

//!// Variáveis de alteração de Dilation:  dilation_elem e dilation_size 
void Dilation( int, void* )
{
  int dilation_type = 0;
  if( dilation_elem == 0 ){ dilation_type = MORPH_RECT; }
  else if( dilation_elem == 1 ){ dilation_type = MORPH_CROSS; }
  else if( dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }
  Mat element = getStructuringElement( dilation_type,
                       Size( 2*dilation_size + 1, 2*dilation_size+1 ),
                       Point( dilation_size, dilation_size ) );
  dilate( destino, dilation_dst, element );
  imshow( "Dilation Demo", dilation_dst );
}
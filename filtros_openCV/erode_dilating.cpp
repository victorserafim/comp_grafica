#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat src, erosion_dst, dilation_dst;

int erosion_elem = 0;
int erosion_size = 0;
int dilation_elem = 0;
int dilation_size = 0;
int const max_elem = 2;
int const max_kernel_size = 21;

void Erosion( int, void* );
void Dilation( int, void* );

int main( int argc, char** argv )
{
  CommandLineParser parser( argc, argv, "{@input | image.jpg | input image}" );
  src = imread( samples::findFile( parser.get<String>( "@input" ) ), IMREAD_COLOR );
  if( src.empty() )
  {
    cout << "Não pude achar a imagem!\n" << endl;
    cout << "Uso: " << argv[0] << " <Input image>" << endl;
    return -1;
  }
  namedWindow( "Erosion", WINDOW_AUTOSIZE );
  namedWindow( "Dilation", WINDOW_AUTOSIZE );
  moveWindow( "Dilation", src.cols, 0 );
  createTrackbar( "Variação:\n 0: Normal \n 1: Cruz \n 2: Elipse", "Erosion",
          &erosion_elem, max_elem,
          Erosion );
  createTrackbar( "Tamanho:\n 2n +1", "Erosion",
          &erosion_size, max_kernel_size,
          Erosion );
  createTrackbar( "Variação:\n 0: Normal \n 1: Cruz \n 2: Elipse", "Dilation",
          &dilation_elem, max_elem,
          Dilation );
  createTrackbar( "Tamanho:\n 2n +1", "Dilation",
          &dilation_size, max_kernel_size,
          Dilation );
  Erosion( 0, 0 );
  Dilation( 0, 0 );
  waitKey(0);
  return 0;
}

//função da Erosion
void Erosion( int, void* )
{
  int erosion_type = 0;
  
  if( erosion_elem == 0 ){ erosion_type = MORPH_RECT; }
  else if( erosion_elem == 1 ){ erosion_type = MORPH_CROSS; }
  else if( erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }
  
  Mat element = getStructuringElement( erosion_type,
                       Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                       Point( erosion_size, erosion_size ) );
  
  erode( src, erosion_dst, element );
  imshow( "Erosion", erosion_dst );
}

//função da Dilation
void Dilation( int, void* )
{
  int dilation_type = 0;
  
  if( dilation_elem == 0 ){ dilation_type = MORPH_RECT; }
  else if( dilation_elem == 1 ){ dilation_type = MORPH_CROSS; }
  else if( dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }
  
  Mat element = getStructuringElement( dilation_type,
                       Size( 2*dilation_size + 1, 2*dilation_size+1 ),
                       Point( dilation_size, dilation_size ) );
  
  dilate( src, dilation_dst, element );
  imshow( "Dilation", dilation_dst );
}
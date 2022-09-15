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
int const max_elem = 2;
int const max_ligado = 1;

int  selecionar = 0;
int const num_filtros = 8;
int aplicar = 0;

int blur_element = 0;
int erosion_size = 0;
int const max_kernel_size = 21;

int dilation_size = 0;
////>/



Mat		image;		// Image object
Mat destino;
Mat bilateralImg;
string	filename;	// Image file name

//Prototipos de funções
void blurF (int, void* );
void selecionarF (int, void* );
void chamarSobelF (int, void* ); //preciasmos disso por causa da forma que Sobel é escrita. Com os args da main

int argc; char** argv; //preciasmos disso por causa da forma que Sobel é escrita. Com os args da main
int sobelF_real (int , char** ); //preciasmos disso por causa da forma que Sobel é escrita. Com os args da main


int xargc; //vamos pegar da main
char** xargv; //vamos pegar da main

int main(int argc, char** argv ) {
	xargc = argc; //vamos pegar da main
	xargv = argv; //vamos pegar da main
	std::cout << "Imprimindo o famoso HELLO WORLD!!!\n";
	


	filename = "../imagens/imagem_01.jpg";

	// Read image from disk
	image = imread(filename);
	destino =  imread(filename); //defini já q no comeco, destimo é igua a imagem carregada

	// Check if image was loaded
	if ( image.empty() ){
		cerr << "Image [ " << filename << " ] not found!" << endl;
		cerr << "Quitting!" << endl;
		exit (-1);
	}
////</

    // Provided by OpenCV function bilateralFilter() We use 5 arguments:
    // src: Source image
    // dst: Destination image
    // d: The diameter of each pixel neighborhood.
	// Standard deviation in the color space.
	// Standard deviation in the coordinate space (in pixel terms).

	//NO CASO DO BILATERAL, VOCÊ TEM QUE POR OUTRO OBJETO MAT DE SAÍDA! NÃO PODE SER O MESMO
	//Q O DE ENTRADA

	
	
	
        
    
   
    //<---AQUI

	//FiltroBilateral ( image, bilateralImg, 15, 95, 45 );
	//----------------------- CHAMANDO AS FUNÇÕES -----------------------------
	blurF (0, 0); //Acho q vai ter q por (0,0)
	chamarSobelF (0,0);

////>/

	// Create a window for display.
	//namedWindow( filename.c_str(), WINDOW_NORMAL); 

	//!!!Abaixo
	//namedWindow( "Filtro Bilateral", WINDOW_NORMAL ); //Temos que por isso aqui pra fazer a janela com o botão deslizante
	// ^ Por o nome da janela a esquerda "Janela"
	moveWindow( "Filtro Bilateral", image.cols, 0 );
	

 

	//destroyWindow("Filtro Bilateral"); USAR PARA FECHAR CADA JANELA
	namedWindow( "Selecionar-Aplicar", WINDOW_AUTOSIZE );
	createTrackbar( "Selecionar", "Selecionar-Aplicar",
          &selecionar, num_filtros,
          selecionarF  );
	
	createTrackbar( "Aplicar", "Selecionar-Aplicar",
          &aplicar, max_ligado,
          blurF );
	
	//setTrackbarPos (1,2,3);

	// Show our image inside it.
	//imshow( filename.c_str(), image );       




  /*
  createTrackbar( "Kernel size:\n 2n +1", "Erosion Demo",
          &erosion_size, max_kernel_size,
          FiltroBilateral );
  */

	
	
         

	waitKey(0);			// Wait for any key was pressed and return
							// the key code pressed or -1 if no key pressed
							// Parameter
							// =0 - Wait for until key pressed
							// >0 - Wait by N miliseconds and return
	return 0;

}


/* -----------------------------------  NÃO-EXCLUIR: NOMES DAS JANELAS --------------------------------------

	namedWindow( "Sobel", WINDOW_NORMAL ); //Temos que por isso aqui pra fazer a janela com o botão deslizante
	namedWindow( "Blur", WINDOW_NORMAL ); } //Temos que por isso aqui pra fazer a janela com o botão deslizante
	namedWindow( "Erode", WINDOW_NORMAL ); } //Temos que por isso aqui pra fazer a janela com o botão deslizante
	namedWindow( "Dilate", WINDOW_NORMAL ); //Temos que por isso aqui pra fazer a janela com o botão deslizante
	namedWindow( "Gaussian", WINDOW_NORMAL ); //Temos que por isso aqui pra fazer a janela com o botão deslizante
	namedWindow( "GaussianBlur", WINDOW_NORMAL ); //Temos que por isso aqui pra fazer a janela com o botão deslizante
	namedWindow( "Laplacian", WINDOW_NORMAL ); //Temos que por isso aqui pra fazer a janela com o botão deslizante
	namedWindow( "Filtro Bilateral", WINDOW_NORMAL ); //Temos que por isso aqui pra fazer a janela com o botão deslizante

	namedWindow( "para RGB", WINDOW_NORMAL ); //Temos que por isso aqui pra fazer a janela com o botão deslizante
	namedWindow( "para HSV", WINDOW_NORMAL ); //Temos que por isso aqui pra fazer a janela com o botão deslizante
	namedWindow( "para Tons de cinza", WINDOW_NORMAL ); //Temos que por isso aqui pra fazer a janela com o botão deslizante

	namedWindow( "Calcular a media", WINDOW_NORMAL ); //Temos que por isso aqui pra fazer a janela com o botão deslizante
	namedWindow( "Calcular o desvio padrão", WINDOW_NORMAL ); //Temos que por isso aqui pra fazer a janela com o botão deslizante
	
	namedWindow( "Salvar a imagem", WINDOW_NORMAL ); //Temos que por isso aqui pra fazer a janela com o botão deslizante
	 
	 -----------------------------------  NÃO-EXCLUIR: NOMES DAS JANELAS --------------------------------------
*/

int sobelF_real (int argc, char** argv)
{
  
  cv::CommandLineParser parser(argc, argv,
                               "{@input   |../imagens/imagem_01.jpg|input image}" //Local da imagem
                               "{ksize   k|1|ksize (hit 'K' to increase its value at run time)}"
                               "{scale   s|1|scale (hit 'S' to increase its value at run time)}"
                               "{delta   d|0|delta (hit 'D' to increase its value at run time)}"
                               "{help    h|false|show help message}");

  cout << "The sample uses Sobel or Scharr OpenCV functions for edge detection\n\n";
  parser.printMessage();
  cout << "\nPress 'ESC' to exit program.\nPress 'R' to reset values ( ksize will be -1 equal to Scharr function )";

  //![variables]
  // First we declare the variables we are going to use
  Mat image,src, src_gray;
  Mat grad;
  const String window_name = "Sobel Demo - Simple Edge Detector";
  int ksize = parser.get<int>("ksize");
  int scale = parser.get<int>("scale");
  int delta = parser.get<int>("delta");
  int ddepth = CV_16S;
  //![variables]

  //![load]
  String imageName = parser.get<String>("@input");
  // As usual we load our source image (src)
  image = imread( samples::findFile( imageName ), IMREAD_COLOR ); // Load an image

  // Check if image is loaded fine
  if( image.empty() )
  {
    printf("Error opening image: %s\n", imageName.c_str());
    return EXIT_FAILURE;
  }
  //![load]

  for (;;)
  {
    //![reduce_noise]
    // Remove noise by blurring with a Gaussian filter ( kernel size = 3 )
    GaussianBlur(image, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
    //![reduce_noise]

    //![convert_to_gray]
    // Convert the image to grayscale
    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    //![convert_to_gray]

    //![sobel]
    /// Generate grad_x and grad_y
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;

    /// Gradient X
    Sobel(src_gray, grad_x, ddepth, 1, 0, ksize, scale, delta, BORDER_DEFAULT);

    /// Gradient Y
    Sobel(src_gray, grad_y, ddepth, 0, 1, ksize, scale, delta, BORDER_DEFAULT);
    //![sobel]

    //![convert]
    // converting back to CV_8U
    convertScaleAbs(grad_x, abs_grad_x);
    convertScaleAbs(grad_y, abs_grad_y);
    //![convert]

    //![blend]
    /// Total Gradient (approximate)
    addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
    //![blend]

    //![display]
    imshow(window_name, grad);
    char key = (char)waitKey(0);
    //![display]

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



void chamarSobelF (int, void* ){
  sobelF_real (xargc, xargv );//PRECISA DE PASSAR ESSES ARGs, que pegamos da main, através do escopo da main, copiando os para essas 2 variáveis
}

void blurF (int, void* ){ //Formato que a função createTrackbar aceita para sua função que será chamada no último argumento
		
		
		///
	  int valor = 1; //NO CASO DO blur, aqui nao pode ter 0 "zero"
	  destino = imread(filename); //ZERANDO DESTINO, PRA APLICARMOS CERTO/REFAZER/FAZER MENOS QUE

  if( blur_element == 0 ){ valor = 1;} //o if recebe o valor do createTrackbar (...&blur_element )
  else if( blur_element == 1 ){ valor = 45; }
  else if( blur_element == 2) { valor = 95; } //VAI ABRIR A IMAGEM, PARA "DESFAZER", OU SEJA, APLICAR A ORIGINAL
//PARA DESFAZER TEM Q EXISTIR UM OUTRO MAT, GUARDANDO O Q FOI FEITO.
  //_______>>>>>>> ELE SÓ NÃO CONSEGUE "DESFAZER " O BLUR. DESCUBRA COMO Q FAZ PARA VOLTAR AO ORIGINAL, A FUNÇÃO

	// int element = ;
		///

		
		//criar variavel, para o primeiro argumento
		//blur(image,image,Size(30,15)); //subir dps?
		
		
	// Show our image inside it.
		blur(destino,destino,Size(valor,valor)); //subir dps? //NAO MODIFICAR A ORIGINAL
		imshow( filename.c_str(), destino ); //OK, FUNCIONA
		
	}


//------------- Fazer as janelas aparecerem e desaparecerem para não bugar --------------------------
void selecionarF  (int, void* ){
	int valor = 0;
  if( selecionar == 0 ){
	destroyWindow("Sobel");
	destroyWindow("Blur");
	destroyWindow("Erode");
	destroyWindow("Dilate");
	destroyWindow("Gaussian");
	destroyWindow("GaussianBlur");
	destroyWindow("Laplacian");
	destroyWindow("Filtro Bilateral");
	
	destroyWindow("para RGB");
	destroyWindow("para HSV");
	destroyWindow("para Tons de cinza");

	destroyWindow("Calcular a media");
	destroyWindow("Calcular o desvio padrão");

	destroyWindow("Salvar a imagem");
  }
  
  else if( selecionar == 1 ){
	valor = 1; namedWindow( "Sobel", WINDOW_NORMAL );
	destroyWindow("Blur");
	destroyWindow("Erode");
	destroyWindow("Dilate");
	destroyWindow("Gaussian");
	destroyWindow("GaussianBlur");
	destroyWindow("Laplacian");
	destroyWindow("Filtro Bilateral");
	
	destroyWindow("para RGB");
	destroyWindow("para HSV");
	destroyWindow("para Tons de cinza");

	destroyWindow("Calcular a media");
	destroyWindow("Calcular o desvio padrão");

	destroyWindow("Salvar a imagem");
	} //o if recebe o valor do createTrackbar (...&selecionar )
  
  else if( selecionar == 2 ){ valor = 2; namedWindow( "Blur", WINDOW_NORMAL );
  	//("Texto", "NOME DA JANELA EM Q ESTARÁ, ")
 	createTrackbar( "Element", "Blur", //<- jANELA EM Q SE CRIARÁ TRACKBAR
        &blur_element, max_elem,
        blurF);
	
	destroyWindow("Sobel");
	
	destroyWindow("Erode");
	destroyWindow("Dilate");
	destroyWindow("Gaussian");
	destroyWindow("GaussianBlur");
	destroyWindow("Laplacian");
	destroyWindow("Filtro Bilateral");
	
	destroyWindow("para RGB");
	destroyWindow("para HSV");
	destroyWindow("para Tons de cinza");

	destroyWindow("Calcular a media");
	destroyWindow("Calcular o desvio padrão");

	destroyWindow("Salvar a imagem");
    }
  else if( selecionar == 3 ){ valor = 3; namedWindow( "Erode", WINDOW_NORMAL ); 
  	destroyWindow("Sobel");
	destroyWindow("Blur");
	
	destroyWindow("Dilate");
	destroyWindow("Gaussian");
	destroyWindow("GaussianBlur");
	destroyWindow("Laplacian");
	destroyWindow("Filtro Bilateral");
	
	destroyWindow("para RGB");
	destroyWindow("para HSV");
	destroyWindow("para Tons de cinza");

	destroyWindow("Calcular a media");
	destroyWindow("Calcular o desvio padrão");

	destroyWindow("Salvar a imagem");
	}
  else if( selecionar == 4 ){ valor = 4; namedWindow( "Dilate", WINDOW_NORMAL );
  	destroyWindow("Sobel");
	destroyWindow("Blur");
	destroyWindow("Erode");
	
	destroyWindow("Gaussian");
	destroyWindow("GaussianBlur");
	destroyWindow("Laplacian");
	destroyWindow("Filtro Bilateral");
	
	destroyWindow("para RGB");
	destroyWindow("para HSV");
	destroyWindow("para Tons de cinza");

	destroyWindow("Calcular a media");
	destroyWindow("Calcular o desvio padrão");

	destroyWindow("Salvar a imagem");
	}
  else if( selecionar == 5 ){ valor = 5; namedWindow( "Gaussian", WINDOW_NORMAL );
  	destroyWindow("Sobel");
	destroyWindow("Blur");
	destroyWindow("Erode");
	destroyWindow("Dilate");
	
	destroyWindow("GaussianBlur");
	destroyWindow("Laplacian");
	destroyWindow("Filtro Bilateral");
	
	destroyWindow("para RGB");
	destroyWindow("para HSV");
	destroyWindow("para Tons de cinza");

	destroyWindow("Calcular a media");
	destroyWindow("Calcular o desvio padrão");

	destroyWindow("Salvar a imagem");
	}
  else if( selecionar == 6 ){ valor = 6; namedWindow( "GaussianBlur", WINDOW_NORMAL );
  	destroyWindow("Sobel");
	destroyWindow("Blur");
	destroyWindow("Erode");
	destroyWindow("Dilate");
	destroyWindow("Gaussian");
	
	destroyWindow("Laplacian");
	destroyWindow("Filtro Bilateral");
	
	destroyWindow("para RGB");
	destroyWindow("para HSV");
	destroyWindow("para Tons de cinza");

	destroyWindow("Calcular a media");
	destroyWindow("Calcular o desvio padrão");

	destroyWindow("Salvar a imagem");}
  else if( selecionar == 7 ){ valor = 7; namedWindow( "Laplacian", WINDOW_NORMAL );
  	destroyWindow("Sobel");
	destroyWindow("Blur");
	destroyWindow("Erode");
	destroyWindow("Dilate");
	destroyWindow("Gaussian");
	destroyWindow("GaussianBlur");
	
	destroyWindow("Filtro Bilateral");
	
	destroyWindow("para RGB");
	destroyWindow("para HSV");
	destroyWindow("para Tons de cinza");

	destroyWindow("Calcular a media");
	destroyWindow("Calcular o desvio padrão");

	destroyWindow("Salvar a imagem");
	}
  else if( selecionar == 8 ){ valor = 8; namedWindow( "Filtro Bilateral", WINDOW_NORMAL );
  	//("Texto", "NOME DA JANELA EM Q ESTARÁ, ")
 	createTrackbar( "Element", "Filtro Bilateral",
        &blur_element, max_elem,
        blurF);

  	destroyWindow("Sobel");
	destroyWindow("Blur");
	destroyWindow("Erode");
	destroyWindow("Dilate");
	destroyWindow("Gaussian");
	destroyWindow("GaussianBlur");
	destroyWindow("Laplacian");

	
	destroyWindow("para RGB");
	destroyWindow("para HSV");
	destroyWindow("para Tons de cinza");

	destroyWindow("Calcular a media");
	destroyWindow("Calcular o desvio padrão");

	destroyWindow("Salvar a imagem");
	}
}
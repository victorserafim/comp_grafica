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

//using namespace std;
//using namespace cv;

//////--


int main(void) {

cv::Mat img = cv::imread ("../imagens/imagem_01.jpg",cv::IMREAD_COLOR);

cv::Mat bilateralImg;

cv::bilateralFilter (img, bilateralImg, 15, 95, 45);

cv::imshow("Bilateral",bilateralImg);
cv::imshow("Input",img);
cv::waitKey(0); //O K é MAIÚSCULO! wait K ey 


	return 0;

}

#include "main.h"


void MyGlDraw(void)
{

	// Chama as funções do mygl.h
    Pixel pxl1 = {100, 300, 255, 0,0, 0};
    Pixel pxl2 = {200, 150, 0, 255, 0, 1};
    Pixel pxl3 = {400, 300, 0, 255, 0, 0};
    Pixel pxl4 = {300, 150, 0, 0, 255, 127};
    Pixel pxl5 = {150, 450, 255, 0, 0, 100};
    Pixel pxl6 = {350, 450, 0, 0, 255, 255};
    Pixel pxl7 = {256, 256, 255, 0, 0, 0};
    Pixel pxl8 = {156, 450, 0, 255, 0, 127};
    Pixel pxl9 = {356, 450, 127, 255, 127, 0};

    colocaPixel(pxl7);


    desenhaLinha(pxl1,pxl9);
    desenhaLinha(pxl5,pxl6);

}

int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}
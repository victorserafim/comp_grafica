#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include <vector>
#include <cmath>

typedef struct Pixel {
	int x;
	int y;

    double red;
    double green;
    double blue;
    double alpha;
	} Pixel;

typedef struct Steps {

    double redStep;
    double greenStep;
    double blueStep;
    double alphaStep;

} Steps;
		


//Desenha um pixel na tela. Seus atributos são definidos no struct passado. 
void colocaPixel(Pixel p) {
	
	if(p.x>IMAGE_WIDTH || p.x<0 || p.y>IMAGE_HEIGHT || p.y<0) return; 
	
	int endereco = p.x*4 + p.y*4*IMAGE_WIDTH;
	FBptr[endereco] = p.red;
	FBptr[endereco + 1] = p.green;
	FBptr[endereco + 2] = p.blue;
	FBptr[endereco + 3] = p.alpha;
}

void setarDist(Pixel inicial, Pixel final, Steps *dist){
    int dx = final.x - inicial.x;
    int dy = final.y - inicial.y;

    double hypo = sqrt(dx*dx + dy*dy);

    //Define o quanto cada cor irá incrementar/decrementar a cada pixel
    dist->redStep = (final.red - inicial.red)/hypo;
    dist->greenStep = (final.green - inicial.green)/hypo;
    dist->blueStep = (final.blue - inicial.blue)/hypo;
    dist->alphaStep = (final.alpha - inicial.alpha)/hypo;
}

void interpolar(Pixel *inicial, Steps dist){
    inicial->red += dist.redStep;
    inicial->green += dist.greenStep;
    inicial->blue += dist.blueStep;
    inicial->alpha += dist.alphaStep;
}

//Implementação do algoritmo de Bresenham
void desenhaLinha(Pixel inicial, Pixel final){
    int xi = inicial.x;
    int xf = final.x;
    int yi = inicial.y;
    int yf = final.y;
    int dx = abs(xf - xi);
    int dy = abs(yf - yi);
    int controle = 0;   //Controla se a direção menor vai crescer ou nao;
    int incX = 0;
    int incY = 0;

    //Define se Y e X estão indo nas direções positivas ou negativas
    if(xf > xi) incX = 1;
    else incX = -1;

    if(yf > yi) incY = 1;
    else incY = -1;

    Steps steps;
    setarDist(inicial,final,&steps);
    
    colocaPixel(inicial);
    Pixel linha = {inicial.x, inicial.y, inicial.red, inicial.green, inicial.blue, inicial.alpha};  //Esse pixel é o que se moverá e pintará a linha
    
    if(dx == 0){
        if(yf > yi){    //linha pra baixo
            while(linha.y != yf)
            {

                linha.y++;
                interpolar(&linha,steps);
                colocaPixel(linha);

            }
        }
        else{           //linha pra cima
            while(linha.y != yf)
            {

                linha.y--;
                interpolar(&linha,steps);
                colocaPixel(linha);

            }
        }

    }
    else if(dy == 0){
        if(xf > xi){    //linha pra direita
            while(linha.x != xf)
            {

                linha.x++;
                interpolar(&linha,steps);
                colocaPixel(linha);

            }
        }
        else{           //linha pra esquerda
            while(linha.x != xf)
            {

                linha.x--;
                interpolar(&linha,steps);
                colocaPixel(linha);

            }
        }
    }
    else {
        if (dx >= dy) {

            controle = dx / 2;
            colocaPixel(inicial);
            while (linha.x != xf) {
                linha.x += incX;
                controle = controle - dy;
                if (controle < 0) {
                    linha.y += incY;
                    controle += dx;
                }
                interpolar(&linha,steps);
                colocaPixel(linha);
            }

        } else {
            controle = dy / 2;
            colocaPixel(inicial);
            while (linha.y != yf) {
                linha.y += incY;
                controle = controle - dx;
                if (controle < 0) {
                    linha.x += incX;
                    controle += dy;
                }
                interpolar(&linha,steps);
                colocaPixel(linha);
            }

        }
    }


}


#endif // _MYGL_H_
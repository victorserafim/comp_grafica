#include <GL/glut.h>

// Tamanho e posição inicial do quadrado
GLfloat x1 = 120.0f;
GLfloat y1 = 100.0f;
GLsizei rsize = 100;                                                    

// Largura e altura da janela
GLfloat windowWidth;
GLfloat windowHeight;


//faz o desenho
void Desenha(void)
{
     // Limpa a janela de visualização com a cor de fundo especificada
     glClear(GL_COLOR_BUFFER_BIT);

     // cor inicial
     //         R     G     B
     glColor3f(0.0f, 1.0f, 0.0f);
  
     // Desenha um quadrado preenchido
     glBegin(GL_QUADS);
          glVertex2i(x1,y1+rsize); 
          glVertex2i(x1,y1);
          // faz o degradê pro azul
          glColor3f(0.0f, 0.0f, 1.0f);
          glVertex2i(x1+rsize,y1);
          glVertex2i(x1+rsize,y1+rsize);               
     glEnd();

     glutSwapBuffers();
}

// Inicializa rendering
void Inicializa (void)
{   // fundo preto
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// modulação do tamanho da tela
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{    // Evita a divisao por zero
     if(h == 0) h = 1;
                           
     // Especifica as dimensões
     glViewport(0, 0, w, h);

     // sistema de coordenadas
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();

     // Estabelece a janela de seleção
     if (w <= h)  {
		windowHeight = 250.0f*h/w;
		windowWidth = 250.0f;
     }
     else  { 
		windowWidth = 250.0f*w/h;
		windowHeight = 250.0f;
     }
     
     gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}

// Programa Principal 
int main(int argc, char** argv)
{    
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
     glutInitWindowSize(400,350);
     glutInitWindowPosition(10,10);
     glutCreateWindow("poligono chei em degrade");
     glutDisplayFunc(Desenha);
     glutReshapeFunc(AlteraTamanhoJanela);
     Inicializa();
     glutMainLoop();
}
// glutEx1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <gl/glut.h>
#include <stdlib.h>

float fTranslate;
float fRotate;
float fScale     = 1.0f;	// set inital scale value to 1.0f

void Draw_Desk() // This function draws a triangle with RGB colors
{
	glColor3f(1, 1, 1);   //������ɫ
	//����
	glPushMatrix();
	glTranslatef(0, 0, 0.4f);	//����ƽ��
	glScalef(5, 4, 1);  //�ߴ�任
	glutWireCube(0.2); //�����߿�������
	glPopMatrix();
	//����
	glPushMatrix();
	glTranslatef(0.25f, 0.2f, 0);	//����ƽ��
	glScalef(1, 1, 3);  //�ߴ�任
	glutWireCube(0.2); //�����߿�������
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.25f, 0.2f, 0);	//����ƽ��
	glScalef(1, 1, 3);  //�ߴ�任
	glutWireCube(0.2); //�����߿�������
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.25f, -0.2f, 0);	//����ƽ��
	glScalef(1, 1, 3);  //�ߴ�任
	glutWireCube(0.2); //�����߿�������
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.25f, -0.2f, 0);	//����ƽ��
	glScalef(1, 1, 3);  //ģ�ͱ任
	glutWireCube(0.2); //����ʵ����������߿�������
	glPopMatrix();

	glFlush();   //ˢ�´�������ʾ��ǰ����ͼ��


}

void reshape(int width, int height)
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

void idle()
{
	glutPostRedisplay();
}

void redraw()
{
// If want display in wireframe mode
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();									// Reset The Current Modelview Matrix
	
	glPushMatrix();
		glTranslatef(-2.0f, 0.0f,-6.0f);		// Place the triangle Left
		glTranslatef(0.0f, fTranslate, 0.0f);	// Translate in Y direction
		Draw_Desk();						// Draw desk					
	glPopMatrix();

    glPushMatrix();
		glTranslatef(0.0f, 0.0f,-6.0f);			// Place the triangle at Center
		glRotatef(fRotate, 0, 1.0f, 0);			// Rotate around Y axis
		Draw_Desk();						// Draw desk
	glPopMatrix();


	glPushMatrix();
		glTranslatef(2.0f,0.0f,-6.0f);			// Place the triangle Right
		glScalef(fScale, fScale, fScale);		// Scale with the same value in x,y,z direction
		Draw_Desk();						// Draw desk						
	glPopMatrix();


	fTranslate += 0.005f;
	fRotate    += 0.5f;
	fScale     -= 0.005f;

	if(fTranslate > 0.5f) fTranslate = 0.0f;
	if(fScale < 0.5f)     fScale     = 1.0f;
	glutSwapBuffers();
}

int main (int argc,  char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(640,480);                                                     ///////////////////////////////////////
  int windowHandle
        = glutCreateWindow("Simple GLUT App");

  glutDisplayFunc(redraw);
	glutReshapeFunc(reshape);			///////////////////////////////////////
	glutIdleFunc(idle);							///////////////////////////////////////

  glutMainLoop();

  return 0;
}


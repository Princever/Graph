// glutEx1.cpp : 定义控制台应用程序的入口点。
//

#include <gl/glut.h>
#include <stdlib.h>

float fTranslate;
float fRotate;
float fScale     = 1.0f;	// set inital scale value to 1.0f

void Draw_Desk() // This function draws a triangle with RGB colors
{
	glColor3f(1, 1, 1);   //重置颜色
	//桌板
	glPushMatrix();
	glTranslatef(0, 0, 0.4f);	//坐标平移
	glScalef(5, 4, 1);  //尺寸变换
	glutWireCube(0.2); //绘制线框立方体
	glPopMatrix();
	//桌腿
	glPushMatrix();
	glTranslatef(0.25f, 0.2f, 0);	//坐标平移
	glScalef(1, 1, 3);  //尺寸变换
	glutWireCube(0.2); //绘制线框立方体
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.25f, 0.2f, 0);	//坐标平移
	glScalef(1, 1, 3);  //尺寸变换
	glutWireCube(0.2); //绘制线框立方体
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.25f, -0.2f, 0);	//坐标平移
	glScalef(1, 1, 3);  //尺寸变换
	glutWireCube(0.2); //绘制线框立方体
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.25f, -0.2f, 0);	//坐标平移
	glScalef(1, 1, 3);  //模型变换
	glutWireCube(0.2); //绘制实心立方体和线框立方体
	glPopMatrix();

	glFlush();   //刷新窗口以显示当前绘制图形


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



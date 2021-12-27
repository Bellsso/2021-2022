#define GLUT_DISABLE_ATEXIT_HACK

#define _CRT_SECURE_NO_WARNINGS
#pragma comment (lib,"glaux.lib")
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gl\glu.h>
#include <GL\glut.h>
#include <GLAUX\glaux.h>
#include <GL\gl.h>

GLuint texture[1];    //存储纹理数据
GLfloat x = 0.0f, y = 0.0f, z = 0.0f;

AUX_RGBImageRec* LoadBMP(const char* Filename)     // 加载图像
{
	FILE* File = NULL;

	if (!Filename)
	{
		return NULL;
	}

	File = fopen(Filename, "r");

	if (File)
	{
		fclose(File);
		//return NULL;
		return auxDIBImageLoad(Filename);
	}

	return NULL;
}

int LoadGLTextures()          // 加载纹理
{
	int Status = FALSE;          // 状态指示器

	AUX_RGBImageRec* TextureImage[1];      // 创建纹理存储空间

	memset(TextureImage, 0, sizeof(void*) * 1);

	// 载入bmp格式图像
	if (TextureImage[0] = LoadBMP("2.bmp"))
	{
		Status = TRUE;
		glGenTextures(1, &texture[0]);      // 创建纹理
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

	if (TextureImage[0])          //如果纹理存在
	{
		if (TextureImage[0]->data)        //如果纹理图像存在
		{
			free(TextureImage[0]->data);
		}

		free(TextureImage[0]);
	}

	return Status;           // 返回指示器
}

void reshape(int width, int height) {
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 2, -5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

//绘制立方体
void display(void) {
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRotatef(20, 1.0, 0.0, 0.0);
	glRotatef(30, 0.0, 1.0, 0.0);
	glRotatef(30, 0.0, 0.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	// 前
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	// 后
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	// 上
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	// 下
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	// 右
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	// 左
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
	x += 0.3f;
	y += 0.2f;
	z += 0.4f;
}

int Init(void) {
	if (!LoadGLTextures())
	{
		return 0;          // 没有加载成功
	}
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	return 1;
}
int main(int argc, char** argv) {
	//glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	//glutInitWindowPosition(300, 400);
	//glutInitWindowSize(600, 600);
	//glutCreateWindow("...");
	//Init();
	//glutDisplayFunc(display);
	//glutIdleFunc(display);
	//glutReshapeFunc(reshape);
	//glutMainLoop();
	//return 0;

		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(300, 300);
		glutInitWindowPosition(100, 100);
		glutCreateWindow("OpenGL Version");

		const GLubyte* name = glGetString(GL_VENDOR); //返回负责当前OpenGL实现厂商的名字
		const GLubyte* biaoshifu = glGetString(GL_RENDERER); //返回一个渲染器标识符，通常是个硬件平台
		const GLubyte* OpenGLVersion = glGetString(GL_VERSION); //返回当前OpenGL实现的版本号
		const GLubyte* gluVersion = gluGetString(GLU_VERSION); //返回当前GLU工具库版本

		printf("OpenGL实现厂商的名字：%s\n", name);
		printf("渲染器标识符：%s\n", biaoshifu);
		printf("OpenGL实现的版本号：%s\n", OpenGLVersion);
		printf("OGLU工具库版本：%s\n", gluVersion);
		//如果是在VS上执行，需要在return前加上：system("pause");
		return 0;
	
}

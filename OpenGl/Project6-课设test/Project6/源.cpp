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

GLuint texture[1];    //�洢��������
GLfloat x = 0.0f, y = 0.0f, z = 0.0f;

AUX_RGBImageRec* LoadBMP(const char* Filename)     // ����ͼ��
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

int LoadGLTextures()          // ��������
{
	int Status = FALSE;          // ״ָ̬ʾ��

	AUX_RGBImageRec* TextureImage[1];      // ��������洢�ռ�

	memset(TextureImage, 0, sizeof(void*) * 1);

	// ����bmp��ʽͼ��
	if (TextureImage[0] = LoadBMP("2.bmp"))
	{
		Status = TRUE;
		glGenTextures(1, &texture[0]);      // ��������
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

	if (TextureImage[0])          //����������
	{
		if (TextureImage[0]->data)        //�������ͼ�����
		{
			free(TextureImage[0]->data);
		}

		free(TextureImage[0]);
	}

	return Status;           // ����ָʾ��
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

//����������
void display(void) {
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRotatef(20, 1.0, 0.0, 0.0);
	glRotatef(30, 0.0, 1.0, 0.0);
	glRotatef(30, 0.0, 0.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	// ǰ
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	// ��
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	// ��
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	// ��
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	// ��
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	// ��
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
		return 0;          // û�м��سɹ�
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

		const GLubyte* name = glGetString(GL_VENDOR); //���ظ���ǰOpenGLʵ�ֳ��̵�����
		const GLubyte* biaoshifu = glGetString(GL_RENDERER); //����һ����Ⱦ����ʶ����ͨ���Ǹ�Ӳ��ƽ̨
		const GLubyte* OpenGLVersion = glGetString(GL_VERSION); //���ص�ǰOpenGLʵ�ֵİ汾��
		const GLubyte* gluVersion = gluGetString(GLU_VERSION); //���ص�ǰGLU���߿�汾

		printf("OpenGLʵ�ֳ��̵����֣�%s\n", name);
		printf("��Ⱦ����ʶ����%s\n", biaoshifu);
		printf("OpenGLʵ�ֵİ汾�ţ�%s\n", OpenGLVersion);
		printf("OGLU���߿�汾��%s\n", gluVersion);
		//�������VS��ִ�У���Ҫ��returnǰ���ϣ�system("pause");
		return 0;
	
}

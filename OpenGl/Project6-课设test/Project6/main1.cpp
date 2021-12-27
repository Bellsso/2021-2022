//// 纹理映射实例.cpp : 定义控制台应用程序的入口点。
////
//
//#include "main1.h"
//#include <stdlib.h>
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(480, 480);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("绘制sanwei");
//	Initialization();
//	glutReshapeFunc(OnReshape);
//	glutDisplayFunc(OnDisplay);
//	glutKeyboardFunc(keyboard);
//	glutMainLoop();
//	return 0;
//}
//
//
////创建位图函数
//void MakeImage(void)
//{
//	int i, j, c;
//	for (i = 0; i < HEIGHT; i++)
//	{
//		for (j = 0; j < WIDTH; j++)
//		{
//			c = (((i & 0x8) == 0) ^ ((j & 0x8) == 0)) * 255;
//			//计算纹理颜色
//			Image[i][j][0] = GLubyte(c);
//			Image[i][j][1] = GLubyte(c);
//			Image[i][j][2] = GLubyte(c);
//			Image[i][j][3] = GLubyte(255);
//
//		}
//	}
//}
//
//void Initialization(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//	glEnable(GL_DEPTH_TEST);
//
//	MakeImage();
//	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//
//
//	glGenTextures(1, &texName);
//	glBindTexture(GL_TEXTURE_2D, texName);
//
//	//设置纹理参数
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WIDTH, HEIGHT,
//		0, GL_RGBA, GL_UNSIGNED_BYTE, Image);
//}
////显示回调函数
//void OnDisplay(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_TEXTURE_2D);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
//
//	glBindTexture(GL_TEXTURE_2D, texName);
//
//	glBegin(GL_QUADS);
//	//指定纹理坐标
//
//	glTexCoord2f(0.0f, 0.0f);
//	glVertex3f(-2.0f, -2.0f, 0.0f);
//	glTexCoord2f(0.0f, 1.0f);
//	glVertex3f(-2.0f, 2.0f, 0.0f);
//	glTexCoord2f(1.0f, 1.0f);
//	glVertex3f(2.0f, 2.0f, 0.0f);
//	glTexCoord2f(1.0f, 0.0f);
//	glVertex3f(2.0f, -2.0f, 0.0f);
//	/*//其他效果
//		glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, -1.0, 0.0);
//		glTexCoord2f(0.0, 1.0); glVertex3f(-2.0, 1.0, 0.0);
//		glTexCoord2f(1.0, 1.0); glVertex3f(0.0, 1.0, 0.0);
//		glTexCoord2f(1.0, 0.0); glVertex3f(0.0, -1.0, 0.0);
//
//		glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
//		glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
//		glTexCoord2f(1.0, 1.0); glVertex3f(2.41421, 1.0, -1.41421);
//		glTexCoord2f(1.0, 0.0); glVertex3f(2.41421, -1.0, -1.41421);
//		*/
//	glEnd();
//	glFlush();
//	glDisable(GL_TEXTURE_2D);
//
//}
////重绘回调函数
//void OnReshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 30.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glTranslatef(0.0, 0.0, -3.6);
//}
//
//
////按Esc退出程序
//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key) {
//	case 27:
//		exit(0);
//		break;
//	default:
//		break;
//	}
//}
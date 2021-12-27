////#include<GL/glut.h>    //头文件  到时候需要改一下  此头文件在codeblocks环境下运行
//
//
//#include<GL/glew.h>        //此头文件在vs环境下运行
//#include<GL/freeglut.h>
//#include<GL/gl.h>
//
//
//#include<iostream>
//using std::cout;
//#define _USE_MATH_DEFINES // for C++
//#include <math.h>
//GLfloat w = 700;
//GLfloat h = 700;
//double rotate_x = 0.0;
//double rotate_y = 0.0;
//# define  white  1.0 ,  1.0  ,  1.0   // 对颜色的宏定义
//# define  green  0.0 ,  0.502,  0.0
//# define  red    1.0 ,  0.0  ,  0.0
//# define  gray   0.502, 0.502,0.502
//# define  hgray  0.117, 0.180,0.227
//# define  blue   0.0  , 0.0  ,  1.0
//# define  pi  3.14159265
//# define  gold   1.0,215.0/255.0,0.0
//# define  hgreen 0.0,100.0/255.0,0.0
//# define  brown  210.0/255.0, 105.0/255.0,  30.0/255.0
//# define  men   244.0/255.0 ,164.0/255.0 , 96.0/255.0
//# define  menba   139.0/255.0 ,69.0/255.0,19.0/255.0
//double fang[8][3];             // 定义长方体的8个顶点
//							   // 定义constract函数  当给定长方体的最里面的点时，
//							   // 计算其余的7个顶点 并赋值给fang
//double san[8][3];              // 定义地面为梯形的长方体
//void drawSphere(double r, int lats, int longs, double x, double y, double z) {
//	int i, j;
//	for (i = 0; i <= lats; i++) {
//		double lat0 = pi * (-0.5 + (double)(i - 1) / lats);   // M_PI
//		double z0 = sin(lat0);
//		double zr0 = cos(lat0);
//
//		double lat1 = pi * (-0.5 + (double)i / lats);
//		double z1 = sin(lat1);
//		double zr1 = cos(lat1);
//
//		glBegin(GL_QUAD_STRIP);
//		glScaled(100, 100, 100);
//		for (j = 0; j <= longs; j++) {
//			double lng = 2 * pi * (double)(j - 1) / longs;
//			double x = cos(lng);
//			double y = sin(lng);
//			glNormal3f(x * zr0, y * zr0, z0);
//			glVertex3f(zr0, zr0, z0);
//			glNormal3f(x * zr1, y * zr1, z1);
//			glVertex3f(zr1, zr1, z1);
//		}
//		glEnd();
//	}
//}
//void cons(double x, double y, double z, double x1, double y1, double z1) {
//	san[0][0] = x;
//	san[0][1] = y;
//	san[0][2] = z;     //  第0个点
//
//	san[1][0] = x;
//	san[1][1] = y;
//	san[1][2] = z + z1;   //  第1个点
//
//	san[4][0] = x;
//	san[4][1] = y + y1;
//	san[4][2] = z;     //  第4个点
//
//	san[5][0] = x;
//	san[5][1] = y + y1;
//	san[5][2] = z + z1 / 2;      //  第5个点
//	for (int i = 0; i < 3; i++) {
//		if (i == 0) {
//			san[3][i] = san[0][i] + x1;
//			san[2][i] = san[1][i] + x1;
//			san[6][i] = san[4][i] + x1;
//			san[7][i] = san[5][i] + x1;
//		}
//		else {
//			san[3][i] = san[0][i];
//			san[2][i] = san[1][i];
//			san[6][i] = san[4][i];
//			san[7][i] = san[5][i];
//		}
//	}
//}
//void constract(double x, double y, double z, double x1, double y1, double z1) {
//	fang[0][0] = x;
//	fang[0][1] = y;
//	fang[0][2] = z;        //  第0个点
//
//	fang[1][0] = x;
//	fang[1][1] = y;
//	fang[1][2] = z + z1;     //  第一个点
//
//	fang[2][0] = x + x1;
//	fang[2][1] = y;
//	fang[2][2] = z + z1;     //  第二个点
//
//	fang[3][0] = x + x1;
//	fang[3][1] = y;
//	fang[3][2] = z;        //  第三个点
//	for (int i = 0; i < 4; i++) {  // for()循环来完成其余的四个点
//		for (int j = 0; j < 3; j++) {
//			if (j == 1)
//				fang[i + 4][j] = fang[i][j] + y1;
//			else
//				fang[i + 4][j] = fang[i][j];
//		}
//	}
//}
//void build2() {
//	glBegin(GL_POLYGON);
//	//glColor3f(red);
//	glNormal3f(0.0, -1.0, 0.0);
//	glVertex3f(san[0][0], san[0][1], san[0][2]);
//	glVertex3f(san[1][0], san[1][1], san[1][2]);
//	glVertex3f(san[2][0], san[2][1], san[2][2]);
//	glVertex3f(san[3][0], san[3][1], san[3][2]);
//	glEnd();   //     下底
//
//	glBegin(GL_POLYGON);
//	//glColor3f(green);
//	glNormal3f(-1.0, 0.0, 0.0);
//	glVertex3f(san[1][0], san[1][1], san[1][2]);
//	glVertex3f(san[0][0], san[0][1], san[0][2]);
//	glVertex3f(san[4][0], san[4][1], san[4][2]);
//	glVertex3f(san[5][0], san[5][1], san[5][2]);
//	glEnd();   //     左面
//
//	glBegin(GL_POLYGON);
//	//glColor3f(green);
//	glNormal3f(1.0, 0.0, 0.0);
//	glVertex3f(san[7][0], san[7][1], san[7][2]);
//	glVertex3f(san[6][0], san[6][1], san[6][2]);
//	glVertex3f(san[3][0], san[3][1], san[3][2]);
//	glVertex3f(san[2][0], san[2][1], san[2][2]);
//	glEnd();   //     右面
//
//	glBegin(GL_POLYGON);
//	//glColor3f(green);
//	glNormal3f(0.0, 0.0, 1.0);
//	glVertex3f(san[5][0], san[5][1], san[5][2]);
//	glVertex3f(san[6][0], san[6][1], san[6][2]);
//	glVertex3f(san[2][0], san[2][1], san[2][2]);
//	glVertex3f(san[1][0], san[1][1], san[1][2]);
//	glEnd();   //     前面
//
//	glBegin(GL_POLYGON);
//	//glColor3f(green);
//	glNormal3f(0.0, 0.0, -1.0);
//	glVertex3f(san[0][0], san[0][1], san[0][2]);
//	glVertex3f(san[3][0], san[3][1], san[3][2]);
//	glVertex3f(san[7][0], san[7][1], san[7][2]);
//	glVertex3f(san[4][0], san[4][1], san[4][2]);
//	glEnd();   //     后面
//
//	glBegin(GL_POLYGON);
//	//glColor3f(red);
//	glNormal3f(0.0, 1.0, 0.0);
//	glVertex3f(san[4][0], san[4][1], san[4][2]);
//	glVertex3f(san[7][0], san[7][1], san[7][2]);
//	glVertex3f(san[6][0], san[6][1], san[6][2]);
//	glVertex3f(san[5][0], san[5][1], san[5][2]);
//	glEnd();   //     上面
//}
//void build() {
//	glBegin(GL_POLYGON);
//	//glColor3f(red);
//	glNormal3f(0.0, -1.0, 0.0);
//	glVertex3f(fang[0][0], fang[0][1], fang[0][2]);
//	glVertex3f(fang[1][0], fang[1][1], fang[1][2]);
//	glVertex3f(fang[2][0], fang[2][1], fang[2][2]);
//	glVertex3f(fang[3][0], fang[3][1], fang[3][2]);
//	glEnd();   //     下底
//
//	glBegin(GL_POLYGON);
//	//glColor3f(green);
//	glNormal3f(-1.0, 0.0, 0.0);
//	glVertex3f(fang[1][0], fang[1][1], fang[1][2]);
//	glVertex3f(fang[0][0], fang[0][1], fang[0][2]);
//	glVertex3f(fang[4][0], fang[4][1], fang[4][2]);
//	glVertex3f(fang[5][0], fang[5][1], fang[5][2]);
//	glEnd();   //     左面
//
//	glBegin(GL_POLYGON);
//	//glColor3f(green);
//	glNormal3f(1.0, 0.0, 0.0);
//	glVertex3f(fang[7][0], fang[7][1], fang[7][2]);
//	glVertex3f(fang[6][0], fang[6][1], fang[6][2]);
//	glVertex3f(fang[2][0], fang[2][1], fang[2][2]);
//	glVertex3f(fang[3][0], fang[3][1], fang[3][2]);
//	glEnd();   //     右面
//
//	glBegin(GL_POLYGON);
//	//glColor3f(green);
//	glNormal3f(0.0, 0.0, 1.0);
//	glVertex3f(fang[5][0], fang[5][1], fang[5][2]);
//	glVertex3f(fang[6][0], fang[6][1], fang[6][2]);
//	glVertex3f(fang[2][0], fang[2][1], fang[2][2]);
//	glVertex3f(fang[1][0], fang[1][1], fang[1][2]);
//	glEnd();   //     前面
//
//	glBegin(GL_POLYGON);
//	//glColor3f(green);
//	glNormal3f(0.0, 0.0, -1.0);
//	glVertex3f(fang[0][0], fang[0][1], fang[0][2]);
//	glVertex3f(fang[3][0], fang[3][1], fang[3][2]);
//	glVertex3f(fang[7][0], fang[7][1], fang[7][2]);
//	glVertex3f(fang[4][0], fang[4][1], fang[4][2]);
//	glEnd();   //     后面
//
//	glBegin(GL_POLYGON);
//	//glColor3f(red);
//	glNormal3f(0.0, 1.0, 0.0);
//	glVertex3f(fang[4][0], fang[4][1], fang[4][2]);
//	glVertex3f(fang[7][0], fang[7][1], fang[7][2]);
//	glVertex3f(fang[6][0], fang[6][1], fang[6][2]);
//	glVertex3f(fang[5][0], fang[5][1], fang[5][2]);
//	glEnd();   //     上面
//}
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();          //增加M矩阵
//	glRotatef(rotate_x, 1.0, 0.0, 0.0);
//	glRotatef(rotate_y, 0.0, 1.0, 0.0);
//
//	glTranslatef(-270, 0, -270);
//	glScalef(1.5, 1.5, 1.5);
//
//	//****************************增加地面底板（颜色为 绿色）********
//	glBegin(GL_POLYGON);
//	constract(0, 0, 0, 500, 10, 500);
//	glColor3f(green);
//	build();
//	//****************************增加小路（颜色  深灰色）***************************
//	glBegin(GL_POLYGON);
//	constract(0, 0, 500, 500, 10, 100);
//	glColor3f(gray);
//	build();
//	//****************************增加车库底板（颜色  深灰色）****************
//	glBegin(GL_POLYGON);
//	constract(330, 20, 250, 140, 1, 250);
//	glColor3f(gray);
//	build();
//	//****************************增加斑马线（颜色为 白色）********
//	for (int i = 0; i < 5; i++) {
//		glBegin(GL_POLYGON);
//		constract(i * 100, 10, 500 + 45, 40, 1, 10);
//		glColor3f(white);
//		build();
//	}
//	//****************************增加栅栏基座（颜色为 白色）********
//	glBegin(GL_POLYGON);
//	constract(10, 10, 10, 20, 20, 480);
//	glColor3f(white);
//	build();       //    对应于A点
//	constract(30, 10, 10, 440, 20, 20);
//	glColor3f(white);
//	build();       //    对应于B点
//	constract(470, 10, 10, 20, 20, 480);
//	glColor3f(white);
//	build();       //    对应于C点
//	constract(30, 10, 470, 100, 20, 20);
//	glColor3f(white);
//	build();       //    对应于D点
//	constract(230, 10, 470, 100, 20, 20);
//	glColor3f(white);
//	build();       //    对应于F点
//	//****************************增加栅栏柱子（颜色为 白色）********
//	glBegin(GL_POLYGON);
//	constract(10, 10, 10, 20, 50, 20);
//	glColor3f(white);
//	build();       //    对应于A点
//	glBegin(GL_POLYGON);
//	constract(470, 10, 10, 20, 50, 20);
//	glColor3f(white);
//	build();       //    对应于C点
//	glBegin(GL_POLYGON);
//	constract(230, 10, 470, 20, 50, 20);
//	glColor3f(white);
//	build();       //    对应于F点
//	glBegin(GL_POLYGON);
//	constract(10, 10, 470, 20, 50, 20);
//	glColor3f(white);
//	build();       //    对应于E点
//	glBegin(GL_POLYGON);
//	constract(470, 10, 470, 20, 50, 20);
//	glColor3f(white);
//	build();       //    对应于G点
//	glBegin(GL_POLYGON);
//	constract(310, 10, 470, 20, 50, 20);
//	glColor3f(white);
//	build();       //    对应于H点
//	glBegin(GL_POLYGON);
//	constract(110, 10, 470, 20, 50, 20);
//	glColor3f(white);
//	build();       //    对应于I点
//	//****************************增加栅栏（颜色为 深灰色）********
//	glColor3f(hgray);
//	for (int i = 35; i < 470; i += 25)
//	{
//		constract(15, 20, i, 6, 30, 6);
//		build();         //左边竖条
//	}
//	for (int i = 35; i < 470; i += 25)
//	{
//		constract(475, 20, i, 6, 30, 6);
//		build();          // 右边竖条
//	}
//	for (int i = 35; i < 470; i += 25)
//	{
//		constract(i, 20, 15, 6, 30, 6);
//		build();          // 上边横条
//	}
//	for (int i = 35; i < 110; i += 25)
//	{
//		constract(i, 20, 485, 6, 30, 6);
//		build();          // 下边横条1
//	}
//	for (int i = 250; i < 310; i += 25)
//	{
//		constract(i, 20, 485, 6, 30, 6);
//		build();          // 下边横条2
//	}
//	//****************************增加车库墙（颜色为 白色）********
//	glColor3f(white);
//	constract(320, 10, 250, 10, 100, 220);
//	build();
//	constract(460, 10, 250, 10, 100, 220);
//	build();
//	//****************************增加车库顶棚（颜色为 深灰色）********
//	glColor3f(hgray);
//	constract(320, 110, 250, 150, 10, 220);
//	build();
//	//****************************增加卧室和客厅的墙壁（颜色为 白色）********
//	glColor3f(white);
//	constract(50, 10, 50, 12, 150, 200);
//	build();     //左墙壁
//	glColor3f(white);
//	constract(438, 10, 50, 12, 150, 200);
//	build();     //右墙壁
//	glColor3f(white);
//	constract(62, 10, 50, 376, 150, 12);
//	build();     //上墙壁
//	glColor3f(white);
//	constract(62, 10, 235, 376, 50, 12);
//	build();     //下墙壁1
//	glColor3f(white);
//	constract(62, 60, 235, 50, 50, 12);
//	build();     //下墙壁2
//	glColor3f(white);
//	constract(162, 60, 235, 276, 50, 12);
//	build();     //下墙壁3
//	glColor3f(white);
//	constract(62, 110, 235, 376, 50, 12);
//	build();     //下墙壁4
//	//****************************增加卧室和客厅的玻璃（颜色为 白色）********
//	glColor4f(blue, 0.35);
//	constract(62 + 50, 60, 235, 50, 50, 12);
//	build();
//	//****************************增加车库玻璃（颜色为 深灰色）********
//	glColor4f(blue, 0.35);
//	constract(330, 22, 450, 130, 90, 10);
//	build();
//	//****************************增加房顶 （颜色 红色）************
//	glColor3f(red);
//	cons(50, 160, 140, 400, 27, 110);
//	build2();
//	cons(50, 187, 140, 400, 27, 90);
//	build2();
//	cons(50, 214, 140, 400, 27, 70);
//	build2();
//	cons(50, 241, 140, 400, 15, 50);
//	build2();
//	glColor3f(red);
//	cons(50, 160, 140, 400, 27, -110);
//	build2();
//	cons(50, 187, 140, 400, 27, -90);
//	build2();
//	cons(50, 214, 140, 400, 27, -70);
//	build2();
//	cons(50, 241, 140, 400, 15, -50);
//	build2();
//	//************************************* 门*************
//	glColor3f(men);
//	constract(230, 10, 250, 50, 100, 5);
//	build();              //门面
//	glColor3f(menba);
//	constract(235, 60, 255, 5, 5, 5);
//	build();              //门把手
//	//**************************************小路*************
//	for (int i = 0; i < 6; i++)
//	{
//		glColor3f(brown);
//		constract(235 - i * 15, 10, 250 + i * 40, 40, 2, 20);
//		build();
//	}
//	//**************************************太阳*************
//	glColor3f(gold);
//	glTranslatef(250, 400, 0);
//	glutSolidSphere(35.0, 20, 20);
//	glTranslatef(-250, -400, 0);
//	//**************************************树干*************
//	glColor3f(brown);
//	constract(60, 10, 390, 15, 70, 15);
//	build();
//	//**************************************树叶*************
//	glColor3f(hgreen);
//	glTranslatef(60, 70, 400);
//	glutSolidSphere(25.0, 20, 20);  //球1
//	glTranslatef(20, 0, 0);
//	glutSolidSphere(25.0, 20, 20);  //球2
//	glTranslatef(-10, 0, -10);
//	glutSolidSphere(25.0, 20, 20);  //球3
//	glTranslatef(0, 0, 20);
//	glutSolidSphere(25.0, 20, 20);  //球4
//	glTranslatef(0, 10, -10);
//	glutSolidSphere(25.0, 20, 20);  //球4
//
//	glFlush();  // 刷新
//	glutSwapBuffers();//还要加上swapbuffer函数
//}
//void init(void)
//{
//	GLfloat sun_direction[] = { 100.0, 100.0, 100.0, 0.0 };
//	GLfloat sun_intensity[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat ambient_intensity[] = { 0.5, 0.5, 0.5, 1.0 };
//
//	glEnable(GL_LIGHTING);              // Set up ambient light.
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_intensity);
//
//	glEnable(GL_LIGHT0);                // Set up sunlight.
//	glLightfv(GL_LIGHT0, GL_POSITION, sun_direction);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_intensity);
//
//	glEnable(GL_COLOR_MATERIAL);        // Configure glColor().
//	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//	cout << "The OpenGL version is: " << glGetString(GL_VERSION) << "\n";
//	cout << glGetString(GL_VENDOR) << "\n";
//	glLineWidth(5);
//	glClearColor(0.0, 0.0, 0.0, 0.0);      //定义背景颜色-->  black
//
//	glEnable(GL_BLEND); // 打开混合
//	glDisable(GL_DEPTH_TEST); // 关闭深度测试
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE); // 基于源象素alpha通道值的半透明混合函数
//
//	glMatrixMode(GL_PROJECTION);     // 貌似和视角有关的定义 places the camera at (0,0,0) and faces it along(0,0,-1).
//	glOrtho(-w, w, -h, h, -w, w); // specify clipping volume
//}
//void specialkeys(int key, int x, int y) {
//	if (key == GLUT_KEY_RIGHT)
//		rotate_y += 5;
//	else if (key == GLUT_KEY_LEFT)
//		rotate_y -= 5;
//	else if (key == GLUT_KEY_UP)
//		rotate_x += 5;
//	else if (key == GLUT_KEY_DOWN)
//		rotate_x -= 5;
//	glutPostRedisplay();
//}
//int main(int argc, char** argv)    //  main函数 增加鼠标和键盘事件
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(w, h);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("A House");
//	init();
//
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//	glEnable(GL_DEPTH_TEST);
//	glutDisplayFunc(display);
//	glutSpecialFunc(specialkeys);
//	glutMainLoop();
//	return 0;
//}
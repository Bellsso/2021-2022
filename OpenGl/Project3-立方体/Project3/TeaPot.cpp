//#include <stdlib.h>
//#include <GL/glut.h>
//
//float fTranslate;//整体平移因子
//float fRotate = 0.0f;//整体旋转因子
//float tRotate = 0.0f;//茶壶旋转因子
////绕x轴旋转角度
//GLfloat xRotAngle =60.0f;
////绕y轴旋转角度
//GLfloat yRotAngle = 0.0f;
//
//bool tAnim = false;//茶壶旋转
//bool bPersp = false;//渲染
//bool bAnim = false;//整体旋转
//bool bWire = false;//填充、线框
//
//int wHeight = 0;
//int wWidth = 0;
//float place[] = { 0, 0, 5 };
//float eye[] = { 0, 20, 60 };
//float center[] = { 0, 0, 0 };
//
//GLint iObjectOrPerspect = 1;
//
////菜单回调函数
//void processMenu(int value) {
//	switch (value) {
//	case 1:
//		iObjectOrPerspect = 1;
//		break;
//	case 2:
//		iObjectOrPerspect = 2;
//		break;
//	default:
//		break;
//	}
//	//重新绘制
//	glutPostRedisplay();
//}
//
////按键输入处理回调函数
//void specialKey(int key, int x, int y) {
//	if (iObjectOrPerspect == 1)
//	{
//		if (key == GLUT_KEY_UP) {
//			xRotAngle -= 5.0f;
//		}
//		else if (key == GLUT_KEY_DOWN) {
//			xRotAngle += 5.0f;
//		}
//		else if (key == GLUT_KEY_LEFT) {
//			yRotAngle -= 5.0f;
//		}
//		else if (key == GLUT_KEY_RIGHT) {
//			yRotAngle += 5.0f;
//		}
//	}
//	else
//	{
//		if (key == GLUT_KEY_UP) {
//			eye[1] += 1;
//		}
//		else if (key == GLUT_KEY_DOWN) {
//			eye[1] -= 1;
//		}
//		else if (key == GLUT_KEY_LEFT) {
//			eye[0] -= 1;
//		}
//		else if (key == GLUT_KEY_RIGHT) {
//			eye[0] += 1;
//		}
//	}
//	
//	//重新绘制
//	glutPostRedisplay();
//}
//
//void Draw_Scene()
//{
//	glPushMatrix();//当前矩阵压栈
//	glTranslatef(place[0], place[1], place[2]);//平移，放在桌面上的高度
//	glRotatef(xRotAngle, 1, 0, 0); //茶壶绕x轴旋转的角度
//	glRotatef(yRotAngle, 0, 1, 0);
//	glScalef(1.8, 1.8, 1.8);
//	glutSolidTeapot(4);//size
//	glPopMatrix();
//}
//
//void updateView(int width, int height)
//{
//	glViewport(0, 0, width, height);	// 视口变换
//
//	glMatrixMode(GL_PROJECTION);	// 设置投影模式
//	glLoadIdentity();			// 变换矩阵初始化为单位阵
//
//	float whRatio = (GLfloat)width / (GLfloat)height;
//
//	if (bPersp)
//		gluPerspective(45, whRatio, 1, 100);
//	//透视模式下，物体近大远小，参数分别为（视角，宽高比，近处，远处）
//	else
//		glOrtho(-3, 3, -3, 3, -100, 100);
//	glMatrixMode(GL_MODELVIEW);//对模型视景矩阵堆栈应用随后的矩阵
//}
//
//void myReshape(int width, int height)
//{
//	if (height == 0)
//	{
//		height = 1;
//	}
//
//	wHeight = height;
//	wWidth = width;
//	updateView(wHeight, wWidth);
//}
//
//void myIdle()
//{
//	glutPostRedisplay();
//}
//
//void myDraw()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity();//重置为单位矩阵
//	//gluLookAt定义一个视图矩阵，并与当前矩阵相乘
//	gluLookAt(eye[0], eye[1], eye[2],
//		center[0], center[1], center[2],
//		0, 1, 0);				// 场景（0，0，0）的视点中心 (0,5,50)，Y轴向上
//	//三个数组代表的分别是：相机在世界坐标中的位置
//	//相机对准的物体在世界坐标中的位置
//	//相机朝上的方向在世界坐标中的位置
//	if (bWire)
//		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//线框模式
//	else
//		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);//填充模式
//
//	glEnable(GL_DEPTH_TEST);//启用深度测试，根据坐标远近自动隐藏被遮住的物体
//	glEnable(GL_LIGHTING);//启用灯光
//	GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat light_pos[] = { 5, 5, 5, 1 };	//在Opengl中总共可以设置8个光源
//	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);//设置0号光源的位置属性
//	glLightfv(GL_LIGHT0, GL_AMBIENT, white);//设置0号光源的环境光属性
//	glEnable(GL_LIGHT0);//启用0号光源
//
//	//	glTranslatef(0.0f, 0.0f,-6.0f);		// 把对象放置再中心
//	glRotatef(fRotate, 0, 1.0f, 0);
//	glRotatef(-90, 1, 0, 0);//绕x轴逆时针90
//	glScalef(0.2, 0.2, 0.2);
//	Draw_Scene();
//
//	if (bAnim)
//		fRotate += 0.5f;//旋转
//	if (tAnim)
//		yRotAngle += 0.5f;
//
//	glutSwapBuffers();//交换缓冲区
//}
//
//int main(int argc, char *argv[])
//{
//		//菜单
//	GLint iMainMenu;
//	GLint iObjectOrPerspectMenu;
//	glutInit(&argc, argv);//对glut函数库进行初始化
////指定glutCreateWindow函数将要创建的窗口显示模式，RGB 深度缓存，双缓存模式
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
//	glutInitWindowSize(480, 480);//设置窗口大小
//	int windowHandle = glutCreateWindow("茶壶三维显示与观察");
//	glutDisplayFunc(myDraw);//指定当前窗口需要重新绘制时调用的函数
//	glutReshapeFunc(myReshape);	//当注册窗口大小改变时回调函数
//	//glutKeyboardFunc(myKey);//为当前窗口指定键盘回调
//	//设置按键输入处理回调函数
//	glutSpecialFunc(specialKey);
//	//菜单回调函数
//	iObjectOrPerspectMenu = glutCreateMenu(processMenu);
//	//添加菜单
//	iObjectOrPerspectMenu = glutCreateMenu(processMenu);
//	glutAddMenuEntry("Object rotate", 1);
//	glutAddMenuEntry("Perspective change", 2);
//	iMainMenu = glutCreateMenu(processMenu);
//	glutAddSubMenu("Object rotate Or Perspective change", iObjectOrPerspectMenu);
//	//将菜单榜定到鼠标右键上
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//	glutIdleFunc(myIdle);//可以执行连续动画
//
//	glutMainLoop();//进入glut时间处理循环，永远不会返回
//	return 0;
//}

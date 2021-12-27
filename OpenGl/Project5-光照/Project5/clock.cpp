//#include<cstdio>
//
//#include<time.h>
//#include<math.h>
//#include <GL/glut.h>
//#pragma warning( disable : 4996 )
////sleep ,gluttimefunc
//struct tm* localTime;
//int hour, minute, second;
//double pi = 3.1415926;
//
//void gettime() {//读取时间到全局变量
//	time_t curTime;
//	time(&curTime);
//	localTime = localtime(&curTime);
//	hour = localTime->tm_hour;
//	minute = localTime->tm_min;
//	second = localTime->tm_sec;
//}
//
//void display_watch()//绘制钟表
//{
//
//	//可见到的坐标系为x,y轴线[-1,1]的正方形区域
//
//	glClear(GL_COLOR_BUFFER_BIT);
//	glEnable(GL_LINE_SMOOTH);
//
//	double r = 0.8, r2 = 0.7, rat = 0, ww = 7, tim = 360;
//	double rr1 = 0.4, rr2 = 0.64, rr3 = 0.75, w1 = 10, w2 = 8, w3 = 4;
//
//
//	glColor3f(0.0, 1.0, 0.4);
//	glBegin(GL_POLYGON);//绘制钟外层圆形
//	for (int q = 1; q <= tim; q++) {
//		glVertex3f(r*cos(rat), r*sin(rat), 0);
//		rat += pi / tim * 2;
//	}
//	glEnd();
//
//	glColor3f(0.0, 0.8, 0.7);
//	glBegin(GL_POLYGON);//绘制钟内层圆形
//	for (int q = 1; q <= tim; q++) {
//		glVertex3f(r2*cos(rat), r2*sin(rat), 0);
//		rat += pi / tim * 2;
//	}
//	glEnd();
//
//	glLineWidth(ww);//修改线宽，绘制刻度
//	glColor3f(0.0, 0.1, 0.1);
//	glBegin(GL_LINES);
//	for (int q = 1; q <= 12; q++) {
//		glVertex3f((r2 - 0.1)*cos(rat), (r2 - 0.1)*sin(rat), 0);
//		glVertex3f(r*cos(rat), r*sin(rat), 0);
//		rat += pi / 6;
//	}
//	glEnd();
//
//
//	rat = pi / 2 - pi * 2 / 12 * (hour + minute / 60.0);//改变线宽，绘制时针
//	glLineWidth(w1);
//	glColor3f(1.0, 1.0, 1.0);
//	glBegin(GL_LINES);
//	glVertex3f(0, 0, 0);
//	glVertex3f(rr1*cos(rat), rr1*sin(rat), 0);
//	glEnd();
//
//	rat = pi / 2 - pi * 2 * (minute / 60.0 + second / 60.0 / 60);//改变线宽，绘制分针
//	glLineWidth(w2);
//	glColor3f(1.0, 1.0, 1.0);
//	glBegin(GL_LINES);
//	glVertex3f(0, 0, 0);
//	glVertex3f(rr2*cos(rat), rr2*sin(rat), 0);
//	glEnd();
//
//	rat = pi / 2 - pi * 2 * (second / 60.0);//改变线宽，绘制秒针
//	glLineWidth(w3);
//	glColor3f(1.0, 1.0, 1.0);
//	glBegin(GL_LINES);
//	glVertex3f(0, 0, 0);
//	glVertex3f(rr3*cos(rat), rr3*sin(rat), 0);
//	glEnd();
//
//	//printf("%d %d %d\n",hour,minute,second);
//	glutSwapBuffers();
//
//}
//
//void idle(void)//读取时间到全局变量，重绘钟表
//{
//
//	gettime();
//	glutPostRedisplay();
//}
//
//int main(int argc, char* argv[])
//{
//
//	glutInit(&argc, argv);
//
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(666, 666);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("watch");
//
//	glutDisplayFunc(display_watch);
//
//	//利用idle操作更新时钟
//	glutIdleFunc(idle);
//
//	glutMainLoop();
//
//
//	return 0;
//}
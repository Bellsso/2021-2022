#include <GL\glut.h>

void myInit(void)
{
	GLfloat light_position[] = { 5.0,8.0,5.0,1.0 };
	GLfloat white_light[] = { 1.0,1.0,1.0,1.0 };
	GLfloat ambient_light[] = { 0.3,0.3,0.3,1.0 };
	GLfloat Light_Model_Ambient[] = { 0.2,0.2,0.2,1.0 };

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Light_Model_Ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();//将矩阵归一化回原样
	GLfloat mat_ambient1[] = { 0.32, 0.1, 0.42, 1.0 };
	GLfloat mat_diffuse1[] = { 0.12, 0.01, 0.42, 0.5 };
	GLfloat mat_specular1[] = { 0.45, 0.0, 0.2, 0.5 };
	GLfloat mat_shininess1[] = { 80 }; //材质RGBA镜面指数，数值在0～128范围内
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);
	glTranslatef(-0.5f, -0.5f, -6.0f);//平移至左侧
	//glRotatef(30, 1.0f, 1.0f, 0.0f);//旋转一个角度
	glutSolidSphere(0.5, 25, 20);

	glLoadIdentity();//将矩阵归一化回原样

	GLfloat mat_ambient2[] = { 0.45, 0.1, 0.0, 0.5 };
	GLfloat mat_diffuse2[] = { 0.32, 0.32, 0.32, 0.5 };
	GLfloat mat_specular2[] = { 1.0, 1.0, 0.1, 0.5 };
	GLfloat mat_shininess2[] = { 60 }; //材质RGBA镜面指数，数值在0～128范围内
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular2);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess2);	
	glTranslatef(0.5f, -0.5f, -6.0f);//平移至右侧
	//glRotatef(30, 1.0f, 1.0f, 0.0f);//旋转一个角度
	glutSolidCube(1);

	glLoadIdentity();//将矩阵归一化回原样
	
	GLfloat mat_ambient3[] = { 0.45, 0.1, 0.0, 0.5 };
	GLfloat mat_diffuse3[] = { 0.45, 0.86, 0.05, 0.5 };
	GLfloat mat_specular3[] = { 1.0,1.0,1.0,1.0 };
	GLfloat mat_shininess3[] = { 30 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse3);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular3);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess3);
	glTranslatef(0.5f, 0.5f, -6.0f);//平移至上侧
	glRotatef(30, 1.0f, 1.0f, 0.0f);//旋转一个角度
	//glutSolidSphere(0.5, 25, 20);
	glutSolidTeapot(0.5);
	glFlush();
}

void myReshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-1.5, 1.5, -1.5*(GLfloat)h / (GLfloat)w,
			1.5*(GLfloat)h / (GLfloat)w, -10.1, 10.0);
	else
		glOrtho(-1.5*(GLfloat)w / (GLfloat)h,
			1.5*(GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	myInit();
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutMainLoop();
	return 0;
}
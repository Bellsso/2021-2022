//#include <stdlib.h>
//#include <GL/glut.h>
//
//float fTranslate;//����ƽ������
//float fRotate = 0.0f;//������ת����
//float tRotate = 0.0f;//�����ת����
////��x����ת�Ƕ�
//GLfloat xRotAngle =60.0f;
////��y����ת�Ƕ�
//GLfloat yRotAngle = 0.0f;
//
//bool tAnim = false;//�����ת
//bool bPersp = false;//��Ⱦ
//bool bAnim = false;//������ת
//bool bWire = false;//��䡢�߿�
//
//int wHeight = 0;
//int wWidth = 0;
//float place[] = { 0, 0, 5 };
//float eye[] = { 0, 20, 60 };
//float center[] = { 0, 0, 0 };
//
//GLint iObjectOrPerspect = 1;
//
////�˵��ص�����
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
//	//���»���
//	glutPostRedisplay();
//}
//
////�������봦��ص�����
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
//	//���»���
//	glutPostRedisplay();
//}
//
//void Draw_Scene()
//{
//	glPushMatrix();//��ǰ����ѹջ
//	glTranslatef(place[0], place[1], place[2]);//ƽ�ƣ����������ϵĸ߶�
//	glRotatef(xRotAngle, 1, 0, 0); //�����x����ת�ĽǶ�
//	glRotatef(yRotAngle, 0, 1, 0);
//	glScalef(1.8, 1.8, 1.8);
//	glutSolidTeapot(4);//size
//	glPopMatrix();
//}
//
//void updateView(int width, int height)
//{
//	glViewport(0, 0, width, height);	// �ӿڱ任
//
//	glMatrixMode(GL_PROJECTION);	// ����ͶӰģʽ
//	glLoadIdentity();			// �任�����ʼ��Ϊ��λ��
//
//	float whRatio = (GLfloat)width / (GLfloat)height;
//
//	if (bPersp)
//		gluPerspective(45, whRatio, 1, 100);
//	//͸��ģʽ�£��������ԶС�������ֱ�Ϊ���ӽǣ���߱ȣ�������Զ����
//	else
//		glOrtho(-3, 3, -3, 3, -100, 100);
//	glMatrixMode(GL_MODELVIEW);//��ģ���Ӿ������ջӦ�����ľ���
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
//	glLoadIdentity();//����Ϊ��λ����
//	//gluLookAt����һ����ͼ���󣬲��뵱ǰ�������
//	gluLookAt(eye[0], eye[1], eye[2],
//		center[0], center[1], center[2],
//		0, 1, 0);				// ������0��0��0�����ӵ����� (0,5,50)��Y������
//	//�����������ķֱ��ǣ���������������е�λ��
//	//�����׼�����������������е�λ��
//	//������ϵķ��������������е�λ��
//	if (bWire)
//		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//�߿�ģʽ
//	else
//		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);//���ģʽ
//
//	glEnable(GL_DEPTH_TEST);//������Ȳ��ԣ���������Զ���Զ����ر���ס������
//	glEnable(GL_LIGHTING);//���õƹ�
//	GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat light_pos[] = { 5, 5, 5, 1 };	//��Opengl���ܹ���������8����Դ
//	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);//����0�Ź�Դ��λ������
//	glLightfv(GL_LIGHT0, GL_AMBIENT, white);//����0�Ź�Դ�Ļ���������
//	glEnable(GL_LIGHT0);//����0�Ź�Դ
//
//	//	glTranslatef(0.0f, 0.0f,-6.0f);		// �Ѷ������������
//	glRotatef(fRotate, 0, 1.0f, 0);
//	glRotatef(-90, 1, 0, 0);//��x����ʱ��90
//	glScalef(0.2, 0.2, 0.2);
//	Draw_Scene();
//
//	if (bAnim)
//		fRotate += 0.5f;//��ת
//	if (tAnim)
//		yRotAngle += 0.5f;
//
//	glutSwapBuffers();//����������
//}
//
//int main(int argc, char *argv[])
//{
//		//�˵�
//	GLint iMainMenu;
//	GLint iObjectOrPerspectMenu;
//	glutInit(&argc, argv);//��glut��������г�ʼ��
////ָ��glutCreateWindow������Ҫ�����Ĵ�����ʾģʽ��RGB ��Ȼ��棬˫����ģʽ
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
//	glutInitWindowSize(480, 480);//���ô��ڴ�С
//	int windowHandle = glutCreateWindow("�����ά��ʾ��۲�");
//	glutDisplayFunc(myDraw);//ָ����ǰ������Ҫ���»���ʱ���õĺ���
//	glutReshapeFunc(myReshape);	//��ע�ᴰ�ڴ�С�ı�ʱ�ص�����
//	//glutKeyboardFunc(myKey);//Ϊ��ǰ����ָ�����̻ص�
//	//���ð������봦��ص�����
//	glutSpecialFunc(specialKey);
//	//�˵��ص�����
//	iObjectOrPerspectMenu = glutCreateMenu(processMenu);
//	//��Ӳ˵�
//	iObjectOrPerspectMenu = glutCreateMenu(processMenu);
//	glutAddMenuEntry("Object rotate", 1);
//	glutAddMenuEntry("Perspective change", 2);
//	iMainMenu = glutCreateMenu(processMenu);
//	glutAddSubMenu("Object rotate Or Perspective change", iObjectOrPerspectMenu);
//	//���˵��񶨵�����Ҽ���
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//	glutIdleFunc(myIdle);//����ִ����������
//
//	glutMainLoop();//����glutʱ�䴦��ѭ������Զ���᷵��
//	return 0;
//}

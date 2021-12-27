#include <GLFW/glfw3.h>
#include<iostream>
#include<vector>
#include<cmath>

#define WIDTH 800.f
#define HEIGHT 800.f
using namespace std;

void drawPoint(double x,double y)
{
	glPointSize(2.0f);
	glBegin(GL_POINTS);

	glColor3f(0.0, 1.0, 0.0);    // Red
	glVertex2f(x, y);
	glEnd();
}

void drawLint()
{
	glLineWidth(2);//设置线段宽度
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-1, -1); //定点坐标范围
	glVertex2f(1, 0);
	glEnd();
}

void BresenhamLine(double x0, double y0, double x1, double y1)
{
	x0 = x0 * 1000;
	y0 = y0 * 1000;
	x1 = x1 * 1000;
	y1 = y1 * 1000;
	double x, y, dx, dy, d, d1, d2;
	dx = x1 - x0;
	dy = y1 - y0;
	d = 2 * dy - dx;
	d1 = 2 * dy;
	d2 = 2 * (dy - dx);
	x = x0;
	y = y0;
	drawPoint(x/1000, y/1000);
	while (x < x1)
	{
		//cout << x << y;
		x++;
		if (d < 0)
			d += d1;
		else
		{
			y += 1;
			d += d2;
		}
		drawPoint(x/1000, y/1000);
	}
}



int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit()) return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(WIDTH, HEIGHT, "Bresemham", NULL, NULL);
	glfwSetWindowPos(window, 600, 200);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);

		// draw here
		drawLint();
		//drawPoint(0, 0);
		BresenhamLine(-1, -0.5, 1, 0.5);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

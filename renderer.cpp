#include "renderer.h"

#include <math.h>
#include <GL/glu.h>

#define PI 3.14159265359f
#define DEG2RAD(x) ((x)*0.01745331111)
#define RAD2DEG(x) ((x)*57.2957795131)

Renderer::Renderer(StewartPlatformSimulator *self, QWidget *widget)
	: Painter(widget)
{
	this->self = self;
	setGeometry(QRect(0, 0, widget->width(), widget->height()));
	surround = false;

	m_range = 4.0f;
	m_rotX = 0.0f;
	m_rotY = 0.0f; 
	m_rotZ = 0.0f;

	initializeRendererCLPOS();
}

void Renderer::initializeGL()
{
	//initializeOpenGLFunctions();
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glShadeModel(GL_SMOOTH);							// set shade smooth
	glClearDepth(1.0);									// set depth buffering (?)
	glEnable(GL_DEPTH_TEST);							// depth test
	//glEnable(GL_CULL_FACE);
	glDepthFunc(GL_LEQUAL);								// <=
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// perspective control
}

void Renderer::resizeGL(GLint w, GLint h)
{
	glViewport(0, 0, w, h);											// reset the current viewport
	glMatrixMode(GL_PROJECTION);									// select the projection matrix
	glLoadIdentity();												// reset the projection matrix

	//set the size of viewport
	gluPerspective(45.0, (GLdouble)w / (GLdouble)h, 0.1, 100.0);	// (angle of perspective, aspect ratio, nearest, farthest)
	glMatrixMode(GL_MODELVIEW);										// select the model-view matrix
	glLoadIdentity();												// reset the model-view matrix
}

void Renderer::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, width(), height());
	glLoadIdentity();

	glOrtho(-m_range, m_range, -m_range, m_range, -10.0f, 10.0f);
	glTranslatef(0.0f, 0.0f, 10.0f);
	glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 0.0f, 0.0f, 1.0f);

	glRotatef(m_rotX, 1.0f, 0.0f, 0.0f);
	glRotatef(m_rotY, 0.0f, cos(DEG2RAD(m_rotX)), -sin(DEG2RAD(m_rotX)));
	//glRotatef(m_rotY, 0.0f, 1.0f, 0.0f);
	glRotatef(m_rotZ, 0.0f, 0.0f, 1.0f);
	m_rotZ += surroundspeed;

	draw_axis();
	draw_axis(vec3(POS[0], POS[1], POS[2]), POS[5], POS[4], POS[3]);

	vec3 colorB(0.2f, 0.2f, 0.4f);
	vec3 colorP(0.4f, 0.4f, 0.8f);

	draw_polygon_color(B, 6, colorB);
	draw_polygon_color(P, 6, colorP);

	draw_Cylinders();


	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0.4, 0.4, 0.81, 0.3);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 6; i++) {
		glVertex3f(OriP[i].x, OriP[i].y, OriP[i].z);
	}
	glEnd();

}

void Renderer::draw_Cylinders()
{
	float L, S;
	vec3 CLm;
	
	vec3 colorL(0.0f, 0.1f, 0.0f);
	vec3 colorS(1.0f, 1.0f, 0.0f);
	for (int i = 0; i < 6; i++) {
		CLm = P[i] - B[i];
		L = CLm.norm2();
		CLm *= (self->spk.Lengthsmin / L);
		CLm = B[i] + CLm;
		S = (P[i]- CLm).norm2();

		colorL.x += 0.15f;
		colorS.z = (self->spk.stroke - S < 1e-6) ? 1 : 0;
		draw_line(B[i], CLm, colorL, 8.0f);
		draw_line(CLm, P[i], colorS, 8.0f);
	}
}

void Renderer::mousePressEvent(QMouseEvent * ev)
{
	m_mouseButton = ev->button();
	m_mouse = ev->pos();
}

void Renderer::mouseMoveEvent(QMouseEvent * ev)
{
	if (m_mouseButton == Qt::LeftButton)
	{
		if (ev->pos().y() > m_mouse.y())
		{
			m_rotY += 2.0;
		}
		else if (ev->pos().y() < m_mouse.y())
		{
			m_rotY -= 2.0;
		}
		if (ev->pos().x() > m_mouse.x())
		{
			m_rotX += 2.0;
		}
		else if (ev->pos().x() < m_mouse.x())
		{
			m_rotX -= 2.0;
		}
		m_mouse = ev->pos();
	}
}

void Renderer::wheelEvent(QWheelEvent * ev)
{
	if (ev->angleDelta().ry() > 0)
		m_range *= 0.9;
	else if (ev->angleDelta().ry() < 0)
		m_range /= 0.9;
}

void Renderer::switchSurroundViewport()
{
	surround = !surround;
	if (surround) surroundspeed = 0.5f;
	else surroundspeed = 0.0f;
}

void Renderer::revertViewport()
{
	m_rotX -= m_rotX;
	m_rotY -= m_rotY;
	m_rotZ -= m_rotZ;
	m_range = 4.0f;
}

void Renderer::initializeRendererCLPOS()
{
	double thetaB = self->spk.angleB;
	double thetaP = self->spk.angleP;
	double rP = self->spk.radiusP;
	double rB = self->spk.radiusB;
	double lmed = self->Lengthsmedian / 1000;
	double z = self->single_z;

	for (int i = 0; i < 6; i++) CL[i] = lmed;
	for (int i = 0; i < 6; i++) POS[i] = 0.0f;
	POS[2] = z;

	for (int i = 0; i < 6; i++) {
		B[i].x = mtx_get_value(&self->spk.parametersB, 0, i);
		B[i].y = mtx_get_value(&self->spk.parametersB, 1, i);
		B[i].z = 0.0f;
		P[i].x = mtx_get_value(&self->spk.parametersP, 0, i);
		P[i].y = mtx_get_value(&self->spk.parametersP, 1, i);
		P[i].z = z;
	}

	for (int i = 0; i < 6; i++) {
		OriP[i].x = P[i].x;
		OriP[i].y = P[i].y;
		OriP[i].z = P[i].z;
	}
}

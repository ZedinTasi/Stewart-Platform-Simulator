#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "StewartPlatformSimulator.h"
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLTexture>

#include "painter.h"
#include "mtx.h"

#include <QWidget>
#include <QImage>
#include <Qtimer>
#include <QMouseEvent>
#include <QWheelEvent>

class StewartPlatformSimulator;

class Renderer : public Painter
{
	friend class StewartPlatformSimulator;
	Q_OBJECT

public:
	explicit Renderer(StewartPlatformSimulator *self, QWidget *widget);

	void mousePressEvent(QMouseEvent * ev);
	void mouseMoveEvent(QMouseEvent * ev);
	void wheelEvent(QWheelEvent *ev);

	void switchSurroundViewport();

	void revertViewport();

	double CL[6];
	// posture. x,y,z:meters. a,b,c:degrees
	double POS[6];
	void initializeRendererCLPOS();

	double surroundspeed = 0.0f;

signals:

	public slots:

protected:
	void initializeGL();
	void resizeGL(GLint w ,GLint h);
	void paintGL();

private:
	StewartPlatformSimulator *self;

	bool surround;

	double m_range;
	double m_rotX, m_rotY, m_rotZ;
	QPoint m_mouse;
	Qt::MouseButton m_mouseButton;

	double lamdaBi;
	double lamdaPi;

	vec3 B[6];
	vec3 P[6];
	vec3 OriP[6];

	void draw_Cylinders();

};

#endif
#pragma once
#ifndef _PAINTER_H_
#define _PAINTER_H_

#include <QOpenGLWidget>
//#include <QtOpenGL/QGLWidget>
#include "mtx.h"
#include <GL/glu.h>

class Painter : public QOpenGLWidget
{
	Q_OBJECT

public:
	Painter(QWidget *parent);
	~Painter();

	void draw_point(vec3 v1, vec3 color, float size);
	void draw_line(vec3 v1, vec3 v2, vec3 color, float lwidth);
	void draw_tri(vec3 v1, vec3 v2, vec3 v3, vec3 color1);
	void draw_tri(vec3 v1, vec3 v2, vec3 v3, vec3 color1, vec3 color2);
	void draw_rect_line(vec3 v1, vec3 v2, vec3 v3, vec3 v4, vec3 color, float lwidth);
	void draw_rect_plane(vec3 v1, vec3 v2, vec3 v3, vec3 v4, vec3 color);
	void draw_box(vec3 v1, vec3 v2, vec3 color, float lwidth);
	void draw_circle(vec3 v0, float r, vec3 color, float lwidth);
	void draw_polygon(vec3 *v, int num, vec3 color, float lwidth);
	void draw_polygon_color(vec3 *v, int num, vec3 color);

	void draw_axis();
	void draw_axis(vec3 v, double rotx, double roty, double rotz);

};


#endif
#include "Painter.h"
#define PI 3.14159265359f
#include <math.h>

Painter::Painter(QWidget *parent)
	: QOpenGLWidget(parent)
{
}

Painter::~Painter()
{
}

//void Painter::render_text(double x, double y, double z, const QString &str)
//{
//	QFont font("Helvetica", 10);
//	QPainter painter(this);
//	painter.setFont(font);
//	//QFontMetrics fm = painter.fontMetrics();
//
//	painter.drawText(x, y, str);
//}

void Painter::draw_point(vec3 v1, vec3 color, float size)
{
	glColor3f(color.x, color.y, color.z);
	//qglColor(color);
	glPointSize(size);
	glBegin(GL_POINTS);
	glVertex3f(v1.x, v1.y, v1.z);
	glEnd();
}

void Painter::draw_line(vec3 v1, vec3 v2, vec3 color, float lwidth)
{
	glColor3f(color.x, color.y, color.z);
	glLineWidth(lwidth);

	glBegin(GL_LINES);
	glVertex3f(v1.x, v1.y, v1.z);
	glVertex3f(v2.x, v2.y, v2.z);
	glEnd();
}

void Painter::draw_tri(vec3 v1, vec3 v2, vec3 v3, vec3 color)
{
	glColor3f(color.x, color.y, color.z);

	glBegin(GL_TRIANGLES);
	glVertex3f(v1.x, v1.y, v1.z);
	glVertex3f(v2.x, v2.y, v2.z);
	glVertex3f(v3.x, v3.y, v3.z);
	glEnd();

	glDisable(GL_TEXTURE_2D);

}

void Painter::draw_tri(vec3 v1, vec3 v2, vec3 v3, vec3 color1, vec3 color2)
{
	glColor3f(color1.x, color1.y, color1.z);

	glBegin(GL_TRIANGLES);
	glVertex3f(v1.x, v1.y, v1.z);
	glVertex3f(v2.x, v2.y, v2.z);
	glVertex3f(v3.x, v3.y, v3.z);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glColor3f(color2.x, color2.y, color2.z);

	glBegin(GL_TRIANGLES);
	glVertex3f(v2.x, v2.y, v2.z);
	glVertex3f(v1.x, v1.y, v1.z);
	glVertex3f(v3.x, v3.y, v3.z);
	glEnd();
}

void Painter::draw_rect_line(vec3 v1, vec3 v2, vec3 v3, vec3 v4, vec3 color, float lwidth)
{
	draw_line(v1, v2, color, lwidth);
	draw_line(v2, v3, color, lwidth);
	draw_line(v3, v4, color, lwidth);
	draw_line(v4, v1, color, lwidth);
}

void Painter::draw_rect_plane(vec3 v1, vec3 v2, vec3 v3, vec3 v4, vec3 color)
{
	glColor3f(color.x, color.y, color.z);
	glBegin(GL_QUADS);
	glVertex3f(v1.x, v1.y, v1.z);
	glVertex3f(v2.x, v2.y, v2.z);
	glVertex3f(v3.x, v3.y, v3.z);
	glVertex3f(v4.x, v4.y, v4.z);
	glEnd();
}

void Painter::draw_box(vec3 v1, vec3 v2, vec3 color, float lwidth)
{
	vec3 v[8];
	for (int i = 0; i < 4; i++)
	{
		v[i] = v1;
		v[i + 4] = v2;
	}
	v[1].z = v2.z; v[2].x = v2.x;
	v[3].x = v2.x; v[3].z = v2.z;
	v[4].z = v1.z; v[4].x = v1.x;
	v[5].x = v1.x; v[6].z = v1.z;

	draw_rect_line(v[0], v[1], v[3], v[2], color, lwidth);
	draw_rect_line(v[1], v[5], v[7], v[3], color, lwidth);
	draw_rect_line(v[0], v[4], v[6], v[2], color, lwidth);
	draw_rect_line(v[4], v[6], v[7], v[5], color, lwidth);

}

void Painter::draw_circle(vec3 v0, float r, vec3 color, float lwidth)
{
	vec3 v1, v2;
	int n = (int)(r * 2 * PI);
	v1.x = r;
	v1.y = 0.0f;
	v1.z = 0.0f;
	for (int k = 1; k < n; k++) {
		v2 = v1;
		v1.x = r * cos(2 * PI*k / n);
		v1.y = r * sin(2 * PI*k / n);
		v1.z = 0.0f;
		draw_line(v1, v2, color, lwidth);
	}
}

void Painter::draw_polygon(vec3 *v, int num, vec3 color, float lwidth)
{
	draw_line(v[0], v[num - 1], color, lwidth);
	for (int k = 0; k < num - 1; k++) {
		draw_line(v[k], v[k + 1], color, lwidth);
	}
}

void Painter::draw_polygon_color(vec3 * v, int num, vec3 color)
{
	glColor3f(color.x, color.y, color.z);
	glBegin(GL_POLYGON);
	for (int k = 0; k < num; k++) {
		glVertex3f(v[k].x, v[k].y, v[k].z);
	}
	glEnd();
}

void Painter::draw_axis()
{
	vec3 Ori(0.0f, 0.0f, 0.0f);
	vec3 x_unit(.2f, 0.0f, 0.0f);
	vec3 y_unit(0.0f, -.2f, 0.0f);
	vec3 z_unit(0.0f, 0.0f, .2f);
	draw_line(Ori, x_unit, vec3(1.0, 0.0, 0.0), 4);
	draw_line(Ori, y_unit, vec3(0.0, 1.0, 0.0), 4);
	draw_line(Ori, z_unit, vec3(0.0, 0.0, 1.0), 4);
}

void Painter::draw_axis(vec3 v, double rotx, double roty, double rotz)
{
	vec3 x_unit = vec3_rotate(vec3(.2f, 0.0f, 0.0f), rotx, roty, rotz);
	vec3 y_unit = vec3_rotate(vec3(0.0f, -.2f, 0.0f), rotx, roty, rotz);
	vec3 z_unit = vec3_rotate(vec3(0.0f, 0.0f, .2f), rotx, roty, rotz);

	draw_line(v, v + x_unit, vec3(1.0, 0.0, 0.0), 4);
	draw_line(v, v + y_unit, vec3(0.0, 1.0, 0.0), 4);
	draw_line(v, v + z_unit, vec3(0.0, 0.0, 1.0), 4);

}

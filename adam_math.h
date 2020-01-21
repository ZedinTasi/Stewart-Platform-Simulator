#pragma once
#ifndef _ADAM_MATH_H_
#define _ADAM_MATH_H_

#define PI 3.14159265359
#define DEG2RAD(x) ((x)*0.01745329251)
#define RAD2DEG(x) ((x)*57.2957795131)

#include <stdlib.h>
#include <time.h>
#include <math.h>

template <typename T> int sgn(T val) {
	return (T(0) <val) - (val <T(0));
}

template <typename T> T MAX(T a, T b) {
	return (a > b) ? a : b;
}
template <typename T> T MIN(T a, T b) {
	return (a > b) ? b : a;
}

double random_uniform();
double random_uniform(double a, double b);

double random_normal();
double random_normal(double mean, double var);



#endif //_ADAM_MATH_H_
#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_StewartPlatformSimulator.h"

#include "renderer.h"
#include "stewart_platform_kinematics.h"

#include <QDesktopWidget>
#include <QSlider>
#include <QLabel>
#include <QTimer>
#include <QLineEdit>
#include <QValidator>

#include <QKeyEvent>

class Renderer;
class StewartPlatformSimulator : public QMainWindow
{
	friend class Renderer;
	Q_OBJECT

public:
	StewartPlatformSimulator(QWidget *parent = Q_NULLPTR);

	public slots:

	void SLOT_CL2L();
	void SLOT_setSliderValueByLineEdit(); 
	void SLOT_setPlatformParametersByLineEdit();
	void SLOT_UseKeyOff();

	void draw();

protected:
	double angleP = 109.007266910599f;
	double angleB = 8.53112053424833f;
	double radiusP = 939.60275858147f;
	double radiusB = 1210.01377400165f;
	double Lengthsmin = 1220;
	double stroke = 324;
	double Lengthsmax = 1544;
	double Lengthsmedian;
	double single_z;

	SPK spk;

	void connectGUIobjects();
	void determineSingleZ();
	void initializeGuiCLSliders();
	void initializeGuiPOSTextBody();
	void initializeGuiPlatformParametersTextBody();

	void updateGuiCLPOSText();

	//while changing the cylinders lengths, the simulator will calculate the new platform posture, and then calculate each vector Pi to render.
	void calculateCL2POS(double CL[6], double POS[6]);

	//while changing the posture, the simulator will calculate each vector Pi to render, and calculate the new platform cylinders length.
	void calculatePOS2CL(double POS[6], double CL[6]);

	void changePOSByKeyPress(int i, double val);

	void keyPressEvent(QKeyEvent *ev);

private:
	Ui::StewartPlatformClass ui;

	QOpenGLWidget *wd;

	bool usekey;

	Renderer *m_renderer;
	QTimer *m_timer;

	QSlider *m_slider[6];

	QLineEdit *m_text_body_CL[6];
	QLineEdit *m_text_body_POS[6];
	QLineEdit *m_text_body_platform_parameters[6];


};

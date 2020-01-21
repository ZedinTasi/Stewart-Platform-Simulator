#include "StewartPlatformSimulator.h"


StewartPlatformSimulator::StewartPlatformSimulator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	SPK_new(&spk, angleP, angleB, radiusP, radiusB, Lengthsmin, stroke);
	determineSingleZ();
	connectGUIobjects();

	m_renderer = new Renderer(this, ui.renderer);

	m_timer = new QTimer(this);
	m_timer->setSingleShot(false);
	m_timer->setInterval(1);

	m_renderer->initializeRendererCLPOS();
	initializeGuiCLSliders();
	initializeGuiPOSTextBody();
	initializeGuiPlatformParametersTextBody();

	connect(m_timer, SIGNAL(timeout()), this, SLOT(draw()));
	m_timer->start(40);
	usekey = false;

	for (int i = 0; i < 6; i++) {
		connect(m_slider[i], SIGNAL(sliderPressed()), this, SLOT(SLOT_UseKeyOff()));
		connect(m_slider[i], SIGNAL(valueChanged(int)), this, SLOT(SLOT_CL2L()));
		connect(m_text_body_CL[i], SIGNAL(editingFinished()), this, SLOT(SLOT_setSliderValueByLineEdit()));
		connect(m_text_body_platform_parameters[i], SIGNAL(editingFinished()), this, SLOT(SLOT_setPlatformParametersByLineEdit()));
		
	}
}

void StewartPlatformSimulator::SLOT_CL2L()
{
	if (usekey)return;
	for (int i = 0; i < 6; i++) {
		m_renderer->CL[i] = (double)m_slider[i]->value() / 1000;
	}
	calculateCL2POS(m_renderer->CL, m_renderer->POS);
	updateGuiCLPOSText();
}

void StewartPlatformSimulator::SLOT_setSliderValueByLineEdit()
{
	double new_CL[6];
	for (int i = 0; i < 6; i++) {
		new_CL[i] = m_text_body_CL[i]->text().toDouble();
		if (new_CL[i] < Lengthsmin) {
			m_text_body_CL[i]->setText(QString::number(Lengthsmin));
		}
		else if (new_CL[i] > Lengthsmax) {
			m_text_body_CL[i]->setText(QString::number(Lengthsmax));
		}

		m_slider[i]->setValue((int)new_CL[i]);
	}
}

void StewartPlatformSimulator::SLOT_setPlatformParametersByLineEdit()
{
	angleP = m_text_body_platform_parameters[0]->text().toDouble();
	angleB = m_text_body_platform_parameters[1]->text().toDouble();
	radiusP = m_text_body_platform_parameters[2]->text().toDouble();
	radiusB = m_text_body_platform_parameters[3]->text().toDouble();
	Lengthsmin = m_text_body_platform_parameters[4]->text().toDouble();
	stroke = m_text_body_platform_parameters[5]->text().toDouble();

	SPK_update(&spk, angleP, angleB, radiusP, radiusB, Lengthsmin, stroke);
	determineSingleZ();
	m_renderer->initializeRendererCLPOS();
	initializeGuiCLSliders();
	initializeGuiPOSTextBody();
}

void StewartPlatformSimulator::SLOT_UseKeyOff()
{
	usekey = false;
}

void StewartPlatformSimulator::keyPressEvent(QKeyEvent * ev)
{
	switch (ev->key())
	{
	case Qt::Key_Z:
		m_renderer->revertViewport();
		break;
	case Qt::Key_X:
		m_renderer->initializeRendererCLPOS();
		initializeGuiCLSliders();
		initializeGuiPOSTextBody();
		break;

	case Qt::Key_R:
		changePOSByKeyPress(0, -0.005);
		break;
	case Qt::Key_F:
		changePOSByKeyPress(0, 0.005);
		break;
	case Qt::Key_A:
		changePOSByKeyPress(1, -0.005);
		break;
	case Qt::Key_D:
		changePOSByKeyPress(1, 0.005);
		break;
	case Qt::Key_W:
		changePOSByKeyPress(2, 0.005);
		break;
	case Qt::Key_S:
		changePOSByKeyPress(2, -0.005);
		break;
	case Qt::Key_3:
		changePOSByKeyPress(3, -0.3);
		break;
	case Qt::Key_4:
		changePOSByKeyPress(3, 0.3);
		break;
	case Qt::Key_1:
		changePOSByKeyPress(4, 0.3);
		break;
	case Qt::Key_2:
		changePOSByKeyPress(4, -0.3);
		break;
	case Qt::Key_E:
		changePOSByKeyPress(5, -0.3);
		break;
	case Qt::Key_Q:
		changePOSByKeyPress(5, 0.3);
		break;

	case Qt::Key_Space:
		m_renderer->switchSurroundViewport();
		break;
	case Qt::Key_Escape:
		close();
	}
}

void StewartPlatformSimulator::draw()
{
	m_renderer->update();
}

void StewartPlatformSimulator::connectGUIobjects()
{
	m_slider[0] = ui.SliderCL1;
	m_slider[1] = ui.SliderCL2;
	m_slider[2] = ui.SliderCL3;
	m_slider[3] = ui.SliderCL4;
	m_slider[4] = ui.SliderCL5;
	m_slider[5] = ui.SliderCL6;

	m_text_body_CL[0] = ui.text_body_L1;
	m_text_body_CL[1] = ui.text_body_L2;
	m_text_body_CL[2] = ui.text_body_L3;
	m_text_body_CL[3] = ui.text_body_L4;
	m_text_body_CL[4] = ui.text_body_L5;
	m_text_body_CL[5] = ui.text_body_L6;

	m_text_body_POS[0] = ui.text_body_x;
	m_text_body_POS[1] = ui.text_body_y;
	m_text_body_POS[2] = ui.text_body_z;
	m_text_body_POS[3] = ui.text_body_zR;
	m_text_body_POS[4] = ui.text_body_yR;
	m_text_body_POS[5] = ui.text_body_xR;

	m_text_body_platform_parameters[0] = ui.text_body_angleP;
	m_text_body_platform_parameters[1] = ui.text_body_angleB;
	m_text_body_platform_parameters[2] = ui.text_body_radiusP;
	m_text_body_platform_parameters[3] = ui.text_body_radiusB;
	m_text_body_platform_parameters[4] = ui.text_body_Lmin;
	m_text_body_platform_parameters[5] = ui.text_body_stroke;
}

void StewartPlatformSimulator::determineSingleZ()
{
	Lengthsmax = Lengthsmin + stroke;
	Lengthsmedian = Lengthsmin + (int)(stroke / 2);
	mtx CL;
	mtx_new(&CL, 6, 1);
	for (int k = 0; k < 6; k++) {
		mtx_set_value(&CL, k, 0, Lengthsmedian / 1000);
	}
	SPK_forward_kinematics(&spk, &CL);
	single_z = mtx_get_value(&spk.Posture, 2, 0);

	mtx_delete(&CL);
}

void StewartPlatformSimulator::initializeGuiCLSliders()
{
	for (int i = 0; i < 6; i++) {
		m_slider[i]->setRange((int)Lengthsmin, (int)Lengthsmax);
		m_slider[i]->setValue((int)(Lengthsmin + stroke / 2));
	}
	for (int i = 0; i < 6; i++) m_text_body_CL[i]->setText(QString::number(Lengthsmedian));
}

void StewartPlatformSimulator::initializeGuiPOSTextBody()
{
	for (int i = 0; i < 6; i++) m_text_body_POS[i]->setText("0.00000000");
	m_text_body_POS[2]->setText(QString::number(single_z, 'd', 8));
}

void StewartPlatformSimulator::initializeGuiPlatformParametersTextBody()
{
	m_text_body_platform_parameters[0]->setText(QString::number(angleP, 'd', 8));
	m_text_body_platform_parameters[1]->setText(QString::number(angleB, 'd', 8));
	m_text_body_platform_parameters[2]->setText(QString::number(radiusP, 'd', 8));
	m_text_body_platform_parameters[3]->setText(QString::number(radiusB, 'd', 8));
	m_text_body_platform_parameters[4]->setText(QString::number(Lengthsmin, 'd', 0));
	m_text_body_platform_parameters[5]->setText(QString::number(stroke, 'd', 0));
}

void StewartPlatformSimulator::updateGuiCLPOSText()
{
	for (int i = 0; i < 6; i++) {
		m_text_body_CL[i]->setText(QString::number(1000 * m_renderer->CL[i]));
		m_text_body_POS[i]->setText(QString::number(m_renderer->POS[i], 'd', 8));
	}
}

void StewartPlatformSimulator::calculateCL2POS(double CL[6], double POS[6])
{
	for (int i = 0; i < 6; i++) {
		mtx_set_value(&spk.CylindersLengths, i, 0, CL[i]);
	}
	SPK_forward_kinematics(&spk, &spk.CylindersLengths);
	for (int i = 0; i < 6; i++) {
		POS[i] = mtx_get_value(&spk.Posture, i, 0);
		if (abs(POS[i]) < 1e-8) POS[i] = 0.0f;
	}
	POS[3] = RAD2DEG(POS[3]);
	POS[4] = RAD2DEG(POS[4]);
	POS[5] = RAD2DEG(POS[5]);

	SPK_inverse_kinematics(&spk, &spk.Posture);
	for (int i = 0; i < 6; i++) {
		m_renderer->P[i].x = mtx_get_value(&spk.CylindersVectors, 0, i);
		m_renderer->P[i].y = mtx_get_value(&spk.CylindersVectors, 1, i);
		m_renderer->P[i].z = mtx_get_value(&spk.CylindersVectors, 2, i);
	}
}

void StewartPlatformSimulator::calculatePOS2CL(double POS[6], double CL[6])
{
	for (int i = 0; i < 3; i++) {
		mtx_set_value(&spk.Posture, i, 0, POS[i]);
	}
	for (int i = 3; i < 6; i++) {
		mtx_set_value(&spk.Posture, i, 0, DEG2RAD(POS[i]));
	}

	SPK_inverse_kinematics(&spk, &spk.Posture);
	for (int i = 0; i < 6; i++) {
		CL[i] = mtx_get_value(&spk.CylindersLengths, i, 0);
	}
	for (int i = 0; i < 6; i++) {
		m_renderer->P[i].x = mtx_get_value(&spk.CylindersVectors, 0, i);
		m_renderer->P[i].y = mtx_get_value(&spk.CylindersVectors, 1, i);
		m_renderer->P[i].z = mtx_get_value(&spk.CylindersVectors, 2, i);
	}
	for (int i = 0; i < 6; i++) {
		m_slider[i]->setValue((int)(1000 * CL[i]));
	}
}

void StewartPlatformSimulator::changePOSByKeyPress(int POSi, double val)
{
	usekey = true;
	bool POSisLimit = false;
	float Lmin = Lengthsmin / 1000;
	float Lmax = Lengthsmax / 1000;

	m_renderer->POS[POSi] += val;
	calculatePOS2CL(m_renderer->POS, m_renderer->CL);
	for (int i = 0; i < 6; i++) {
		if (m_renderer->CL[i] < Lmin || m_renderer->CL[i] > Lmax) {
			m_renderer->CL[i] = (m_renderer->CL[i] < Lmin) ? Lmin : Lmax;
			POSisLimit = true;
		}
	}
	if (POSisLimit)m_renderer->POS[POSi] -= val;
	updateGuiCLPOSText();
}


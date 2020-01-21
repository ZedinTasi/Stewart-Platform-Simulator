/********************************************************************************
** Form generated from reading UI file 'StewartPlatformSimulator.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEWARTPLATFORMSIMULATOR_H
#define UI_STEWARTPLATFORMSIMULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StewartPlatformClass
{
public:
    QWidget *centralWidget;
    QOpenGLWidget *renderer;
    QLabel *label_CL;
    QLabel *label_POS;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_x;
    QLabel *label_y;
    QLabel *label_z;
    QLabel *label_zR;
    QLabel *label_yR;
    QLabel *label_xR;
    QLineEdit *text_body_y;
    QLineEdit *text_body_z;
    QLineEdit *text_body_zR;
    QLineEdit *text_body_xR;
    QLineEdit *text_body_yR;
    QLineEdit *text_body_x;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_angleP;
    QLabel *label_angleB;
    QLineEdit *text_body_angleB;
    QLabel *label_radiusP;
    QLineEdit *text_body_radiusP;
    QLabel *label_radiusB;
    QLineEdit *text_body_radiusB;
    QLabel *label_Lmin;
    QLineEdit *text_body_Lmin;
    QLabel *label_stroke;
    QLineEdit *text_body_stroke;
    QLineEdit *text_body_angleP;
    QLabel *label_PP;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_L1;
    QLabel *label_L4;
    QLabel *label_L2;
    QLabel *label_L3;
    QLineEdit *text_body_L2;
    QSlider *SliderCL2;
    QLineEdit *text_body_L1;
    QSlider *SliderCL1;
    QLineEdit *text_body_L3;
    QSlider *SliderCL3;
    QLabel *label_L5;
    QLabel *label_L6;
    QLineEdit *text_body_L4;
    QLineEdit *text_body_L5;
    QLineEdit *text_body_L6;
    QSlider *SliderCL4;
    QSlider *SliderCL5;
    QSlider *SliderCL6;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StewartPlatformClass)
    {
        if (StewartPlatformClass->objectName().isEmpty())
            StewartPlatformClass->setObjectName(QStringLiteral("StewartPlatformClass"));
        StewartPlatformClass->resize(1280, 720);
        centralWidget = new QWidget(StewartPlatformClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        renderer = new QOpenGLWidget(centralWidget);
        renderer->setObjectName(QStringLiteral("renderer"));
        renderer->setGeometry(QRect(20, 30, 800, 600));
        label_CL = new QLabel(centralWidget);
        label_CL->setObjectName(QStringLiteral("label_CL"));
        label_CL->setGeometry(QRect(870, 30, 120, 20));
        label_POS = new QLabel(centralWidget);
        label_POS->setObjectName(QStringLiteral("label_POS"));
        label_POS->setGeometry(QRect(870, 260, 120, 20));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(870, 290, 141, 152));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_x = new QLabel(formLayoutWidget);
        label_x->setObjectName(QStringLiteral("label_x"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_x);

        label_y = new QLabel(formLayoutWidget);
        label_y->setObjectName(QStringLiteral("label_y"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_y);

        label_z = new QLabel(formLayoutWidget);
        label_z->setObjectName(QStringLiteral("label_z"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_z);

        label_zR = new QLabel(formLayoutWidget);
        label_zR->setObjectName(QStringLiteral("label_zR"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_zR);

        label_yR = new QLabel(formLayoutWidget);
        label_yR->setObjectName(QStringLiteral("label_yR"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_yR);

        label_xR = new QLabel(formLayoutWidget);
        label_xR->setObjectName(QStringLiteral("label_xR"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_xR);

        text_body_y = new QLineEdit(formLayoutWidget);
        text_body_y->setObjectName(QStringLiteral("text_body_y"));
        text_body_y->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, text_body_y);

        text_body_z = new QLineEdit(formLayoutWidget);
        text_body_z->setObjectName(QStringLiteral("text_body_z"));
        text_body_z->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, text_body_z);

        text_body_zR = new QLineEdit(formLayoutWidget);
        text_body_zR->setObjectName(QStringLiteral("text_body_zR"));
        text_body_zR->setReadOnly(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, text_body_zR);

        text_body_xR = new QLineEdit(formLayoutWidget);
        text_body_xR->setObjectName(QStringLiteral("text_body_xR"));

        formLayout->setWidget(5, QFormLayout::FieldRole, text_body_xR);

        text_body_yR = new QLineEdit(formLayoutWidget);
        text_body_yR->setObjectName(QStringLiteral("text_body_yR"));
        text_body_yR->setReadOnly(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, text_body_yR);

        text_body_x = new QLineEdit(formLayoutWidget);
        text_body_x->setObjectName(QStringLiteral("text_body_x"));
        text_body_x->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, text_body_x);

        formLayoutWidget_2 = new QWidget(centralWidget);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(1060, 290, 161, 152));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_angleP = new QLabel(formLayoutWidget_2);
        label_angleP->setObjectName(QStringLiteral("label_angleP"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_angleP);

        label_angleB = new QLabel(formLayoutWidget_2);
        label_angleB->setObjectName(QStringLiteral("label_angleB"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_angleB);

        text_body_angleB = new QLineEdit(formLayoutWidget_2);
        text_body_angleB->setObjectName(QStringLiteral("text_body_angleB"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, text_body_angleB);

        label_radiusP = new QLabel(formLayoutWidget_2);
        label_radiusP->setObjectName(QStringLiteral("label_radiusP"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_radiusP);

        text_body_radiusP = new QLineEdit(formLayoutWidget_2);
        text_body_radiusP->setObjectName(QStringLiteral("text_body_radiusP"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, text_body_radiusP);

        label_radiusB = new QLabel(formLayoutWidget_2);
        label_radiusB->setObjectName(QStringLiteral("label_radiusB"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_radiusB);

        text_body_radiusB = new QLineEdit(formLayoutWidget_2);
        text_body_radiusB->setObjectName(QStringLiteral("text_body_radiusB"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, text_body_radiusB);

        label_Lmin = new QLabel(formLayoutWidget_2);
        label_Lmin->setObjectName(QStringLiteral("label_Lmin"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_Lmin);

        text_body_Lmin = new QLineEdit(formLayoutWidget_2);
        text_body_Lmin->setObjectName(QStringLiteral("text_body_Lmin"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, text_body_Lmin);

        label_stroke = new QLabel(formLayoutWidget_2);
        label_stroke->setObjectName(QStringLiteral("label_stroke"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_stroke);

        text_body_stroke = new QLineEdit(formLayoutWidget_2);
        text_body_stroke->setObjectName(QStringLiteral("text_body_stroke"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, text_body_stroke);

        text_body_angleP = new QLineEdit(formLayoutWidget_2);
        text_body_angleP->setObjectName(QStringLiteral("text_body_angleP"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, text_body_angleP);

        label_PP = new QLabel(centralWidget);
        label_PP->setObjectName(QStringLiteral("label_PP"));
        label_PP->setGeometry(QRect(1060, 260, 120, 20));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(870, 60, 371, 191));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(15);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_L1 = new QLabel(gridLayoutWidget);
        label_L1->setObjectName(QStringLiteral("label_L1"));

        gridLayout->addWidget(label_L1, 0, 1, 1, 1);

        label_L4 = new QLabel(gridLayoutWidget);
        label_L4->setObjectName(QStringLiteral("label_L4"));

        gridLayout->addWidget(label_L4, 3, 1, 1, 1);

        label_L2 = new QLabel(gridLayoutWidget);
        label_L2->setObjectName(QStringLiteral("label_L2"));

        gridLayout->addWidget(label_L2, 1, 1, 1, 1);

        label_L3 = new QLabel(gridLayoutWidget);
        label_L3->setObjectName(QStringLiteral("label_L3"));

        gridLayout->addWidget(label_L3, 2, 1, 1, 1);

        text_body_L2 = new QLineEdit(gridLayoutWidget);
        text_body_L2->setObjectName(QStringLiteral("text_body_L2"));

        gridLayout->addWidget(text_body_L2, 1, 2, 1, 1);

        SliderCL2 = new QSlider(gridLayoutWidget);
        SliderCL2->setObjectName(QStringLiteral("SliderCL2"));
        SliderCL2->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(SliderCL2, 1, 3, 1, 1);

        text_body_L1 = new QLineEdit(gridLayoutWidget);
        text_body_L1->setObjectName(QStringLiteral("text_body_L1"));

        gridLayout->addWidget(text_body_L1, 0, 2, 1, 1);

        SliderCL1 = new QSlider(gridLayoutWidget);
        SliderCL1->setObjectName(QStringLiteral("SliderCL1"));
        SliderCL1->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(SliderCL1, 0, 3, 1, 1);

        text_body_L3 = new QLineEdit(gridLayoutWidget);
        text_body_L3->setObjectName(QStringLiteral("text_body_L3"));

        gridLayout->addWidget(text_body_L3, 2, 2, 1, 1);

        SliderCL3 = new QSlider(gridLayoutWidget);
        SliderCL3->setObjectName(QStringLiteral("SliderCL3"));
        SliderCL3->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(SliderCL3, 2, 3, 1, 1);

        label_L5 = new QLabel(gridLayoutWidget);
        label_L5->setObjectName(QStringLiteral("label_L5"));

        gridLayout->addWidget(label_L5, 4, 1, 1, 1);

        label_L6 = new QLabel(gridLayoutWidget);
        label_L6->setObjectName(QStringLiteral("label_L6"));

        gridLayout->addWidget(label_L6, 5, 1, 1, 1);

        text_body_L4 = new QLineEdit(gridLayoutWidget);
        text_body_L4->setObjectName(QStringLiteral("text_body_L4"));

        gridLayout->addWidget(text_body_L4, 3, 2, 1, 1);

        text_body_L5 = new QLineEdit(gridLayoutWidget);
        text_body_L5->setObjectName(QStringLiteral("text_body_L5"));

        gridLayout->addWidget(text_body_L5, 4, 2, 1, 1);

        text_body_L6 = new QLineEdit(gridLayoutWidget);
        text_body_L6->setObjectName(QStringLiteral("text_body_L6"));

        gridLayout->addWidget(text_body_L6, 5, 2, 1, 1);

        SliderCL4 = new QSlider(gridLayoutWidget);
        SliderCL4->setObjectName(QStringLiteral("SliderCL4"));
        SliderCL4->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(SliderCL4, 3, 3, 1, 1);

        SliderCL5 = new QSlider(gridLayoutWidget);
        SliderCL5->setObjectName(QStringLiteral("SliderCL5"));
        SliderCL5->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(SliderCL5, 4, 3, 1, 1);

        SliderCL6 = new QSlider(gridLayoutWidget);
        SliderCL6->setObjectName(QStringLiteral("SliderCL6"));
        SliderCL6->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(SliderCL6, 5, 3, 1, 1);

        gridLayout->setColumnStretch(2, 3);
        gridLayout->setColumnStretch(3, 8);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(950, 490, 47, 12));
        StewartPlatformClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(StewartPlatformClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 22));
        StewartPlatformClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(StewartPlatformClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        StewartPlatformClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(StewartPlatformClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        StewartPlatformClass->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        label_z->setBuddy(text_body_yR);
        label_radiusP->setBuddy(text_body_yR);
        label_L1->setBuddy(SliderCL1);
        label_L4->setBuddy(SliderCL4);
        label_L2->setBuddy(SliderCL2);
        label_L3->setBuddy(SliderCL3);
        label_L5->setBuddy(SliderCL5);
        label_L6->setBuddy(SliderCL6);
#endif // QT_NO_SHORTCUT

        retranslateUi(StewartPlatformClass);

        QMetaObject::connectSlotsByName(StewartPlatformClass);
    } // setupUi

    void retranslateUi(QMainWindow *StewartPlatformClass)
    {
        StewartPlatformClass->setWindowTitle(QApplication::translate("StewartPlatformClass", "StewartPlatformSimulator", Q_NULLPTR));
        label_CL->setText(QApplication::translate("StewartPlatformClass", "Cylinders Lengths", Q_NULLPTR));
        label_POS->setText(QApplication::translate("StewartPlatformClass", "Posture", Q_NULLPTR));
        label_x->setText(QApplication::translate("StewartPlatformClass", "x (m)", Q_NULLPTR));
        label_y->setText(QApplication::translate("StewartPlatformClass", "y (m)", Q_NULLPTR));
        label_z->setText(QApplication::translate("StewartPlatformClass", "z (m)", Q_NULLPTR));
        label_zR->setText(QApplication::translate("StewartPlatformClass", "zR (deg)", Q_NULLPTR));
        label_yR->setText(QApplication::translate("StewartPlatformClass", "yR (deg)", Q_NULLPTR));
        label_xR->setText(QApplication::translate("StewartPlatformClass", "xR (deg)", Q_NULLPTR));
        text_body_y->setText(QApplication::translate("StewartPlatformClass", "text_body_y", Q_NULLPTR));
        text_body_z->setText(QApplication::translate("StewartPlatformClass", "text_body_z", Q_NULLPTR));
        text_body_zR->setText(QApplication::translate("StewartPlatformClass", "text_body_zR", Q_NULLPTR));
        text_body_xR->setText(QApplication::translate("StewartPlatformClass", "text_body_xR", Q_NULLPTR));
        text_body_yR->setText(QApplication::translate("StewartPlatformClass", "text_body_yR", Q_NULLPTR));
        text_body_x->setText(QApplication::translate("StewartPlatformClass", "text_body_x", Q_NULLPTR));
        label_angleP->setText(QApplication::translate("StewartPlatformClass", "angleP (deg)", Q_NULLPTR));
        label_angleB->setText(QApplication::translate("StewartPlatformClass", "angleB (deg)", Q_NULLPTR));
        text_body_angleB->setText(QApplication::translate("StewartPlatformClass", "text_body_angleB", Q_NULLPTR));
        label_radiusP->setText(QApplication::translate("StewartPlatformClass", "radiusP (mm)", Q_NULLPTR));
        text_body_radiusP->setText(QApplication::translate("StewartPlatformClass", "text_body_radiusP", Q_NULLPTR));
        label_radiusB->setText(QApplication::translate("StewartPlatformClass", "radiusB (mm)", Q_NULLPTR));
        text_body_radiusB->setText(QApplication::translate("StewartPlatformClass", "text_body_radiusB", Q_NULLPTR));
        label_Lmin->setText(QApplication::translate("StewartPlatformClass", "Lmin (mm)", Q_NULLPTR));
        text_body_Lmin->setText(QApplication::translate("StewartPlatformClass", "text_body_Lmin", Q_NULLPTR));
        label_stroke->setText(QApplication::translate("StewartPlatformClass", "stroke (mm)", Q_NULLPTR));
        text_body_stroke->setText(QApplication::translate("StewartPlatformClass", "text_body_stroke", Q_NULLPTR));
        text_body_angleP->setText(QApplication::translate("StewartPlatformClass", "text_body_angleP", Q_NULLPTR));
        label_PP->setText(QApplication::translate("StewartPlatformClass", "Platform Parameters", Q_NULLPTR));
        label_L1->setText(QApplication::translate("StewartPlatformClass", "L1 (mm)", Q_NULLPTR));
        label_L4->setText(QApplication::translate("StewartPlatformClass", "L4 (mm)", Q_NULLPTR));
        label_L2->setText(QApplication::translate("StewartPlatformClass", "L2 (mm)", Q_NULLPTR));
        label_L3->setText(QApplication::translate("StewartPlatformClass", "L3 (mm)", Q_NULLPTR));
        text_body_L2->setText(QApplication::translate("StewartPlatformClass", "text_body_L2", Q_NULLPTR));
        text_body_L1->setText(QApplication::translate("StewartPlatformClass", "text_body_L1", Q_NULLPTR));
        text_body_L3->setText(QApplication::translate("StewartPlatformClass", "text_body_L3", Q_NULLPTR));
        label_L5->setText(QApplication::translate("StewartPlatformClass", "L5 (mm)", Q_NULLPTR));
        label_L6->setText(QApplication::translate("StewartPlatformClass", "L6 (mm)", Q_NULLPTR));
        text_body_L4->setText(QApplication::translate("StewartPlatformClass", "text_body_L4", Q_NULLPTR));
        text_body_L5->setText(QApplication::translate("StewartPlatformClass", "text_body_L5", Q_NULLPTR));
        text_body_L6->setText(QApplication::translate("StewartPlatformClass", "text_body_L6", Q_NULLPTR));
        label->setText(QApplication::translate("StewartPlatformClass", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StewartPlatformClass: public Ui_StewartPlatformClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEWARTPLATFORMSIMULATOR_H

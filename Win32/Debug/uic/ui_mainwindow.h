/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *baseAngleAddBtn;
    QPushButton *baseAngleSubBtn;
    QPushButton *longArmAddBtn;
    QPushButton *longArmSubBtn;
    QPushButton *shortArmAddBtn;
    QPushButton *shortArmSubBtn;
    QPushButton *rHeadAddBtn;
    QPushButton *rHeadSubBtn;
    QComboBox *teachMode;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *joint1Label;
    QLabel *xLabel;
    QLabel *joint2Label;
    QLabel *yLabel;
    QLabel *joint3Label;
    QLabel *zLabel;
    QLabel *rLabel;
    QLabel *joint4Label;
    QGroupBox *groupBox_3;
    QLineEdit *xPTPEdit;
    QLineEdit *yPTPEdit;
    QLineEdit *zPTPEdit;
    QLineEdit *rPTPEdit;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QPushButton *sendBtn;
    QPushButton *connectBtn;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *deviceSNLabel;
    QLabel *DeviceNameLabel;
    QLabel *DeviceInfoLabel;
    QGroupBox *groupBox_4;
    QRadioButton *PumpBtnON;
    QRadioButton *PumpBtnOFF;
    QPushButton *HomeSafeBtn;
    QGroupBox *groupBox_5;
    QLineEdit *stringType;
    QPushButton *PrintBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(820, 746);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 10, 411, 181));
        baseAngleAddBtn = new QPushButton(groupBox);
        baseAngleAddBtn->setObjectName(QString::fromUtf8("baseAngleAddBtn"));
        baseAngleAddBtn->setEnabled(false);
        baseAngleAddBtn->setGeometry(QRect(50, 50, 41, 23));
        baseAngleSubBtn = new QPushButton(groupBox);
        baseAngleSubBtn->setObjectName(QString::fromUtf8("baseAngleSubBtn"));
        baseAngleSubBtn->setEnabled(false);
        baseAngleSubBtn->setGeometry(QRect(50, 110, 41, 23));
        longArmAddBtn = new QPushButton(groupBox);
        longArmAddBtn->setObjectName(QString::fromUtf8("longArmAddBtn"));
        longArmAddBtn->setEnabled(false);
        longArmAddBtn->setGeometry(QRect(10, 80, 41, 23));
        longArmSubBtn = new QPushButton(groupBox);
        longArmSubBtn->setObjectName(QString::fromUtf8("longArmSubBtn"));
        longArmSubBtn->setEnabled(false);
        longArmSubBtn->setGeometry(QRect(90, 80, 41, 23));
        shortArmAddBtn = new QPushButton(groupBox);
        shortArmAddBtn->setObjectName(QString::fromUtf8("shortArmAddBtn"));
        shortArmAddBtn->setEnabled(false);
        shortArmAddBtn->setGeometry(QRect(200, 100, 41, 23));
        shortArmSubBtn = new QPushButton(groupBox);
        shortArmSubBtn->setObjectName(QString::fromUtf8("shortArmSubBtn"));
        shortArmSubBtn->setEnabled(false);
        shortArmSubBtn->setGeometry(QRect(200, 50, 41, 23));
        rHeadAddBtn = new QPushButton(groupBox);
        rHeadAddBtn->setObjectName(QString::fromUtf8("rHeadAddBtn"));
        rHeadAddBtn->setEnabled(false);
        rHeadAddBtn->setGeometry(QRect(150, 80, 41, 23));
        rHeadSubBtn = new QPushButton(groupBox);
        rHeadSubBtn->setObjectName(QString::fromUtf8("rHeadSubBtn"));
        rHeadSubBtn->setEnabled(false);
        rHeadSubBtn->setGeometry(QRect(250, 80, 41, 23));
        teachMode = new QComboBox(groupBox);
        teachMode->addItem(QString());
        teachMode->addItem(QString());
        teachMode->setObjectName(QString::fromUtf8("teachMode"));
        teachMode->setEnabled(false);
        teachMode->setGeometry(QRect(300, 20, 69, 22));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 210, 421, 91));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 21, 16));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 16, 16));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 20, 16, 16));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(210, 20, 16, 16));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(330, 20, 16, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(110, 70, 16, 16));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(210, 70, 16, 16));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(330, 70, 16, 16));
        joint1Label = new QLabel(groupBox_2);
        joint1Label->setObjectName(QString::fromUtf8("joint1Label"));
        joint1Label->setEnabled(true);
        joint1Label->setGeometry(QRect(50, 20, 54, 12));
        xLabel = new QLabel(groupBox_2);
        xLabel->setObjectName(QString::fromUtf8("xLabel"));
        xLabel->setEnabled(true);
        xLabel->setGeometry(QRect(50, 70, 54, 12));
        joint2Label = new QLabel(groupBox_2);
        joint2Label->setObjectName(QString::fromUtf8("joint2Label"));
        joint2Label->setGeometry(QRect(140, 20, 54, 12));
        yLabel = new QLabel(groupBox_2);
        yLabel->setObjectName(QString::fromUtf8("yLabel"));
        yLabel->setGeometry(QRect(140, 70, 54, 12));
        joint3Label = new QLabel(groupBox_2);
        joint3Label->setObjectName(QString::fromUtf8("joint3Label"));
        joint3Label->setGeometry(QRect(240, 20, 54, 12));
        zLabel = new QLabel(groupBox_2);
        zLabel->setObjectName(QString::fromUtf8("zLabel"));
        zLabel->setGeometry(QRect(240, 70, 54, 12));
        rLabel = new QLabel(groupBox_2);
        rLabel->setObjectName(QString::fromUtf8("rLabel"));
        rLabel->setGeometry(QRect(360, 70, 54, 12));
        joint4Label = new QLabel(groupBox_2);
        joint4Label->setObjectName(QString::fromUtf8("joint4Label"));
        joint4Label->setGeometry(QRect(360, 20, 54, 12));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 320, 421, 231));
        xPTPEdit = new QLineEdit(groupBox_3);
        xPTPEdit->setObjectName(QString::fromUtf8("xPTPEdit"));
        xPTPEdit->setEnabled(false);
        xPTPEdit->setGeometry(QRect(130, 40, 113, 20));
        yPTPEdit = new QLineEdit(groupBox_3);
        yPTPEdit->setObjectName(QString::fromUtf8("yPTPEdit"));
        yPTPEdit->setEnabled(false);
        yPTPEdit->setGeometry(QRect(130, 80, 113, 20));
        zPTPEdit = new QLineEdit(groupBox_3);
        zPTPEdit->setObjectName(QString::fromUtf8("zPTPEdit"));
        zPTPEdit->setEnabled(false);
        zPTPEdit->setGeometry(QRect(130, 120, 113, 20));
        rPTPEdit = new QLineEdit(groupBox_3);
        rPTPEdit->setObjectName(QString::fromUtf8("rPTPEdit"));
        rPTPEdit->setEnabled(false);
        rPTPEdit->setGeometry(QRect(130, 160, 113, 20));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(50, 40, 54, 12));
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(50, 80, 54, 12));
        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(50, 120, 54, 12));
        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(50, 160, 54, 12));
        sendBtn = new QPushButton(groupBox_3);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));
        sendBtn->setEnabled(false);
        sendBtn->setGeometry(QRect(130, 200, 111, 23));
        connectBtn = new QPushButton(centralWidget);
        connectBtn->setObjectName(QString::fromUtf8("connectBtn"));
        connectBtn->setGeometry(QRect(580, 40, 131, 41));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(520, 120, 71, 16));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(520, 150, 81, 16));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(520, 180, 121, 20));
        deviceSNLabel = new QLabel(centralWidget);
        deviceSNLabel->setObjectName(QString::fromUtf8("deviceSNLabel"));
        deviceSNLabel->setGeometry(QRect(653, 120, 131, 20));
        deviceSNLabel->setFrameShape(QFrame::Panel);
        DeviceNameLabel = new QLabel(centralWidget);
        DeviceNameLabel->setObjectName(QString::fromUtf8("DeviceNameLabel"));
        DeviceNameLabel->setGeometry(QRect(653, 150, 131, 20));
        DeviceNameLabel->setFrameShape(QFrame::Panel);
        DeviceNameLabel->setTextFormat(Qt::AutoText);
        DeviceInfoLabel = new QLabel(centralWidget);
        DeviceInfoLabel->setObjectName(QString::fromUtf8("DeviceInfoLabel"));
        DeviceInfoLabel->setGeometry(QRect(653, 180, 131, 20));
        DeviceInfoLabel->setFrameShape(QFrame::Panel);
        DeviceInfoLabel->setFrameShadow(QFrame::Plain);
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 580, 151, 71));
        PumpBtnON = new QRadioButton(groupBox_4);
        PumpBtnON->setObjectName(QString::fromUtf8("PumpBtnON"));
        PumpBtnON->setGeometry(QRect(10, 30, 95, 20));
        PumpBtnOFF = new QRadioButton(groupBox_4);
        PumpBtnOFF->setObjectName(QString::fromUtf8("PumpBtnOFF"));
        PumpBtnOFF->setGeometry(QRect(70, 30, 95, 20));
        HomeSafeBtn = new QPushButton(centralWidget);
        HomeSafeBtn->setObjectName(QString::fromUtf8("HomeSafeBtn"));
        HomeSafeBtn->setGeometry(QRect(240, 610, 93, 28));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(460, 330, 331, 91));
        stringType = new QLineEdit(groupBox_5);
        stringType->setObjectName(QString::fromUtf8("stringType"));
        stringType->setGeometry(QRect(10, 30, 301, 22));
        PrintBtn = new QPushButton(groupBox_5);
        PrintBtn->setObjectName(QString::fromUtf8("PrintBtn"));
        PrintBtn->setGeometry(QRect(10, 60, 93, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 820, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "JOG / Cartesian", nullptr));
        baseAngleAddBtn->setText(QCoreApplication::translate("MainWindow", "J1+", nullptr));
        baseAngleSubBtn->setText(QCoreApplication::translate("MainWindow", "J1-", nullptr));
        longArmAddBtn->setText(QCoreApplication::translate("MainWindow", "J2+", nullptr));
        longArmSubBtn->setText(QCoreApplication::translate("MainWindow", "J2-", nullptr));
        shortArmAddBtn->setText(QCoreApplication::translate("MainWindow", "J3+", nullptr));
        shortArmSubBtn->setText(QCoreApplication::translate("MainWindow", "J3-", nullptr));
        rHeadAddBtn->setText(QCoreApplication::translate("MainWindow", "J4+", nullptr));
        rHeadSubBtn->setText(QCoreApplication::translate("MainWindow", "J4-", nullptr));
        teachMode->setItemText(0, QCoreApplication::translate("MainWindow", "Joint", nullptr));
        teachMode->setItemText(1, QCoreApplication::translate("MainWindow", "Axis", nullptr));

        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Pose", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "J1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "J2", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "J3", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "J4", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        joint1Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        xLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        joint2Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        yLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        joint3Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        zLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        rLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        joint4Label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "PTP", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        sendBtn->setText(QCoreApplication::translate("MainWindow", "SendPTP", nullptr));
        connectBtn->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Device SN:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Device Name:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Device information:", nullptr));
        deviceSNLabel->setText(QString());
        DeviceNameLabel->setText(QString());
        DeviceInfoLabel->setText(QString());
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Pump", nullptr));
        PumpBtnON->setText(QCoreApplication::translate("MainWindow", "ON", nullptr));
        PumpBtnOFF->setText(QCoreApplication::translate("MainWindow", "OFF", nullptr));
        HomeSafeBtn->setText(QCoreApplication::translate("MainWindow", "HomeSafe", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Enter string to print", nullptr));
        PrintBtn->setText(QCoreApplication::translate("MainWindow", "Print!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

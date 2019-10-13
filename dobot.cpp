#include "dobot.h"
#include <iostream>
#include <mainwindow.h>
#include <QDebug>
#include <ui_mainwindow.h>
#include "mainwindow.h"
#include <string>
#include <QMessageBox>
#include <QDebug>
#include <QSignalMapper>
#include <QTimer>


dobot::dobot(QObject *parent) : QObject(parent)
{
}


dobot::~dobot()
{
}

bool dobot::isConnected() const
{
	return m_isConnected;
}

QString dobot::getDeviceSNDobot() const
{
	return QString(deviceSN);
}

QString dobot::getDeviceName() const
{
	return QString(deviceName);
}

QString dobot::getVersion() const
{
	uint8_t majorVersion, minorVersion, revision;
	GetDeviceVersion(&majorVersion, &minorVersion, &revision);
	return (QString::number(majorVersion) + "." + QString::number(minorVersion) + "." + QString::number(revision));
}

void dobot::JOGCtrlBtnPressed(int index, bool isJoint)
{
	JOGCmd jogCmd;

	jogCmd.isJoint = isJoint;
	jogCmd.cmd = index + 1;
	while (SetJOGCmd(&jogCmd, false, NULL) != DobotCommunicate_NoError) {
	}
}

void dobot::JOGCtrlBtnReleased(bool isJoint)
{
	JOGCmd jogCmd;

	jogCmd.isJoint = isJoint;
	jogCmd.cmd = JogIdle;
	while (SetJOGCmd(&jogCmd, false, NULL) != DobotCommunicate_NoError) {
	}
}

void dobot::startPump()
{
	m_PumpIsActive = true;
	SetEndEffectorSuctionCup(m_PumpIsActive, 1, 1, 0);
	qDebug() << "inside startPump";
}

void dobot::PTPSendBtnClicked(float x, float y, float z, float r) const
{
	PTPCmd ptpCmd;
	ptpCmd.ptpMode = PTPMOVJXYZMode;
	ptpCmd.x = x; 
	ptpCmd.y = y; 
	ptpCmd.z = z; 
	ptpCmd.r = r; 

	while (SetPTPCmd(&ptpCmd, true, NULL) != DobotCommunicate_NoError) {
	}
}

void dobot::HomeSafeBtnClicked() const
{
	PTPCmd ptpCmd;
	ptpCmd.ptpMode = PTPMOVJXYZMode;
	ptpCmd.x = 200;
	ptpCmd.y = 0; 
	ptpCmd.z = 50; 
	ptpCmd.r = 0; 

	while (SetPTPCmd(&ptpCmd, true, NULL) != DobotCommunicate_NoError) {
	}
}


void dobot::stopPump()
{
	qDebug() << "inside stopPump";
	m_PumpIsActive = false;
	SetEndEffectorSuctionCup(m_PumpIsActive, 0, 0, 0);
}

void dobot::enablePumpCtrl()
{
	if (!m_PumpIsActive)
	{
		qDebug() << "insideEnablePump if pump is NOT active";
		startPump();
	}
	else {
		qDebug() << "insideEnablePump if pump IS active";
		stopPump();
	}
	//return m_PumpIsActive == 1;
}

void dobot::setTheEndEffParam() const
{
	EndEffectorParams endEffectorParams;
	memset(&endEffectorParams, 0, sizeof(endEffectorParams));
	endEffectorParams.xBias = 71.6f;
	SetEndEffectorParams(&endEffectorParams, false, NULL);

	JOGJointParams jogJointParams;
	for (int i = 0; i < 4; i++) {
		jogJointParams.velocity[i] = 100;
		jogJointParams.acceleration[i] = 100;
	}
	SetJOGJointParams(&jogJointParams, false, NULL);

	JOGCoordinateParams jogCoordinateParams;
	for (int i = 0; i < 4; i++) {
		jogCoordinateParams.velocity[i] = 100;
		jogCoordinateParams.acceleration[i] = 100;
	}
	SetJOGCoordinateParams(&jogCoordinateParams, false, NULL);

	JOGCommonParams jogCommonParams;
	jogCommonParams.velocityRatio = 50;
	jogCommonParams.accelerationRatio = 50;
	SetJOGCommonParams(&jogCommonParams, false, NULL);

	PTPJointParams ptpJointParams;
	for (int i = 0; i < 4; i++) {
		ptpJointParams.velocity[i] = 100;
		ptpJointParams.acceleration[i] = 100;
	}
	SetPTPJointParams(&ptpJointParams, false, NULL);

	PTPCoordinateParams ptpCoordinateParams;
	ptpCoordinateParams.xyzVelocity = 100;
	ptpCoordinateParams.xyzAcceleration = 100;
	ptpCoordinateParams.rVelocity = 100;
	ptpCoordinateParams.rAcceleration = 100;
	SetPTPCoordinateParams(&ptpCoordinateParams, false, NULL);

	PTPJumpParams ptpJumpParams;
	ptpJumpParams.jumpHeight = 20;
	ptpJumpParams.zLimit = 150;
	SetPTPJumpParams(&ptpJumpParams, false, NULL);
}

void dobot::init()
{
	//Command timeout
	SetCmdTimeout(3000);
	//clear old commands and set the queued command running
	SetQueuedCmdClear();
	SetQueuedCmdStartExec();
	setTheEndEffParam();
}

bool dobot::connect()
{
	if (!isConnected()) {
		qDebug() << "inside connect()";
		m_isConnected = ConnectDobot(0, 115200, 0, 0) == DobotConnect_NoError;
		if (isConnected())
		{
			qDebug() << "isConnected";
		}
	}

	return isConnected();
}

void dobot::disconnect()
{
	if (isConnected()) {
		qDebug() << "trying to disconnect";
		DisconnectDobot();
		m_isConnected = false;
	}
}

void dobot::PrintBtnClicked(Point keyCoord)
{	
	std::cout << "inside printBtnclicked" << std::endl;
	std::cout << keyCoord << std::endl;
	PTPCmd ptpCmd;
	ptpCmd.ptpMode = PTPMOVJXYZMode;
	ptpCmd.x = keyCoord.getX();
	ptpCmd.y = keyCoord.getY();
	ptpCmd.z = -40; 
	ptpCmd.r = 0; 

	while (SetPTPCmd(&ptpCmd, true, NULL) != DobotCommunicate_NoError) {
	}
	//press
	ptpCmd.z = -60;
	while (SetPTPCmd(&ptpCmd, true, NULL) != DobotCommunicate_NoError) {
	}
	//hover
	ptpCmd.z = -40;
	while (SetPTPCmd(&ptpCmd, true, NULL) != DobotCommunicate_NoError) {
	}
}

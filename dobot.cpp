#include "dobot.h"
#include <iostream>
#include <mainwindow.h>
#include <QDebug>
#include <ui_mainwindow.h>
#include "mainwindow.h"

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
	//int SetEndEffectorSuctionCup(bool enableCtrl, bool suck,
	//	bool isQueued, uint64_t *queuedCmdIndex)
	
	m_PumpIsActive = true;
	SetEndEffectorSuctionCup(m_PumpIsActive, 1, 1, 0);
	qDebug() << "inside startPump";
}

void dobot::PTPSendBtnClicked(float x, float y, float z, float r)
{
	PTPCmd ptpCmd;
	ptpCmd.ptpMode = PTPMOVJXYZMode;
	ptpCmd.x = x; //ui->xPTPEdit->text().toFloat();
	ptpCmd.y = y; //ui->yPTPEdit->text().toFloat();
	ptpCmd.z = z; //ui->zPTPEdit->text().toFloat();
	ptpCmd.r = r; //ui->rPTPEdit->text().toFloat();

	while (SetPTPCmd(&ptpCmd, true, NULL) != DobotCommunicate_NoError) {
	}
}

void dobot::HomeSafeBtnClicked() const
{
	PTPCmd ptpCmd;
	ptpCmd.ptpMode = PTPMOVJXYZMode;
	ptpCmd.x = 200;
	ptpCmd.y = 0; //ui->yPTPEdit->text().toFloat();
	ptpCmd.z = -20; //ui->zPTPEdit->text().toFloat();
	ptpCmd.r = 0; //ui->rPTPEdit->text().toFloat();

	while (SetPTPCmd(&ptpCmd, true, NULL) != DobotCommunicate_NoError) {
	}
	//PTPCmd ptpCmd;
	//ptpCmd.ptpMode = PTPMOVJXYZMode;
	//ptpCmd.x = 215;
	//ptpCmd.y = -170; //ui->yPTPEdit->text().toFloat();
	//ptpCmd.z = -40; //ui->zPTPEdit->text().toFloat();
	//ptpCmd.r = 0; //ui->rPTPEdit->text().toFloat();

	//while (SetPTPCmd(&ptpCmd, true, NULL) != DobotCommunicate_NoError) {
	//}

	////PTPCmd ptpCmd;
	////ptpCmd.ptpMode = PTPMOVJXYZMode;
	//ptpCmd.x = 215;
	//ptpCmd.y = -170; //ui->yPTPEdit->text().toFloat();
	//ptpCmd.z = -60; //ui->zPTPEdit->text().toFloat();
	//ptpCmd.r = 0; //ui->rPTPEdit->text().toFloat();

	//while (SetPTPCmd(&ptpCmd, true, NULL) != DobotCommunicate_NoError) {
	//}
}

void dobot::PrintBtnClicked(QString string)
{

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
	//char deviceSN[64];
	//SetDeviceSN(deviceSN);
	//GetDeviceSN(deviceSN, sizeof(deviceSN));

	//char deviceName[64];
	//GetDeviceName(deviceName, sizeof(deviceName));


}

bool dobot::connect()
{
	if (!isConnected()) {
		qDebug() << "inside connect()";
		m_isConnected = ConnectDobot(0, 115200, 0, 0) == DobotConnect_NoError;
		if (isConnected())
		{
			qDebug() << "isConnected";
			//init();
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

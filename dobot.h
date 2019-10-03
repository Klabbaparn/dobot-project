#pragma once
#include <QObject>
#include "DobotDll.h"
#include "DobotType.h"
#include <QVector>
#include <QMainWindow>
//#include "Point.h"

class dobot : public QObject
{
	Q_OBJECT
public:
	explicit dobot(QObject *parent = nullptr);
	~dobot();

	bool connect();
	void disconnect();
	bool isConnected() const;
	void init();
	QString getDeviceSNDobot() const;
	QString getDeviceName() const;
	QString getVersion() const;
	void JOGCtrlBtnPressed(int index, bool isJoint);
	void JOGCtrlBtnReleased(bool isJoint);
	void enablePumpCtrl();
	void startPump();
	void PTPSendBtnClicked(float x, float y, float z, float r);
	void HomeSafeBtnClicked() const;
	void PrintBtnClicked(QString string);
	

private:


	void setTheEndEffParam() const;
	//void startPump();
	void stopPump();

private:
	bool m_isConnected = false;
	bool m_PumpIsActive = false;
	char deviceSN[64];
	char deviceName[64];
	
};


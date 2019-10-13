#ifndef DOBOT_H
#define DOBOT_H
#include <QObject>
#include "DobotDll.h"
#include "DobotType.h"
#include <QVector>
#include <QMainWindow>
#include <keyboard.h>

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
	void PTPSendBtnClicked(float x, float y, float z, float r) const;
	void HomeSafeBtnClicked() const;
	void PrintBtnClicked(Point keyCoord);
	

private:


	void setTheEndEffParam() const;
	void stopPump();
	void startPump();

private:
	bool m_isConnected = false;
	bool m_PumpIsActive = false;
	char deviceSN[64];
	char deviceName[64];
	
};

#endif // DOBOT_H


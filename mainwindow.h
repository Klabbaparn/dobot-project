#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DobotDll.h"
#include "DobotType.h"
#include "dobot.h"
#include "keyboard.h"

#include <QMessageBox>
#include <QDebug>
#include <QSerialPortInfo>
#include <assert.h>
#include <QFile>
#include <QXmlStreamWriter>
#include <QDomDocument>

//#include "VisionDll.h"
//#include "JHCap.h"
//#include "capturethread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    bool connectStatus;

protected:
    void closeEvent(QCloseEvent *);

private:
    void refreshBtn();
    void initDobot();
    void initControl();
	//void connectCam(); // work in progress
	//void initCamParams(void); // work in progress


private slots:
    void onChangedMode();
    void onConnectDobot();
    void onJOGCtrlBtnPressed(int index);
    void onJOGCtrlBtnReleased();
    void onPTPsendBtnClicked();
    void onGetPoseTimer();
	void onPumpBtnClicked();
	void onHomeSafeBtnClicked();
	void onPrintBtnClicked();

private:
	dobot m_dobot;
	keyboard m_keyboard;
};

#endif // MAINWINDOW_H

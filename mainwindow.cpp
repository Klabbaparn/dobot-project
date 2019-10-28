#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QDebug>
#include <QSignalMapper>
#include <QTimer>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    
    //endtype change
    connect(ui->teachMode, SIGNAL(currentIndexChanged(int)), this, SLOT(onChangedMode()));

    //connect dobot
    connect(ui->connectBtn, SIGNAL(clicked(bool)), this, SLOT(onConnectDobot()));

    //send PTP data
    connect(ui->sendBtn, SIGNAL(clicked(bool)), this, SLOT(onPTPsendBtnClicked()));

	//start pump
	connect(ui->PumpBtnON, SIGNAL(clicked(bool)), this, SLOT(onPumpBtnClicked()));
	//turn off pump
	connect(ui->PumpBtnOFF, SIGNAL(clicked(bool)), this, SLOT(onPumpBtnClicked()));
	//go home safely
	connect(ui->HomeSafeBtn, SIGNAL(clicked(bool)), this, SLOT(onHomeSafeBtnClicked()));
	//print string on a keyboard
	connect(ui->PrintBtn, SIGNAL(clicked(bool)), this, SLOT(onPrintBtnClicked()));

    //init JOG control
	//connectCam(); // work in progress
    initControl();

    //getPose Timer
    QTimer *getPoseTimer = new QTimer(this);
    getPoseTimer->setObjectName("getPoseTimer");
    connect(getPoseTimer, SIGNAL(timeout()), this, SLOT(onGetPoseTimer()));
    getPoseTimer->setSingleShot(true);

    //not more than 1000
    QRegExp regExp("500|0|[-]|[1-9][0-9]{0,2}[.][0-9]{1,3}");
    QValidator *validator = new QRegExpValidator(regExp, this);
    ui->xPTPEdit->setValidator(validator);
    ui->yPTPEdit->setValidator(validator);
    ui->zPTPEdit->setValidator(validator);
    ui->rPTPEdit->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onGetPoseTimer()
{
    QTimer *getPoseTimer = findChild<QTimer *>("getPoseTimer");
    Pose pose;

    while (GetPose(&pose) != DobotCommunicate_NoError) {
    }
    ui->joint1Label->setText(QString::number(pose.jointAngle[0]));
    ui->joint2Label->setText(QString::number(pose.jointAngle[1]));
    ui->joint3Label->setText(QString::number(pose.jointAngle[2]));
    ui->joint4Label->setText(QString::number(pose.jointAngle[3]));

    ui->xLabel->setText(QString::number(pose.x));
    ui->yLabel->setText(QString::number(pose.y));
    ui->zLabel->setText(QString::number(pose.z));
    ui->rLabel->setText(QString::number(pose.r));

    getPoseTimer->start();
}

void MainWindow::onChangedMode()
{
    if (ui->teachMode->currentIndex() == 1) {
        ui->baseAngleAddBtn->setText(tr("X+"));
        ui->baseAngleSubBtn->setText(tr("X-"));
        ui->longArmAddBtn->setText(tr("Y+"));
        ui->longArmSubBtn->setText(tr("Y-"));
        ui->shortArmAddBtn->setText(tr("Z+"));
        ui->shortArmSubBtn->setText(tr("Z-"));
        ui->rHeadAddBtn->setText(tr("R+"));
        ui->rHeadSubBtn->setText(tr("R-"));
    } else {
        ui->baseAngleAddBtn->setText(tr("J1+"));
        ui->baseAngleSubBtn->setText(tr("J1-"));
        ui->longArmAddBtn->setText(tr("J2+"));
        ui->longArmSubBtn->setText(tr("J2-"));
        ui->shortArmAddBtn->setText(tr("J3+"));
        ui->shortArmSubBtn->setText(tr("J3-"));
        ui->rHeadAddBtn->setText(tr("J4+"));
        ui->rHeadSubBtn->setText(tr("J4-"));
    }
}

void MainWindow::onConnectDobot()
{
    
	if (!m_dobot.isConnected()) {
		if (!m_dobot.connect()) {
			qDebug() << "error!!!";
			QMessageBox::information(this, tr("error"), tr("Connect dobot error!!!"), QMessageBox::Ok);
			return;
		}
        connectStatus = true;
        refreshBtn(); 
		m_dobot.init();
        initDobot();

        QTimer *getPoseTimer = findChild<QTimer *>("getPoseTimer");
        getPoseTimer->start(200);
        qDebug() << "connect success!!!";
    } else {
        QTimer *getPoseTimer = findChild<QTimer *>("getPoseTimer");
        getPoseTimer->stop();
        connectStatus = false;
        refreshBtn();
		m_dobot.disconnect();
    }
}

void MainWindow::refreshBtn()
{
    if (connectStatus) {
        ui->connectBtn->setText(tr("Disconnect"));

        ui->teachMode->setEnabled(true);
        ui->teachMode->setEnabled(true);
        ui->baseAngleAddBtn->setEnabled(true);
        ui->baseAngleSubBtn->setEnabled(true);
        ui->longArmAddBtn->setEnabled(true);
        ui->longArmSubBtn->setEnabled(true);
        ui->shortArmAddBtn->setEnabled(true);
        ui->shortArmSubBtn->setEnabled(true);
        ui->rHeadAddBtn->setEnabled(true);
        ui->rHeadSubBtn->setEnabled(true);

        ui->sendBtn->setEnabled(true);
        ui->xPTPEdit->setEnabled(true);
        ui->yPTPEdit->setEnabled(true);
        ui->zPTPEdit->setEnabled(true);
        ui->rPTPEdit->setEnabled(true);

		ui->PumpBtnON->setEnabled(true);
		ui->PumpBtnOFF->setEnabled(true);
		ui->HomeSafeBtn->setEnabled(true);
		ui->PrintBtn->setEnabled(true);
    } else {
        ui->connectBtn->setText(tr("Connect"));

        ui->teachMode->setEnabled(false);
        ui->baseAngleAddBtn->setEnabled(false);
        ui->baseAngleSubBtn->setEnabled(false);
        ui->longArmAddBtn->setEnabled(false);
        ui->longArmSubBtn->setEnabled(false);
        ui->shortArmAddBtn->setEnabled(false);
        ui->shortArmSubBtn->setEnabled(false);
        ui->rHeadAddBtn->setEnabled(false);
        ui->rHeadSubBtn->setEnabled(false);

        ui->sendBtn->setEnabled(false);
        ui->xPTPEdit->setEnabled(false);
        ui->yPTPEdit->setEnabled(false);
        ui->zPTPEdit->setEnabled(false);
        ui->rPTPEdit->setEnabled(false);

		ui->HomeSafeBtn->setEnabled(false);
		ui->PrintBtn->setEnabled(false);
    }
}

void MainWindow::initDobot()
{
	char deviceSN[64];
	GetDeviceSN(deviceSN, sizeof(deviceSN));
	ui->deviceSNLabel->setText(deviceSN);


	char deviceName[64];
	GetDeviceName(deviceName, sizeof(deviceName));
	ui->DeviceNameLabel->setText("Skynet");

	uint8_t majorVersion, minorVersion, revision;
	GetDeviceVersion(&majorVersion, &minorVersion, &revision);
	ui->DeviceInfoLabel->setText(QString::number(majorVersion) + "." + QString::number(minorVersion) + "." + QString::number(revision));
}

void MainWindow::initControl()
{
    QSignalMapper *signalMapper  = new QSignalMapper(this);

    connect(ui->baseAngleAddBtn, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->baseAngleSubBtn, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->longArmAddBtn, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->longArmSubBtn, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->shortArmAddBtn, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->shortArmSubBtn, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->rHeadAddBtn, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->rHeadSubBtn, SIGNAL(pressed()), signalMapper, SLOT(map()));

    signalMapper->setMapping(ui->baseAngleAddBtn, 0);
    signalMapper->setMapping(ui->baseAngleSubBtn, 1);
    signalMapper->setMapping(ui->longArmAddBtn, 2);
    signalMapper->setMapping(ui->longArmSubBtn, 3);
    signalMapper->setMapping(ui->shortArmAddBtn, 4);
    signalMapper->setMapping(ui->shortArmSubBtn, 5);
    signalMapper->setMapping(ui->rHeadAddBtn, 6);
    signalMapper->setMapping(ui->rHeadSubBtn, 7);

    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(onJOGCtrlBtnPressed(int)));

    connect(ui->baseAngleAddBtn, SIGNAL(released()), this, SLOT(onJOGCtrlBtnReleased()));
    connect(ui->baseAngleSubBtn, SIGNAL(released()), this, SLOT(onJOGCtrlBtnReleased()));
    connect(ui->longArmAddBtn, SIGNAL(released()), this, SLOT(onJOGCtrlBtnReleased()));
    connect(ui->longArmSubBtn, SIGNAL(released()), this, SLOT(onJOGCtrlBtnReleased()));
    connect(ui->shortArmAddBtn, SIGNAL(released()), this, SLOT(onJOGCtrlBtnReleased()));
    connect(ui->shortArmSubBtn, SIGNAL(released()), this, SLOT(onJOGCtrlBtnReleased()));
    connect(ui->rHeadAddBtn, SIGNAL(released()), this, SLOT(onJOGCtrlBtnReleased()));
    connect(ui->rHeadSubBtn, SIGNAL(released()), this, SLOT(onJOGCtrlBtnReleased()));
}

void MainWindow::onJOGCtrlBtnPressed(int index)
{
	m_dobot.JOGCtrlBtnPressed(index, ui->teachMode->currentIndex() == 1);
}

void MainWindow::onJOGCtrlBtnReleased()
{
	m_dobot.JOGCtrlBtnReleased(ui->teachMode->currentIndex() == 1);
}

void MainWindow::onPumpBtnClicked()
{
	m_dobot.enablePumpCtrl();
}

void MainWindow::onHomeSafeBtnClicked()
{
	ui->HomeSafeBtn->setEnabled(false);
	m_dobot.HomeSafeBtnClicked();
	ui->HomeSafeBtn->setEnabled(true);
}


void MainWindow::onPTPsendBtnClicked()
{
    ui->sendBtn->setEnabled(false);
	m_dobot.PTPSendBtnClicked(ui->xPTPEdit->text().toFloat(), 
		ui->yPTPEdit->text().toFloat(), 
		ui->zPTPEdit->text().toFloat(), 
		ui->rPTPEdit->text().toFloat());

    ui->sendBtn->setEnabled(true);
}

void MainWindow::onPrintBtnClicked()
{
	ui->PrintBtn->setEnabled(false);
	QString buttonText = ui->stringType->text();
	std::string stringToPrint = buttonText.toLocal8Bit().constData();
	for (unsigned i = 0; i < stringToPrint.size(); i++)
	{
		const char charToPrint = stringToPrint[i];
		Point keyCoord = m_keyboard.getKeyCoord(charToPrint);
		m_dobot.PrintBtnClicked(keyCoord);
	}
	ui->PrintBtn->setEnabled(true);
}

/*void MainWindow::connectCam() // work in progress
{
	m_index = 0;
	m_thread = new CaptureThread(this);
	connect(m_thread, SIGNAL(captured(QImage, unsigned char *)),
		this, SLOT(process(QImage, unsigned char *)));
	m_thread->start();

	if (CameraInit(m_index) == API_ERROR) {
		QMessageBox::information(this, "Error", "Connect Camera error. Please insert Camera USB repeatedly.");
		exit(1);
	}
	m_thread->setIndex(m_index);
}*/

/*void MainWindow::initCamParams() //work in progress
{
	CameraSetSnapMode(m_index, CAMERA_SNAP_CONTINUATION);
	int width = 2048;
	int height = 1536;
	CameraSetResolution(m_index, 0, &width, &height);

	double gamma = 1.34;
	CameraSetGamma(m_index, gamma);

	double contrast = 1;
	CameraSetContrast(m_index, contrast);

	int gain = 63;
	CameraSetGain(m_index, gain);
	CameraSetAEC(m_index, true);
	CameraSetAGC(m_index, false);

	int exposure = 1450;
	CameraSetExposure(m_index, exposure);
	CameraSetAEC(m_index, false);
	CameraSetAWB(m_index, false);

	for (int i = 0; i < 256; i++)
	{
		vcolorTable.append(qRgb(i, i, i));
	}
	m_thread->stream();
}*/

void MainWindow::closeEvent(QCloseEvent *)
{

}

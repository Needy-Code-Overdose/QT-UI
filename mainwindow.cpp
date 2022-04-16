#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Check before use camera
    switch(CamCheck()){
        case 0: qDebug("No Cam Found");break;
        case 1: qDebug("Cam Works Fine");break;
        default: qDebug("Unknown Error");//Never excute it
    }

    // Init Camera
    Cam1.reset(new QCamera(QMediaDevices::defaultVideoInput()));

    //Capture Camera
    CamCaptureSession1.setCamera(Cam1.data());
    CamCaptureSession1.setVideoOutput(ui->CamDisplayWidget1);

    //Start
    Cam1->start();

    //New a capturer
    CamImageCapture = new QImageCapture();
    CamCaptureSession1.setImageCapture(CamImageCapture);

    //Get the PWD
    QDir dir;
    CurrentPath = dir.currentPath();


}

int MainWindow::CamCheck()
{
    if (QMediaDevices::videoInputs().count() > 0)
        return 1;//Good
    else
        return 0;//Damn
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_CaptureButton_clicked()
{
    CamImageCapture->captureToFile(CurrentPath+"CapturedPic"); //Capture it to PWD
}


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCamera>
#include <QDir>
#include <QMediaCaptureSession>
#include <QMediaDevices>
#include <QMediaRecorder>
#include <QImageCapture>
#include <QVideoWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_CaptureButton_clicked();

private:
    Ui::MainWindow *ui;
    QScopedPointer<QCamera> Cam1;
    QScopedPointer<QMediaRecorder> CamRecorder1;
    QMediaCaptureSession CamCaptureSession1;
    QImageCapture* CamImageCapture;
    int CamCheck(void);
    QString CurrentPath;
};
#endif // MAINWINDOW_H

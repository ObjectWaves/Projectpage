#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir d(QStandardPaths::writableLocation(QStandardPaths::DownloadLocation));
    ui->widget->setPath(d.path());
}

MainWindow::~MainWindow()
{
    delete ui;
}


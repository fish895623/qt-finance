#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "echoclient.h"

MainWindow::MainWindow(QWidget* parent)
  : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  manager = new QNetworkAccessManager();

  a = new EchoClient(QUrl("wss://socketsbay.com/wss/v2/1/demo/"));

  connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::managerFinished);
  connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
}

void MainWindow::onPushButtonClicked() {
}

void MainWindow::managerFinished(QNetworkReply* reply) {
  if (reply->error()) {
    qDebug() << reply->errorString();
    return;
  }

  QString answer = reply->readAll();
  ui->textEdit->setText(answer);
  qDebug() << answer;
}

MainWindow::~MainWindow() {
  delete ui;
  delete manager;
}

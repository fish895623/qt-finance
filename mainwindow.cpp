#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
  : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  manager = new QNetworkAccessManager();

  connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::managerFinished);
  connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
}

void MainWindow::onPushButtonClicked() {
  request.setUrl(QUrl("https://www.google.com"));
  manager->get(request);
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

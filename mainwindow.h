#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qobject.h>
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTextEdit>
#include "echoclient.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow() override;

 private:
  Ui::MainWindow* ui;
  QNetworkAccessManager* manager;
  EchoClient* a;
  QNetworkRequest request;

 private slots:
  void managerFinished(QNetworkReply* reply);
  void onPushButtonClicked();
};
#endif  // MAINWINDOW_H

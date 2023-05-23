// Copyright (C) 2016 Kurt Pattyn <pattyn.kurt@gmail.com>.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
#include "echoclient.h"
#include <QtCore/QDebug>

QT_USE_NAMESPACE

//! [constructor]
EchoClient::EchoClient(const QUrl& url, bool debug, QObject* parent)
  : QObject(parent) {
  qDebug() << "WebSocket server:" << url;
  connect(&m_webSocket, &QWebSocket::connected, this, &EchoClient::onConnected);
  connect(&m_webSocket, &QWebSocket::disconnected, this, &EchoClient::closed);
  m_webSocket.open(QUrl("wss://socketsbay.com/wss/v2/1/demo/"));
}
//! [constructor]

//! [onConnected]
void EchoClient::onConnected() {
  qDebug() << "WebSocket connected";
  connect(&m_webSocket, &QWebSocket::textMessageReceived,
          this, &EchoClient::onTextMessageReceived);
  m_webSocket.sendTextMessage(QStringLiteral("Hello, world!"));
}
//! [onConnected]

//! [onTextMessageReceived]
void EchoClient::onTextMessageReceived(QString message) {
  qDebug() << "Message received:" << message;
  m_webSocket.close();
}
//! [onTextMessageReceived]

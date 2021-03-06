/*************************************************************************
 ** This file is part of QSkyDrive Explorer
 ** Copyright (C) 2012 Stanislav Ionascu <stanislav.ionascu@gmail.com>
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#ifndef RESTCLIENT_H
#define RESTCLIENT_H

#include <QObject>
#include <QUrl>
#include <QVariantMap>

class RestClientPrivate;
class QNetworkReply;

class RestClient : public QObject
{
    Q_OBJECT
public:
    void destroy();
    static RestClient *instance();

    QNetworkReply *get(const QUrl &url);
    QNetworkReply *post(const QUrl &url, const QByteArray &data);
    QNetworkReply *post(const QUrl &url, const QVariant &data);
    QNetworkReply *remove(const QUrl &url);
    QNetworkReply *put(const QUrl &url, QIODevice *data = 0);

signals:
    void requestFinished(QNetworkReply *reply);

private:
    explicit RestClient(QObject *parent = 0);
    virtual ~RestClient();

private:
    Q_DECLARE_PRIVATE(RestClient)
    RestClientPrivate *d_ptr;
};

#endif // RESTCLIENT_H

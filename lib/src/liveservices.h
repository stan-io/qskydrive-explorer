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

#ifndef LIVESERVICES_H
#define LIVESERVICES_H

#include <QObject>

class LiveServicesPrivate;
class SkyDriveService;

class LiveServices : public QObject
{
    Q_OBJECT
public:
    explicit LiveServices(const QString &refreshToken, QObject *parent = 0);
    virtual ~LiveServices();

    SkyDriveService *skyDriveService();
    const QString &accessToken() const;

signals:
    void signInSucceded();
    void signInFailed();

public slots:
    void signIn();

private:
    Q_PRIVATE_SLOT(d_func(), void _q_checkSignInReply())

private:
    Q_DECLARE_PRIVATE(LiveServices)
    LiveServicesPrivate *d_ptr;
};

#endif // LIVESERVICES_H

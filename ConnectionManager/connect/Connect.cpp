/*************************************************************************

bq Cervantes e-book reader application
Copyright (C) 2011-2013  Mundoreader, S.L

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with the source code.  If not, see <http://www.gnu.org/licenses/>.

*************************************************************************/

#include <QDebug>
#include <QObject>
#include <QApplication>

#include <Connect.h>


Connect::Connect(QObject *parent, ConnectionManager *cm) : QObject(parent) { 
	this->cm = cm;
};

void Connect::doWork() {
	QString path = QCoreApplication::arguments()[1];
	qDebug() << "sending request to connect to: " << path;
        QList<Network> networks = cm->getNetworks();
	foreach (Network n, networks) {
		if (n.getPath() == path) {
			QString state = n.getState();
			qDebug() << "network " << path << " has state " << state;
			if (state == "failure") {
				qDebug() << "network was in failure state, removing it for reseting";
				cm->remove(path);
			}
		}
	}
	cm->connectTo(path);
	QApplication::quit();
}

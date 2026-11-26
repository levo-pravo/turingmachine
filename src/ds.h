#pragma once

#include <QString>
#include <QSet>
#include <qchar.h>
#include <qobject.h>

struct alphs {
    QString base, extra;
};

QString getUnique(const QString& str);
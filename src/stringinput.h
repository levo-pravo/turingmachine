#pragma once

#include <QLineEdit>
#include <qobject.h>
#include <qwidget.h>

class StringInput : public QWidget {
    Q_OBJECT

public:
    explicit StringInput(QWidget *parent = nullptr);

private:
    QLineEdit *lineEdit;
};
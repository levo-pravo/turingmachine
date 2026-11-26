#pragma once

#include <QDialog>
#include <QLineEdit>
#include <qobject.h>
#include "ds.h"

class AlphabetDialog : public QDialog {
    Q_OBJECT

public:
    AlphabetDialog(QWidget *parent = nullptr);
    alphs getData() const;

private:
    QLineEdit *mainA, *dopA;
    QPushButton *button;
    bool f = 0;
};
#pragma once

#include <QMainWindow>
#include <qlabel.h>
#include <qpushbutton.h>
#include "alphabetdialog.h"
#include "stringinput.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() {}

private:
    AlphabetDialog *AlphabetD;
    QPushButton *setAlphsButton;
    StringInput *stringInput;
    QLabel *baseLabel, *extraLabel;
};
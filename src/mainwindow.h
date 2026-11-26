#pragma once

#include <QMainWindow>
#include "alphabetdialog.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() {}

private:
    AlphabetDialog *AlphabetD;
};
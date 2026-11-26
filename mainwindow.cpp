#include "mainwindow.h"
#include "alphabetdialog.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("Эмулятор машины Тьюринга");
    resize(1200, 800);

    AlphabetDialog AlphabetD(this);
    AlphabetD.exec();
}
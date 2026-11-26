#include "mainwindow.h"
#include <QShortcut>
#include <QKeySequence>
#include <QApplication>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("Эмулятор машины Тьюринга");
    resize(1200, 800);

    QShortcut *quitShortcut = new QShortcut(QKeySequence::Quit, this);
    connect(quitShortcut, &QShortcut::activated, qApp, &QApplication::quit);

    AlphabetD = new AlphabetDialog(this);
    AlphabetD->exec();
}
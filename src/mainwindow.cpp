#include "mainwindow.h"
#include "state.h"
#include "stringinput.h"
#include <QShortcut>
#include <QKeySequence>
#include <QApplication>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qlogging.h>
#include <qpushbutton.h>
#include <QVBoxLayout>
#include <qwidget.h>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("Эмулятор машины Тьюринга");
    resize(600, 400);
    
    QShortcut *quitShortcut = new QShortcut(QKeySequence::Quit, this);
    connect(quitShortcut, &QShortcut::activated, qApp, &QApplication::quit);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    stringInput = new StringInput(this);
    State::instance().setAlphabets({"ab", ""});
    
    setAlphsButton = new QPushButton("Задать алфавиты", this);
    connect(setAlphsButton, &QPushButton::clicked, [this]() {
        AlphabetD = new AlphabetDialog(this);
        AlphabetD->exec();
    });

    baseLabel = new QLabel(State::instance().alphabets().base, this);
    extraLabel = new QLabel(State::instance().alphabets().extra, this);

    QVBoxLayout* vert = new QVBoxLayout(centralWidget);
    vert->addWidget(setAlphsButton);
    vert->addWidget(stringInput);
    vert->addWidget(baseLabel);
    vert->addWidget(extraLabel);

    connect(&State::instance(), &State::alphabetsChanged, [this]() {
        baseLabel->setText(State::instance().alphabets().base);
        extraLabel->setText(State::instance().alphabets().extra);
    });
}
#include "alphabetdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <qboxlayout.h>
#include <qobject.h>
#include <qpushbutton.h>

AlphabetDialog::AlphabetDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Задать алфавиты");
    resize(400, 200);

    QVBoxLayout *vertical = new QVBoxLayout(this);
    QHBoxLayout *horizontal = new QHBoxLayout();

    QVBoxLayout *left = new QVBoxLayout();
    left->setSpacing(4);
    QLabel *mainL = new QLabel("Алфавит строки:", this);
    mainA = new QLineEdit(this);
    left->addWidget(mainL);
    left->addWidget(mainA);

    QVBoxLayout *right = new QVBoxLayout();
    right->setSpacing(4);
    QLabel *dopL = new QLabel("Алфавит доп. символов:", this);
    dopA = new QLineEdit(this);
    right->addWidget(dopL);
    right->addWidget(dopA);

    horizontal->addStretch();
    horizontal->addLayout(left);
    horizontal->addStretch();
    horizontal->addLayout(right);
    horizontal->addStretch();
    vertical->addStretch();
    vertical->addLayout(horizontal);
    vertical->addStretch();

    QHBoxLayout *down = new QHBoxLayout();
    down->addStretch();
    QPushButton *button = new QPushButton("Задать алфавиты", this);
    connect(button, &QPushButton::clicked, [&](){
        close();
    });
    down->addWidget(button);
    down->addStretch();
    vertical->addLayout(down);

    QHBoxLayout *down2 = new QHBoxLayout();
    down2->addStretch();
    QPushButton *button2 = new QPushButton("Отмена", this);
    connect(button2, &QPushButton::clicked, [&](){
        mainA->setText("");
        dopA->setText("");
        close();
    });
    down2->addWidget(button2);
    down2->addStretch();
    vertical->addLayout(down2);

    vertical->addStretch();

    setLayout(vertical);
}

alphs AlphabetDialog::getData() const {
    return {mainA->text(), dopA->text()};
}
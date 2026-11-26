#include "alphabetdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

AlphabetDialog::AlphabetDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Задать алфавиты");
    resize(800, 400);

    QVBoxLayout *vertical = new QVBoxLayout(this);
    QHBoxLayout *horizontal = new QHBoxLayout(this);

    QVBoxLayout *left = new QVBoxLayout(this);
    QLabel *mainL = new QLabel("Алфавит строки:");
    QLineEdit *mainA = new QLineEdit();
    left->addWidget(mainL);
    left->addWidget(mainA);

    QVBoxLayout *right = new QVBoxLayout(this);
    QLabel *dopL = new QLabel("Алфавит доп. символов:");
    QLineEdit *dopA = new QLineEdit();
    left->addWidget(dopL);
    left->addWidget(dopA);

    horizontal->addLayout(left);
    horizontal->addLayout(right);
}
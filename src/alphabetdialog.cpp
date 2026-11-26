#include "alphabetdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <qboxlayout.h>
#include <qchar.h>
#include <qobject.h>
#include <qpushbutton.h>
#include "state.h"

bool uniting(const QString& a, const QString& b) {
    for (QChar ch : b) {
        if (a.contains(ch)) return true;
    }
    return false;
}

AlphabetDialog::AlphabetDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Задать алфавиты");
    resize(400, 200);

    QVBoxLayout *vertical = new QVBoxLayout(this);
    QHBoxLayout *horizontal = new QHBoxLayout();

    QVBoxLayout *left = new QVBoxLayout();
    left->setSpacing(4);
    QLabel *mainL = new QLabel("Алфавит строки:", this);
    mainA = new QLineEdit(this);
    mainA->setText(State::instance().alphabets().base);
    left->addWidget(mainL);
    left->addWidget(mainA);

    QVBoxLayout *right = new QVBoxLayout();
    right->setSpacing(4);
    QLabel *dopL = new QLabel("Алфавит доп. символов:", this);
    dopA = new QLineEdit(this);
    dopA->setText(State::instance().alphabets().extra);
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
    button = new QPushButton("Задать алфавиты", this);
    connect(button, &QPushButton::clicked, [this](){
        alphs before = State::instance().alphabets();
        if (before.base == getUnique(mainA->text()) && before.extra == getUnique(dopA->text())) {
            if (f) {
                button->setText("Изменений не произошло");
                f = 0;
            } else {
                button->setText("Изменения отсутствуют");
                f = 1;
            }
        } else if (uniting(mainA->text(), dopA->text())) {
            if (f) {
                button->setText("Алфавиты перекрываются");
                f = 0;
            } else {
                button->setText("Алфавиты имеют общие буквы");
                f = 1;
            }
        } else {
            State::instance().setAlphabets({getUnique(mainA->text()), getUnique(dopA->text())});
            button->setText("Задать алфавиты");
            close();
        }
    });
    down->addWidget(button);
    down->addStretch();
    vertical->addLayout(down);

    QHBoxLayout *down2 = new QHBoxLayout();
    down2->addStretch();
    QPushButton *button2 = new QPushButton("Отмена", this);
    connect(button2, &QPushButton::clicked, [this](){
        close();
    });
    down2->addWidget(button2);
    down2->addStretch();
    vertical->addLayout(down2);

    vertical->addStretch();
}

alphs AlphabetDialog::getData() const {
    return {mainA->text(), dopA->text()};
}
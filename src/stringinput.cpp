#include "stringinput.h"
#include <qdebug.h>
#include <qlineedit.h>
#include <qobject.h>
#include <qregularexpression.h>
#include <qvalidator.h>
#include <qwidget.h>
#include "state.h"
#include <QDebug>

StringInput::StringInput(QWidget *parent) : QWidget(parent) {
    lineEdit = new QLineEdit(this);
    connect(&State::instance(), &State::alphabetsChanged, [this]() {
        lineEdit->setText("");
        if (State::instance().alphabets().base.isEmpty()) {
            qDebug() << "hi!";
            lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^$"), this));
            return;
        }
        QString escaped = QRegularExpression::escape(State::instance().alphabets().base);
        QRegularExpression regex(QString("^[%1]*$").arg(escaped));
        QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);
        lineEdit->setValidator(validator);
    });
}
#pragma once
#include <QObject>
#include <QString>
#include "ds.h"

class State : public QObject {
    Q_OBJECT

public:
    static State& instance() { //тут static для вызова без создания объекта
        static State instance; //тут, чтобы создалось только раз
        return instance; //instance - ссылка на этот когда-то созданный объект
    }

    //запрет на копирование
    State(const State&) = delete;
    State& operator=(const State&) = delete;

    const alphs& alphabets() const { return A; }
    void setAlphabets(const alphs& as) {
        if (A.base != as.base || A.extra != as.extra) {
            A.base = as.base;
            A.extra = as.extra;
            emit alphabetsChanged();
        }
    }

signals:
    void alphabetsChanged();

private:
    explicit State(QObject* parent = nullptr) : QObject(parent) {}
    alphs A;
};

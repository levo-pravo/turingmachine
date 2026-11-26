#pragma once
#include <QObject>
#include <QString>

class State : public QObject {
    Q_OBJECT

public:
    static State& instance() {
        static State instance;
        return instance;
    }

    State(const State&) = delete;
    State& operator=(const State&) = delete;

    QString userName() const { return m_userName; }
    void setUserName(const QString& name) {
        if (m_userName != name) {
            m_userName = name;
            emit userNameChanged();
        }
    }

signals:
    void userNameChanged();

private:
    explicit State(QObject* parent = nullptr) : QObject(parent) {}
    QString m_userName = "Гость";
};

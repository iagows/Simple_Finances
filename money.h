#ifndef MONEY_H
#define MONEY_H

#include <QString>
#include <QDateTime>

class Money
{
public:
    Money(const int id, const QString &description, const double value, const QDateTime &dt);

    int id;
    int getId();
    QString getDescription();
    double getValue();
    QDateTime getDateTime();
private:
    QString desc;
    double value;
    QDateTime dt;
};

#endif // MONEY_H

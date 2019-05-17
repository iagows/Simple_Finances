#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QtSql>

#include "money.h"

class DbManager
{
public:
    DbManager(const QString &path);
    ~DbManager();
    bool addIncome(Money &m);
    bool removeIncome(Money &m);

    bool addOutcome(Money &m);
    bool removeOutcome(Money &m);

private:
    enum Type {
        INCOME,
        OUTCOME
    };
    QSqlDatabase db;
    bool add(Money &m, Type t);
    bool remove(Money &m, Type t);
    QString getTable(Type t);
};

#endif // DBMANAGER_H

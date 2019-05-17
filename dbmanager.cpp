#include "dbmanager.h"

#include <QStringBuilder>

DbManager::DbManager()
{

}

DbManager::~DbManager()
{
    if (isOpen()) {
        db.close();
    }
}

QSqlDatabase DbManager::getModel()
{
    return db;
}

bool DbManager::open(const QString &path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    return db.open();
}

void DbManager::createDB(const QString &path)
{

}

bool DbManager::isOpen()
{
    return db.isOpen();
}

bool DbManager::addIncome(Money &m)
{
    return add(m, INCOME);
}

bool DbManager::removeIncome(Money &m)
{
    return remove(m, INCOME);
}

bool DbManager::addOutcome(Money &m)
{
    return add(m, OUTCOME);
}

bool DbManager::removeOutcome(Money &m)
{
    return remove(m, OUTCOME);
}

bool DbManager::add(Money &m, DbManager::Type t)
{
    bool success = false;
    QSqlQuery query;

    query.prepare("INSERT INTO " % getTable(t) % " (description, amount, datetime) VALUES (:desc, :amount, :dt)");
    query.bindValue(":desc", m.getDescription());
    query.bindValue(":amount", m.getValue());
    query.bindValue(":dt", m.getDateTime());

    if (query.exec()) {
        success = true;

    } else {
        qDebug() << "Add income error:  "
                 << query.lastError();
    }

    return success;
}

bool DbManager::remove(Money &m, DbManager::Type t)
{
    bool success = false;
    QSqlQuery query;
    query.prepare("DELETE FROM " % getTable(t) % " WHERE id = (:id)");
    query.bindValue(":id", m.getId());
    success = query.exec();

    if (!success) {
        qDebug() << "removePerson error: "
                 << query.lastError();
    }

    return success;
}

QString DbManager::getTable(DbManager::Type t)
{
    return t == INCOME ? "income" : "outcome";
}

#include "money.h"

Money::Money(const int id, const QString &description, const double value, const QDateTime &dt)
{
    this->id = id;
    this->desc = description;
    this->value = value;
    this->dt = dt;
}

int Money::getId()
{
    return this->id;
}

QString Money::getDescription()
{
    return this->desc;
}

double Money::getValue()
{
    return this->value;
}

QDateTime Money::getDateTime()
{
    return this->dt;
}

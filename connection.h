#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


class connection
{
public:
    connection();
    bool createConnection();
};

#endif // CONNECTION_H

#include "connection.h"

connection::connection()
{

}
bool connection::createConnection()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");//inserer le nom de la source de données ODBC
    db.setUserName("system");//inserer nom de l'utilisateur
    db.setPassword("0000");//inserer mot de passe de cet utilisateur

    if (db.open())
    test=true;

        return  test;
}

#ifndef SQLITECONNECTION_H
#define SQLITECONNECTION_H

#include <iostream>
#include <sqlite3.h>
#include <string>

using namespace std;

class SQLiteConnection
{
private:
    sqlite3 * db;
    string dbPath;
    int status;
    char *zErrMsg = 0;
public:
    SQLiteConnection();
    ~SQLiteConnection();
    void setDatabaseFile(string path);
    string getDatabaseFile();
    bool openDataBase();
    void executeQuery(string query);
private:
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
};

#endif // SQLITECONNECTION_H

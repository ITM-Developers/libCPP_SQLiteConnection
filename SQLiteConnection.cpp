#include "SQLiteConnection.h"

ConexionSQLite::ConexionSQLite()
{

}

void ConexionSQLite::setDatabaseFile(string path){
    dbPath = path;
}

string ConexionSQLite::getDatabaseFile(){
    return dbPath;
}

bool ConexionSQLite::openDataBase(){
    status = sqlite3_open(dbPath.c_str(), &db);
    if( status != SQLITE_OK ){
        cout << "No se puede abrir la base de datos: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return false;
    }else{
        return true;
    }
}

void ConexionSQLite::executeQuery( string query ){
    status = sqlite3_exec(db, query.c_str(), callback, 0, &zErrMsg);

    if( status != SQLITE_OK ){
        cout << "Error SQL: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
}

int ConexionSQLite::callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    return EXIT_SUCCESS;
}

ConexionSQLite::~ConexionSQLite()
{
    sqlite3_free(zErrMsg);
    sqlite3_close(db);
}

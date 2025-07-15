#pragma once
#include "DatabaseInterface.h"
class SQLDatabaseConnector :
	public DatabaseInterface
{
public:
	bool ConectarConBaseDeDatos(string nombreDeBaseDeDatos) override
	{
		// hacer la conexión a la base de datos de SQL con el nombre recibido como parámetro.
		return true;
	}

	bool DesconectarConBaseDeDatos(string nombreDeBaseDeDatos) override
	{
		// hacer la desconexión a la base de datos de SQL con el nombre recibido como parámetro.
		return true;
	}

	string* RealizarQuery(string query) override 
	{
		string myString;
		// hacer la query a la base de datos de SQL con el query recibido como parámetro.
		return &myString;
	}

};


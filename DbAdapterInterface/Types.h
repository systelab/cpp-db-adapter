#pragma once

namespace systelab { namespace db {

	enum FieldTypes
	{
		BOOLEAN,
		INT,
		DOUBLE,
		STRING,
		DATETIME,
		BINARY
	};

	typedef int RowsAffected;

	typedef long RowId;
}}


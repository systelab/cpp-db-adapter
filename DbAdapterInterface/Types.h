#pragma once

#include <chrono>

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

#if DB_DATETIME_PRECISION_SECONDS
	using DateTimeType = std::chrono::sys_seconds;
#elif DB_DATETIME_PRECISION_MILLISECONDS
	using DateTimeType = std::chrono::sys_time<std::chrono::milliseconds>;
#else
	using DateTimeType = std::chrono::sys_time<std::chrono::microseconds>;
#endif
}}


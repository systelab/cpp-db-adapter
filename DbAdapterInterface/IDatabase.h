#pragma once

#include "Types.h"

#include <memory>

namespace systelab::db {
	class ITable;
	class IRecordSet;
	class ITransaction;

	class IDatabase
	{
	public:
		virtual ~IDatabase() = default;

		virtual ITable& getTable(cosnt std::string& tableName) = 0;
		virtual std::unique_ptr<IRecordSet> executeQuery(const std::string& query) = 0;
		virtual void executeOperation(const std::string& operation) = 0;
		virtual void executeMultipleStatements(const std::string& statements) = 0;
		virtual RowsAffected getRowsAffectedByLastChangeOperation() const = 0;
		virtual RowId getLastInsertedRowId() const = 0;
		virtual std::unique_ptr<ITransaction> startTransaction() = 0;
	};
}


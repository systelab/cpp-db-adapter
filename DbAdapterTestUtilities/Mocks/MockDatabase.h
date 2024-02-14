#pragma once

#include "DbAdapterInterface/IDatabase.h"
#include "DbAdapterInterface/IRecordSet.h"
#include "DbAdapterInterface/ITable.h"
#include "DbAdapterInterface/ITransaction.h"
#include "DbAdapterInterface/Types.h"

namespace systelab::db::test_utility {

	class MockDatabase: public IDatabase
	{
	public:
		MockDatabase();
		virtual ~MockDatabase();

		MOCK_METHOD(ITable& , getTable, (std::string), (override));

		MOCK_METHOD(std::unique_ptr<IRecordSet>, executeQuery, (const std::string&), (override));
		MOCK_METHOD(void, executeOperation, (const std::string&), (override));
		MOCK_METHOD(void, executeMultipleStatements, (const std::string&), (override));
		MOCK_METHOD(RowsAffected, getRowsAffectedByLastChangeOperation, (), (const, override));
		MOCK_METHOD(RowId, getLastInsertedRowId, (), (const, override));

		MOCK_METHOD(std::unique_ptr<ITransaction>, startTransaction, (), (override));

		void addTable(std::unique_ptr<ITable> table)
		{
			ITable* tableRawPtr = table.release();
			m_tables.push_back( tableRawPtr );

			std::string tableName = tableRawPtr->getName();
			ON_CALL(*this, getTable(tableName)).WillByDefault(testing::ReturnRef(*tableRawPtr));
		}

	private:
		std::vector<ITable*> m_tables;
	};
}


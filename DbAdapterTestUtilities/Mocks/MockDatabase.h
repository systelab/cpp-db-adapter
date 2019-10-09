#pragma once

#include "DbAdapterInterface/IDatabase.h"


namespace systelab { namespace db { namespace test_utility {

	class MockDatabase: public IDatabase
	{
	public:
		MockDatabase();
		virtual ~MockDatabase();

		MOCK_METHOD1(getTable, ITable& (std::string tableName));

		MOCK_METHOD1(executeQueryProxy, IRecordSet* (const std::string& query));
		std::unique_ptr<IRecordSet> executeQuery(const std::string& query)
		{
			return std::unique_ptr<db::IRecordSet>(executeQueryProxy(query));
		}

		MOCK_METHOD1(executeOperation, void (const std::string& operation));
		MOCK_METHOD1(executeMultipleStatements, void (const std::string& operation));
		MOCK_CONST_METHOD0(getRowsAffectedByLastChangeOperation, RowsAffected());
		MOCK_CONST_METHOD0(getLastInsertedRowId, RowId());

		MOCK_METHOD0(startTransactionProxy, ITransaction* ());
		std::unique_ptr<ITransaction> startTransaction()
		{
			return std::unique_ptr<ITransaction>(startTransactionProxy());
		};

		void addTable(std::unique_ptr<ITable> table)
		{
			ITable* tableRawPtr = table.release();
			m_tables.push_back( tableRawPtr );

			std::string tableName = tableRawPtr->getName();
			ON_CALL(*this, getTable(tableName)).WillRepeatedly(testing::ReturnRef(*tableRawPtr));
		}

	private:
		std::vector<ITable*> m_tables;
	};

}}}


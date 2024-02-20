#pragma once

#include "DbAdapterInterface/ITableRecord.h"
#include "DbAdapterInterface/ITable.h"

#include "MockFieldValue.h"


namespace systelab::db::test_utility {

	class MockTableRecord : public ITableRecord
	{
	public:
		MockTableRecord();
		~MockTableRecord() override;

		MOCK_METHOD(ITable& , getTable, (), (const, override));

		MOCK_METHOD(unsigned int, getFieldValuesCount, (), (const, override));
		MOCK_METHOD(IFieldValue&, getFieldValue, (unsigned int), (const, override));
		MOCK_METHOD(IFieldValue&, getFieldValue, (const std::string&), (const, override));

		MOCK_METHOD(bool, hasFieldValue, (const std::string&), (const, override));

		MOCK_METHOD(std::vector<IFieldValue*>, getValuesList, (), (const, override));
	};
}


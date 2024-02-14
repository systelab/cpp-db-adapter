#pragma once

#include "DbAdapterInterface/IPrimaryKeyValue.h"
#include "DbAdapterInterface/ITable.h"

namespace systelab::db::test_utility {

	class MockPrimaryKeyValue : public IPrimaryKeyValue
	{
	public:
		MockPrimaryKeyValue();
		~MockPrimaryKeyValue() override;

		MOCK_METHOD(ITable& , getTable, (), (const, override));
		MOCK_METHOD(IPrimaryKey& , getPrimaryKey, (), (const, override));

		MOCK_METHOD(unsigned int, getFieldValuesCount, (), (const, override));
		MOCK_METHOD(IFieldValue& , getFieldValue, (unsigned int), (const, override));
		MOCK_METHOD(IFieldValue& , getFieldValue, (const std::string&), (const, override));
	};
}

#pragma once

#include "DbAdapterInterface/IPrimaryKeyValue.h"


namespace systelab { namespace test_utility {

	using namespace testing;

	class MockPrimaryKeyValue : public db::IPrimaryKeyValue
	{
	public:
		MOCK_CONST_METHOD0(getTable, db::ITable&());
		MOCK_CONST_METHOD0(getPrimaryKey, db::IPrimaryKey&());

		MOCK_CONST_METHOD0(getFieldValuesCount, unsigned int());
		MOCK_CONST_METHOD1(getFieldValue, db::IFieldValue&(unsigned int));
		MOCK_CONST_METHOD1(getFieldValue, db::IFieldValue&(const std::string&));
	};
}}


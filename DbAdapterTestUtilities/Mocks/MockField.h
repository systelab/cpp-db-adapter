#pragma once

#include "DbAdapterInterface/IField.h"


namespace systelab::db::test_utility {

	using namespace testing;

	class MockField : public IField
	{
	public:
		MockField();
		virtual ~MockField();

		MOCK_METHOD(bool, hasNullDefaultValue, (), (const, override));
		MOCK_METHOD(unsigned int, getIndex, (), (const, override));
		MOCK_METHOD(std::string, getName, (), (const, override));
		MOCK_METHOD(FieldTypes, getType, (), (const, override));
		MOCK_METHOD(bool, isPrimaryKey, (), (const, override));

		MOCK_METHOD(int, getIntDefaultValue, (), (const, override));
		MOCK_METHOD(bool, getBooleanDefaultValue, (), (const, override));
		MOCK_METHOD(double, getDoubleDefaultValue, (), (const, override));
		MOCK_METHOD(std::string, getStringDefaultValue, (), (const, override));
		MOCK_METHOD(std::chrono::system_clock::time_point, getDateTimeDefaultValue, (), (const, override));
		MOCK_METHOD(IBinaryValue&, getBinaryDefaultValue, (), (const, override));
	};
}


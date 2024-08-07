#pragma once

#include "DbAdapterInterface/IBinaryValue.h"
#include "DbAdapterInterface/IField.h"
#include "DbAdapterInterface/IFieldValue.h"
#include "DbAdapterInterface/Types.h"

namespace systelab::db::test_utility {

	class MockFieldValue: public IFieldValue
	{
	public:
		MockFieldValue();
		~MockFieldValue() override;

		MOCK_METHOD(IField& , getField, (), (const, override));

		MOCK_METHOD(bool, isDefault, (), (const, override));
		MOCK_METHOD(bool, isNull, (), (const, override));
		MOCK_METHOD(bool, getBooleanValue, (), (const, override));
		MOCK_METHOD(int, getIntValue, (), (const, override));
		MOCK_METHOD(double, getDoubleValue, (), (const, override));
		MOCK_METHOD(std::string, getStringValue, (), (const, override));
		MOCK_METHOD(DateTimeType, getDateTimeValue, (), (const, override));
		MOCK_METHOD(IBinaryValue&, getBinaryValue, (), (const, override));

		MOCK_METHOD(void, setValue, (const IFieldValue&), (override));
		MOCK_METHOD(void, setNull, (), (override));
		MOCK_METHOD(void, setDefault, (), (override));
		MOCK_METHOD(void, setBooleanValue, (bool), (override));
		MOCK_METHOD(void, setIntValue, (int), (override));
		MOCK_METHOD(void, setDoubleValue, (double), (override));
		MOCK_METHOD(void, setStringValue, (const std::string&), (override));
		MOCK_METHOD(void, setDateTimeValue, (const DateTimeType&), (override));

		MOCK_METHOD(void, setBinaryValue, (std::unique_ptr<IBinaryValue>), (override));
		MOCK_METHOD(void, useDefaultValue, (), (override));

		MOCK_METHOD(std::unique_ptr<IFieldValue>, clone, (), (const, override));
	};

}


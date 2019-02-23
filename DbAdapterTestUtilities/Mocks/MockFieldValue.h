#pragma once

#include "DbAdapterInterface/IBinaryValue.h"
#include "DbAdapterInterface/IField.h"
#include "DbAdapterInterface/IFieldValue.h"


namespace systelab { namespace db { namespace test_utility {

	class MockFieldValue: public IFieldValue
	{
	public:
		MockFieldValue();
		virtual ~MockFieldValue();

		MOCK_CONST_METHOD0(getField, IField&());

		MOCK_CONST_METHOD0(isDefault, bool());
		MOCK_CONST_METHOD0(isNull, bool());
		MOCK_CONST_METHOD0(getBooleanValue, bool());
		MOCK_CONST_METHOD0(getIntValue, int());
		MOCK_CONST_METHOD0(getDoubleValue, double());
		MOCK_CONST_METHOD0(getStringValue, std::string());
		MOCK_CONST_METHOD0(getDateTimeValue, boost::posix_time::ptime());
		MOCK_CONST_METHOD0(getBinaryValue, IBinaryValue&());

		MOCK_METHOD1(setValue, void(const IFieldValue&));
		MOCK_METHOD0(setNull, void());
		MOCK_METHOD0(setDefault, void());
		MOCK_METHOD1(setBooleanValue, void(bool));
		MOCK_METHOD1(setIntValue, void(int));
		MOCK_METHOD1(setDoubleValue, void(double));
		MOCK_METHOD1(setStringValue, void(const std::string&));
		MOCK_METHOD1(setDateTimeValue, void(const boost::posix_time::ptime&));

		MOCK_METHOD1(setBinaryValueProxy, void(IBinaryValue*));
		void setBinaryValue(std::unique_ptr<IBinaryValue> value)
		{
			setBinaryValueProxy(value.release());
		};

		MOCK_METHOD0(useDefaultValue, void());

		MOCK_CONST_METHOD0(cloneProxy, IFieldValue*());
		std::unique_ptr<IFieldValue> clone() const
		{
			return std::unique_ptr<IFieldValue>(cloneProxy());
		}
	};

}}}


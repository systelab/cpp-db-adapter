#pragma once

#include "DbAdapterInterface/IBinaryValue.h"
#include "DbAdapterInterface/IField.h"


namespace systelab { namespace db { namespace test_utility {

	using namespace testing;

	class MockField : public IField
	{
	public:
		MockField();
		virtual ~MockField();

		MOCK_CONST_METHOD0(hasNullDefaultValue, bool());
		MOCK_CONST_METHOD0(getIndex, unsigned int());
		MOCK_CONST_METHOD0(getName, std::string());
		MOCK_CONST_METHOD0(getType, db::FieldTypes());
		MOCK_CONST_METHOD0(isPrimaryKey, bool());

		MOCK_CONST_METHOD0(getIntDefaultValue, int());
		MOCK_CONST_METHOD0(getBooleanDefaultValue, bool());
		MOCK_CONST_METHOD0(getDoubleDefaultValue, double());
		MOCK_CONST_METHOD0(getStringDefaultValue, std::string());
		MOCK_CONST_METHOD0(getDateTimeDefaultValue, boost::posix_time::ptime());
		MOCK_CONST_METHOD0(getBinaryDefaultValue, db::IBinaryValue&());
	};

}}}


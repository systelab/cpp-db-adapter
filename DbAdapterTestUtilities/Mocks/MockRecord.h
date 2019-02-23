#pragma once

#include "DbAdapterInterface/IRecord.h"

#include "MockFieldValue.h"


namespace systelab { namespace db { namespace test_utility {

	class MockRecord : public IRecord
	{
	public:
		MockRecord();
		virtual ~MockRecord();

		MOCK_CONST_METHOD0(getFieldValuesCount, unsigned int());
		MOCK_CONST_METHOD1(getFieldValue, IFieldValue&(unsigned int));
		MOCK_CONST_METHOD1(getFieldValue, IFieldValue&(const std::string&));
		MOCK_CONST_METHOD1(hasFieldValue, bool(const std::string&));
	};

}}}


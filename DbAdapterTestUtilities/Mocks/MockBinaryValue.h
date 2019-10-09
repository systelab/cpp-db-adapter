#pragma once

#include "DbAdapterInterface/IBinaryValue.h"

namespace systelab { namespace db { namespace test_utility {

	class MockBinaryValue : public IBinaryValue
	{
	public:
		MockBinaryValue();
		~MockBinaryValue();
	
		MOCK_CONST_METHOD0(getOutputStream, std::ostream());
		MOCK_CONST_METHOD0(getInputStream, std::istream());
	};
	
}}}

#pragma once

#include "DbAdapterInterface/IConnectionConfiguration.h"


namespace systelab { namespace db { namespace test_utility {

	class MockConnectionConfiguration: public IConnectionConfiguration
	{
	public:
		MOCK_CONST_METHOD1(getParameter, std::string (const std::string& parameterName));
	};

}}}


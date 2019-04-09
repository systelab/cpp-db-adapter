#pragma once

#include "DbAdapterInterface/IConnectionConfiguration.h"


namespace systelab { namespace db { namespace test_utility {

	class MockConnectionConfiguration: public IConnectionConfiguration
	{
	public:
		MockConnectionConfiguration();
		virtual ~MockConnectionConfiguration();

		MOCK_CONST_METHOD1(hasParameter, bool(const std::string& parameterName));
		MOCK_CONST_METHOD1(getParameter, std::string (const std::string& parameterName));
	};

}}}


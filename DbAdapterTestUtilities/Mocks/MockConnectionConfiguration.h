#pragma once

#include "DbAdapterInterface/IConnectionConfiguration.h"

namespace systelab { namespace test_utility {

	class MockConnectionConfiguration: public db::IConnectionConfiguration
	{
	public:
		MOCK_CONST_METHOD1(getParameter, std::string (const std::string& parameterName));
	};

}}


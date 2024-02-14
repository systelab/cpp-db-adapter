#pragma once

#include "DbAdapterInterface/IConnectionConfiguration.h"

namespace systelab::db::test_utility {

	class MockConnectionConfiguration: public IConnectionConfiguration
	{
	public:
		MockConnectionConfiguration();
		virtual ~MockConnectionConfiguration();

		MOCK_METHOD(bool, hasParameter, (const std::string& parameterName), (const, override));
		MOCK_METHOD(std::string, getParameter, (const std::string&), (const, override));
	};

}


#pragma once

#include <string>

namespace systelab { namespace db {

	class IConnectionConfiguration
	{
	public:
		virtual ~IConnectionConfiguration() {}
		virtual std::string getParameter(const std::string& parameterName) const = 0;
	};
}}


#pragma once

#include <string>

namespace systelab::db {

	class IConnectionConfiguration
	{
	public:
		virtual ~IConnectionConfiguration() {}

		virtual bool hasParameter(const std::string& parameterName) const = 0;
		virtual std::string getParameter(const std::string& parameterName) const = 0;
	};
}


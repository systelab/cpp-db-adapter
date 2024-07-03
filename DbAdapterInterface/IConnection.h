#pragma once

#include <memory>
#include <stdexcept>
#include <string>

namespace systelab::db {
	class IConnectionConfiguration;
	class IDatabase;

	class IConnection
	{
	public:
		virtual ~IConnection() {}

		virtual std::unique_ptr<IDatabase> loadDatabase(IConnectionConfiguration&) = 0;

	public:
		struct Exception : public std::runtime_error
		{
			Exception(const std::string& message)
				: std::runtime_error(message)
			{
			}
		};
	};
}


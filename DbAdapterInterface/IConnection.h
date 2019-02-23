#pragma once

#include "IDatabase.h"
#include "IConnectionConfiguration.h"

#include <memory>

namespace systelab { namespace db {
	class IConnection
	{
	public:
		virtual ~IConnection() {}

		virtual std::unique_ptr<IDatabase> loadDatabase(IConnectionConfiguration&) = 0;
	};
}}


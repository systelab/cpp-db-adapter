#pragma once

#include "Types.h"

namespace systelab::db {
	class ITransaction
	{
	public:
		virtual ~ITransaction() {}

		virtual void commit() = 0;
		virtual void rollback() = 0;
	};
}


#pragma once

#include "DbAdapterInterface/IConnection.h"
#include "DbAdapterInterface/IDatabase.h"

namespace systelab::db::test_utility {

	class MockConnection : public IConnection
	{
	public:
		MockConnection();
		~MockConnection() override;

		MOCK_METHOD(std::unique_ptr<IDatabase>, loadDatabase, (IConnectionConfiguration&), (override));
	};
}

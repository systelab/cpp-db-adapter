#pragma once

#include "DbAdapterInterface/IConnection.h"


namespace systelab { namespace db { namespace test_utility {

	class MockConnection : public IConnection
	{
	public:
		MockConnection();
		virtual ~MockConnection();

		MOCK_METHOD1(loadDatabaseProxy, db::IDatabase* (db::IConnectionConfiguration&));
		std::unique_ptr<db::IDatabase> loadDatabase(db::IConnectionConfiguration& config)
		{
			return std::unique_ptr<db::IDatabase>(loadDatabaseProxy(config));
		}
	};

}}}


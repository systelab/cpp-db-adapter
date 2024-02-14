#pragma once

#include "DbAdapterInterface/ITransaction.h"

namespace systelab::db::test_utility {

	class MockTransaction : public ITransaction
	{
	public:
		MockTransaction();
		~MockTransaction() override;

		MOCK_METHOD(void, commit, (), (override));
		MOCK_METHOD(void, rollback, (), (override));
	};
}


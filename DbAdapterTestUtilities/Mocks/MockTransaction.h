#pragma once

#include "DbAdapterInterface/ITransaction.h"


namespace systelab { namespace db { namespace test_utility {

	class MockTransaction : public ITransaction
	{
	public:
		MockTransaction();
		virtual ~MockTransaction();

		MOCK_METHOD0(commit, void());
		MOCK_METHOD0(rollback, void());
	};

}}}


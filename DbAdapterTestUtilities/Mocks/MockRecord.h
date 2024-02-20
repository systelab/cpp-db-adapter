#pragma once

#include "DbAdapterInterface/IRecord.h"

namespace systelab::db::test_utility {

	class MockRecord : public IRecord
	{
	public:
		MockRecord();
		~MockRecord() override;

		MOCK_METHOD(unsigned int, getFieldValuesCount, (), (const, override));
		MOCK_METHOD(IFieldValue&, getFieldValue, (unsigned int), (const, override));
		MOCK_METHOD(IFieldValue&, getFieldValue, (const std::string&), (const, override));
		MOCK_METHOD(bool, hasFieldValue, (const std::string&), (const, override));
	};
}


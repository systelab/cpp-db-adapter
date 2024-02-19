#pragma once

#include "DbAdapterInterface/IRecordSet.h"

namespace systelab::db::test_utility {

	class MockRecordSet : public IRecordSet
	{
	public:
		MockRecordSet();
		~MockRecordSet() override;

		MOCK_METHOD(unsigned int, getFieldsCount, (), (const override));
		MOCK_METHOD(const IField& , getField, (unsigned int), (const override));
		MOCK_METHOD(const IField& , getField, (const std::string&), (const override));

		MOCK_METHOD(unsigned int, getRecordsCount, (), (const override));

		MOCK_METHOD(const IRecord&, getCurrentRecord, (), (const override));
		MOCK_METHOD(bool, isCurrentRecordValid, (), (const override));
		MOCK_METHOD(void, nextRecord, (), (override));
	};

}


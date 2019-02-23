#pragma once

#include "DbAdapterInterface/IRecordSet.h"


namespace systelab { namespace db { namespace test_utility {

	class MockRecordSet : public IRecordSet
	{
	public:
		MockRecordSet();
		virtual ~MockRecordSet();

		MOCK_CONST_METHOD0(getFieldsCount, unsigned int());
		MOCK_CONST_METHOD1(getField, const db::IField&(unsigned int));
		MOCK_CONST_METHOD1(getField, const db::IField&(const std::string&));

		MOCK_CONST_METHOD0(getRecordsCount, unsigned int());

		MOCK_CONST_METHOD0(getCurrentRecord, const db::IRecord&());
		MOCK_CONST_METHOD0(isCurrentRecordValid, bool());
		MOCK_METHOD0(nextRecord, void());
	};

}}}


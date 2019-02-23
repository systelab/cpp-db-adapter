#pragma once

#include "DbAdapterInterface/ITableRecordSet.h"

#include "DbAdapterInterface/IField.h"
#include "DbAdapterInterface/ITable.h"
#include "DbAdapterInterface/ITableRecord.h"


namespace systelab { namespace db { namespace test_utility {

	class MockTableRecordSet : public ITableRecordSet
	{
	public:
		MockTableRecordSet();
		virtual ~MockTableRecordSet();

		MOCK_CONST_METHOD0(getTable, db::ITable&());

		MOCK_CONST_METHOD0(getFieldsCount, unsigned int());
		MOCK_CONST_METHOD1(getField, const db::IField&(unsigned int));
		MOCK_CONST_METHOD1(getField, const db::IField&(const std::string&));

		MOCK_CONST_METHOD0(getRecordsCount, unsigned int());

		MOCK_CONST_METHOD0(getCurrentRecord, const db::ITableRecord&());

		MOCK_CONST_METHOD0(copyCurrentRecordProxy, db::ITableRecord*());
		std::unique_ptr<db::ITableRecord> copyCurrentRecord() const
		{
			return std::unique_ptr<db::ITableRecord>(copyCurrentRecordProxy());
		}

		MOCK_CONST_METHOD0(isCurrentRecordValid, bool());

		MOCK_METHOD0(nextRecord, void());
	};

}}}


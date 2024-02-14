#pragma once

#include "DbAdapterInterface/ITableRecordSet.h"

#include "DbAdapterInterface/IField.h"
#include "DbAdapterInterface/ITable.h"
#include "DbAdapterInterface/ITableRecord.h"

namespace systelab::db::test_utility {

	class MockTableRecordSet : public ITableRecordSet
	{
	public:
		MockTableRecordSet();
		~MockTableRecordSet() override;

		MOCK_METHOD(ITable& , getTable, (), (const, override));

		MOCK_METHOD(unsigned int, getFieldsCount, (), (const, override));
		MOCK_METHOD(const db::IField&, getField, (unsigned int), (const, override));
		MOCK_METHOD(const db::IField&, getField, (const std::string&), (const, override));

		MOCK_METHOD(unsigned int, getRecordsCount, (), (const, override));

		MOCK_METHOD(const db::ITableRecord&, getCurrentRecord, (), (const, override));

		MOCK_METHOD(std::unique_ptr<db::ITableRecord>, copyCurrentRecord, (), (const, override));

		MOCK_METHOD(bool, isCurrentRecordValid, (), (const, override));

		MOCK_METHOD(void, nextRecord, (), (override));
	};
}


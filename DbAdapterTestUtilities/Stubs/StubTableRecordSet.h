#pragma once

#include "Mocks/MockTableRecordSet.h"

#include "DbAdapterInterface/ITableRecordSet.h"
#include "DbAdapterInterface/ITableRecord.h"
#include "DbAdapterInterface/Types.h"

#include <memory>
#include <vector>

namespace systelab { namespace db {
	class IField;
	class ITable;
}}

namespace systelab::db::test_utility {

	class StubTableRecord;

	class StubTableRecordSet : public MockTableRecordSet
	{
	public:
		StubTableRecordSet(ITable& table, std::vector<StubTableRecord>& records);
		~StubTableRecordSet() override;

		ITable& getTable() const;

		unsigned int getFieldsCount() const override;
		const IField& getField(unsigned int index) const override;
		const IField& getField(const std::string& fieldName) const override;

		unsigned int getRecordsCount() const override;

		const ITableRecord& getCurrentRecord() const override;
		std::unique_ptr<ITableRecord> copyCurrentRecord() const override;
		bool isCurrentRecordValid() const override;
		void nextRecord() override;

	private:
		ITable& m_table;
		std::vector<std::unique_ptr<StubTableRecord>> m_records;
		std::vector<std::unique_ptr<StubTableRecord>>::iterator m_iterator;
	};
}


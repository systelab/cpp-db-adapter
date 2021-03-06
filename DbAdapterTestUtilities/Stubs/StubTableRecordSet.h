#pragma once

#include "../Mocks/MockTableRecordSet.h"

#include "DbAdapterInterface/ITableRecordSet.h"
#include "DbAdapterInterface/ITableRecord.h"
#include "DbAdapterInterface/Types.h"

#include <memory>
#include <vector>


namespace systelab { namespace db {
	class IField;
	class ITable;
}}

namespace systelab { namespace db { namespace test_utility {

	class StubTableRecord;

	class StubTableRecordSet : public MockTableRecordSet
	{
	public:
		StubTableRecordSet(ITable& table, std::vector< StubTableRecord >& records);
		virtual ~StubTableRecordSet();

		ITable& getTable() const;

		unsigned int getFieldsCount() const;
		const IField& getField(unsigned int index) const;
		const IField& getField(const std::string& fieldName) const;

		unsigned int getRecordsCount() const;

		const ITableRecord& getCurrentRecord() const;
		std::unique_ptr<ITableRecord> copyCurrentRecord() const;
		bool isCurrentRecordValid() const;
		void nextRecord();

	private:
		ITable& m_table;
		std::vector< std::unique_ptr<StubTableRecord> > m_records;
		std::vector< std::unique_ptr<StubTableRecord> >::iterator m_iterator;
	};

}}}


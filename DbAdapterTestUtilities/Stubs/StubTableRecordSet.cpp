#include "stdafx.h"
#include "StubTableRecordSet.h"

#include "DbAdapterInterface/ITable.h"

#include "StubField.h"
#include "StubTableRecord.h"

namespace systelab::db::test_utility {

	StubTableRecordSet::StubTableRecordSet(ITable& table, std::vector<StubTableRecord>& tableRecords)
		:m_table(table)
	{
		for(const auto& tableRecord: tableRecords)
		{
			m_records.push_back(std::make_unique<StubTableRecord>(tableRecord));
		}

		m_iterator = m_records.begin();
	}

	ITable& StubTableRecordSet::getTable() const
	{
		return m_table;
	}

	unsigned int StubTableRecordSet::getFieldsCount() const
	{
		return m_table.getFieldsCount();
	}

	const IField& StubTableRecordSet::getField(unsigned int index) const
	{
		return m_table.getField(index);
	}

	const IField& StubTableRecordSet::getField(const std::string& fieldName) const
	{
		return m_table.getField(fieldName);
	}

	unsigned int StubTableRecordSet::getRecordsCount() const
	{
		return static_cast<unsigned int>(m_records.size());
	}

	const ITableRecord& StubTableRecordSet::getCurrentRecord() const
	{
		return **m_iterator;
	}

	std::unique_ptr<ITableRecord> StubTableRecordSet::copyCurrentRecord() const
	{
		const ITableRecord& currentRecord = getCurrentRecord();
		
		return std::make_unique<StubTableRecord>(currentRecord);
	}

	bool StubTableRecordSet::isCurrentRecordValid() const
	{
		return (m_iterator != m_records.end());
	}

	void StubTableRecordSet::nextRecord()
	{
		m_iterator++;
	}

}
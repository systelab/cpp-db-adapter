#include "stdafx.h"
#include "StubTable.h"

#include "StubField.h"
#include "StubFieldValue.h"
#include "StubTableRecord.h"
#include "StubTableRecordSet.h"
#include "StubPrimaryKey.h"
#include "StubPrimaryKeyValue.h"

#include "DbAdapterInterface/IDatabase.h"

namespace systelab::db::test_utility {
	
	using namespace testing;

	StubTable::StubTable(const std::string& name)
		:m_name(name)
	{
		m_primaryKey = std::make_unique<StubPrimaryKey>(*this);

		ON_CALL(*this, insertRecord(_)).WillByDefault(Invoke(this, &StubTable::insertRecordProxy));
		ON_CALL(*this, updateRecord(_)).WillByDefault(Invoke(this, &StubTable::updateRecordProxy));
		ON_CALL(*this, deleteRecord(testing::An<const ITableRecord&>())).WillByDefault(Invoke(this, &StubTable::deleteRecordProxy));
	}

	StubTable::~StubTable() = default;

	std::string StubTable::getName() const
	{
		return m_name;
	}

	const IPrimaryKey& StubTable::getPrimaryKey() const
	{
		return *(m_primaryKey.get());
	}

	unsigned int StubTable::getFieldsCount() const
	{
		return (unsigned int) m_fields.size();
	}

	const IField& StubTable::getField(unsigned int index) const
	{
		return *(m_fields.at(index).get());
	}

	const IField& StubTable::getField(const std::string& fieldName) const
	{
		unsigned int nFields = (unsigned int) m_fields.size();
		for (unsigned int i = 0; i < nFields; i++)
		{
			if (m_fields[i]->getName() == fieldName)
			{
				return *(m_fields[i].get());
			}
		}

		throw std::runtime_error( "The requested field doesn't exist" );
	}

	void StubTable::addField(std::unique_ptr<IField> field)
	{
		m_primaryKey->addField(*field);
		m_fields.push_back(std::move(field));
	}

	std::unique_ptr<IFieldValue> StubTable::createFieldValue(const IField& field) const
	{
		return std::make_unique<StubFieldValue>(field.getName());
	}

	std::unique_ptr<IFieldValue> StubTable::createFieldValue(const IField& field, bool value) const
	{
		return std::make_unique<StubFieldValue>(field.getName(), value);
	}

	std::unique_ptr<IFieldValue> StubTable::createFieldValue(const IField& field, int value) const
	{
		return std::make_unique<StubFieldValue>(field.getName(),value);
	}

	std::unique_ptr<IFieldValue> StubTable::createFieldValue(const IField& field, double value) const
	{
		return std::make_unique<StubFieldValue>(field.getName(),value);
	}

	std::unique_ptr<IFieldValue> StubTable::createFieldValue(const IField& field, const std::string& value) const
	{
		return std::make_unique<StubFieldValue>(field.getName(),value);
	}

	std::unique_ptr<IFieldValue> StubTable::createFieldValue(const IField& field, const std::chrono::system_clock::time_point& value) const
	{
		return std::make_unique<StubFieldValue>(field.getName(),value);
	}

	std::unique_ptr<IFieldValue> StubTable::createFieldValue(const IField& field, std::unique_ptr<IBinaryValue> value) const
	{
		std::unique_ptr<IFieldValue> newField(new StubFieldValue(field.getName()));

		newField->setBinaryValue(std::move(value));

		return std::move(newField);
	}

	std::unique_ptr<IPrimaryKeyValue> StubTable::createPrimaryKeyValue() const
	{
		return std::make_unique<StubPrimaryKeyValue>(getPrimaryKey());
	}

	std::unique_ptr<ITableRecordSet> StubTable::getAllRecords() const
	{
		std::vector<StubTableRecord> records;
		std::for_each(m_tableRecords.begin(), m_tableRecords.end(),
			[&records](const std::unique_ptr<StubTableRecord>& srcRecord)
			{
				records.push_back(*srcRecord);
			}
		);

		std::unique_ptr<StubTableRecordSet> recordset(new StubTableRecordSet((ITable&)*this, records));
		return std::move(recordset);
	}

	std::unique_ptr<ITableRecord> StubTable::getRecordByPrimaryKey(const IPrimaryKeyValue& primaryKeyValue) const
	{
		std::vector<IFieldValue*> conditionValues;
		unsigned int nPrimaryKeyFieldValues = primaryKeyValue.getFieldValuesCount();
		for (unsigned int i = 0; i < nPrimaryKeyFieldValues; i++)
		{
			IFieldValue& fieldValue = primaryKeyValue.getFieldValue(i);
			conditionValues.push_back(&fieldValue);
		}

		std::unique_ptr<ITableRecordSet> recordset = filterRecordsByFields(conditionValues);
		if (recordset->getRecordsCount() > 0)
		{
			return recordset->copyCurrentRecord();
		}
		else
		{
			return std::unique_ptr<ITableRecord>();
		}
	}

	int StubTable::getMaxFieldValueInt(const IField& /*field*/) const
	{
		throw std::runtime_error("Not implemented");
	}

	std::unique_ptr<ITableRecord> StubTable::createRecord() const
	{		
		std::vector<std::unique_ptr<StubFieldValue>> fieldValues;

		unsigned int nFields = (unsigned int) m_fields.size();
		for (unsigned int i = 0; i < nFields; i++)
		{
			IField& field = *m_fields[i].get();
			std::unique_ptr<IFieldValue> fieldValue = createFieldValue(field);
			std::unique_ptr<StubFieldValue> stubFieldValue(new StubFieldValue(*fieldValue));
			fieldValue->setDefault();
			fieldValues.push_back(std::move(stubFieldValue));
		}

		return std::make_unique<StubTableRecord>(fieldValues);
	}

	std::unique_ptr<ITableRecord> StubTable::copyRecord(const ITableRecord& /*record*/) const
	{
		return std::unique_ptr<ITableRecord>(); 
	}

	RowsAffected StubTable::insertRecordProxy(ITableRecord& record)
	{
		std::unique_ptr<StubTableRecord> recordCopy(new StubTableRecord(record));
		m_tableRecords.push_back(std::move(recordCopy));
		return 1;
	}

	RowsAffected StubTable::updateRecordProxy(const ITableRecord&)
	{
		throw std::runtime_error("Not implemented");
	}

	RowsAffected StubTable::updateRecord(const std::vector<IFieldValue*>& /*newValues*/, const IPrimaryKeyValue& /*primaryKeyValue*/)
	{
		throw std::runtime_error("Not implemented");
	}

	RowsAffected StubTable::deleteRecordProxy(const ITableRecord& /*record*/)
	{
		throw std::runtime_error("Not implemented");
	}

	RowsAffected StubTable::deleteRecord(const IPrimaryKeyValue& /*primaryKeyValue*/)
	{
		throw std::runtime_error("Not implemented");
	}

	RowsAffected StubTable::updateRecordsByCondition(const std::vector<IFieldValue*>& /*newValues*/, const std::vector<IFieldValue*>& /*conditionValues*/)
	{
		throw std::runtime_error("Not implemented");
	}

	RowsAffected StubTable::deleteRecordsByCondition(const std::vector<IFieldValue*>& /*conditionValues*/)
	{
		throw std::runtime_error("Not implemented");
	}

	RowsAffected StubTable::deleteRecordsByCondition(const std::string& /*condition*/)
	{
		throw std::runtime_error("Not implemented");
	}

	RowsAffected StubTable::deleteAllRecords()
	{
		RowsAffected size = (unsigned int) m_tableRecords.size();
		m_tableRecords.clear();

		return size;
	}


	FieldTypes StubTable::getTypeFromSQLiteTypeName(std::string SQLiteTypeName)
	{
		if (SQLiteTypeName == "BOOLEAN")
		{
			return db::BOOLEAN;
		}
		else if (SQLiteTypeName == "INTEGER" || SQLiteTypeName == "INT")
		{
			return db::INT;
		}
		else if (SQLiteTypeName == "REAL" || SQLiteTypeName == "DOUBLE")
		{
			return db::DOUBLE;
		}
		else if (SQLiteTypeName == "TEXT" || SQLiteTypeName.substr(0,4) == "CHAR")
		{
			return STRING;
		}
		else if (SQLiteTypeName == "DATETIME")
		{
			return DATETIME;
		}
		else
		{
			std::string excMessage = "SQLite type name not recognized: " + SQLiteTypeName;
			throw std::runtime_error(excMessage.c_str());
		}
	}

	bool StubTable::isOwned(const IField& field) const
	{
		unsigned int index = field.getIndex();
		if( index < m_fields.size() )
		{
			return (&(*m_fields[index]) == &field);
		}
		else
		{
			return false;
		}
	}

	std::string StubTable::getSQLValue(const IFieldValue& fieldValue, bool forComparison, bool forAssignment) const
	{
		std::ostringstream fieldValueStream;
		if (fieldValue.isNull())
		{
			if (forComparison)
			{
				fieldValueStream << " IS ";
			}
			else if (forAssignment)
			{
				fieldValueStream << " = ";
			}

			fieldValueStream << "NULL";
		}
		else
		{
			if (forComparison || forAssignment)
			{
				fieldValueStream << " = ";
			}

			FieldTypes fieldType = fieldValue.getField().getType();
			switch (fieldType)
			{
				case db::BOOLEAN:
					fieldValueStream << (fieldValue.getBooleanValue() ? 1 : 0);
					break;
				case db::INT:
					fieldValueStream << fieldValue.getIntValue();
					break;
				case db::DOUBLE:
					fieldValueStream << std::setprecision(10) << fieldValue.getDoubleValue();
					break;
				case STRING:
					throw std::runtime_error("Invalid record field type." );
					break;
				case DATETIME:
					fieldValueStream << "'" << std::format("{:%FT%T%z}", fieldValue.getDateTimeValue()) << "'";
					break;

				case BINARY:
					throw std::runtime_error("Insert of tables with binary fields not implemented." );
					break;
				default:
					throw std::runtime_error("Invalid record field type." );
					break;
			}
		}

		return fieldValueStream.str();
	}

	std::string StubTable::getStringList(const std::vector<std::string>& items, const std::string& separator) const
	{
		std::string to_return = "";

		unsigned int nItems = (unsigned int) items.size();
		for (unsigned int i = 0; i < nItems; i++)
		{
			to_return += (i > 0) ? separator : "";
			to_return += items[i];
		}

		return to_return;
	}
}
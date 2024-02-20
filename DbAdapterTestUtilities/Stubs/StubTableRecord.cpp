#include "stdafx.h"
#include "StubTableRecord.h"

#include "StubField.h"
#include "StubFieldValue.h"


namespace systelab::db::test_utility {

	StubTableRecord::StubTableRecord(const ITableRecord& other)
	{
		unsigned int nFieldValues = other.getFieldValuesCount();
		for (unsigned int i = 0; i < nFieldValues; i++)
		{
			IFieldValue& fieldValue = other.getFieldValue(i);
			m_fieldValues.push_back(std::make_unique<StubFieldValue>(fieldValue));
		}
	}

	StubTableRecord::StubTableRecord(const StubTableRecord& other)
	{
		for (const auto& fieldValue: other.m_fieldValues)
		{
			m_fieldValues.push_back(std::make_unique<StubFieldValue>(*fieldValue.get()));
		}
	}

	StubTableRecord::StubTableRecord(std::vector<std::unique_ptr<StubFieldValue>>& fieldValues)
	{
		for(auto& fieldValue: fieldValues)
		{
			m_fieldValues.push_back(std::move(fieldValue));
		}
	}

	db::ITable& StubTableRecord::getTable() const
	{
		throw std::runtime_error( "Not implemented" );
	}

	unsigned int StubTableRecord::getFieldValuesCount() const
	{
		return static_cast<unsigned int>(m_fieldValues.size());
	}

	IFieldValue& StubTableRecord::getFieldValue(unsigned int index) const
	{
			return *(m_fieldValues.at(index).get());
	}

	db::IFieldValue& StubTableRecord::getFieldValue(const std::string& fieldName) const
	{
		unsigned int nFields = (unsigned int) m_fieldValues.size();
		for (unsigned int i = 0; i < nFields; i++)
		{
			if (m_fieldValues[i]->getField().getName() == fieldName)
			{
				return *(m_fieldValues[i].get());
			}
		}

		throw std::runtime_error( "The requested field value doesn't exist" );
	}

	bool StubTableRecord::hasFieldValue(const std::string& fieldName) const
	{
		unsigned int nFields = (unsigned int) m_fieldValues.size();
		for (unsigned int i = 0; i < nFields; i++)
		{
			if (m_fieldValues[i]->getField().getName() == fieldName)
			{
				return true;
			}
		}

		return false;
	}

	std::vector<IFieldValue*> StubTableRecord::getValuesList() const
	{
		std::vector<IFieldValue*> values;

		unsigned int nRecordFieldValues = getFieldValuesCount();
		for(unsigned int i = 0; i < nRecordFieldValues; i++)
		{
			db::IFieldValue& recordFieldValue = getFieldValue(i);
			const db::IField& recordField = recordFieldValue.getField();
			if (!recordField.isPrimaryKey())
			{
				values.push_back(&recordFieldValue);
			}
		}

		return values;
	}

	StubTableRecord& StubTableRecord::operator= (const StubTableRecord& other)
	{
		unsigned int nFieldValues = (unsigned int) other.m_fieldValues.size();
		for (unsigned int i = 0; i < nFieldValues; i++)
		{
			m_fieldValues.push_back( std::unique_ptr<StubFieldValue>(new StubFieldValue(*other.m_fieldValues[i].get())) );
		}

		return *this;
	}

}

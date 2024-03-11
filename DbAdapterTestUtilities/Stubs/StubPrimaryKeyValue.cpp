#include "DbAdapterTestUtilities/stdafx.h"
#include "StubPrimaryKeyValue.h"
#include "StubFieldValue.h"

#include "DbAdapterInterface/IPrimaryKey.h"
#include "DbAdapterInterface/IField.h"

namespace systelab::db::test_utility {

	StubPrimaryKeyValue::StubPrimaryKeyValue(const IPrimaryKey& primaryKey)
		:m_primaryKey(primaryKey)
	{
		unsigned int nPrimaryKeyFields = m_primaryKey.getFieldsCount();
		for (unsigned int i = 0; i < nPrimaryKeyFields; i++)
		{
			std::unique_ptr<IFieldValue> fieldValue;

			const IField& field = primaryKey.getField(i);
			if (field.hasNullDefaultValue())
			{
				fieldValue.reset( new StubFieldValue(field.getName()) );
			}
			else
			{
				FieldTypes fieldType = field.getType();
				switch(fieldType)
				{
					case db::BOOLEAN:
						fieldValue.reset( new StubFieldValue(field.getName(), std::make_optional(field.getBooleanDefaultValue())) );
						break;

					case db::INT:
						fieldValue.reset( new StubFieldValue(field.getName(), std::make_optional(field.getIntDefaultValue())));
						break;

					case db::DOUBLE:
						fieldValue.reset( new StubFieldValue(field.getName(), std::make_optional(field.getDoubleDefaultValue())));
						break;

					case STRING:
						fieldValue.reset( new StubFieldValue(field.getName(), field.getStringDefaultValue()) );
						break;

					case DATETIME:
						fieldValue.reset( new StubFieldValue(field.getName(), field.getDateTimeDefaultValue()) );
						break;

					case BINARY:
						throw std::runtime_error( "Binary fields can't belong to primary key." );
						break;

					default:
						throw std::runtime_error( "Unknown field type." );
				}
			}

			m_fieldValues.push_back( std::move(fieldValue) );
		}
	}

	StubPrimaryKeyValue::~StubPrimaryKeyValue()
	{
	}

	ITable& StubPrimaryKeyValue::getTable() const
	{
		return m_primaryKey.getTable();
	}

	const IPrimaryKey& StubPrimaryKeyValue::getPrimaryKey() const
	{
		return m_primaryKey;
	}

	unsigned int StubPrimaryKeyValue::getFieldValuesCount() const
	{
		return static_cast<unsigned int>(m_fieldValues.size());
	}

	IFieldValue& StubPrimaryKeyValue::getFieldValue(unsigned int index) const
	{
		return *(m_fieldValues.at(index));
	}

	IFieldValue& StubPrimaryKeyValue::getFieldValue(const std::string& fieldName) const
	{
		const auto fieldValue = std::ranges::find_if(m_fieldValues,
			[&fieldName](const std::unique_ptr<IFieldValue>& field)
			{
				return field->getField().getName() == fieldName;
			});

		if (fieldValue != m_fieldValues.cend())
		{
			return **fieldValue;
		}

		throw std::runtime_error("The requested primary key field doesn't exist");
	}

}

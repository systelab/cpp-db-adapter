#include "stdafx.h"
#include "StubFieldValue.h"
#include "StubField.h"

#include "DbAdapterInterface/IBinaryValue.h"

namespace systelab::db::test_utility {

	StubFieldValue::StubFieldValue(const db::IFieldValue& other)
		:m_nullValue(other.isNull())
		,m_default(other.isDefault())
		,m_boolValue(false)
		,m_intValue(0)
		,m_doubleValue(0.)
		,m_stringValue("")
		,m_dateTimeValue()
	{
		m_field.reset(new StubField(other.getField()));
		
		if (!other.isNull())
		{
			switch (m_field->getType())
			{
				case BOOLEAN:
					setBooleanValue(other.getBooleanValue());
					break;
				case INT:
					setIntValue(other.getIntValue());
					break;
				case DOUBLE:
					setDoubleValue(other.getDoubleValue());
					break;
				case STRING:
					setStringValue(other.getStringValue());
					break;
				case DATETIME:
					setDateTimeValue(other.getDateTimeValue());
					break;
				case BINARY:
					//setBinaryValue(other.getBinaryValue()); // Not implemented
					break;
			}
		}
	}

	StubFieldValue::StubFieldValue(const StubFieldValue& other)
		:m_nullValue(other.m_nullValue)
		,m_default(other.m_default)
		,m_boolValue(other.m_boolValue)
		,m_intValue(other.m_intValue)
		,m_doubleValue(other.m_doubleValue)
		,m_stringValue(other.m_stringValue)
		,m_dateTimeValue(other.m_dateTimeValue)
	{
		m_field.reset(new StubField(*other.m_field));
	}

	StubFieldValue::StubFieldValue(const std::string& name)
		:m_nullValue(true)
		,m_default(false)
		,m_boolValue(false)
		,m_intValue(0)
		,m_doubleValue(0.)
		,m_stringValue("")
		,m_dateTimeValue()
	{
		m_field.reset(new StubField(name, INT));
	}

	StubFieldValue::StubFieldValue(const std::string& name, const std::optional<int>& value)
		:m_default(false)
		,m_boolValue(false)
		,m_doubleValue(0.)
		,m_stringValue("")
		,m_dateTimeValue()
	{
		m_field.reset(new StubField(name, INT));
			
		if (value)
		{
			m_intValue = value.value();
			m_nullValue = false;
		}
		else
		{
			m_intValue = 0;
			m_nullValue = true;
		}
	}

	StubFieldValue::StubFieldValue(const std::string& name, const std::optional<bool>& value)
		:m_default(false)
		,m_intValue(0)
		,m_doubleValue(0.)
		,m_stringValue("")
		,m_dateTimeValue()
	{
		m_field.reset(new StubField(name, BOOLEAN));

		if (value)
		{
			m_boolValue = value.value();
			m_nullValue = false;
		}
		else
		{
			m_boolValue = false;
			m_nullValue = true;
		}
	}
		
	StubFieldValue::StubFieldValue(const std::string& name, const std::optional<double>& value)
		:m_default(false)
		,m_intValue(0)
		,m_boolValue(false)
		,m_stringValue("")
		,m_dateTimeValue()
	{
		m_field.reset(new StubField(name, DOUBLE));

		if (value)
		{
			m_doubleValue = value.value();
			m_nullValue = false;
		}
		else
		{
			m_doubleValue = 0.;
			m_nullValue = true;
		}
	}

	StubFieldValue::StubFieldValue(const std::string& name, const std::optional<std::string>& value)
		:m_default(false)
		,m_intValue(0)
		,m_boolValue(false)
		,m_doubleValue(0.)
		,m_dateTimeValue()
	{
		m_field.reset(new StubField(name, db::STRING));
			
		if (value)
		{
			m_stringValue = value.value();
			m_nullValue = false;
		}
		else
		{
			m_stringValue = "";
			m_nullValue = true;
		}
	}


	StubFieldValue::StubFieldValue(const std::string& name, const std::optional<std::chrono::system_clock::time_point>& value)
		:m_default(false)
		,m_intValue(0)
		,m_boolValue(false)
		,m_doubleValue(0.)
		,m_dateTimeValue()
	{
		m_field.reset(new StubField(name, db::DATETIME));
		if (value)
		{
			m_dateTimeValue = value.value();
			m_nullValue = false;
		}
		else
		{
			m_dateTimeValue = std::chrono::system_clock::time_point{};
			m_nullValue = true;
		}

	}

	StubFieldValue::~StubFieldValue()
	{}

	const db::IField& StubFieldValue::getField() const
	{
		return *m_field;
	}

	bool StubFieldValue::isNull() const
	{
		return m_nullValue;
	}

	bool StubFieldValue::isDefault() const
	{
		return m_default;
	}

	bool StubFieldValue::getBooleanValue() const
	{
		if (!isNull() && !isDefault())
		{
			if( m_field->getType() == BOOLEAN )
			{
				return m_boolValue;
			}
			else
			{
				throw std::runtime_error( "Field type isn't boolean" );
			}
		}
		else
		{
			if (isNull())
			{
				throw std::runtime_error( "Field value is null" );
			}
			else
			{
				throw std::runtime_error( "Field value is default" );
			}
		}
	}

	int StubFieldValue::getIntValue() const
	{
		if (!isNull() && !isDefault())
		{
			if( m_field->getType() == INT )
			{
				return m_intValue;
			}
			else
			{
				throw std::runtime_error( "Field type isn't integer" );
			}
		}
		else
		{
			if (isNull())
			{
				throw std::runtime_error( "Field value is null" );
			}
			else
			{
				throw std::runtime_error( "Field value is default" );
			}
		}
	}

	double StubFieldValue::getDoubleValue() const
	{
		if (!isNull() && !isDefault())
		{
			if( m_field->getType() == DOUBLE )
			{
				return m_doubleValue;
			}
			else
			{
				throw std::runtime_error( "Field type isn't double" );
			}
		}
		else
		{
			if (isNull())
			{
				throw std::runtime_error( "Field value is null" );
			}
			else
			{
				throw std::runtime_error( "Field value is default" );
			}
		}
	}

	std::string StubFieldValue::getStringValue() const
	{
		if (!isNull() && !isDefault())
		{
			if( m_field->getType() == STRING )
			{
				return m_stringValue;
			}
			else
			{
				throw std::runtime_error( "Field type isn't string" );
			}
		}
		else
		{
			if (isNull())
			{
				throw std::runtime_error( "Field value is null" );
			}
			else
			{
				throw std::runtime_error( "Field value is default" );
			}
		}
	}
		

	std::chrono::system_clock::time_point StubFieldValue::getDateTimeValue() const
	{
		if (!isDefault())
		{
			if( m_field->getType() == DATETIME )
			{
				return m_dateTimeValue;
			}
			else if ( m_field->getType() == STRING )
			{
				if (!isNull())
				{
					return getDateTimeFromISOString(m_stringValue);
				}
				else
				{
					return std::chrono::system_clock::time_point{};
				}
			}
			else
			{
				throw std::runtime_error( "Field type isn't datetime" );
			}
		}
		else
		{
			throw std::runtime_error( "Field value is default" );
		}
	}

	db::IBinaryValue& StubFieldValue::getBinaryValue() const
	{
		throw std::runtime_error( "Not implemented" );
	}

	void StubFieldValue::setValue(const IFieldValue& srcFieldValue)
	{
		db::FieldTypes srcFieldType = srcFieldValue.getField().getType();
		if (srcFieldType != getField().getType())
		{
			throw std::runtime_error( "Can't set the value of a field of another type" );
		}

		if (srcFieldValue.isNull())
		{
			setNull();
		}
		else if (srcFieldValue.isDefault())
		{
			setDefault();
		}
		else
		{
			switch (srcFieldType)
			{
				case BOOLEAN:
					setBooleanValue(srcFieldValue.getBooleanValue());
					break;
				case INT:
					setIntValue(srcFieldValue.getIntValue());
					break;
				case DOUBLE:
					setDoubleValue(srcFieldValue.getDoubleValue());
					break;
				case STRING:
					setStringValue(srcFieldValue.getStringValue());
					break;
				case DATETIME:
					setDateTimeValue(srcFieldValue.getDateTimeValue());
					break;
				case BINARY:
					//setBinaryValue(srcFieldValue.getBinaryValue()); // Not implemented
					break;
			}
		}
	}

	void StubFieldValue::setNull()
	{
		m_nullValue = true;
		m_default = false;
		m_boolValue = false;
		m_intValue = 0;
		m_doubleValue = 0.;
		m_stringValue = "";
		m_dateTimeValue = std::chrono::system_clock::time_point{};
	}

	void StubFieldValue::setDefault()
	{
		m_nullValue = false;
		m_default = true;
		m_boolValue = false;
		m_intValue = 0;
		m_doubleValue = 0.;
		m_stringValue = "";
		m_dateTimeValue = std::chrono::system_clock::time_point{};
	}

	void StubFieldValue::setBooleanValue(bool value)
	{
		if( m_field->getType() == BOOLEAN )
		{
			m_boolValue = value;
			m_nullValue = false;
			m_default = false;
		}
		else
		{
			throw std::runtime_error( "Field type isn't boolean" );
		}
	}

	void StubFieldValue::setIntValue(int value)
	{
		if( m_field->getType() == INT )
		{
			m_intValue = value;
			m_nullValue = false;
			m_default = false;
		}
		else
		{
			throw std::runtime_error( "Field type isn't integer" );
		}
	}

	void StubFieldValue::setDoubleValue(double value)
	{
		if( m_field->getType() == DOUBLE )
		{
			m_doubleValue = value;
			m_nullValue = false;
			m_default = false;
		}
		else
		{
			throw std::runtime_error( "Field type isn't double" );
		}
	}

	void StubFieldValue::setStringValue(const std::string& value)
	{
		if( m_field->getType() == STRING )
		{
			m_stringValue = value;
			m_nullValue = false;
			m_default = false;
		}
		else
		{
			throw std::runtime_error( "Field type isn't string" );
		}
	}

	void StubFieldValue::setDateTimeValue(const std::chrono::system_clock::time_point& value)
	{
		if( m_field->getType() == DATETIME )
		{
			m_dateTimeValue = value;
			m_nullValue = (value == std::chrono::system_clock::time_point {});
			m_default = false;
		}
		else
		{
			throw std::runtime_error( "Field type isn't datetime" );
		}
	}

	void StubFieldValue::setBinaryValue(std::unique_ptr<IBinaryValue> value)
	{
		throw std::runtime_error( "Not implemented" );
	}

	void StubFieldValue::useDefaultValue()
	{
		db::FieldTypes fieldType = m_field->getType();
		switch (fieldType)
		{
			case BOOLEAN:
				setBooleanValue(m_field->getBooleanDefaultValue());
				break;

			case INT:
				setIntValue(m_field->getIntDefaultValue());
				break;

			case DOUBLE:
				setDoubleValue(m_field->getDoubleDefaultValue());
				break;

			case STRING:
				setStringValue(m_field->getStringDefaultValue());
				break;

			case DATETIME:
				setDateTimeValue(m_field->getDateTimeDefaultValue());
				break;

			case BINARY:
				throw std::runtime_error( "Binary field type not implemented." );

			default:
				throw std::runtime_error( "Invalid field type." );
				break;
		}
	}

	std::unique_ptr<IFieldValue> StubFieldValue::clone() const
	{
		return std::make_unique<StubFieldValue>(*this);
	}

	StubFieldValue& StubFieldValue::operator= (const StubFieldValue& other)
	{
		m_field.reset(new StubField(*other.m_field));
		m_nullValue = other.m_nullValue;
		m_default = other.m_default;
		m_boolValue = other.m_boolValue;
		m_intValue = other.m_intValue;
		m_doubleValue = other.m_doubleValue;
		m_stringValue = other.m_stringValue;
		m_dateTimeValue = other.m_dateTimeValue;

		return *this;
	}

	std::chrono::system_clock::time_point StubFieldValue::getDateTimeFromISOString(const std::string& ISODateTime) const
	{
		if (!ISODateTime.empty())
		{
			std::chrono::system_clock::time_point result;
			std::istringstream{ ISODateTime } >> std::chrono::parse("%FT%T%z", result);
			return result;
		}
		else
		{
			return std::chrono::system_clock::time_point{};
		}
	}
}


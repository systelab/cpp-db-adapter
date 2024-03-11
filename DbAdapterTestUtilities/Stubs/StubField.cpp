#include "DbAdapterTestUtilities/stdafx.h"
#include "StubField.h"

namespace systelab::db::test_utility {

	StubField::StubField(const db::IField& other)
		:m_index(other.getIndex())
		,m_name(other.getName())
		,m_type(other.getType())
		,m_primaryKey(other.isPrimaryKey())
	{
	}

	StubField::StubField(const StubField& other)
		:m_index(other.m_index)
		,m_name(other.m_name)
		,m_type(other.m_type)
		,m_primaryKey(other.m_primaryKey)
	{
	}

	StubField::StubField(const std::string& name, FieldTypes type)
		:m_index(0)
		,m_name(name)
		,m_type(type)
		,m_primaryKey(false)
	{
	}

	StubField::StubField(unsigned int index, const std::string& name, FieldTypes type, const std::string& defaultValue, bool primaryKey)
		:m_index(index)
		,m_name(name)
		,m_type(type)
		,m_primaryKey(primaryKey)
	{
		setDefaultValue(type, defaultValue);
	}

	StubField::~StubField() = default;

	unsigned int StubField::getIndex() const
	{
		return m_index;
	}

	std::string StubField::getName() const
	{
		return m_name;
	}

	systelab::db::FieldTypes StubField::getType() const
	{
		return m_type;
	}

	bool StubField::hasNullDefaultValue() const
	{
		return m_nullDefaultValue;
	}

	bool StubField::getBooleanDefaultValue() const
	{
		if (!hasNullDefaultValue())
		{
			if (m_type == BOOLEAN)
			{
				return m_defaultBoolValue;
			}
			else
			{
				throw std::runtime_error( "Field type isn't boolean" );
			}
		}
		else
		{
			throw std::runtime_error( "Default value is null" );
		}
	}

	int StubField::getIntDefaultValue() const
	{
		if (!hasNullDefaultValue())
		{
			if (m_type == INT)
			{
				return m_defaultIntValue;
			}
			else
			{
				throw std::runtime_error( "Field type isn't integer" );
			}
		}
		else
		{
			throw std::runtime_error( "Default value is null" );
		}
	}

	double StubField::getDoubleDefaultValue() const
	{
		if (!hasNullDefaultValue())
		{
			if (m_type == DOUBLE)
			{
				return m_defaultDoubleValue;
			}
			else
			{
				throw std::runtime_error( "Field type isn't double" );
			}
		}
		else
		{
			throw std::runtime_error( "Default value is null" );
		}
	}

	std::string StubField::getStringDefaultValue() const
	{
		if (!hasNullDefaultValue())
		{
			if (m_type == STRING)
			{
				return m_defaultStringValue;
			}
			else
			{
				throw std::runtime_error( "Field type isn't string" );
			}
		}
		else
		{
			throw std::runtime_error( "Default value is null" );
		}
	}

	std::chrono::system_clock::time_point StubField::getDateTimeDefaultValue() const
	{
		if (!hasNullDefaultValue())
		{
			if (m_type == DATETIME)
			{
				return m_defaultDateTimeValue;
			}
			else
			{
				throw std::runtime_error( "Field type isn't datetime" );
			}
		}
		else
		{
			throw std::runtime_error( "Default value is null" );
		}
	}
	
	IBinaryValue& StubField::getBinaryDefaultValue() const
	{
		throw std::runtime_error( "Not implemented" );
	}

	bool StubField::isPrimaryKey() const
	{
		return m_primaryKey;
	}

	void StubField::setDefaultValue(systelab::db::FieldTypes type, const std::string& defaultValue)
	{
		m_defaultBoolValue = false;
		m_defaultIntValue = 0;
		m_defaultDoubleValue = 0.;
		m_defaultStringValue = "";
		m_defaultDateTimeValue = std::chrono::system_clock::time_point{};

		std::string defaultValueUpper = defaultValue;
		std::transform(defaultValueUpper.begin(), defaultValueUpper.end(), defaultValueUpper.begin(), ::toupper);
		if (defaultValue.empty() || defaultValueUpper == "NULL")
		{
			m_nullDefaultValue = true;
		}
		else
		{
			m_nullDefaultValue = false;
			switch (type)
			{
				case db::BOOLEAN:
					m_defaultBoolValue = (std::stoi(defaultValue) == 1);
					break;
				case db::INT:
					m_defaultIntValue = std::stoi(defaultValue);
					break;
				case db::DOUBLE:
					m_defaultDoubleValue = std::stod(defaultValue);
					break;
				case db::STRING:
					m_defaultStringValue = defaultValue;
					break;
				case db::DATETIME:
					m_defaultDateTimeValue = getDateTimeFromISOString(defaultValue);
					break;
				case db::BINARY:
					//m_defaultBinaryValue = ; // Not implemented
					break;
				default:
					throw std::runtime_error("Invalid record field type." );
					break;
			}
		}
	}

	std::chrono::system_clock::time_point StubField::getDateTimeFromISOString(const std::string& ISODateTime) const
	{
		if (!ISODateTime.empty())
		{
			std::chrono::system_clock::time_point timePointDateTime;
			std::istringstream{ ISODateTime } >> std::chrono::parse("%FT%T%z", timePointDateTime);
			return timePointDateTime;
		}
		else
		{
			return std::chrono::system_clock::time_point{};
		}
	}

	StubField& StubField::operator= (const StubField& other)
	{
		m_index = other.m_index;
		m_name = other.m_name;
		m_type = other.m_type;
		m_primaryKey = other.m_primaryKey;

		return *this;
	}

}

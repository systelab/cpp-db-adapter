#pragma once

#include "DbAdapterInterface/IField.h"

namespace systelab::db {
	class IBinaryValue;
}

namespace systelab::db::test_utility {

	class StubField : public IField
	{
	public:
		StubField(const IField&);
		StubField(const StubField& other);
		StubField(const std::string& name, FieldTypes type);
		StubField(unsigned int index, const std::string& name, FieldTypes type, const std::string& defaultValue, bool primaryKey);
		~StubField() override;

		unsigned int getIndex() const override;
		std::string getName() const override;
		FieldTypes getType() const override;

		bool hasNullDefaultValue() const override;
		bool getBooleanDefaultValue() const override;
		int getIntDefaultValue() const override;
		double getDoubleDefaultValue() const override;
		std::string getStringDefaultValue() const override;
		std::chrono::system_clock::time_point getDateTimeDefaultValue() const override;
		IBinaryValue& getBinaryDefaultValue() const override;

		bool isPrimaryKey() const override;

		StubField& operator= (const StubField& other);

	private:
		unsigned int m_index;
		std::string m_name;
		FieldTypes m_type;
		bool m_primaryKey;

		bool m_nullDefaultValue;
		bool m_defaultBoolValue;
		int m_defaultIntValue;
		double m_defaultDoubleValue;
		std::string m_defaultStringValue;
		std::chrono::system_clock::time_point m_defaultDateTimeValue;

		void setDefaultValue(db::FieldTypes type, const std::string& defaultValue);
		std::chrono::system_clock::time_point getDateTimeFromISOString(const std::string& postgresDateTime) const;
	};
}
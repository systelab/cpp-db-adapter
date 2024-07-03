#pragma once

#include "DbAdapterInterface/IFieldValue.h"

namespace systelab::db {
	class IBinaryValue;
	class IField;
}

namespace systelab::db::test_utility {

	class StubField;

	class StubFieldValue : public IFieldValue
	{
	public:
		StubFieldValue(const db::IFieldValue&);
		StubFieldValue(const StubFieldValue&);
		StubFieldValue(const std::string& name);
		StubFieldValue(const std::string& name, int value);
		explicit StubFieldValue(const std::string& name, bool value);
		StubFieldValue(const std::string& name, double value);
		StubFieldValue(const std::string& name, const std::string& value);
		StubFieldValue(const std::string& name, const DateTimeType& value);

		StubFieldValue(const std::string& name, const std::optional<int>& value);
		StubFieldValue(const std::string& name, const std::optional<bool>& value);
		StubFieldValue(const std::string& name, const std::optional<double>& value);
		StubFieldValue(const std::string& name, const std::optional<std::string>& value);
		StubFieldValue(const std::string& name, const std::optional<DateTimeType>& value);

		virtual ~StubFieldValue() override;

		const IField& getField() const override;
		bool isNull() const override;
		bool isDefault() const override;

		bool getBooleanValue() const override;
		int getIntValue() const override;
		double getDoubleValue() const override;
		std::string getStringValue() const override;
		DateTimeType getDateTimeValue() const override;
		IBinaryValue& getBinaryValue() const override;

		void setValue(const IFieldValue&) override;
		void setNull() override;
		void setDefault() override;
		void setBooleanValue(bool) override;
		void setIntValue(int) override;
		void setDoubleValue(double) override;
		void setStringValue(const std::string&) override;
		void setDateTimeValue(const DateTimeType&) override;
		void setBinaryValue(std::unique_ptr<IBinaryValue>) override;

		void useDefaultValue() override;
		std::unique_ptr<IFieldValue> clone() const override;

		StubFieldValue& operator= (const StubFieldValue& other);

	private:
		std::unique_ptr<StubField> m_field;
		bool m_nullValue;
		bool m_default;
		bool m_boolValue;
		int m_intValue;
		double m_doubleValue;
		std::string m_stringValue;
		DateTimeType m_dateTimeValue;

		DateTimeType getDateTimeFromISOString(const std::string& ISODateTime) const;
	};
}


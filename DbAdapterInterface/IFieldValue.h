#pragma once

#include "Types.h"
#include <memory>
#include <string>

namespace systelab::db {
	class IBinaryValue;
	class IField;

	class IFieldValue
	{
	public:
		virtual ~IFieldValue(void) {}

		virtual const IField& getField() const = 0;

		virtual bool isNull() const = 0;
		virtual bool isDefault() const = 0;
		virtual bool getBooleanValue() const = 0;
		virtual int getIntValue() const = 0;
		virtual double getDoubleValue() const = 0;
		virtual std::string getStringValue() const = 0;
		virtual DateTimeType getDateTimeValue() const = 0;
		virtual IBinaryValue& getBinaryValue() const = 0;

		virtual void setValue(const IFieldValue&) = 0;
		virtual void setNull() = 0;
		virtual void setDefault() = 0;
		virtual void setBooleanValue(bool value) = 0;
		virtual void setIntValue(int value) = 0;
		virtual void setDoubleValue(double value) = 0;
		virtual void setStringValue(const std::string& value) = 0;
		virtual void setDateTimeValue(const DateTimeType& value) = 0;
		virtual void setBinaryValue(std::unique_ptr<IBinaryValue> value) = 0;

		virtual void useDefaultValue() = 0;

		virtual std::unique_ptr<IFieldValue> clone() const = 0;

		inline friend bool operator== (const IFieldValue& lhs, const IFieldValue& rhs);
	};
}

#include "IFieldValue.inl"

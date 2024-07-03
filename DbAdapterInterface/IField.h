#pragma once

#include "Types.h"
#include <string>

namespace systelab::db {
	class IBinaryValue;

	class IField
	{
	public:
		virtual ~IField() {}

		virtual unsigned int getIndex() const = 0;
		virtual std::string getName() const = 0;
		virtual FieldTypes getType() const = 0;
		virtual bool isPrimaryKey() const = 0;

		virtual bool hasNullDefaultValue() const = 0;
		virtual bool getBooleanDefaultValue() const = 0;
		virtual int getIntDefaultValue() const = 0;
		virtual double getDoubleDefaultValue() const = 0;
		virtual std::string getStringDefaultValue() const = 0;
		virtual DateTimeType getDateTimeDefaultValue() const = 0;
		virtual IBinaryValue& getBinaryDefaultValue() const = 0;

		inline friend bool operator== (const IField& lhs, const IField& rhs);
	};
}

#include "IField.inl"
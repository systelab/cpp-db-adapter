#pragma once

#include "Types.h"

#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>



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
		virtual boost::posix_time::ptime getDateTimeDefaultValue() const = 0;
		virtual IBinaryValue& getBinaryDefaultValue() const = 0;

		inline friend bool operator== (const IField& lhs, const IField& rhs);
		inline friend bool operator!= (const IField& lhs, const IField& rhs);
	};
}

#include "IField.inl"
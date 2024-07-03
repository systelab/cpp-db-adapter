#pragma once

#include <string>

namespace systelab::db {

	class IFieldValue;

	class IRecord
	{
	public:
		virtual ~IRecord() {}

		virtual unsigned int getFieldValuesCount() const = 0;
		virtual IFieldValue& getFieldValue(unsigned int index) const = 0;
		virtual IFieldValue& getFieldValue(const std::string& fieldName) const = 0;

		virtual bool hasFieldValue(const std::string& fieldName) const = 0;
	};
}


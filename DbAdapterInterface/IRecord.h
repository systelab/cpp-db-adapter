#pragma once

#include "IField.h"
#include "IFieldValue.h"

namespace systelab { namespace db {

	class ITable;

	class IRecord
	{
	public:
		virtual ~IRecord() {}

		virtual unsigned int getFieldValuesCount() const = 0;
		virtual IFieldValue& getFieldValue(unsigned int index) const = 0;
		virtual IFieldValue& getFieldValue(const std::string& fieldName) const = 0;

		virtual bool hasFieldValue(const std::string& fieldName) const = 0;
	};
}}


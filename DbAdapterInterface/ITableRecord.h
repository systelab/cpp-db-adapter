#pragma once

#include <string>
#include <vector>

namespace systelab { namespace db {

	class ITable;
	class IField;
	class IFieldValue;

	class ITableRecord
	{
	public:
		virtual ~ITableRecord() {}

		virtual ITable& getTable() const = 0;

		virtual unsigned int getFieldValuesCount() const = 0;
		virtual IFieldValue& getFieldValue(unsigned int index) const = 0;
		virtual IFieldValue& getFieldValue(const std::string& fieldName) const = 0;

		virtual bool hasFieldValue(const std::string& fieldName) const = 0;

		virtual std::vector<IFieldValue*> getValuesList() const = 0;

		inline friend bool operator== (const ITableRecord& lhs, const ITableRecord& rhs);
		inline friend bool operator!= (const ITableRecord& lhs, const ITableRecord& rhs);
	};
}}

#include "ITableRecord.inl"

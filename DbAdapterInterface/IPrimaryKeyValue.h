#pragma once

#include <string>

namespace systelab::db {

	class IFieldValue;
	class IPrimaryKey;
	class ITable;

	class IPrimaryKeyValue
	{
	public:
		virtual ~IPrimaryKeyValue(void) {}

		virtual ITable& getTable() const = 0;
		virtual const IPrimaryKey& getPrimaryKey() const = 0;

		virtual unsigned int getFieldValuesCount() const = 0;
		virtual IFieldValue& getFieldValue(unsigned int index) const = 0;
		virtual IFieldValue& getFieldValue(const std::string& fieldName) const = 0;
	};

}


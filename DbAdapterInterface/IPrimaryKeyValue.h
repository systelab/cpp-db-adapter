#pragma once

#include "IPrimaryKey.h"
#include "IBinaryValue.h"
#include "IFieldValue.h"

namespace systelab { namespace db {

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

}}


#pragma once

#include <string>

namespace systelab::db {

	class ITable;
	class IField;

	class IPrimaryKey
	{
	public:
		virtual ~IPrimaryKey() {}

		virtual ITable& getTable() const = 0;

		virtual unsigned int getFieldsCount() const = 0;
		virtual const IField& getField(unsigned int index) const = 0;
		virtual const IField& getField(const std::string& fieldName) const = 0;
	};
}


#pragma once

#include <string>
#include <memory>

namespace systelab::db {

	class IField;
	class ITableRecord;
	class ITable;

	class ITableRecordSet
	{
	public:
		virtual ~ITableRecordSet() {}

		virtual ITable& getTable() const = 0;

		virtual unsigned int getFieldsCount() const = 0;
		virtual const IField& getField(unsigned int index) const = 0;
		virtual const IField& getField(const std::string& fieldName) const = 0;

		virtual unsigned int getRecordsCount() const = 0;

		virtual const ITableRecord& getCurrentRecord() const = 0;
		virtual std::unique_ptr<ITableRecord> copyCurrentRecord() const = 0;
		virtual bool isCurrentRecordValid() const = 0;
		virtual void nextRecord() = 0;
	};
}


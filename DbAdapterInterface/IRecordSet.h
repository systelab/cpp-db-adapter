#pragma once

#include <memory>
#include <string>

namespace systelab::db {

	class IField;
	class IRecord;

	class IRecordSet
	{
	public:
		virtual ~IRecordSet() {}

		virtual unsigned int getFieldsCount() const = 0;
		virtual const IField& getField(unsigned int index) const = 0;
		virtual const IField& getField(const std::string& fieldName) const = 0;

		virtual unsigned int getRecordsCount() const = 0;

		virtual const IRecord& getCurrentRecord() const = 0;
		virtual std::unique_ptr<IRecord> copyCurrentRecord() const = 0;
		virtual bool isCurrentRecordValid() const = 0;
		virtual void nextRecord() = 0;
	};
}


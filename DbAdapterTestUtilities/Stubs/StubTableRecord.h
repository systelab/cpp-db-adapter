#pragma once

#include "../Mocks/MockTableRecord.h"

#include <memory>
#include <vector>


namespace systelab::db::test_utility {

	class StubField;
	class StubFieldValue;

	class StubTableRecord : public MockTableRecord
	{
	public:
		StubTableRecord(const ITableRecord&);
		StubTableRecord(const StubTableRecord&);
		StubTableRecord(std::vector< std::unique_ptr<StubFieldValue> >&);
		~StubTableRecord() override = default;

		db::ITable& getTable() const;
		unsigned int getFieldValuesCount() const;
		IFieldValue& getFieldValue(unsigned int index) const;
		db::IFieldValue& getFieldValue(const std::string& fieldName) const;

		bool hasFieldValue(const std::string& fieldName) const;

		std::vector<IFieldValue*> getValuesList() const;

		StubTableRecord& operator= (const StubTableRecord& other);

	private:
		std::vector<std::unique_ptr<StubFieldValue>> m_fieldValues;
	};
}


#pragma once

#include "DbAdapterInterface/IPrimaryKeyValue.h"

namespace systelab::db::test_utility {

	class StubPrimaryKeyValue : public IPrimaryKeyValue
	{
	public:
		StubPrimaryKeyValue(const IPrimaryKey& primaryKey);
		virtual ~StubPrimaryKeyValue() override;

		ITable& getTable() const override;
		const IPrimaryKey& getPrimaryKey() const override;

		unsigned int getFieldValuesCount() const override;
		IFieldValue& getFieldValue(unsigned int index) const override;
		IFieldValue& getFieldValue(const std::string& fieldName) const override;

	private:
		const IPrimaryKey& m_primaryKey;
		std::vector<std::unique_ptr<IFieldValue>> m_fieldValues;

	};
}

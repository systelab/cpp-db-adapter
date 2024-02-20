#pragma once

#include "DbAdapterInterface/IPrimaryKey.h"

namespace systelab::db::test_utility {

	class StubTable;

	class StubPrimaryKey : public IPrimaryKey
	{
		public:

			StubPrimaryKey(StubTable& table);
			~StubPrimaryKey(){};

			ITable& getTable() const override;

			unsigned int getFieldsCount() const override;
			const IField& getField(unsigned int index) const override;
			const IField& getField(const std::string& fieldName) const override;

			void addField(const IField& tableField);

		private:
			StubTable& m_table;
			std::vector<const IField*> m_fields;
	};

}


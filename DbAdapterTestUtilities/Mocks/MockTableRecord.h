#pragma once

#include "DbAdapterInterface/ITableRecord.h"
#include "DbAdapterInterface/ITable.h"

#include "MockFieldValue.h"


namespace systelab { namespace db { namespace test_utility {

	class MockTableRecord : public ITableRecord
	{
	public:
		MockTableRecord();
		virtual ~MockTableRecord();

		MOCK_CONST_METHOD0(getTable, db::ITable&());

		MOCK_CONST_METHOD0(getFieldValuesCount, unsigned int());
		MOCK_CONST_METHOD1(getFieldValue, IFieldValue&(unsigned int));
		MOCK_CONST_METHOD1(getFieldValue, IFieldValue&(const std::string&));

		MOCK_CONST_METHOD1(hasFieldValue, bool(const std::string&));

		MOCK_CONST_METHOD0(getValuesList, std::vector<IFieldValue*>());
	};

}}}


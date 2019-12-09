#pragma once

#include "../Mocks/MockRecord.h"


namespace systelab { namespace db { namespace test_utility {

	class StubFieldValue;

	class StubRecord : public MockRecord
	{
	public:
		StubRecord();
		StubRecord(const StubRecord&);
		StubRecord(std::vector< std::unique_ptr<StubFieldValue> >& fieldValues);
		virtual ~StubRecord();

		unsigned int getFieldValuesCountStub() const;
		db::IFieldValue& getFieldValueByIndexStub(unsigned int index) const;
		db::IFieldValue& getFieldValueByNameStub(const std::string& name) const;
		bool hasFieldValueStub(const std::string& name) const;

		StubRecord& operator= (const StubRecord& other);

	protected:
		void setUpStubMethods();

	private:
		std::vector< std::unique_ptr<StubFieldValue> > m_fieldValues;
	};

}}}


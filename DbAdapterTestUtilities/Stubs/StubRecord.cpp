#include "stdafx.h"
#include "StubRecord.h"


using namespace testing;

namespace systelab { namespace db { namespace test_utility {

	StubRecord::StubRecord()
		:m_fieldValues()
	{
		setUpStubMethods();
	}

	StubRecord::StubRecord(const StubRecord& other)
		:m_fieldValues()
	{
		unsigned int nFieldValues = other.m_fieldValues.size();
		for (unsigned int i = 0; i < nFieldValues; i++)
		{
			m_fieldValues.push_back(std::unique_ptr<StubFieldValue>(new StubFieldValue(*other.m_fieldValues[i].get())));
		}

		setUpStubMethods();
	}

	StubRecord::StubRecord(std::vector< std::unique_ptr<StubFieldValue> >& fieldValues)
	{
		unsigned int nFieldValues = fieldValues.size();
		for (unsigned int i = 0; i < nFieldValues; i++)
		{
			m_fieldValues.push_back(std::move(fieldValues[i]));
		}

		setUpStubMethods();
	}

	StubRecord::~StubRecord() = default;

	unsigned int StubRecord::getFieldValuesCountStub() const
	{
		return m_fieldValues.size();
	}

	db::IFieldValue& StubRecord::getFieldValueByIndexStub(unsigned int index) const
	{
		return *m_fieldValues[index];
	}

	db::IFieldValue& StubRecord::getFieldValueByNameStub(const std::string& name) const
	{
		unsigned int nFieldValues = m_fieldValues.size();
		for (unsigned int i = 0; i < nFieldValues; i++)
		{
			std::string fieldName = m_fieldValues[i]->getField().getName();
			if (fieldName == name)
			{
				return *m_fieldValues[i];
			}
		}

		throw std::runtime_error(std::string("Record hasn't a value for field " + name).c_str());
	}

	bool StubRecord::hasFieldValueStub(const std::string& name) const
	{
		unsigned int nFieldValues = m_fieldValues.size();
		for (unsigned int i = 0; i < nFieldValues; i++)
		{
			std::string fieldName = m_fieldValues[i]->getField().getName();
			if (fieldName == name)
			{
				return true;
			}
		}

		return false;
	}

	StubRecord& StubRecord::operator= (const StubRecord& other)
	{
		unsigned int nFieldValues = other.m_fieldValues.size();
		for (unsigned int i = 0; i < nFieldValues; i++)
		{
			m_fieldValues.push_back(std::unique_ptr<StubFieldValue>(new StubFieldValue(*other.m_fieldValues[i].get())));
		}

		return *this;
	}

	void StubRecord::setUpStubMethods()
	{
		ON_CALL(*this, getFieldValuesCount()).WillByDefault(Invoke(this, &StubRecord::getFieldValuesCountStub));
		ON_CALL(*this, getFieldValue(A<unsigned int>())).WillByDefault(Invoke(this, &StubRecord::getFieldValueByIndexStub));
		ON_CALL(*this, getFieldValue(A<const std::string&>())).WillByDefault(Invoke(this, &StubRecord::getFieldValueByNameStub));
		ON_CALL(*this, hasFieldValue(_)).WillByDefault(Invoke(this, &StubRecord::hasFieldValueStub));
	}

}}}

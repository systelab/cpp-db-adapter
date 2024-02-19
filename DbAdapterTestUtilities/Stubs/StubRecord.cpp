#include "stdafx.h"
#include "StubRecord.h"

#include "StubFieldValue.h"

using namespace testing;

namespace systelab::db::test_utility {

	StubRecord::StubRecord()
		:m_fieldValues()
	{
		setUpStubMethods();
	}

	StubRecord::StubRecord(const StubRecord& other)
		:m_fieldValues()
	{
		unsigned int nFieldValues = (unsigned int) other.m_fieldValues.size();
		for (unsigned int i = 0; i < nFieldValues; i++)
		{
			m_fieldValues.push_back(std::make_unique<StubFieldValue>(*other.m_fieldValues[i].get()));
		}

		setUpStubMethods();
	}

	StubRecord::StubRecord(std::vector<std::unique_ptr<StubFieldValue>>& fieldValues)
	{
		unsigned int nFieldValues = (unsigned int) fieldValues.size();
		for (unsigned int i = 0; i < nFieldValues; i++)
		{
			m_fieldValues.push_back(std::move(fieldValues[i]));
		}

		setUpStubMethods();
	}

	StubRecord::~StubRecord() = default;

	unsigned int StubRecord::getFieldValuesCountStub() const
	{
		return (unsigned int) m_fieldValues.size();
	}

	db::IFieldValue& StubRecord::getFieldValueByIndexStub(unsigned int index) const
	{
		return *m_fieldValues[index];
	}

	db::IFieldValue& StubRecord::getFieldValueByNameStub(const std::string& name) const
	{
		unsigned int nFieldValues = static_cast<unsigned int>(m_fieldValues.size());
		for (const auto& fieldValue: m_fieldValues)
		{
			std::string fieldName = fieldValue->getField().getName();
			if (fieldName == name)
			{
				return *fieldValue;
			}
		}

		throw std::runtime_error(std::string("Record hasn't a value for field " + name).c_str());
	}

	bool StubRecord::hasFieldValueStub(const std::string& name) const
	{
		const auto fieldValueIterator = std::ranges::find_if(m_fieldValues,
			[&name](const std::unique_ptr<StubFieldValue>& fieldValue)
			{
				return fieldValue->getField().getName() == name;
			});

		return fieldValueIterator != m_fieldValues.cend();
	}

	StubRecord& StubRecord::operator= (const StubRecord& other)
	{
		unsigned int nFieldValues = (unsigned int) other.m_fieldValues.size();
		for (unsigned int i = 0; i < nFieldValues; i++)
		{
			m_fieldValues.push_back(std::make_unique<StubFieldValue>(*other.m_fieldValues[i].get()));
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
}

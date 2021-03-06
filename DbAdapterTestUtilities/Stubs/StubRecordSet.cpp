#include "stdafx.h"
#include "StubRecordSet.h"

#include "StubField.h"
#include "StubFieldValue.h"
#include "StubRecord.h"


using namespace testing;

namespace systelab { namespace db { namespace test_utility {

	StubRecordSet::StubRecordSet( std::vector< std::unique_ptr<StubRecord> >& records)
	{
		for (unsigned int i = 0; i < records.size(); i++)
		{
			m_records.push_back(std::unique_ptr<StubRecord>(new StubRecord(*records[i])));
		}

		m_iterator = m_records.begin();

		setUpStubMethods();
	}

	StubRecordSet::~StubRecordSet() = default;

	unsigned int StubRecordSet::getRecordsCountStub() const
	{
		return (unsigned int) m_records.size();
	}

	const IRecord& StubRecordSet::getCurrentRecordStub() const
	{
		return *m_iterator->get();
	}

	bool StubRecordSet::isCurrentRecordValidStub() const
	{
		return (m_iterator != m_records.end());
	}

	void StubRecordSet::nextRecordStub()
	{
		m_iterator++;
	}

	void StubRecordSet::setUpStubMethods()
	{
		ON_CALL(*this, getRecordsCount()).WillByDefault(Invoke(this, &StubRecordSet::getRecordsCountStub));
		ON_CALL(*this, getCurrentRecord()).WillByDefault(Invoke(this, &StubRecordSet::getCurrentRecordStub));
		ON_CALL(*this, isCurrentRecordValid()).WillByDefault(Invoke(this, &StubRecordSet::isCurrentRecordValidStub));
		ON_CALL(*this, nextRecord()).WillByDefault(Invoke(this, &StubRecordSet::nextRecordStub));
	}

}}}


#pragma once

#include "DbAdapterTestUtilities/Mocks/MockRecordSet.h"
#include "DbAdapterTestUtilities/Stubs/StubRecord.h"


namespace systelab { namespace db { namespace test_utility {

	class StubRecordSet : public MockRecordSet
	{
	public:
		StubRecordSet(std::vector< std::unique_ptr<StubRecord> >& records);
		virtual ~StubRecordSet();

		unsigned int getRecordsCountStub() const;
		const IRecord& getCurrentRecordStub() const;
		bool isCurrentRecordValidStub() const;
		void nextRecordStub();

	protected:
		void setUpStubMethods();

	private:
		std::vector< std::unique_ptr<StubRecord> > m_records;
		std::vector< std::unique_ptr<StubRecord> >::iterator m_iterator;
	};

}}}


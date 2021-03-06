#include "stdafx.h"
#include "MockDatabase.h"


namespace systelab { namespace db { namespace test_utility {

	MockDatabase::MockDatabase()
	{
	}

	MockDatabase::~MockDatabase()
	{
		size_t nTables = m_tables.size();
		for (size_t i = 0; i < nTables; i++)
		{
			delete m_tables[i];
		}
	}

}}}


#include "stdafx.h"
#include "MockDatabase.h"


namespace systelab { namespace db { namespace test_utility {

	MockDatabase::MockDatabase()
	{
	}

	MockDatabase::~MockDatabase()
	{
		unsigned int nTables = m_tables.size();
		for (unsigned int i = 0; i < nTables; i++)
		{
			delete m_tables[i];
		}
	}

}}}


#pragma once

#include "EntityComparator.h"
#include "EntityMatcher.h"

namespace systelab::db {
	class ITableRecord;
}

namespace systelab::db::test_utility {

	class TableRecordComparator
	{
	public:
		static testing::AssertionResult compare(const ITableRecord&, const ITableRecord&);
		static MatcherType<ITableRecord> isEqualTo(const ITableRecord&);
	};
}

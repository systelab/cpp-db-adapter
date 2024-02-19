#pragma once

#include "EntityMatcher.h"

namespace systelab::db {
	class IFieldValue;
}

namespace systelab::db::test_utility {

	class FieldValueComparator
	{
	public:
		static testing::AssertionResult compare(const IFieldValue&, const IFieldValue&);
		static MatcherType<IFieldValue> isEqualTo(const IFieldValue&);
	};
}

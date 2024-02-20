#pragma once

#include "EntityMatcher.h"

namespace systelab::db {
	class IField;
}

namespace systelab::db::test_utility {

	class FieldComparator
	{
	public:
		static testing::AssertionResult compare(const IField&, const IField&);
		static MatcherType<IField> isEqualTo(const IField&);
	};
}

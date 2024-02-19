#include "stdafx.h"
#include "FieldComparator.h"

#include "DbAdapterInterface/IField.h"
#include "EntityComparatorMacros.h"

using namespace testing;
namespace systelab::db::test_utility {

	AssertionResult FieldComparator::compare(const IField& expected, const IField& actual)
	{
		if (typeid(expected) != typeid(actual))
		{
			return AssertionFailure() << "Different class type: "
									  << "expected=" << typeid(expected).name() << ", "
									  << "actual=" << typeid(actual).name();
		}

		COMPARATOR_ASSERT_EQUAL(expected, actual, getIndex());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getName());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getType());

		return AssertionSuccess();
	}

	MatcherType<IField> FieldComparator::isEqualTo(const IField& expected)
	{
		return MakePolymorphicMatcher(EntityMatcher<IField>(expected, compare));
	}
}

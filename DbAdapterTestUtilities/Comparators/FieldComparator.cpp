#include "stdafx.h"
#include "TestUtilitiesInterface/EntityComparator.h"
#include "TestUtilitiesInterface/EntityComparatorMacros.h"

#include "DbAdapterInterface/IField.h"


using namespace testing;

namespace systelab { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const db::IField& expected, const db::IField& actual) const
	{
		if (typeid(expected) != typeid(actual))
		{
			return AssertionFailure() << "Different class type: "
									  << "expected=" << typeid(expected).name() << ", "
									  << "actual=" << typeid(actual).name();
		}

		COMPARATOR_ASSERT_EQUAL(expected, actual, getName());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getType());

		return AssertionSuccess();
	}

}};


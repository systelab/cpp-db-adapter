#include "stdafx.h"
#include "TestUtilitiesInterface/EntityComparator.h"

#include "DbAdapterInterface/IFieldValue.h"


using namespace testing;

namespace systelab { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const db::IFieldValue& expected, const db::IFieldValue& actual) const
	{
		if (typeid(expected) != typeid(actual))
		{
			return AssertionFailure() << "Different class type: "
									  << "expected=" << typeid(expected).name() << ", "
									  << "actual=" << typeid(actual).name();
		}

		const db::IField& expectedField = expected.getField();
		const db::IField& actualField = actual.getField();
		AssertionResult fieldResult = EntityComparator()(expectedField, actualField);
		if (!fieldResult)
		{
			return AssertionFailure() << "Different field data: " << fieldResult.message();
		}

		COMPARATOR_ASSERT_EQUAL(expected, actual, isDefault());
		COMPARATOR_ASSERT_EQUAL(expected, actual, isNull());

		if (!expected.isNull())
		{
			systelab::db::FieldTypes fieldType = expected.getField().getType();
			if (fieldType == systelab::db::BOOLEAN)
			{
				COMPARATOR_ASSERT_EQUAL(expected, actual, getBooleanValue());
			}

			if (fieldType == systelab::db::INT)
			{
				COMPARATOR_ASSERT_EQUAL(expected, actual, getIntValue());
			}

			if (fieldType == systelab::db::DOUBLE)
			{
				COMPARATOR_ASSERT_NEAR(expected, actual, getDoubleValue(), 1e-7);
			}

			if (fieldType == systelab::db::STRING)
			{
				COMPARATOR_ASSERT_EQUAL(expected, actual, getStringValue());
			}

			if (fieldType == systelab::db::DATETIME)
			{
				COMPARATOR_ASSERT_EQUAL(expected, actual, getDateTimeValue());
			}
		}

		return AssertionSuccess();
	}

}};


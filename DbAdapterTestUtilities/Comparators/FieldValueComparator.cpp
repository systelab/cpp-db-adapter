#include "stdafx.h"
#include "FieldValueComparator.h"

#include "DbAdapterInterface/IField.h"
#include "DbAdapterInterface/IFieldValue.h"
#include "FieldComparator.h"

using namespace testing;
namespace systelab::db::test_utility {

	AssertionResult FieldValueComparator::compare(const IFieldValue& expected, const IFieldValue& actual)
	{
		if (typeid(expected) != typeid(actual))
		{
			return AssertionFailure() << "Different class type: "
									  << "expected=" << typeid(expected).name() << ", "
									  << "actual=" << typeid(actual).name();
		}

		COMPARATOR_ASSERT_EQUAL(expected, actual, isDefault());
		COMPARATOR_ASSERT_EQUAL(expected, actual, isNull());

		const IField& expectedField = expected.getField();
		const IField& actualField = actual.getField();
		AssertionResult fieldResult = FieldComparator::compare(expectedField, actualField);
		if (!fieldResult)
		{
			return AssertionFailure() << "Different field data: " << fieldResult.message();
		}

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

	MatcherType<systelab::db::IFieldValue> FieldValueComparator::isEqualTo(const systelab::db::IFieldValue& expected)
	{
		return MakePolymorphicMatcher(EntityMatcher<systelab::db::IFieldValue>(expected, compare));
	}
}
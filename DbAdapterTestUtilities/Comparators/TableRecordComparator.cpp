#include "DbAdapterTestUtilities/stdafx.h"
#include "TableRecordComparator.h"

#include "DbAdapterInterface/IFieldValue.h"
#include "DbAdapterInterface/ITableRecord.h"
#include "EntityComparatorMacros.h"
#include "FieldValueComparator.h"

using namespace testing;
namespace systelab::db::test_utility {

	AssertionResult TableRecordComparator::compare(const ITableRecord& expected, const ITableRecord& actual)
	{
		if (typeid(expected) != typeid(actual))
		{
			return AssertionFailure() << "Different class type: "
									  << "expected=" << typeid(expected).name() << ", "
									  << "actual=" << typeid(actual).name();
		}

		COMPARATOR_ASSERT_EQUAL(expected, actual, getFieldValuesCount());

		unsigned int nFieldValues = expected.getFieldValuesCount();
		for (unsigned int i = 0; i < nFieldValues; i++)
		{
			const db::IFieldValue& expectedFieldValue = expected.getFieldValue(i);
			const db::IFieldValue& actualFieldValue = actual.getFieldValue(i);
		
			AssertionResult fieldValueResult = FieldValueComparator::compare(expectedFieldValue, actualFieldValue);
			if (!fieldValueResult)
			{
				return AssertionFailure() << "Different data for field " << i << " "
										  << "(name='" + expectedFieldValue.getField().getName() + "'): "
										  << fieldValueResult.message();
			}
		}

		return AssertionSuccess();
	}

	MatcherType<ITableRecord> TableRecordComparator::isEqualTo(const ITableRecord& expected)
	{
		return MakePolymorphicMatcher(EntityMatcher<ITableRecord>(expected, compare));
	}
}


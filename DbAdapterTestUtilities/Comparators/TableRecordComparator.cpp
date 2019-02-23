#include "stdafx.h"
#include "TestUtilitiesInterface/EntityComparator.h"

#include "DbAdapterInterface/IFieldValue.h"
#include "DbAdapterInterface/ITableRecord.h"

using namespace testing;

namespace systelab { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const db::ITableRecord& expected, const db::ITableRecord& actual) const
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
		
			AssertionResult fieldValueResult = EntityComparator()(expectedFieldValue, actualFieldValue);
			if (!fieldValueResult)
			{
				return AssertionFailure() << "Different data for field " << i << " "
										  << "(name='" + expectedFieldValue.getField().getName() + "'): "
										  << fieldValueResult.message();
			}
		}

		return AssertionSuccess();
	}

}};


#include "IFieldValue.h"
#include "IField.h"

namespace systelab::db {

	bool operator== (const ITableRecord& lhs, const ITableRecord& rhs)
	{
		if (lhs.getFieldValuesCount() != rhs.getFieldValuesCount())
		{
			return false;
		}

		auto lhsFieldValues = lhs.getValuesList();
		for (auto lhsFieldValue : lhsFieldValues)
		{
			std::string fieldName = lhsFieldValue->getField().getName();
			if (!rhs.hasFieldValue(fieldName))
			{
				return false;
			}

			const IFieldValue& rhsFieldValue = rhs.getFieldValue(fieldName);
			if (*lhsFieldValue != rhsFieldValue)
			{
				return false;
			}
		}

		return true;
	}

	bool operator!= (const ITableRecord& lhs, const ITableRecord& rhs)
	{
		return !(lhs == rhs);
	}

}

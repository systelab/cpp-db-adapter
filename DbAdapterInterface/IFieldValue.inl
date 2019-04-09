
namespace systelab { namespace db {

	bool operator== (const IFieldValue& lhs, const IFieldValue& rhs)
	{
		const IField& lhsField = lhs.getField();
		const IField& rhsField = rhs.getField();

		if (lhsField != rhsField)
		{
			return false;
		}

		if (lhs.isNull() != rhs.isNull())
		{
			return false;
		}

		if (!lhs.isNull())
		{
			FieldTypes fieldType = lhsField.getType();
			switch (fieldType)
			{
			case FieldTypes::BOOLEAN:
				return lhs.getBooleanValue() == rhs.getBooleanValue();
			case FieldTypes::INT:
				return lhs.getIntValue() == rhs.getIntValue();
			case FieldTypes::DOUBLE:
				return lhs.getDoubleValue() == rhs.getDoubleValue();
			case FieldTypes::STRING:
				return lhs.getStringValue() == rhs.getStringValue();
			case FieldTypes::DATETIME:
				return lhs.getDateTimeValue() == rhs.getDateTimeValue();
			default:
				return true;
			}
		}

		return true;
	}

	bool operator!= (const IFieldValue& lhs, const IFieldValue& rhs)
	{
		return !(lhs == rhs);
	}

}}
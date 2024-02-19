namespace systelab::db {

	bool operator== (const IField& lhs, const IField& rhs)
	{
		if (lhs.getType() != rhs.getType()
			|| lhs.getName() != rhs.getName())
		{
			return false;
		}

		return true;
	}
}

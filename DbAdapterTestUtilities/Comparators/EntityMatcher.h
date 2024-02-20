#pragma once

#include "gtest/gtest.h"

namespace systelab::db::test_utility {

	template<typename _Entity>
	class EntityMatcher
	{
	private:
		typedef std::function<testing::AssertionResult(const _Entity&, const _Entity&)> EntityComparison;
		const _Entity& m_expected;
		const EntityComparison m_entityComparison;
	public:
		EntityMatcher(const _Entity& expected, const EntityComparison& entityComparison)
			: m_expected(expected)
			, m_entityComparison(entityComparison)
		{}

		bool MatchAndExplain(const _Entity& actual, testing::MatchResultListener result_listener) const
		{
			auto result = m_entityComparison(m_expected, actual);
			if (!result)
			{
				result_listener = result.message();
			}
			return result;
		}
		void DescribeTo(std::ostream* os) const { *os << "is equal to expected"; }
		void DescribeNegationTo(std::ostream* os) const { *os << "is not equal to expected"; }
	};

	template<typename _Entity> using MatcherType = testing::PolymorphicMatcher<EntityMatcher<_Entity>>;
}
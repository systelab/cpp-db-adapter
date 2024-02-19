#pragma once

#include <gtest/gtest.h>

// Macros to be used by the comparators to compare the same expression for 2 entities of the same type
#define COMPARATOR_ASSERT_EQUAL(EXPECTED, TO_TEST, EXPRESSION) \
	if (TO_TEST.EXPRESSION != EXPECTED.EXPRESSION) \
	{ \
		return testing::AssertionFailure() << "Result for expression " #EXPRESSION " is different: expected=" << EXPECTED.EXPRESSION << ", actual=" << TO_TEST.EXPRESSION;\
	}

#define COMPARATOR_ASSERT_NEAR(EXPECTED, TO_TEST, EXPRESSION, TOLERANCE) \
	if (fabs(TO_TEST.EXPRESSION - EXPECTED.EXPRESSION) > TOLERANCE) \
	{ \
		return testing::AssertionFailure() << "Result for expression " #EXPRESSION " is different: expected=" << EXPECTED.EXPRESSION << ", actual=" << TO_TEST.EXPRESSION << ", tolerance=" << TOLERANCE;\
	}

#define COMPARATOR_ASSERT_NEAR_REL(EXPECTED, TO_TEST, EXPRESSION, REL_ERR) \
	if (fabs(TO_TEST.EXPRESSION - EXPECTED.EXPRESSION) > (std::min(std::fabs(EXPECTED.EXPRESSION), std::fabs(TO_TEST.EXPRESSION)) * REL_ERR)) \
	{ \
		return testing::AssertionFailure() << "Result for expression " #EXPRESSION " is different: expected=" << EXPECTED.EXPRESSION << ", actual=" << TO_TEST.EXPRESSION << ", relative error=" << REL_ERR;\
	}

#define COMPARATOR_ASSERT_EQUAL_WITH_EXCLUSION(EXPECTED, TO_TEST, EXPRESSION, MEMBER_NAME) \
	if (!m_configuration.isMemberExcluded(MEMBER_NAME))\
	{\
		if (TO_TEST.EXPRESSION != EXPECTED.EXPRESSION) \
		{ \
			return testing::AssertionFailure() << "Result for expression " #EXPRESSION " is different: expected=" << EXPECTED.EXPRESSION << ", actual=" << TO_TEST.EXPRESSION;\
		}\
	}

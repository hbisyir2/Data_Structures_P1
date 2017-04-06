#include <string>
#include <vector>
#include <cxxtest/TestSuite.h>

#include "search.h"

class SearchTests : public CxxTest::TestSuite
{
public:
	void testTODO(void)
	{
		std::vector<int> testVector = { 1,2,3,4,5,6,7 };
		//Test for last place in vector for linear, iterative, and binary
		SearchResultType<int> result1 = linear_search(testVector, 7);
		TS_ASSERT(result1.found);
		TS_ASSERT_EQUALS(result1.value, 7);
		TS_ASSERT_EQUALS(result1.index, 6);
		SearchResultType<int> result2 = iterative_binary_search(testVector, 7);
		TS_ASSERT(result2.found);
		TS_ASSERT_EQUALS(result2.value, 7);
		TS_ASSERT_EQUALS(result2.index, 6);
		SearchResultType<int> result3 = recursive_binary_search(testVector, 7);
		TS_ASSERT(result3.found);
		TS_ASSERT_EQUALS(result3.value, 7);
		TS_ASSERT_EQUALS(result3.index, 6);
		//Test for first place in vector for linear, iterative, and binary
		SearchResultType<int> result4 = linear_search(testVector, 1);
		TS_ASSERT(result4.found);
		TS_ASSERT_EQUALS(result4.value, 1);
		TS_ASSERT_EQUALS(result4.index, 0);
		SearchResultType<int> result5 = iterative_binary_search(testVector, 1);
		TS_ASSERT(result5.found);
		TS_ASSERT_EQUALS(result5.value, 1);
		TS_ASSERT_EQUALS(result5.index, 0);
		SearchResultType<int> result6 = recursive_binary_search(testVector, 1);
		TS_ASSERT(result6.found);
		TS_ASSERT_EQUALS(result6.value, 1);
		TS_ASSERT_EQUALS(result6.index, 0);
		//Test when value is too high
		SearchResultType<int> result7 = linear_search(testVector, 8);
		TS_ASSERT(!result7.found);
		TS_ASSERT_EQUALS(result7.value, 7);
		TS_ASSERT_EQUALS(result7.index, 6);
		SearchResultType<int> result8 = iterative_binary_search(testVector, 8);
		TS_ASSERT(!result8.found);
		TS_ASSERT_EQUALS(result8.value, 7);
		TS_ASSERT_EQUALS(result8.index, 6);
		SearchResultType<int> result9 = recursive_binary_search(testVector, 8);
		TS_ASSERT(!result9.found);
		TS_ASSERT_EQUALS(result9.value, 7);
		TS_ASSERT_EQUALS(result9.index, 6);
		//Test when value is too low
		SearchResultType<int> result10 = linear_search(testVector, 0);
		TS_ASSERT(!result10.found);
		TS_ASSERT_EQUALS(result10.value, 7);
		TS_ASSERT_EQUALS(result10.index, 6);
		SearchResultType<int> result11 = iterative_binary_search(testVector, 0);
		TS_ASSERT(!result11.found);
		TS_ASSERT_EQUALS(result11.value, 1);
		TS_ASSERT_EQUALS(result11.index, 0);
		SearchResultType<int> result12 = recursive_binary_search(testVector, 0);
		TS_ASSERT(!result12.found);
		TS_ASSERT_EQUALS(result12.value, 1);
		TS_ASSERT_EQUALS(result12.index, 0);
		//Test for middle value
		SearchResultType<int> result13 = linear_search(testVector, 4);
		TS_ASSERT(result13.found);
		TS_ASSERT_EQUALS(result13.value, 4);
		TS_ASSERT_EQUALS(result13.index, 3);
		SearchResultType<int> result14 = iterative_binary_search(testVector, 4);
		TS_ASSERT(result14.found);
		TS_ASSERT_EQUALS(result14.value, 4);
		TS_ASSERT_EQUALS(result14.index, 3);
		SearchResultType<int> result15 = recursive_binary_search(testVector, 4);
		TS_ASSERT(result15.found);
		TS_ASSERT_EQUALS(result15.value, 4);
		TS_ASSERT_EQUALS(result15.index, 3);
		//Test for middle value not found
		std::vector<int> testVector2 = { 1,3,4,5,6,7,9 };
		SearchResultType<int> result16 = linear_search(testVector2, 2);
		TS_ASSERT(!result16.found);
		TS_ASSERT_EQUALS(result16.value, 9);
		TS_ASSERT_EQUALS(result16.index, 6);
		SearchResultType<int> result17 = iterative_binary_search(testVector2, 2);
		TS_ASSERT(!result17.found);
		TS_ASSERT_EQUALS(result17.value, 1);
		TS_ASSERT_EQUALS(result17.index, 0);
		SearchResultType<int> result18 = recursive_binary_search(testVector2, 2);
		TS_ASSERT(!result18.found);
		TS_ASSERT_EQUALS(result18.value, 1);
		TS_ASSERT_EQUALS(result18.index, 0);
	}
};

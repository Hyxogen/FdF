#include "simple_tests.hpp"
#include <cstring>

extern "C" {
	#include "parser/map_parser.h"
}

SIMPLE_TEST(flat_map) {
	int width, height;
	const char *map_str = "0 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0\n";
	const int expected[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int* actual = parser_parse_map(map_str, std::strlen(map_str), &width, &height);
	ASSERT_EQUAL_ARRAY(expected, actual, 25);
	free(actual);
}

SIMPLE_TEST(hobbly_map) {
	int width, height;
	const char *map_str = "-4 0 9 22 42\n9 -100 5 4 5\n242 1 0 0 45\n54 61 0 -542 -214783648\n214783647 0 -3 4 5\n";
	const int expected[] = {-4, 0, 9, 22, 42, 9, -100, 5, 4, 5, 242, 1, 0, 0, 45, 54, 61, 0, -542, -214783648, 214783647, 0, -3, 4, 5};
	int* actual = parser_parse_map(map_str, std::strlen(map_str), &width, &height);
	ASSERT_EQUAL_ARRAY(expected, actual, 25);
	free(actual);
}

SIMPLE_TEST(nonsquare_map) {
	int width, height;
	const char *map_str = "0 5 3\n 2 3 4\n";
	const int expected[] = {0, 5, 3, 2, 3, 4 };
	int *actual = parser_parse_map(map_str, std::strlen(map_str), &width, &height);
	ASSERT_EQUAL(width, 3);
	ASSERT_EQUAL(height, 2);
	ASSERT_EQUAL_ARRAY(expected, actual, 6);
	free(actual);
}

SIMPLE_TEST(test102_map) {
	int width, height;
	const char *map_str = "1 0 0 -1 -1 0 1 1 0 0\n-1 0 0 0 1 0 0 0 0 0\n-1 1 0 0 -1 1 0 0 0 1\n1 -1 0 1 1 -1 0 0 -1 0\n1 -1 -1 0 -1 0 0 0 -1 -1\n-1 1 0 1 1 0 1 0 0 0\n0 -1 -1 0 0 1 0 0 0 1\n0 0 0 0 1 0 -1 0 0 0\n-1 -1 0 1 -1 0 1 0 0 1\n0 0 1 -1 0 -1 0 0 0 0\n";
	const int expected[] = {1, 0, 0, -1, -1, 0, 1, 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, 0, 0, 0, -1, 1, 0, 0, -1, 1, 0, 0, 0, 1, 1, -1, 0, 1, 1, -1, 0, 0, -1, 0, 1, -1, -1, 0, -1, 0, 0, 0, -1, -1, -1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, -1, -1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, -1, 0, 0, 0, -1, -1, 0, 1, -1, 0, 1, 0, 0, 1, 0, 0, 1, -1, 0, -1, 0, 0, 0, 0};
	int *actual = parser_parse_map(map_str, std::strlen(map_str), &width, &height);
	ASSERT_EQUAL(width, 10);
	ASSERT_EQUAL(height, 10);
	ASSERT_EQUAL_ARRAY(expected, actual, 10 * 10);
	free(actual);
}

int main(int argc, char **argv) {
	SIMPLE_INIT(argc, argv);
	SIMPLE_RUN_ALL_TESTS();
	SIMPLE_CLEANUP();
	return (0);
}

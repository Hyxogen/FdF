#include "simple_tests.hpp"

extern "C" {
	#include "parser/map_parser.h"
}

SIMPLE_TEST(flat_map) {
	int width, height;
	const char *map_str = "0 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0\n";
	const int expected[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int* actual = parser_parse_map(map_str, strlen(map_str) + 1, &width, &height);
	ASSERT_EQUAL_ARRAY(expected, actual, 25);
	// SimpleAssertArrayEqual(*this, expected, actual, 25, __FILE__, __LINE__, "");
}

int main(int argc, char **argv) {
	SIMPLE_INIT(argc, argv);
	SIMPLE_RUN_ALL_TESTS();
	SIMPLE_CLEANUP();
	return (0);
}
#define BOOST_TEST_MODULE calculations

#include <boost/test/included/unit_test.hpp>

#include "calculations.hpp"

BOOST_AUTO_TEST_SUITE(calculations)

BOOST_AUTO_TEST_CASE(combinations) {
  detail::FrequencyMap freq_map   = {{}};
  freq_map[detail::to_index('E')] = 3;
  freq_map[detail::to_index('K')] = 2;
  freq_map[detail::to_index('O')] = 2;
  freq_map[detail::to_index('P')] = 1;
  freq_map[detail::to_index('R')] = 1;

  BOOST_REQUIRE_EQUAL(detail::calculate_combinations(freq_map, detail::to_index('E'), 9), 5040);
  BOOST_REQUIRE_EQUAL(detail::calculate_combinations(freq_map, detail::to_index('K'), 9), 3360);

  freq_map[detail::to_index('O')] = 1;

  BOOST_REQUIRE_EQUAL(detail::calculate_combinations(freq_map, detail::to_index('E'), 8), 1260);
  BOOST_REQUIRE_EQUAL(detail::calculate_combinations(freq_map, detail::to_index('K'), 8), 840);

  freq_map[detail::to_index('O')] = 0;

  BOOST_REQUIRE_EQUAL(detail::calculate_combinations(freq_map, detail::to_index('E'), 7), 180);

  freq_map[detail::to_index('K')] = 1;

  BOOST_REQUIRE_EQUAL(detail::calculate_combinations(freq_map, detail::to_index('E'), 6), 60);

  freq_map[detail::to_index('K')] = 0;
  freq_map[detail::to_index('E')] = 1;

  BOOST_REQUIRE_EQUAL(detail::calculate_combinations(freq_map, detail::to_index('E'), 3), 2);
}

BOOST_AUTO_TEST_CASE(number) {
  BOOST_REQUIRE_EQUAL(calculate_number("NONINTUITIVENESS"), 8222334634);
  BOOST_REQUIRE_EQUAL(calculate_number("BOOKKEEPER"), 10743);
  BOOST_REQUIRE_EQUAL(calculate_number("QUESTION"), 24572);
  BOOST_REQUIRE_EQUAL(calculate_number("BAAA"), 4);
  BOOST_REQUIRE_EQUAL(calculate_number("AAAB"), 1);
  BOOST_REQUIRE_EQUAL(calculate_number("ABAB"), 2);
}

BOOST_AUTO_TEST_SUITE_END()

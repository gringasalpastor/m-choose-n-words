#include "calculations.hpp"

#include <boost/math/special_functions/binomial.hpp>
#include <stdexcept>

uint64_t calculate_number(const std::string& word) {
  // Build the frequency map for the whole word
  detail::FrequencyMap frequency_map = {{}};

  for (const auto& _char : word) {
    if (_char < 'A' || _char > 'Z')
      throw std::invalid_argument("Input contains an character that is not in the range A-Z");

    frequency_map[detail::to_index(_char)]++;
  }

  uint64_t sum            = 0;
  int      substring_size = word.size();
  for (const auto& _char : word) {
    const int current_char_index = detail::to_index(_char);
    // Loop over all letters that appear before the current first letter
    for (int i = 0; i < current_char_index; i++) {
      // Calculate the number of ways that this letter could come before the current first letter
      if (frequency_map[i] != 0) sum += detail::calculate_combinations(frequency_map, i, substring_size);
    }

    frequency_map[current_char_index]--;
    substring_size--;
  }

  return sum + 1;
}

namespace detail {
uint64_t calculate_combinations(const FrequencyMap& frequency_map, const int char_index, const int substring_size) {
  uint64_t combinations = 1;
  int      m            = substring_size - 1;
  for (int i = 0; i < static_cast<int>(frequency_map.size()); i++) {
    int num_chars = frequency_map[i];
    if (i == char_index) num_chars--;

    /*
     * NOTE: This could be made faster by using a lookup table for all of the binomial_coefficients
     * with m and n less than some threshold. `boost::math::binomial_coefficient` already uses a
     * lookup table internally for some parts of its calculations,
     */
    combinations *= static_cast<uint64_t>(boost::math::binomial_coefficient<long double>(m, num_chars));
    m -= num_chars;
  }
  return combinations;
}

int to_index(const char c) {
  assert(c >= 'A' && c <= 'Z');
  return c - 'A';
}
}  // namespace detail

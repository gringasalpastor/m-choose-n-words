#ifndef GUARD_CALCULATIONS_H
#define GUARD_CALCULATIONS_H

#include <array>

/*
 * Return the 'number' for a given word. Input must contain only letters in the
 * range A-Z. Words containing letters not in A-Z will throw an exception.
 * 
 * For each word.substring(i, word.size()) the number of combinations of ways that
 * any letter, l, where l < word[i] could be the first letter is calculated. The sum
 * of this is all positions that could come before the given word; so this sum + 1 is
 * returned.
 * 
 * Example "BOOKKEEPER":
 * 
 * BOOKKEEPER --> 0             // No letters < 'B'
 * OOKKEEPER --> 5040 + 3360    // 'E' could of been first 5040 ways and 'K' 3360 ways
 * OKKEEPER --> 1260 + 840      // 'E' could of been first 1260 ways and 'K' 840 ways
 * KKEEPER --> 180              // 'E' could of been first 180 ways
 * EEPER --> 60                 // No letters < 'E'
 * EPER --> 60                  // No letters < 'E'
 * PER --> 2                    // 'E' could of been first 2 ways
 * ER --> 0                     // 'No letters < 'E'
 * R --> 0                      // 'No letters < 'R'
 * 
 */
uint64_t calculate_number(const std::string& word);

// Internal details used for calculating the number
namespace detail
{
    /*
    * Used to store the frequency for letters in the range A-Z. 'A' maps to index 0. 
    * Use `to_index` to get the index of a given letter.
    * 
    * Alternatively, `std::map<char, int>` could have been used. However, this would cause
    * cache misses since elements are not stored contiguously (chasing pointers). Since the 
    * problem was scoped to exactly the range A-Z, I decided to use an std::array for the mapping.
    * This has the drawback that we always end up iterating over most of the array(even for 
    * letters with a frequency of 0). This is still faster though since the whole map will stay
    * in one cache entry (cache locality). 
    * reference: <http://cppwisdom.quora.com/std-map-and-std-set-considered-harmful>
    */
    typedef std::array<int, 26> FrequencyMap;

    /*
    * Return the number of ways that a substring of size `substring_size`
    * could start with the letter corresponding to `current_char_index`.
    * `frequency_map` is the FrequencyMap for the given substring.
    * 
    * Example given the substring "OOKKEEPER":
    * 
    * calculate_combinations(freq_map, to_index('E'), 9) == 5040
    * 
    * Reasoning:
    * Let C(m,n) be the binomial_coefficient(m choose n)
    * 
    * So we have that the first position is fixed, and 8 remaining positions left
    * 
    * ('E')-->   C(8, 2) = 28  // Only 2 because we used 1 'E' for the first position
    * ('K')-->   C(6, 2) = 15  // 6(8-2) comes from subtracting off the 2 E's already placed
    * ('O')-->   C(4, 2) = 6
    * ('R')-->   C(2, 1) = 2
    * ('P')-->   C(1, 1) = 1
    *
    * 5040 == 28*15*6*2*1
    * 
    * See `test_calculations.cpp` for more examples.
    * 
    */
    uint64_t calculate_combinations(const FrequencyMap& frequency_map,
                                    const int char_index,
                                    const int substring_size);

    /*
    * Return the index for a given letter in the `FrequencyMap`
    */
    int to_index(const char c);
}

#endif 
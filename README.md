# m-choose-n-words
Using binomial coefficient to solve a counting challenge

# Challenge
Consider a "word" as any sequence of capital letters A-Z (not limited to just "dictionary words"). For any word with at least two different letters, there are other words composed of the same letters but in a different order.

We can then assign a number to every word, based on where it falls in an alphabetically sorted list of all words made up of the same set of letters. One way to do this would be to generate the entire list of words and find the desired one, but this would be slow if the word is long. We use binomial coefficient to make this fast.

Sample words, with their rank:
ABAB = 2 AAAB = 1 BAAA = 4 QUESTION = 24572 BOOKKEEPER = 10743 NONINTUITIVENESS = 8222334634

# Required Dependencies 
 
 - CMake (used to build)
 - Boost (used for binomial_coefficient and timing functions)

# How to Build

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j
```

# How to Run

```
./m-choose-n NONINTUITIVENESS
```

# How to Run the Tests

```
make test
```

# Format
```
find ./ -name "*.h" -o -name "*.cpp" | xargs clang-format -i --style=file
```

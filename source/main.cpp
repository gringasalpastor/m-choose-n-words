#include <iostream>

#include "calculations.hpp"
#include "timer.hpp"

int main(int argc, const char* argv[]) {
  if (argc != 2) {
    std::cerr << "Must pass in exactly 1 argument." << std::endl;
    std::cerr << std::string("Usage: ") + argv[0] + " BOOKKEEPER" << std::endl;
    return 1;
  }

  try {
    timer t;
    std::cout << calculate_number(argv[1]) << std::endl;
    std::cout << "Run Time: " << t << " ms" << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown Exception." << std::endl;
  }

  return 0;
}

#pragma once

#include "benchmark.hpp"
#include <tibonacci.hpp>
// std
#include <cstdint>
#include <ctime>
#include <iostream>

namespace Tests {
uint64_t get_fib_number(int n) {
  int first = 1, second = 1;
  if (n <= 2)
    return 1;
  for (int i = 3; i <= n; ++i) {
    second = second + first;
    first = second - first;
  }
  return second;
}

void test_calculating(int number_of_tests = 10, int max_number_of_threads = 5) {
  srand(time(NULL));
  if (number_of_tests == 0)
    number_of_tests = 10;
  if (max_number_of_threads == 0)
    max_number_of_threads = 5;

  int errors = 0;
  size_t max_size = 5000;
  TIB::Tibonacci tib;

  std::cout << "-----Testing caclulating with threads-----" << std::endl;

  for (int i = 0; i < number_of_tests; ++i) {
    fill_tib(tib, max_size);
    tib.calculate_fibonacci_numbers_with_threads(
        rand() % max_number_of_threads + 1);
    for (int j = 0; j < max_size; ++j) {
      uint64_t tib_result = tib.get_fibonacci_number(j);
      uint64_t my_result = get_fib_number(tib.get_start_number(j));
      if (tib_result != my_result) {
        errors++;
        std::cout << "ERROR IN TEST:" << std::endl;
        std::cout << "\tRequired Fibonacci number: " << tib.get_start_number(j)
                  << std::endl;
        std::cout << "\tTibonacci result: " << tib_result << std::endl;
        std::cout << "\tCorrect result:" << my_result << std::endl;
      }
    }
  }
  if (errors == 0)
    std::cout
        << "-----All calculating with threads tests passed successfully-----"
        << std::endl;
  else
    std::cout << "----" << errors << " errors in some tests-----" << std::endl;
  errors = 0;
  std::cout << "-----Testing calculating without threads-----" << std::endl;
  for (int i = 0; i < number_of_tests; ++i) {
    fill_tib(tib, max_size);
    tib.calculate_fibonacci_numbers_without_threads();
    for (int j = 0; j < max_size; ++j) {
      uint64_t tib_result = tib.get_fibonacci_number(j);
      uint64_t my_result = get_fib_number(tib.get_start_number(j));
      if (tib_result != my_result) {
        errors++;
        std::cout << "ERROR IN TEST:" << std::endl;
        std::cout << "\tRequired Fibonacci number: " << tib.get_start_number(j)
                  << std::endl;
        std::cout << "\tTibonacci result: " << tib_result << std::endl;
        std::cout << "\tCorrect result:" << my_result << std::endl;
      }
    }
  }
  if (errors == 0)
    std::cout
        << "-----All calculating tests without threads passed successfully-----"
        << std::endl;
  else
    std::cout << "----" << errors << " errors in some tests-----" << std::endl;
}
} // namespace Tests
#pragma once

#include "../thirdparty/simple-bench.h"
#include <tibonacci.hpp>

// std
#include <algorithm>
#include <ctime>
#include <iostream>
namespace Tests {
void fill_tib(TIB::Tibonacci &tib, int size_to_fill) {
  tib.clear_all();
  for (int i = 0; i < size_to_fill; ++i)
    tib.push_back_start_number(rand() % 92 + 1);
}

void benchmark(int number_of_elements = 10000, int tests = 10,
               int number_of_threads = 5) {
  std::cout << "Benchmarking TIB::Tibonacci" << std::endl;
  std::cout << "Number of elements = " << number_of_elements << std::endl;
  std::cout << "Number of tests: " << tests << std::endl;
  std::cout << "Number of using threads " << number_of_threads << std::endl;
  srand(time(NULL));

  if (number_of_elements == 0)
    number_of_elements = 10000;
  if (tests == 0)
    tests = 10;
  if (number_of_threads == 0)
    number_of_threads = 5;

  double with_threads_result = 0;
  double without_threads_result = 0;

  TIB::Tibonacci tib;
  timespec t1, t2;
  double t;
  simple_gettime(&t1);
  for (int i = 0; i < tests; ++i) {
    fill_tib(tib, number_of_elements);
    tib.calculate_fibonacci_numbers_without_threads();
  }
  simple_gettime(&t2);
  t = diff(t1, t2);
  without_threads_result = t;
  std::cout << "Calculating without threads took: " << t << " seconds."
            << std::endl;
  simple_gettime(&t1);
  for (int i = 0; i < tests; ++i) {
    fill_tib(tib, number_of_elements);
    tib.calculate_fibonacci_numbers_with_threads(number_of_threads);
  }
  simple_gettime(&t2);
  t = diff(t1, t2);
  with_threads_result = t;
  std::cout << "Calculating with " << number_of_threads << " threads took " << t
            << " seconds. " << std::endl;
  std::cout << "Difference is "
            << std::abs(with_threads_result - without_threads_result)
            << " seconds." << std::endl;
}
} // namespace Tests
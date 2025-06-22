#pragma once

#include <Tibonacci.hpp>

// std
#include <algorithm>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <chrono>

namespace Tests {
void fill_tib(TIB::Tibonacci &tib, int size_to_fill) {
  tib.clear_all();
  for (int i = 0; i < size_to_fill; ++i)
    tib.push_back_start_number(rand() % 92 + 1);
}

void benchmark(int number_of_elements = 10000, int tests = 10,
               int number_of_threads = 5) {

  if (number_of_elements == 0)
    number_of_elements = 10000;
  if (tests == 0)
    tests = 10;
  if (number_of_threads == 0)
    number_of_threads = 5;

  std::cout << "Benchmarking TIB::Tibonacci" << std::endl;
  std::cout << "Number of elements = " << number_of_elements << std::endl;
  std::cout << "Number of tests: " << tests << std::endl;
  std::cout << "Number of using threads " << number_of_threads << std::endl;
  srand(time(NULL));

  double with_threads_result = 0;
  double without_threads_result = 0;

  TIB::Tibonacci tib;

  double diff = 0;

  for (int i = 0; i < tests; ++i) {
    fill_tib(tib, number_of_elements);
    auto start = std::chrono::high_resolution_clock::now();
    tib.calculate_fibonacci_numbers_without_threads();
    auto end = std::chrono::high_resolution_clock::now();
    diff = std::chrono::duration<double>(end - start).count();
    without_threads_result += diff;
  }
  std::cout << "Calculating without threads took: " << without_threads_result << " seconds."
            << std::endl;
  for (int i = 0; i < tests; ++i) {
    fill_tib(tib, number_of_elements);
    auto start = std::chrono::high_resolution_clock::now();
    tib.calculate_fibonacci_numbers_with_threads(number_of_threads);
    auto end = std::chrono::high_resolution_clock::now();
    diff = std::chrono::duration<double>(end - start).count();
    with_threads_result += diff;
  }
  std::cout << "Calculating with " << number_of_threads << " threads took: " << with_threads_result
            << " seconds. " << std::endl;
  std::cout << "Difference is "
            << std::abs(with_threads_result - without_threads_result)
            << " seconds. ~" << std::setprecision(2) << without_threads_result / with_threads_result << "x"<< std::endl;
}
} // namespace Tests
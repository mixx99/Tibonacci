#pragma once

#include "typedef.h"

// std
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>
#include <stdexcept>

namespace TIB{
  class Tibonacci{
    std::vector<int> start_numbers; // int?
    std::vector<ULL> fibonacci_numbers;

  public:
    Tibonacci() = default;
    Tibonacci(size_t n) : start_numbers(n) {}
    Tibonacci(const std::vector<int>& other) : start_numbers(other) {}

    void calculate_fibonacci_numbers_with_threads(int threads);
    void calculate_fibonacci_numbers_without_threads();

    std::vector<int> get_start_numbers()     const { return start_numbers; }
    std::vector<ULL> get_fibonacci_numbers() const { return fibonacci_numbers; }
    ULL get_fibonacci_number(size_t index)   const { return fibonacci_numbers[index]; }
  };
}
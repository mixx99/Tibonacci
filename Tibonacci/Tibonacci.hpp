#pragma once

// std
#include <vector>
#include <cstdint>

namespace TIB{
  class Tibonacci{
    std::vector<int> start_numbers;
    std::vector<uint64_t> fibonacci_numbers;

    uint64_t calculate_fib(int n) const;
  public:
    Tibonacci() = default;
    Tibonacci(size_t n) : start_numbers(n), fibonacci_numbers(n) {}
    Tibonacci(const std::vector<int>& other) : start_numbers(other), fibonacci_numbers(other.size()) {}

    void calculate_fibonacci_numbers_with_threads(int threads);
    void calculate_fibonacci_numbers_without_threads();

    void push_back_start_number(int number);

    std::vector<int> get_start_numbers()          const { return start_numbers; }
    std::vector<uint64_t> get_fibonacci_numbers() const { return fibonacci_numbers; }
    uint64_t get_fibonacci_number(size_t index)   const { return fibonacci_numbers[index]; }
    int get_start_number(size_t index) const { return start_numbers[index]; }
    void clear_all(){ start_numbers.clear(); fibonacci_numbers.clear(); }
  };
}
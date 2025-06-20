#include "Tibonacci.hpp"

#include <iostream>

namespace TIB{
  void Tibonacci::calculate_fibonacci_numbers_with_threads(int number_of_threads){
    if(number_of_threads <= 0)
    throw std::invalid_argument("Invalid threads number");

    if(number_of_threads > start_numbers.size())
    number_of_threads = start_numbers.size();
    
    std::vector<std::thread> threads;

    auto work = [this](size_t start, size_t end){
      try{
      for(int i = start; i < end; ++i)
        fibonacci_numbers[i] = calculate_fib(start_numbers[i]);
      }
      catch(const std::exception& e){
        std::cerr << "Exception in work thread: " << e.what() << std::endl;
        throw;
      }
    };
    int work_size_for_each = start_numbers.size() / number_of_threads;
    int start = 0;
    int end = work_size_for_each;
    for(int i = 0; i < number_of_threads; ++i){
      if(i == number_of_threads - 1){
        threads.emplace_back(work, start, start_numbers.size());
        break;
      }
      threads.emplace_back(work, start, end);
      start = end;
      end += work_size_for_each;
    }

    for(int i = 0; i < threads.size(); ++i)
      threads[i].join();
  }

  uint64_t Tibonacci::calculate_fib(int n) const {
    int a = 1, b = 1;
    if(n <= 0)
      throw std::invalid_argument("Invalid Fibonacci number");
    if(n >= 93)
      throw std::invalid_argument("Fibonacci number is too large");
    if(n <= 2) return 1;
    for(int i = 2; i < n; ++i){
      b += a;
      a = b - a;
    }
    return b;
  }

  void Tibonacci::push_back_start_number(int number){
    start_numbers.push_back(number);
    fibonacci_numbers.push_back(0); 
    /* 
    0 needs because we need to keep both vectors the same size
    Maybe we should count Fibonacci number instantly to save our invariant a[i] = F(b[i])? 
    Probably not because it'll hit perfomance
    */
  }

  void Tibonacci::calculate_fibonacci_numbers_without_threads(){
    for(int i = 0; i < start_numbers.size(); ++i){
      fibonacci_numbers[i] = calculate_fib(start_numbers[i]);
    }
  }
}
// std
#include <iostream>
#include <string>

#include "tests/benchmark.hpp"
#include "tests/test_calculating.hpp"

void print_help_message() {
  std::cout << "--help - displays all parameters" << std::endl;
  std::cout << "--benchmark [size of Fibonacci numbers array] [how many tests "
               "will run] [number of using threads] - runs simple benchmark "
               "calculating speed"
            << std::endl;
  std::cout << "--tests [number of tests(each inlcudes 5k size of Fibonacci "
               "array)] [number of using threads] - runs simple tests"
            << std::endl;
  std::cout << "You can pass 0 for every parameter to set it by default"
            << std::endl;
}

int main(int argc, char **argv) {
  for (int i = 1; i < argc; ++i) {
    std::string msg = argv[i];
    if (msg == "--help" || msg == "-h")
      print_help_message();
    if (msg == "--benchmark") {
      if (argc - i >= 3)
        Tests::benchmark(std::stoi(argv[i + 1]), std::stoi(argv[i + 2]),
                         std::stoi(argv[i + 3]));
      else
        Tests::benchmark();
    }
    if (msg == "--tests") {
      if (argc - i >= 2)
        Tests::test_calculating(std::stoi(argv[i + 1]), std::stoi(argv[i + 2]));
      else
        Tests::test_calculating();
    }
  }
}
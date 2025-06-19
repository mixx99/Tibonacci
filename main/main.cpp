#include <iostream>
#include <fstream>
#include <thread>

unsigned long long fib(int n){
  unsigned long long a = 1, b = 1;
  if(n <= 2) return 1;
  for(int i = 2; i < n; ++i)
  {
    b += a;
    a = b - a;
  }
  return b;
}

int main(){
  
}
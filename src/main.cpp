/*
 * main.cpp
 *
 */

#include <iostream>
#include <limits>

int count_factors(auto n)
{
  auto total=1;
  for(auto i=2; i<=n; ++i){
    if(n % i == 0)
      ++total;
  }
  return total;
}

int main()
{
  return 0;
}
/*
 * euler12_trial_div.cpp
 * 4 iteratively improved solutions to Project Euler #12, using trial division
 *
 */

#include <iostream>
#include <list>
#include <math.h>
#include <ctime>
#include <ratio>
#include <chrono>
#include <limits>

int count_divisors(long n)
{
  auto total=1;
  for(auto i=2; i<=n; ++i){
    if(n % i == 0)
      ++total;
  }
  return total;
}

int quick_count_divisors(long n)
{
  // from code.jasonbhill.com/sage/project-euler-problem-12
  auto div = 1;
  auto count = 0;
  while(n % 2 == 0){
    ++count;
    n /= 2;
  }
  div = div * (count+1);
  auto p=3;
  while(n != 1){
    count=0;
    while(n % p ==0){
      ++count;
      n = n/p;
    }
    div = div * (count+1);
    p += 2;
  }
  return div;
}

int count_prime_factors(long n)
{
  auto total=1;
  auto i=2;
  auto lim=sqrt(n);
  while(i < lim){
    if(n % i == 0){
      total += 1;
      n = n / i;
    }
    else
      ++i;
  }
  return total;
}

/*
  int naive_euler12(int);
  naive solution, using trial division
*/
int naive_euler12(int limit)
{
  auto i {2};
  long tri {1};
  auto count {0};
  while(count <= limit){
    tri += i;
    ++i;
    count = quick_count_divisors(tri);
  }
  return tri;
}

/*
  int mostly_divisible_euler12(int);
  this version only checks to see if the candidate has the required number
  of factors if it is already a factor of 2, 3 and 5 before testing further
  (unproven heuristic!)
*/
int mostly_divisible_euler12(int limit)
{

  long i {2};
  long tri {1};
  auto count {0};
  while(count <= limit){
    tri += i;
    ++i;
    if((tri % 2 == 0) && (tri % 3 == 0) && (tri % 5 == 0))
        count = quick_count_divisors(tri);
  }
  return tri;
}

/*
  int min_prime_factors_needed(int);
  This function works out the minimum number of prime factors required
  for it to be possible to have the desired number of factors.
  e.g. with 4 prime factors you can have a max of 4 + 6 + 4 + 1 factors,
  which equals 2^4-1 for any number of prime factors(from 4C1+4C2+4C3+4C4).
*/
int min_prime_factors_needed(auto divisors)
{
  auto p {0}; // number of prime factors
  auto d {0}; // max number of factors
  while(d < divisors){
    ++p;
    d = pow(2,p) - 1;
  }
  return p;
}

int main()
{
  using std::cout;
  using std::endl;
  using namespace std::chrono;
  high_resolution_clock::time_point t1,t2,t3;
  auto n {400};
  int answer1, answer2;
  t1 = high_resolution_clock::now();
  answer1 = naive_euler12(n);
  t2 = high_resolution_clock::now();
  answer2 = mostly_divisible_euler12(n);
  t3 = high_resolution_clock::now();
  duration<double, std::milli> naive = t2-t1;
  duration<double, std::milli> mostly = t3-t2;
  cout << "naive took: " << naive.count() << endl;
  cout << "improved (1) took: " << mostly.count() << endl;
  cout << "answers = " << answer1 << ", " << answer2 << endl;
  return 0;
}

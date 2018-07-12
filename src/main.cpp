#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

extern void euler12();
extern int euler14(unsigned int);
extern int euler14_map(unsigned int);

void euler14_test_script()
{
  using std::cout;
  using std::endl;
  using namespace std::chrono;

  std::vector<int> tests {13, 1000, 100000, 200000, 1000000, 6000000};
  for(auto n : tests){
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    int r1 = euler14(n);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    int r2 = euler14_map(n);
    high_resolution_clock::time_point t3 = high_resolution_clock::now();
    duration<double, std::milli> test1 = t2-t1;
    duration<double, std::milli> test2 = t3-t2;
    cout << "euler14(" << n << ")=" << r1 << " took " << test1.count() << endl;
    cout << "euler14_map(" << n << ")=" << r2 << " took " << test2.count() << endl;
    cout << "ratio t2/t1 = " << test2.count()/ test1.count() << endl;
  }
  /* RESULT: euler_map() is at least 2.5x slower until N > 5,000,000*/
  return;
}

int main()
{
  euler14_test_script();
  return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>

int euler14(unsigned int N)
{
  auto max=0;
  for(auto i=1; i<=N; ++i){
    unsigned long c=i;
    auto counter=1;
    while(c != 1){
      if(c < 0){
        std::cout << "Integer wrap around!" << std::endl;
        return -1;
      }
      if(c % 2 == 0)
        c = c / 2;
      else
        c= 3*c + 1;
      ++counter;
    }
    if(counter > max)
      max = counter;
  }
  return max;
}

int euler14_map(unsigned int N)
{
  using std::unordered_map;
  unordered_map<int, int> collatz {{0, 0}, {1, 1}}; //{n->collatz chain length}
  auto max=0;
  for(auto i=2; i<=N; ++i){
    auto counter=0;
    auto found_chain=0;
    unsigned long c=i;
    /* generate a new iterative sequence, starting at i */
    while(c != 1){
      if(collatz.find(c) != collatz.end()){
        //already seen this number in another chain
        found_chain = collatz[c];
        break;
      }
      ++counter;
      if(c % 2 == 0)
        c /= 2;
      else
        c = 3*c+1;
    }
    /* count the length of the sequence */
    if(found_chain != 0)
      collatz[i] = found_chain + counter;
    else
      collatz[i] = counter + 1;
    /* compare with the current largest chain */
    if(collatz[i] > max)
      max = collatz[i];
  }
  return max;
}

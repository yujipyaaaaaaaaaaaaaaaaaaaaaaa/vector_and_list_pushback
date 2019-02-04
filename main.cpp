#include <iostream>
#include <vector>
#include <list>

#include "WallTimer/src/walltimer.hpp"

template<typename T>
void push(T stl, int size){
  for(int i = 0; i < size; ++i){
    stl.push_back(i);
  }

  // for(auto &s : stl){
  //   std::cout << reinterpret_cast<long>(&s) << ",";
  // }
  // std::cout << std::endl;
}

int main(){
  for(int size = 1; size <= 100000; size += 1000){
  
    BLOCK_TIMER;

    BLOCK_START;

    for(int i = 0; i < 1000; ++i){
      std::vector<int> vec;
      push(vec, size);
    }

    BLOCK_CHECK;

    for(int i = 0; i < 1000; ++i){
      std::list<int> list;
      push(list, size);
    }

    BLOCK_CHECK;
  }

  return 0;
}


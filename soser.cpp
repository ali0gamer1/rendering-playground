// main.cpp
#include <iostream>
#include <chrono>
#include <thread>



int main(){
  using namespace std::chrono;

  time_point StartTime{
    system_clock::now()
  };

  std::this_thread::sleep_for(seconds(2));

  time_point EndTime{
    system_clock::now()
  };

  duration RunningTime{
    EndTime - StartTime
  };


}
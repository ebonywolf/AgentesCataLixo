#include "TimedThread.h"
#include <iostream>
using namespace std;

namespace pg{
TimedThread::TimedThread( void(*t)() ,int mili){

    auto    startCounter= [this](int c){ this->counter(c); };


    auto    startWatched=
        [this,&t]{
            t();
            signal.lock();
            done=true;
            signal.unlock();
        };
   // void (*boo)(int);

    counterThread = new thread(startCounter,mili);
     watched= new std::thread(startWatched);
    watched->detach();



}
 TimedThread::~TimedThread(){
     delete(counterThread);
 }
void TimedThread::join(){
    // std::cout<< "joining" <<endl;

    signal.lock();
    bool cond=done;
    signal.unlock();
    while (!cond){
        if(signal.try_lock()){
            cond=done;
            signal.unlock();
        }else{
            this_thread::sleep_for(std::chrono::milliseconds(1));
        }


    }


         counterThread->join();

}

void TimedThread::counter(int n){

 std::this_thread::sleep_for(std::chrono::milliseconds(n));


 signal.lock();
 done=true;
 signal.unlock();




}
}

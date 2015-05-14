#ifndef TIMEDTHREAD_H
#define TIMEDTHREAD_H
#include <thread>
#include <chrono>
#include <mutex>
//TODO :get it Working

namespace pg{
class TimedThread
{
    public:
        /** Default constructor */
        TimedThread(void(*)(),int mili);
        /** Default destructor */
        virtual ~TimedThread();
        void join();

    protected:

        void counter(int n);
        std::thread* counterThread;
        std::thread* watched;

        bool done=false;
        std::mutex signal;//semaphore for the variable done
    private:
};
}


#endif // TIMEDTHREAD_H

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex mtx;
std::condition_variable condition_;
bool ready = false;

void waiting_thread() {
    std::unique_lock<std::mutex> lock(mtx);  // 1. 获取锁

    // condition_.wait() 的内部操作：
    condition_.wait(lock, [] { return ready; });
    std::cout << "waiting_thread! Thread ID: "
        << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void trigger_thread() {
    std::unique_lock<std::mutex> lock(mtx);  // 1. 获取锁
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    ready = true;
    condition_.notify_all();
    std::cout << "trigger_thread! Thread ID: "
        << std::this_thread::get_id() << std::endl;
}

int main()
{
    std::thread waitingthread(waiting_thread);
    std::thread triggerthread(trigger_thread);

    waitingthread.join();
    triggerthread.join();
    std::cout << "Hello World!\n";
}
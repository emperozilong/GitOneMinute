#include <iostream>
#include <thread>

// 简单的线程函数
void hello_thread() {
    std::cout << "Hello from thread! Thread ID: "
        << std::this_thread::get_id() << std::endl;
}

// 带循环的线程函数
void worker_thread(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        std::cout << "Worker iteration: " << i
            << " Thread ID: " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}


class ThreadManager {
public:
    // 1. 使用普通函数
    static void static_function(int id) {
        std::cout << "Static function, thread " << id << std::endl;
    }

    // 2. 使用成员函数
    void member_function(int id) {
        std::cout << "Member function, thread " << id
            << " this: " << this << std::endl;
    }
};

// 3. 使用函数对象
struct Functor {
    void operator()(int id) const {
        std::cout << "Functor, thread " << id << std::endl;
    }
};

int main()
{   
    ThreadManager manager;
    // 方式1: 静态函数
    std::thread t1(ThreadManager::static_function, 1);

    // 方式2: 成员函数
    std::thread t2(&ThreadManager::member_function, &manager, 2);

    t1.join();
    t2.join();

    std::cout << "Hello World!\n";

}

#include <chrono>
#include <iostream>
#include <thread>
#include <utility>

class scoped_thread
{
private:
    std::thread m_t;

public:
    explicit scoped_thread(std::thread t):m_t(std::move(t)) 
    {
        if (!m_t.joinable())
        {
            throw std::logic_error("No thread");
        }
    }

    ~scoped_thread() 
    { 
        m_t.join(); 
    }

    scoped_thread(scoped_thread const&) = delete;
    scoped_thread& operator=(scoped_thread const&) = delete;
};


void hello()
{
    std::cout << "Hello, concurrent world" << std::endl;
    std::cout << "There are " << std::thread::hardware_concurrency() << " concurrent paths";
}


struct func
{
    func() {}

    void operator()()
    {
        hello();
    }
};


int main()
{
    scoped_thread t_scoped{ std::thread(func()) };

    std::cout << "The main thread" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(20000));

    return 0;
} 
#include <iostream>
#include <thread>


void hello()
{
    std::cout << "Hello, concurrent world" << std::endl;
    std::cout << "There are " << std::thread::hardware_concurrency() << " concurrent paths";
}

int main()
{
    std::thread t_hello(hello);
    t_hello.join();

    return 0;
}
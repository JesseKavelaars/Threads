#include <iostream>
#include <thread>


void hello()
{
    std::cout << "Hello, concurrent world" << std::endl;
}

int main()
{
    std::thread t_hello(hello);
    t_hello.join();

    return 0;
}
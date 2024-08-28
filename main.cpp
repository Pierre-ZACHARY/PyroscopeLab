#include <iostream>
#include <random>
#include <thread>
#include <fcntl.h>
#include <unistd.h>

int __attribute__((noinline)) fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int __attribute__((noinline)) top() {
    for (int i = 0; i < 100000; i++) {
        int fd = open("/", O_DIRECTORY);
        close(fd);
    }

    return 0;
}

// ones
int __attribute__((noinline)) c1() { return top(); }

int __attribute__((noinline)) b1() { return c1(); }

int __attribute__((noinline)) a1() { return b1(); }

// twos
int __attribute__((noinline)) c2() { return top(); }

int __attribute__((noinline)) b2() { return c2(); }

int __attribute__((noinline)) a2() { return b2(); }

int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(10.0, 40.0);
    while (true) {
        int n = (int) dist(mt);
        std::cout << "fibonacci ("<<n<<") = " << fibonacci((int) dist(mt)) << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        std::cout << "Calling a1" << std::endl;
        a1();
        std::cout << "Calling a2" << std::endl;
        a2();
    }
}

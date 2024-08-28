#include <iostream>
#include <random>
#include <thread>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(10.0, 40.0);


    while (true) {
        int n = (int) dist(mt);
        std::cout << "fibonacci ("<<n<<") = " << fibonacci((int) dist(mt)) << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

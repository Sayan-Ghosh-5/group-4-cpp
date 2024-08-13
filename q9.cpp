#include <iostream>

template <typename T>
T findMax(T a, T b, T c) {
    
    T max = a;  

    if (b > max) {
        max = b;  
    }

    if (c > max) {
        max = c;  
    }

    return max;  
}

int main() {
    
    int x = 10, y = 20, z = 15;
    std::cout << "The largest integer is: " << findMax(x, y, z) << std::endl;

    double a = 5.7, b = 8.9, c = 7.6;
    std::cout << "The largest double is: " << findMax(a, b, c) << std::endl;

    char p = 'a', q = 'z', r = 'm';
    std::cout << "The largest character is: " << findMax(p, q, r) << std::endl;

    return 0;
}

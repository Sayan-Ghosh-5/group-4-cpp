#include <iostream>
#include <vector>
#include <stdexcept>
#include <numeric>

template <typename T>
class Vector {
private:
    std::vector<T> elements;

public:
   
    Vector(std::initializer_list<T> list) : elements(list) {}

    T findMin() const {
        if (elements.empty()) {
            throw std::runtime_error("Vector is empty.");
        }
        T min = elements[0];
        for (const auto& elem : elements) {
            if (elem < min) {
                min = elem;
            }
        }
        return min;
    }

    bool search(const T& value) const {
        for (const auto& elem : elements) {
            if (elem == value) {
                return true;
            }
        }
        return false;
    }
    double findAverage() const {
        if (elements.empty()) {
            throw std::runtime_error("Vector is empty.");
        }
        T sum = std::accumulate(elements.begin(), elements.end(), T(0));
        return static_cast<double>(sum) / elements.size();
    }

    void print() const {
        for (const auto& elem : elements) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

int main() {

    Vector<int> intVec = {10, 20, 5, 8, 15};

    std::cout << "The smallest element in intVec is: " << intVec.findMin() << std::endl;

    std::cout << "Search for 20 in intVec: " << (intVec.search(20) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 100 in intVec: " << (intVec.search(100) ? "Found" : "Not Found") << std::endl;

    std::cout << "The average of intVec is: " << intVec.findAverage() << std::endl;
    Vector<double> doubleVec = {1.5, 2.5, 3.5, 4.5};

    std::cout << "The smallest element in doubleVec is: " << doubleVec.findMin() << std::endl;

    std::cout << "Search for 3.5 in doubleVec: " << (doubleVec.search(3.5) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 5.5 in doubleVec: " << (doubleVec.search(5.5) ? "Found" : "Not Found") << std::endl;

    std::cout << "The average of doubleVec is: " << doubleVec.findAverage() << std::endl;

    return 0;
}

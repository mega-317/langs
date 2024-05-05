#include <iostream>

int main() {
    int n;
    std::cin >> n;

    for (int j = 0; j < n; j++) {
        for(int i = j+1; i < n; i++) {
            std::cout << " ";
        }
        for(int i = n-j-1; i < n; i++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}
#include <iostream>

int main() {
    int arr[9];

    for (int i=0; i<9; i++) {
        std::cin >> arr[i];
    }

    int max = arr[0];
    int idx = 0;
    for (int i=0; i<9; i++) {
        if (arr[i] > max) {
            max = arr[i];
            idx = i;
        }
    }
    std::cout << max << std::endl;
    std::cout << idx+1 << std::endl;

    return 0;
}
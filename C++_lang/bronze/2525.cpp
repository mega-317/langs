#include <iostream>

int main() {
    int hour, min, time;
    std::cin >> hour >> min;
    std::cin >> time;
    
    int sum = min + time;

    if ((sum) >= 60) {
        hour += int((sum) / 60);
        sum = sum % 60;
        if (hour >= 24) {
            hour -= 24;
        }
    }

    std::cout << hour << ' ' << sum << std::endl;

    return 0;
}
#include <iostream>

int main() {
    int score;
    std::cin >> score;
    
    if (score >= 90) {
        std::cout << "A";
    }
    else if (score >= 80) {
        std::cout << "B";
    }
    else if (score >= 70) {
        std::cout << "C";
    }
    else if (score >= 60) {
        std::cout << "D";
    }
    else {
        std::cout << "F";
    }
    // TODO: score 값에 따라 A, B, C, D, F 중 하나를 출력하세요.
    // 90 이상은 A, 80 이상은 B, 70 이상은 C, 60 이상은 D, 그보다 작으면 F 입니다.

    return 0;
}

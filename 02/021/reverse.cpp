#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int* original_arr = new int[n];
    int i = 0;
    for (; i < n; i++) {
        int num;
        std::cin >> num;
        original_arr[i] = num;
    } //i = n-1?
    i--;
    for (; i >-1; i--) {
        std::cout << original_arr[i] << " ";
    }
    delete[] original_arr;
    // TODO: 길이 n의 정수 배열을 준비하세요.
    // TODO: n개의 정수를 입력받아 배열에 저장하세요.
    // TODO: 배열의 마지막 원소부터 첫 원소까지 역순으로 출력하세요.

    return 0;
}

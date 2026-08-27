#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int* arr = new int[n];
    
    // TODO: new[]로 길이 n의 정수 배열을 동적 할당하세요.
    // TODO: 배열 원소 n개를 입력받아 arr에 저장하세요.

    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        arr[i] = num;
    }
    

    int index;
    std::cin >> index;
    std::cout << arr[arr[index]] << std::endl;

    delete[] arr;


    // TODO: arr[arr[index]] 값을 출력하세요.
    // TODO: 사용이 끝난 배열은 delete[]로 해제하세요.
    
    return 0;
}

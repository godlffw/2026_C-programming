#include <array>
#include <iostream>
#include <algorithm>

int main() {
    std::array<int, 10> values{};
    for (int i = 0; i < 10; i++) {
        std::cin >> values[i];
    }

    int *min = std::min_element(values.begin(), values.end());
    int *max = std::max_element(values.begin(), values.end());
    std::cout << *max << " " << *min;
    
    // TODO: values에 정수 10개를 입력받으세요.
    // TODO: 가장 큰 값과 가장 작은 값을 찾아 공백 하나로 출력하세요.
    // TODO: 필요하면 <algorithm> 헤더를 추가해 std::minmax_element를 사용할 수 있습니다.

    return 0;
}

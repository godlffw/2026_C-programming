#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> values(n);

    // TODO: n개의 정수를 입력받아 values에 저장하세요.
    for (int i = 0; i < n; i++) {
        std::cin >> values[i];
    }

    int remove_index;
    int remove_value;
    std::cin >> remove_index >> remove_value;
    values.erase(values.begin()+remove_index);
    values.erase(remove(values.begin(), values.end(), remove_value), values.end());
    std::cout << values.size() << std::endl;
    for (int i = 0; i < values.size(); i++ ){
        std::cout << values[i] << " ";
    }
    // TODO: 먼저 remove_index 위치의 원소를 삭제하세요.
    // TODO: 그다음 remove_value와 같은 값을 가지는 모든 원소를 삭제하세요.
    // TODO: 남은 원소의 개수와 원소들을 형식에 맞게 출력하세요.

    return 0;
}

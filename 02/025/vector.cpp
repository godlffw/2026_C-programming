#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    int *answer = new int[m];
    std::vector<std::vector<int>> data;
    
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        std::vector<int> arr(num);
        for (int j = 0; j < num; j++) {
            std::cin >> arr[j];
        }
        data.push_back(arr);
    }

    for(int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >>b;
        answer[i] = data[a][b];
    }
    for (int i = 0; i < m; i++) {
        std::cout << answer[i] << " ";
    }
    delete[] answer;


    // TODO: n개의 가변 길이 정수 배열을 입력받아 data에 저장하세요.

    // TODO: m개의 질문 (i, j)을 입력받아 data[i][j]를 한 줄에 하나씩 출력하세요.

    return 0;
}

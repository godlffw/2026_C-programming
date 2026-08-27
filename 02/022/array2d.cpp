#include <iostream>

int main() {
    int rows;
    int cols;
    std::cin >> rows >> cols;
    int **arr = new int*[rows];
    for (int i =0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j =0; j < cols; j++) {
            std::cin >> arr[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
       int sum_row = 0;
       for (int j =0; j < cols; j++) {
        sum_row += arr[i][j];
       } 
       std::cout << sum_row << " ";
    }
    std::cout << std::endl;

    for (int i =0; i < cols; i++) {
        int sum_col = 0;
        for (int j = 0; j < rows; j++) {
            sum_col += arr[j][i];
        }
        std::cout << sum_col << " ";
    }
    
    //1 2 3 4 
    //5 6 7 8
    //9 10 11 12
    // TODO: rows x cols 크기의 2차원 정수 배열을 준비하세요.
    // TODO: 행렬을 입력받으면서 각 행의 합과 각 열의 합을 계산하세요.
    // TODO: 첫째 줄에 행의 합, 둘째 줄에 열의 합을 출력하세요.

    return 0;
}

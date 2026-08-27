#include <algorithm>
#include <iostream>
#include <string>
#include <vector>



struct Student {
    std::string name;
    int score;
};

int comp_name (Student a, Student b) {
    return a.name < b.name;
}

int comp_score (Student a, Student b) {
    return a.score > b.score;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> students[i].name >> students[i].score;
    }

    std::vector<Student> qualified;
    bool exist = false;
    int index = 0;
    while(index < students.size()) {
        if (students[index].score >= 90) {
            qualified.push_back(students[index]);
            exist = true;
        }
        index++;
    }
    if (exist) {
        std::sort(qualified.begin(), qualified.end(), comp_name);
        std::sort(qualified.begin(), qualified.end(), comp_score);
        for (int i = 0; i <3; i++) {
            std::cout << qualified[i].name << "\n";
        }
    }
    else {
        std::cout << "None";
    }

    

    // TODO: while 문으로 students를 검사하며 90점 이상인 학생만 qualified에 넣으세요.
    // TODO: qualified를 점수 내림차순, 이름 오름차순으로 정렬하세요.
    
    // TODO: qualified가 비어 있으면 None을 출력하고, 아니면 앞에서부터 최대 3명의 이름을 출력하세요.
    // TODO: 필요하면 std::sort 또는 std::ranges::sort를 사용할 수 있습니다.

    return 0;
}

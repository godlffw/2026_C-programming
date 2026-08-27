#include "student.h"

std::array<Student, STUDENT_COUNT> init_students() {
    return {{
        {1, "Choi", 9.9},
        {2, "Park", 0.1},
        {3, "Kim", 5.0},
        {4, "Lee", 3.0},
        {5, "Moon", 9.5},
        {6, "Kang", 7.0},
        {7, "Jeon", 0.9}
    }};
}

const Student& get_last(const std::array<Student, STUDENT_COUNT>& students) {
    // TODO: 마지막 학생을 반환하세요.
    
    return students[STUDENT_COUNT-1];
}

std::string compare_points(const Student& s1, const Student& s2) {
    // TODO: 점수를 비교해 의미 있는 문장을 반환하세요.
    int score1, score2;
    score1 = s1.points;
    score2 = s2.points;
    std::string more_higher;
    std::string more_lower;
    if (score1 > score2) {
        more_higher = s1.name;
        more_lower = s2.name;
    }
    else {
        more_higher = s2.name;
        more_lower = s2.name;
    }
    return more_higher + " has more points than " + more_lower +"." ;
    
}

const Student& get_lowest_points(const std::array<Student, STUDENT_COUNT>& students) {
    // TODO: 가장 낮은 점수의 학생을 찾아 반환하세요.
    float min = 101;
    int idx;
    for (int i = 0; i < STUDENT_COUNT; i++) {
        if (min > students[i].points ) {
            min = students[i].points;
            idx = i;
        }
    }
    return students[idx];
}

const Student& get_highest_points(const std::array<Student, STUDENT_COUNT>& students) {
    float max = -1;
    int idx;
    for (int i = 0; i < STUDENT_COUNT; i++) {
        if (max < students[i].points) {
            max = students[i].points;
            idx = i;
        }
    }
    return students[idx];
}

void my_sort(std::array<Student, STUDENT_COUNT>& students) {
    for (int i = 0; i < STUDENT_COUNT-1; i++) {
        for (int j = 0; j < STUDENT_COUNT-1; j++) {
            if (students[j].points > students[j+1].points) {
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;


            } 
        }
    }
}

void print(const Student& s) {
    std::cout << "ID: " << s.id
              << ", Name: " << s.name
              << ", Points: " << s.points << '\n';
}

#include <iostream>
#include <string>

int main() {
    int studentCount = 0;
    std::cin >> studentCount;
    std::string *name = new std::string[studentCount];
    int *grade = new int[studentCount];

    for (int i = 0; i < studentCount; i++) {
        std::cin >> name[i] >> grade[i];
    }
    int avg = 0;
    for (int j = 0; j < studentCount; j++) {
        avg += grade[j];
    }
    avg /= studentCount;
    
    int max = -1;
    int whoismax;
    for (int i = studentCount -1; i > -1; i--) {
        if (grade[i] > max) {
            max = grade[i];
            whoismax = i;
        }
    }
    std::cout << "Average: " << avg << std::endl;
    std::cout << "Highest: " << name[whoismax] << " " << max << std::endl;
    // TODO: read each student's name and score, then print the average and top student.
    return 0;
}

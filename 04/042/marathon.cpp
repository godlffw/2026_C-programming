#include "marathon.h"
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

// TODO: 아래 여덟 함수를 구현하세요.
// 참가자 목록은 아래 static 변수로 관리합니다. 함수 파라미터로 전달하지 않습니다.
static std::vector<Runner> runners;

void add_runner(const Runner& r) {
    runners.push_back(r);
    // 참가자를 목록에 추가합니다.
}

void remove_runner(const std::string& name) {
    auto it = std::find_if(runners.begin(), runners.end(), [&name](const Runner &r) {return r.name == name; });

    if (it != runners.end()) {
        runners.erase(it);
    }

    // 이름이 name인 첫 번째 참가자를 목록에서 제거합니다. 없으면 아무것도 하지 않습니다.
    // 힌트: std::find_if 로 반복자를 얻고, end()가 아닐 때만 erase 합니다.
}

void update_time(const std::string& name, int new_time) {
    auto it = std::find_if(runners.begin(), runners.end(), [&name](const Runner &r) {return r.name == name; });

    if (it != runners.end()) {
        it->time = new_time;
    }
    // 이름이 name인 첫 번째 참가자의 기록을 new_time으로 수정합니다. 없으면 무시합니다.
    // 힌트: std::find_if 로 반복자를 얻고, it->time = new_time; 으로 수정합니다.
}

void print_runner(const std::string& name) {
    bool exist = false;
    for (auto kv : runners) {
        if (kv.name == name) {
            std::cout << kv.name << " " << kv.time << " " << kv.age <<"\n";
            exist = true;
        }
    }
    if (!exist) {
        std::cout << "NOT FOUND" << "\n";
    }

    // 이름이 name인 참가자를 모두 출력합니다. 형식: "name time age"
    // 한 명도 없으면 "NOT FOUND" 를 출력합니다.
}

int total_time() {
    int total = std::accumulate(runners.begin(), runners.end(), 0, [](int acc, const Runner &r) {return acc + r.time;});
    // 모든 완주 기록의 합계를 반환합니다.
    return total;
}

double avg_time() {
    double sum = std::accumulate(runners.begin(), runners.end(), 0, [](double acc, const Runner &r) {return acc + r.time;});
    double avg = sum / (double)runners.size();
    // 완주 기록의 평균을 반환합니다. (정수 나눗셈 주의)
    return avg;
}

int best_time() {
    auto cmp = [](const Runner& a, const Runner& b) {return a.time < b.time;};
    int best = std::min_element(runners.begin(), runners.end(), cmp) ->time;
    // 가장 빠른 기록(최솟값)을 반환합니다.
    return best;
}

int worst_time() {
    auto cmp = [](const Runner& a, const Runner& b) {return a.time < b.time;};
    int worst = std::max_element(runners.begin(), runners.end(), cmp) ->time;
    // 가장 느린 기록(최댓값)을 반환합니다.
    return worst;
}

#include <iostream>
#include <map>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::map<std::string, int> counts;

    for (int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str;
        if (counts.count(str) > 0) {
            ++counts[str];
        }
        else {
            counts.insert(std::pair<std::string, int>(str, 1));
        }
    }

    for (const auto& kv : counts) {
        std::cout << kv.first << " " << kv.second << "\n";
    }

    // TODO: 단어 n개를 입력받아 counts[word] 를 증가시키세요.
    // TODO: for 문으로 map 을 순회하며 "단어 개수" 형식으로 출력하세요.

    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> values(n);

    for (int i = 0; i < n; i++) {
        std::cin >> values[i];
    }
    std::sort(values.begin(), values.end());
    for (int i = 0; i < values.size(); i++) {
        std::cout << values[i] << " ";
    }

    return 0;
}

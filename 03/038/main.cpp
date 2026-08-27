#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>



int main() {
    int n;
    std::cin >> n;

    std::vector<int> values;
    values.reserve(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n,std::back_inserter(values));


    std::sort(values.begin(), values.end());


    std::ostream_iterator<int> ans(std::cout, "\n");
    
    std::copy(values.begin(), values.end(), ans);

    // TODO: std::copy_n 과 std::istream_iterator<int> 로 n개의 정수를 읽으세요.
    // TODO: 정렬한 뒤 std::copy 와 std::ostream_iterator<int> 로 한 줄에 하나씩 출력하세요.

    return 0;
}

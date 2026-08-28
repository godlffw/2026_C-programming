#pragma once

#include <concepts>
#include <iterator>
#include <ranges>
#include <utility>

// =========================================================================
// [최신 방식 / C++20 · C++23] modern::my_accumulate
//
//   현재 방식과 동일한 동작을 하되, 아래 두 가지 형태를 모두 구현하세요.
//
//   (1) 반복자 + 센티넬 버전
//       - template <std::input_iterator Iterator,
//                   std::sentinel_for<Iterator> Sentinel,
//                   typename T>
//         constexpr T my_accumulate(Iterator begin, Sentinel end, T init);
//
//       Concepts 로 "입력 반복자(input_iterator)" 와 그 끝점(sentinel_for)
//       만 받도록 제한합니다. constexpr 이라 컴파일 타임에도 호출 가능.
//
//   (2) Range(컨테이너) 버전 — (1) 을 호출하는 얇은 래퍼
//       - template <std::ranges::input_range Range, typename T>
//         constexpr T my_accumulate(Range&& r, T init);
//
//       std::ranges::begin(r) / std::ranges::end(r) 로 두 반복자를 얻은 뒤
//       (1) 의 my_accumulate 를 호출하면 됩니다.
//
//   - 누적값을 더할 때 std::move(init) + *it 처럼 옮겨 쓰면 복사를 줄일 수 있습니다.
//   - 두 함수 모두 modern 네임스페이스 안에 둡니다.
//   - std::accumulate 같은 표준 알고리즘을 호출하지 않습니다.
// =========================================================================
namespace modern {

// TODO: (1) 반복자 + 센티넬 버전 my_accumulate 를 작성하세요.
    template <std::input_iterator Iterator, std::sentinel_for<Iterator> Sentinel, typename T> constexpr T my_accumulate(Iterator begin, Sentinel end, T init) {
        for (auto i = begin; i != end; i++) {
            init = std::move(init) + *i;
        }
        return init;
    }
// TODO: (2) Range 버전 my_accumulate 를 작성하세요.
    template <std::ranges::input_range Range, typename T> constexpr T my_accumulate(Range &&r, T init) {
        return my_accumulate(std::ranges::begin(r), std::ranges::end(r), init);
    }

}  // namespace modern

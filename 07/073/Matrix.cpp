#include "Matrix.hpp"
#include <ranges>
#include <algorithm>
#include <numeric>
#include <functional>

// C++23 Range 별칭 — 아래 TODO 힌트에서 활용할 수 있습니다.
namespace rv = std::views;
namespace rg = std::ranges;
constexpr auto sum     = rg::fold_left;      // sum(range, init, op)
constexpr auto zip_mul = rv::zip_transform;  // zip_mul(op, r1, r2)

// ════════════════════════════════════════════════════════════════
//  제공된 Private Helpers
//  as_span() : data 전체를 span<const int> 로 반환 (읽기 전용 뷰)
//  get_row(r): r 번째 행을 Range view 로 반환 (복사 없음)
//  get_col(c): c 번째 열을 Range view 로 반환 (복사 없음)
// ════════════════════════════════════════════════════════════════
std::span<const int> Matrix::as_span() const noexcept { return {data, rows * cols}; }

auto Matrix::get_row(std::size_t r) const {
    return as_span() | rv::drop(r * cols) | rv::take(cols);
}

auto Matrix::get_col(std::size_t c) const {
    return as_span() | rv::drop(c) | rv::stride(cols);
}

// ── 기본 생성자 (제공됨) ─────────────────────────────────────────
Matrix::Matrix() : data(nullptr), rows(0), cols(0) {}

// ── (r, c) 크기 생성자 (제공됨) ─────────────────────────────────
Matrix::Matrix(std::size_t r, std::size_t c) : rows(r), cols(c) {
    data = new int[r * c]();
}

// TODO: initializer_list 생성자
// 힌트: rg::copy(init | rv::join, data) 로 중첩 리스트를 펼쳐 한 번에 복사
Matrix::Matrix(std::initializer_list<std::initializer_list<int>> init) {
    rows = init.size();
    if (rows > 0) {
        cols = init.begin() -> size();
    }
    else {
        cols = 0;
    }
    data = new int[rows * cols]{};
    auto i = 0;
    for (const auto& kv : init) {
        auto j = 0;
        for (int v : kv) {
            data[i * cols + j] = v;
            j++;
        }
        i++;
    }
}

// TODO: 복사 생성자 (deep copy)
// 힌트: rg::copy(other.as_span(), data)
Matrix::Matrix(const Matrix& other)
    : data(nullptr), rows(other.rows), cols(other.cols) {
        data = new int[rows * cols];
        for (size_t k = 0; k < rows*cols; ++k) {
            data[k] = other.data[k];
        }
    }

// TODO: 복사 대입 연산자
// 힌트: 자기 대입 가드 → delete[] data → 크기 복사 → rg::copy
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) {
        return *this;
    }
    delete[] data;
    rows = other.rows;
    cols = other.cols;
    data = new int[rows * cols];
    for (auto i = 0; i < rows * cols; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

// TODO: 소멸자 — delete[] data
Matrix::~Matrix() {
    delete[] data;
}

// ── C++23 다차원 첨자 연산자 (제공됨) ───────────────────────────
int& Matrix::operator[](std::size_t r, std::size_t c) { return data[r * cols + c]; }
const int& Matrix::operator[](std::size_t r, std::size_t c) const { return data[r * cols + c]; }

// ── 산술 연산 ────────────────────────────────────────────────────

// TODO: operator+
// 힌트: rg::transform(as_span(), rhs.as_span(), res.data, std::plus<>{})
Matrix Matrix::operator+(const Matrix& rhs) const {
    Matrix res(rows, cols);
    for (size_t i = 0; i < rows * cols; i++) {
        res.data[i] = data[i] + rhs.data[i];
    }
    return res;
}

// TODO: operator-
// 힌트: rg::transform(... std::minus<>{})
Matrix Matrix::operator-(const Matrix& rhs) const {
    Matrix res(rows, cols);
    for (size_t i = 0; i < rows * cols; i++) {
        res.data[i] = data[i] - rhs.data[i];
    }
    return res;
}

// TODO: operator* (행렬 곱)
// 힌트:
//   auto dot = [](auto row_view, auto col_view) {
//       return sum(zip_mul(std::multiplies<>{}, row_view, col_view), 0, std::plus<>{});
//   };
//   for (auto i : rv::iota(0uz, rows))
//       for (auto j : rv::iota(0uz, rhs.cols))
//           res[i, j] = dot(get_row(i), rhs.get_col(j));
Matrix Matrix::operator*(const Matrix& rhs) const {
    Matrix res(rows, rhs.cols);
    int temp;
    for (auto i = 0; i < rows; i++) {
        for (auto j = 0; j < rhs.cols; j++) {
            temp = 0;
            for (auto k = 0; k < cols; k++) {
                temp += (*this)[i,k] * rhs[k,j];
            } 
            res[i,j] = temp;
        }
    }
    return res;
}

// TODO: operator==
// 힌트: rg::equal(as_span(), rhs.as_span())
bool Matrix::operator==(const Matrix& rhs) const { 
    if ((rows != rhs.rows) || (cols != rhs.cols)) {
        return false;
    }    
    for (auto i = 0; i < rows * cols; i++) {
        if (data[i] != rhs.data[i]) {
            return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& rhs) const { return !(*this == rhs); }

// TODO: operator<<
// 힌트:
//   for (auto i : rv::iota(0uz, m.rows)) {
//       for (auto [j, val] : m.get_row(i) | rv::enumerate) {
//           if (j > 0) os << " ";
//           os << val;
//       }
//       os << "\n";
//   }
std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for (auto i : rv::iota(0uz, m.rows)) {
        for (auto [j, val] : m.get_row(i) | rv::enumerate) {
            if (j>0) {
                os << " ";
            }
            os << val;
        }
        os << "\n";
    }

    return os;

}

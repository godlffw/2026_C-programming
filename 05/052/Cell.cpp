#include "Cell.h"
#include <iomanip>
#include <sstream>

Cell::Cell() : type_{CellType::STRING}, stringVal_{""}, intVal_{0}, doubleVal_{0.0} {}

// TODO: 아래 생성자와 멤버 함수를 구현하세요.

Cell::Cell(const std::string val) {
    type_ = CellType::STRING;
    stringVal_ = val;
    // 문자열 값을 저장하는 생성자
    // type_ 을 STRING 으로 설정하세요.
}

Cell::Cell(int val) {
    type_ = CellType::INT;
    intVal_ = val;
    // 정수 값을 저장하는 생성자
    // type_ 을 INT 로 설정하세요.
}

Cell::Cell(double val) {
    type_ = CellType::DOUBLE;
    doubleVal_ = val;
    // 실수 값을 저장하는 생성자
    // type_ 을 DOUBLE 로 설정하세요.
}

bool Cell::isNumeric() const {
    if (type_ == CellType::STRING) {
        return false;
    }
    // INT 또는 DOUBLE 이면 true 를 반환합니다.
    return true;
}

bool Cell::isString() const {
    if (type_ == CellType::STRING) {
        return true;
    }
    // STRING 이면 true 를 반환합니다.
    return false;
}

double Cell::getNumericValue() const {
    if (type_ == CellType::INT) {
        return (double)intVal_;
    }
    else if (type_ == CellType::DOUBLE) {
        return doubleVal_;
    }

    // INT 이면 intVal_ 을 double 로, DOUBLE 이면 doubleVal_ 을 반환합니다.
    // STRING 이면 0.0 을 반환합니다.
    return 0.0;
}

std::string Cell::toString() const {
    if (type_ == CellType::STRING) {
        return stringVal_;
    }
    else if (type_ == CellType::INT) {
        return std::to_string(intVal_);
    }
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << doubleVal_;
    // STRING 이면 stringVal_ 을 그대로 반환합니다.
    // INT 이면 정수를 문자열로 변환합니다 (예: 87 → "87").
    // DOUBLE 이면 소수점 1자리로 변환합니다 (예: 75.7 → "75.7").
    // 힌트: std::ostringstream + std::fixed + std::setprecision(1)
    return oss.str();
}

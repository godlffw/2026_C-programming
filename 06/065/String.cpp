#include "String.hpp"
#include <iostream>
#include <cstring>

// static 멤버 변수 정의 — 헤더에 선언만, .cpp에 반드시 이 한 줄이 있어야 합니다.
int String::count_ = 0;

// 기본 생성자: 빈 문자열("")을 저장하고 count_를 올린 뒤 메시지를 출력합니다.
// 출력 형식:
//   Default Constructor
//   # of String object: N
// 힌트: data_ = new char[1]{'\0'};  len_ = 0;
String::String() {
    data_ = new char[1]{'\0'};
    len_ = 0;
    count_++;
    std::cout << "Default Constructor\n# of String object: " << count_ << "\n";
    
    // TODO
}

// C-문자열 생성자: s를 깊은 복사로 저장하고 count_를 올린 뒤 메시지를 출력합니다.
// 출력 형식:
//   Constructor
//   # of String object: N
// 힌트: len_ = std::strlen(s);  data_ = new char[len_ + 1];  std::strcpy(data_, s);
String::String(const char* s) {
    // TODO
    len_ = std::strlen(s);
    data_ = new char[len_ + 1];
    std::strcpy(data_, s);
    count_++;
    std::cout << "Constructor\n# of String object: " << count_ << "\n";
}

// 복사 생성자: s를 깊은 복사로 저장하고 count_를 올린 뒤 메시지를 출력합니다.
// 출력 형식:
//   Copy Constructor
//   # of String object: N
// 주의: data_ 포인터만 복사(얕은 복사)하면 두 소멸자가 같은 메모리를 두 번 해제합니다.
//       반드시 new char[]로 새 메모리를 할당한 뒤 내용을 복사하세요.
String::String(const String& s) {
    len_ = s.len_;
    data_ = new char[len_ + 1];
    for (auto i = 0; i <= len_; i++) {
        data_[i] = s.data_[i];
    }
    count_++;
    std::cout << "Copy Constructor\n# of String object: " << count_ << "\n";
    // TODO
}

// 소멸자: delete[]로 메모리를 해제하고 count_를 내린 뒤 메시지를 출력합니다.
// 출력 형식:
//   Destructor
//   # of String object: N    ← count_ 먼저 감소 후 출력
// 힌트: delete[] data_;  --count_;  std::cout << ...
String::~String() noexcept {
    delete[] data_;
    count_--;
    std::cout << "Destructor\n# of String object: " << count_ << "\n";
    // TODO
}

// ── 아래 세 함수는 이미 완성되어 있습니다 — 수정 불필요 ──────────────────────
const char* String::data()  const noexcept { return data_; }
bool        String::empty() const noexcept { return len_ == 0; }
std::size_t String::size()  const noexcept { return len_; }

// append: str의 내용을 현재 문자열 뒤에 이어 붙입니다. (재할당 필요)
// 힌트:
//   1. 새 길이 = len_ + strlen(str)
//   2. new char[새 길이 + 1] 로 새 버퍼 할당
//   3. strcpy(새 버퍼, data_) → strcat(새 버퍼, str)
//   4. delete[] data_  →  data_ = 새 버퍼  →  len_ = 새 길이
//   5. return *this;  (메서드 체인을 위해)
String& String::append(const String& str) {
    int temp_len = len_;
    len_ += str.len_;
    char* temp = new char[len_ + 1];
    for (int i = 0; i < temp_len; i++) {
        temp[i] = data_[i];
    }
    for (int i = 0; i < str.len_; i++) {
        temp[temp_len + i] = str.data_[i];
    }
    temp[len_] = '\0';

    delete[] data_;
    data_ = new char[len_ +1];
    data_ = temp;
    
    // TODO
    return *this;
}

String& String::append(const char* str) {
    int temp_len = len_;
    len_ += std::strlen(str);
    char *temp = new char[len_ + 1];
    for (int i = 0; i < temp_len; i++) {
        temp[i]  = data_[i];
    }
    for (int i = 0; i < std::strlen(str); i++) {
        temp[temp_len + i] = str[i];
    }
    temp[len_] = '\0';
    delete[] data_;
    data_ = new char[len_ +1 ];
    data_ = temp;
    
    // TODO
    return *this;
}

#include "Logger.h"
#include <iostream>

// TODO: static 멤버 변수를 클래스 밖에서 정의하세요.
// 기본 로그 레벨은 INFO(1)입니다.
// int Logger::logLevel = ???;

// TODO: 아래 함수들을 구현하세요.
int Logger::logLevel = 1;

std::string Logger::levelToString(LogLevel level) {
    switch(level) {
        case DEBUG:
            return "DEBUG";
        case INFO:
            return "INFO";
        case WARNING:
            return "WARNING";
        case ERROR:
            return "ERROR";
    }
    // LogLevel 값을 대응하는 문자열로 반환합니다.
    // DEBUG → "DEBUG", INFO → "INFO", WARNING → "WARNING", ERROR → "ERROR"
    // 힌트: switch 문을 사용하세요.
    return "";
}

void Logger::setLogLevel(LogLevel level) {
    logLevel = level;
    // 클래스 전체의 logLevel 을 변경합니다.
}

void Logger::debug(const std::string& message, const std::string& tag) {
    if (logLevel <= DEBUG) {
        std::cout << "[" << levelToString(DEBUG) << "]" << "[" << tag << "]" <<" " << message <<"\n";
    }
    // logLevel 이 DEBUG 이하일 때만 출력합니다.
    // 형식: [DEBUG][tag] message
    // 힌트: if (logLevel <= DEBUG) std::cout << "[" << levelToString(DEBUG) << "]...";
}

void Logger::info(const std::string& message, const std::string& tag) {
    if (logLevel <= INFO) {
        std::cout << "[" << levelToString(INFO) << "]" << "[" << tag << "]" <<" " << message <<"\n";
    }
    // logLevel 이 INFO 이하일 때만 출력합니다.
}

void Logger::warning(const std::string& message, const std::string& tag) {
    if (logLevel <= WARNING) {
        std::cout << "[" << levelToString(WARNING) << "]" << "[" << tag << "]" <<" " << message <<"\n";
    }
    // logLevel 이 WARNING 이하일 때만 출력합니다.
}

void Logger::error(const std::string& message, const std::string& tag) {
    if (logLevel <= ERROR) {
        std::cout << "[" << levelToString(ERROR) << "]" << "[" << tag << "]" <<" " << message <<"\n";
    }
    // logLevel 이 ERROR 이하일 때만 출력합니다.
}

#include "tools.h"

std::string normalize_newlines(std::string_view text) {
    std::string result;

    for (size_t i = 0; i < text.size(); i++) {
        if (text[i] == '\r') {
            if (i+1 < text.size() && text[i+1] == '\n') {
                result += '\n';
                i++;
            }
            else {
                result += '\n';
            }
        }
        else if (text[i] == '\n') {
            result += '\n';
        }
        else {
            result += text[i];
        }
    }
        
    // TODO: "\r\n" 은 "\n" 하나로 바꾸세요.
    // TODO: 단독 '\r' 도 '\n' 으로 바꾸세요.
    // TODO: 그 외 문자는 그대로 유지하세요.

    return result;
}

std::string visualize_invisible(std::string_view text) {
    std::string result;
    for (char c : text) {
        if (c == ' ') {
            result += "[SP]";
        }
        else if (c == '\t') {
            result += "[TAB]";
        }
        else if (c == '\n') {
            result += "[LF]";
        }
        else if (c == '\r') {
            result += "[CR]";
        }
        else {
            result += c;
        }
    }
    // TODO: 공백은 [SP], 탭은 [TAB], 줄바꿈은 [LF], 캐리지리턴은 [CR] 로 바꾸세요.
    // TODO: 그 외 문자는 그대로 result 에 추가하세요.

    return result;
}

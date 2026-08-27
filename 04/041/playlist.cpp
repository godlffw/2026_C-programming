#include "playlist.h"
#include <vector>
#include <algorithm>
#include <iostream>

// TODO: 아래 네 함수를 구현하세요.
// 재생 목록은 아래 static 변수로 관리합니다. 함수 파라미터로 전달하지 않습니다.
static std::vector<int> playlist;

void queue_song(int song_id) {  
    if (song_id < 1 || song_id > 99999) {
        return;
    }
    playlist.push_back(song_id);
    // 재생 목록 끝에 song_id 추가
}

bool is_queued(int song_id) {
    if (std::find(playlist.begin(), playlist.end(),song_id) != playlist.end()) {
        return true;
    } 
    // song_id가 재생 목록에 있으면 true 반환
    return false;
}

void dequeue_song(int song_id) {
    for (int i = 0; i < playlist.size(); i++) {
        if (playlist[i] == song_id) {
            playlist.erase(playlist.begin() + i);
            break;
        }
    }
    // 재생 목록에서 song_id가 처음 등장하는 항목 제거 (없으면 아무 것도 하지 않음)
}

void print_playlist() {
    for (auto kv : playlist) {
        std::cout << kv << "\n";
    }
    // 재생 목록의 곡 ID를 한 줄에 하나씩 출력
}

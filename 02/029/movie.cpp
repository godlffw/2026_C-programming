#include "movie.h"
#include <iostream>
// TODO: genreToString을 구현하세요.
void MovieDatabase::addRating(const std::string& title, std::string_view genre_text, std::string_view stars){
    Genre genre = stringToGenre(genre_text);
    int score = starsToInt(stars);
    auto gresult = genres_.insert({title, genre}); //원소 추가
    int sum = score;
    auto rresult = ratings_.insert(std::make_pair(title, std::vector<int>{1, score, sum})); //ratings 원소 추가 제목 [0] 누적수 [1] 평균 점수 [2] 합 (출력할땐 필요없음)
    if (rresult.second == false) {
        ratings_[title][0]++;
        ratings_[title][2] += score;
        ratings_[title][1] = ratings_[title][2] / ratings_[title][0];
    }


}

void MovieDatabase::printSummary() const{
    std::cout << "Movie Ratings Summary:" <<std::endl;
    for (const auto& kv : genres_) {
        const auto& rating = ratings_.at(kv.first);

        std::cout << kv.first <<": " << ratings_.at(kv.first)[0] <<" ratings, average rating " << ratings_.at(kv.first)[1] << " stars, genre: " << genreToString(kv.second) << std::endl;
        
        


    }
}
// TODO: stringToGenre를 구현하세요.
Genre stringToGenre(std::string_view text) {
    if (text == "Action") {
        return Genre::Action;
    }
    else if (text == "Drama") {
        return Genre::Drama;
    }
    else {
        return Genre::SciFi;
    }
}
std::string genreToString(Genre genre) {
    if (genre == Genre::Action) {
        return "Action";
    }
    else if (genre == Genre::Drama) {
        return "Drama";
    }
    else {
        return "SciFi";
    }
}

int starsToInt(std::string_view stars) {
    int cnt = 0;
    std::string str = "★";
    for (size_t i = 0; i + str.size() <= stars.size();) {
        if (stars.substr(i, str.size()) == str) {
            cnt++;
            i+=str.size();
        }
        else {
            i++;
        }
    }
    
    return cnt;
}


    // TODO: 별점 문자열에서 검은 별(★) 개수를 세어 정수로 반환하세요.

// TODO: addRating에서 제목별 장르와 평점을 저장하세요.

// TODO: printSummary에서 제목 알파벳 순으로
// "제목: N ratings, average rating M stars, genre: 장르"
// 형식의 요약을 출력하세요.

//문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42576
//문제 풀이 : https://shine-xia.tistory.com/77

#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    //해시 맵 생성    #include <unordered_map> 
    unordered_map <string, int> um;
    
    //참가자 명단의 이름의 키인 맵에 1 추가
    for(string a : participant) {
        um[a]++;
    }
    
    //완주자 명단의 이름이 키인 맵에 1 추가
    for(string b : completion) {
        um[b]--;
    }
    
    //맵의 값(.second)을 확인해 0이 아니면 해당 맵의 키(.first) 반환
    for(auto c : um) {
        if(c.second >0){
            answer = c.first;
            break;
        }
    }
    return answer;
}

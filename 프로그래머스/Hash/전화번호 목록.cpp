//문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42577
//풀이 링크 : https://shine-xia.tistory.com/78


#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

bool solution(vector<string> phone_book) {
    
    unordered_map <string, int> m;
    // 먼저 해시맵에 모든 전화번호 삽입
    for(string s : phone_book) m.insert(make_pair(s,1));
    string cmp = "";
    
    //모든 전화번호 탐색
    for(string s : phone_book) {
        cmp = "";
        //해당 전화번호를 한글자씩 더해서 붙여진 번호를 키로 같는 맵이 있는지 확인
        for(char c : s) {
            cmp = cmp + c;
            // s== cmp  과 s.compare(cmp) 은 같음,
            if(s == cmp) break;
            if(m.count(cmp)) return false;
        }
    }
    return true;
}

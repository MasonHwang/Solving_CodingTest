//문제 링크 : https://ongveloper.tistory.com/66
//문제 풀이 : https://shine-xia.tistory.com/79
//참고 블로그 : https://ongveloper.tistory.com/66

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//두 문자열을 인자로 받아 붙일 수 있는 경우를 비교
bool cmp (string a, string b) {
    return a+b> b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    //numbers내의 숫자들을 문자열로 변환해 벡터에 저장
    for(int n : numbers) {
        v.push_back(to_string(n));
    }
    //퀵정렬 (algorithm 헤더)
    sort(v.begin(), v.end(), cmp);
    
    if(v[0].compare("0")==0) return "0";
    // 문자열 이어 붙이기
    for(string s : v) {
        answer += s;
    }
    return answer;
}

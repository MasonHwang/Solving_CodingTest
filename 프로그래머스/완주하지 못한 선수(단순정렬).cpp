
//문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42576
//문제 풀이 : https://shine-xia.tistory.com/74
//참고 블로그 : https://blockdmask.tistory.com/338 (string 클래스 관련 블로그 글)


#include <bits/stdc++.h>

using namespace std;


string getName (vector<string> participant, vector<string> completion) {
    int cnt = completion.size(); 
    string par, com;
    // 정렬된 명단을 처음부터 살피며 같은 이름인지 확인
    for(int i=0; i<cnt;i++) {
        par = participant[i];
        com = completion[i]; 
        // 이름이 다르다면 해당 선수의 이름 출력
        if(par.compare(com)!=0) return par;
    }
    //완주한 선수 명단을 모두 확인했으므로 참가자 명단의 마지막 선수 출력
    return participant[cnt];
}

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    // 참여 명단과 완주 명단을 algorithm 헤더의 sort를 통해 이름 순으로 정렬
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    // 완주하지 못한 선수의 이름을 return 하는 함수 실행
    answer = getName(participant, completion);
    
    return answer;
}

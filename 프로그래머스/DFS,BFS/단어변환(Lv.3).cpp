//문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/43163
//문제 풀이 : https://shine-xia.tistory.com/82

#include <string>
#include <vector>
#include <queue>

using namespace std;
int ch[52];
int bfs(string begin, string target, vector<string> words) {
    //현재 문자열과 과정 횟수를 담는 큐 선언
    queue<pair<string,int>> q;        
    q.push(make_pair(begin,0));
    
    int diff;
    
    while(!q.empty()) {
        pair<string,int> p = q.front();
        //현재 문자열과 타겟이 같다면 횟수 반환
        if(p.first == target) return p.second;
        
        q.pop();
        //words 문자열들과 비교해 한글자만 다르다면 큐에 삽입
        for(int i = 0; i < words.size(); i++) {
            diff = 0;
            for(int k = 0 ; k < target.length(); k++) {
                if(p.first[k] != words[i][k]) diff++;
            }
            if(diff == 1 && ch[i] == 0) {
                ch[i] = 1;
                q.push(make_pair(words[i], p.second+1));   
            }
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    answer = bfs(begin, target, words);
    
    return answer;
}

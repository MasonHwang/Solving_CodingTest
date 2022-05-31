//문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42587?language=cpp
//문제 풀이 : https://shine-xia.tistory.com/84

#include <string>
#include <vector>
#include <queue>
using namespace std;

int prior[10];

int solution(vector<int> priorities, int location) {
    int answer = -1;
    
    //대기 큐(tmp) 과 정렬된 목록 큐(q)
     queue<pair<int, int>> tmp;
    queue<pair<int, int>> q;
    pair<int, int> p;
    
    
    //대기 큐에 모두 저장해두기
    for(int i = 0; i < priorities.size();i++) {
        prior[priorities[i]]++;
        tmp.push(make_pair(priorities[i],i));   
    }      
    //중요도 9부터 1까지 순차 진행
    for(int i = 9 ; i >= 1 ; i--) {
        // 해당하는 중요도의 문서가 남아있다면
        while(prior[i] > 0) {
            p = tmp.front();
            tmp.pop();
            //중요도가 같지 않으면 대기 큐에 넣기
            if(p.first != i) tmp.push(p);
            //중요도가 같으면 목록 큐에 넣기
            else {
                q.push(p);
                prior[i]--;
            }
        }
    }
    
    
    int index = 1;
    
    //목록 큐에서 요청한 문서가 몇 번째에 위치하는지 찾기
    while(!q.empty()) {
        p = q.front();
        if(p.second == location) {
            answer = index;
            break;
        }
        else {
            q.pop();
            index++;
        }
    }
    
    return answer;
}

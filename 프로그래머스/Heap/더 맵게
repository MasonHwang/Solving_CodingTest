//문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42626
//풀이 링크 : https://shine-xia.tistory.com/72

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    
    
    //오름차순 우선순위 큐 생성과 초기화 한 번에
//  priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    //오름차순 우선순위 큐 생성 방법
    priority_queue<int, vector<int>, greater<int>> pq;
    //스코빌 배열의 값을 우선 순위 큐에 전부 삽입
    for(auto v : scoville) {
        pq.push(v);
    }
    
    //큐 사이즈가 1보다 작지 않고 가장 낮은 스코빌이 K보다 작은 동안 횟수 증가
    while(pq.size() > 1 && pq.top() < K) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int c = a + b*2;
        pq.push(c);
        answer++;
    }
    if(pq.top() < K) return -1;
    else return answer;
}

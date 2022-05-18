// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/43162
// 참고 블로그 : https://woojeenow.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EB%84%A4%ED%8A%B8%EC%9B%8C%ED%81%AC-cKotlin#recentComments
// 혼자 못 풀고 풀이보고 이해하며 다시 품
// 문제 풀이 : https://shine-xia.tistory.com/73

#include <string>
#include <vector>

using namespace std;

//해당 행의 방문 여부 체크, 1: 방문 0:미방문
bool visited[200];

//DFS 수행
void dfs(vector<vector<int>> &computers, int j) {
    //해당 행 방문 처리
    visited[j] = true;
    for(int i=0; i<computers.size(); i++) {
        //computer[k][k] 는 무조건 1이므로 넘기기 
        if(i==j) continue;
        
        //아직 방문하지 않았고 해당 행렬값이 1인 경우 dfs 방문
        if(!visited[i] && computers[j][i]) {
            dfs(computers, i);
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    //0~n 탐색해 이미 방문했는지 확인  행렬로 표현해 i는 가로행, j는 세로행으로 생각
    for(int j = 0; j< n; j++) {
        //이미 방문한 노드인 경우
        if(visited[j]) continue;
        
        //방문하지 않은 경우 dfs 수행
        answer++;
        dfs(computers, j);
    }
    return answer;
}

//문제 풀이 : https://programmers.co.kr/learn/courses/30/lessons/43105
//풀이 링크 : https://shine-xia.tistory.com/96

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int height;
vector<vector<int>> vertex;
vector<vector<int>> tri;
void dfs(int depth) {
    //모든 행을 다 담은 경우 return
    if(depth == height) return;
    vector<int> v(depth+1,0);
    
    for(int i = 0; i<depth ; i++) {
        //좌,우 번갈아서 아래행의 최대값 비교해 변경해주기
        if(v[i] < vertex[depth-1][i]+tri[depth][i]) v[i] = vertex[depth-1][i]+tri[depth][i];
        if(v[i+1] < vertex[depth-1][i]+tri[depth][i+1]) v[i+1] = vertex[depth-1][i]+tri[depth][i+1];
    }
    //최댓값을 저장한 배열을 최댓값 이중배열인 vertex에 저장
    vertex.push_back(v);
    //다음 깊이로 dfs 실행
    dfs(depth+1);
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    tri = triangle;
    height = triangle.size();
    
    vertex.push_back(triangle[0]);
    //다음 연산할 행인 1부터 dfs 시작
    dfs(1);
    
    //최댓값 이중 배열의 마지막 행 반환
    vector<int> v_ans = vertex[height-1];
    //sort로 배열 정렬(오름차순) 후 맨 뒤 원소를 answer에 저장
    // 맨 뒤 원소가 가장 큰 값을 가지고 있음.
    sort(v_ans.begin(),v_ans.end());
    answer = v_ans.back();
    return answer;
}

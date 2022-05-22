//문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42862
//문제 풀이 : https://shine-xia.tistory.com/80


#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 체육복 갯수를 저장하는 n크기의 벡터 저장
    vector<int> students(n,1);
    int answer = 0;
    
    //체육복 갯수 맞추기
    for(int i : reserve) students[i-1]++;
    for(int i : lost) students[i-1]--;
    
    //탐욕적으로 왼쪽, 오른쪽을 살펴 체육복 가져오기
    for(int i = 0 ; i < n ; i++) {
        if(students[i] == 0) {
            //왼쪽 친구에게 체육복 얻기
            if(i>0 && students[i-1]==2) {
                students[i-1]--;
                students[i]++;
            }
            //오른쪽 친구에게 체육복 얻기
            else if(i<n-1 && students[i+1] == 2) {
                students[i+1]++;
                students[i]++;
            }
        }
    }

    for(int n : students) if(n>0) answer++;

    return answer;
}

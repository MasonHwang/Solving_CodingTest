//문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/43165
//문제 풀이 : https://shine-xia.tistory.com/54?category=954310

#include <string>
#include <vector>

using namespace std;
int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int cnt) {
    //모든 수를 다 사용한 경우 target과 sum이 같은지 확인
    if(cnt == numbers.size()) {
        if(sum == target) answer++;
        return;
    }
    //재귀를 통한 dfs 시도
    dfs(numbers, target, sum-numbers[cnt], cnt+1);
    dfs(numbers, target, sum+numbers[cnt], cnt+1);
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, target, 0, 0);
    
    return answer;
}

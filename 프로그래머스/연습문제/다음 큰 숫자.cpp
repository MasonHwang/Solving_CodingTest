// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/12911
// 문제 풀이 : https://shine-xia.tistory.com/76


#include <string>
#include <vector>

using namespace std;

// 해당 수를 2진수로 바꿀 때 1의 갯수
int get1(int n) {
    int count = 0;
    while(n) {
        if(n%2 == 1) count++;
        n= n/2;
    }
    return count;
}

int solution(int n) {
    //다음 수와 다음 수의 2진수 1의 갯수를 저장하는 변수 선언
    int next = n;
    int next1 = 0;
    
    //n의 2진수의 1의 갯수를 저장
    int n1 = get1(n);
    
    //n 다음수부터 하나씩 체크
    bool k = true;
    while(k) {
        next++;
        next1 = get1(next);
        if(next1 == n1) k = false;
    }

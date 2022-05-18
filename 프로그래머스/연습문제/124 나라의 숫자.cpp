// 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/12899
// 문제 풀이 : https://shine-xia.tistory.com/75

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    //n이 0보다 큰 경우 계산 반복
    while(n>0) {
        int a = n/3; int b = n%3; // a: 몫 b: 나머지
        string add;
        
        //나머지에 따라 다른 문자열이 붙도록 구현
        if(b==1) add= "1";
        else if(b==2) add = "2";
        else{ //b==0 일 경우에는 몫에서 1을 뺌
            a = a-1;
            add = "4";
        }
        answer = add + answer;
        n= a;
    } 
    return answer;
}

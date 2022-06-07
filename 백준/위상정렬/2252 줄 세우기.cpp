#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N,M;
//진입차수 저장 배열과 체크 배열 생성 
int edge[32002];
int ch[32002];
//진입차수 0인 노드를 담을 큐 생성 
queue<int> q;

int main() {
	cin >> N >> M;
	//인접 리스트 배열와 정답배열 
	vector<vector<int> > v(N+1);
	vector<int> answer; 
	int a, b;
	//인접 리스트과 진입차수 배열 저장 
	for(int i = 0; i<M;i++) {
		cin >> a >> b;
		v[a].push_back(b);
		edge[b]++;
	}
	//진입 차수가 0인 큐 먼저 넣고 체크하기 
	for(int i = 1; i<=N;i++) {
		if(edge[i]==0) {
			q.push(i);
			ch[i] = 1;	
		}
	}
	
	while(!q.empty()) {
		int k = q.front();
		//큐 맨 앞 원소의 진입 차수가 0이 아니면 종료 
		if(edge[k] !=0) return 0;
		q.pop();
		//맨 앞 원소를 정답 배열에 넣기 
		answer.push_back(k);
		for(int i= 0; i<v[k].size();i++) {
			//이미 방문한 노드이면 스킵 
			if(ch[v[k][i]] == 1) continue;
			//진입차수 1 줄이기 
			edge[v[k][i]]--;
			//진입차수가 0이면 큐에 넣고 체크 하기 
			if(edge[v[k][i]] == 0) {
				q.push(v[k][i]);
				ch[v[k][i]] = 1;
			}
		}
	}
	
	//정답배열 출력! 
	for(int i = 0; i<answer.size();i++) {
		cout << answer[i] << " ";
	}
	return 0;
}

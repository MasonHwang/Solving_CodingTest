

#include <iostream>
#include <climits>
#include <vector>
#include <utility>
#include <queue>

#define INF INT_MAX
using namespace std;

int V, E, K, u, v, w;
int a, b, c, d;
pair<int, int> p;
priority_queue<pair<int, int>,vector<pair<int, int> >, greater<pair<int, int> > > q;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//입력 받기 
	cin >> V >> E;
	cin >> K;
	//정답 배열 생성 
	vector<int> answer(V + 1, INF);
	
	//인접리스트생성 및 초기화  (아동할노드와 가중치) 
	vector<vector<pair<int, int> > > near(V + 1);
	for (int i = 0; i < E; i++) {
		cin >> u >> v>> w;
		near[u].push_back(make_pair(v,w));
	}
	//큐에 넣고 정답 배열 값 바꾸기 
	q.push(make_pair(0, K));
	answer[K] = 0;

	while (!q.empty()) {
		p = q.top();
		//a: 현재가중치 , b:현재노드  
		a = p.first; b = p.second;
        q.pop();
		
		for (int i = 0; i < near[b].size(); i++) {
			p = near[b][i];
			c = p.first, d = p.second;
			//이미 있는 가중치가 구할 가중치보다 이미 작다면 스킵 
			if (answer[c] <= a + d) continue;
			answer[c] = a + d;
			q.push(make_pair(answer[c],c));
		}
	}

	for (int i = 1; i <= V; i++) {
		if (answer[i] == INF) cout << "INF" << "\n";
		else cout << answer[i] << "\n";
	}

	return 0;
}

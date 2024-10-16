#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

struct Edge {//간선 정보를 저장하는 구조체
    //v: 연결된 정점, w: 가중치, u: 시작 정점
    //u는 없어도 되지만 출력할 때 사용하기 위해 추가
    int v, w, u;
    Edge(int v, int w, int u) : v(v), w(w), u(u) {}
    bool operator>(const Edge& e) const {
        return this->w > e.w;
    }
};

void prim(vector<vector<Edge>>& graph, int n) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    vector<bool> visited(n + 1, false);
    //시작 정점은 0으로 설정
    for (const Edge& e : graph[0]) {
        pq.push(e);//0에서 연결된 간선들을 우선순위 큐에 넣음
    }
    visited[0] = true;//0은 방문한 것으로 처리
    
    while (!pq.empty()) {
        Edge e = pq.top();//가중치가 가장 작은 간선을 선택
        pq.pop();
        if (visited[e.v]) continue;//이미 방문한 정점이면 넘어감
        visited[e.v] = true;//방문한 것으로 처리
        cout << e.u << " " << e.v << " " << e.w << endl;//간선 정보 출력
        for (const Edge& next : graph[e.v]) {//선택한 간선에서 방문하지 않은 연결된 간선들을 우선순위 큐에 넣음
            if (!visited[next.v]) {
                pq.push(next);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n + 1);
    
    for (int i = 0; i < m; ++i) {//간선 정보 입력
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w, u);//u에서 v로 가는 가중치 w인 간선
        graph[v].emplace_back(u, w, v);//v에서 u로 가는 가중치 w인 간선
    }
    
    prim(graph, n);//prim 알고리즘 실행
    
    return 0;
}

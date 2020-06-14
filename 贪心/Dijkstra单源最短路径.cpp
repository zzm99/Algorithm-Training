#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<vector<int>> graph;

void getInputInfo() {
	cin >> N;
	graph = vector<vector<int>>(N, vector<int>(N, 9999999));
	for (int i = 0; i < N; ++i)
		graph[i][i] = 0;
    int M = 0, t1, t2, w;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> t1 >> t2 >> w;
        graph[t1][t2] = w;
        graph[t2][t1] = w;
    }
}

void disjKstraFunc(int startNode) {
	vector<bool> visited(N, false);
	vector<int> disToStart = graph[startNode];
	visited[startNode] = true;
	for (int i = 1; i < N; ++i) {
		int minDis = INT_MAX, minIndex = 0;
		for (int j = 0; j < N; ++j) {
			if (!visited[j] && disToStart[j] < minDis) {
				minDis = disToStart[j];
				minIndex = j;
			}
		}
		visited[minIndex] = true;
		for (int j = 0; j < N; ++j) {
			if (disToStart[j] > disToStart[minIndex] + graph[minIndex][j]) {
				disToStart[j] = disToStart[minIndex] + graph[minIndex][j];
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << startNode << "->" << i << " " << disToStart[i] << endl;
	}
}
int main() {
	int startNode = 0;
	getInputInfo();
	cin >> startNode;
	disjKstraFunc(startNode);
	return 0;
}

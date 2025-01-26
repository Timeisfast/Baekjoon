#include <iostream>
#include <vector>

#define INF 1000000000

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<std::vector<int>> graph(N, std::vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> graph[i][j];
			if (graph[i][j] == 0) {
				graph[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				graph[j][k] = std::min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == INF) {
				std::cout << "0 ";
			}
			else {
				std::cout << "1 ";
			}
		}
		std::cout << "\n";
	}
	return 0;
}
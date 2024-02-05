#include <iostream>
using namespace std;

int score[1001];
double newScore[1001];

int main() {
	int N, maxValue{ 0 };
	double sum{ 0 };

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> score[i];
		maxValue = max(maxValue, score[i]);
	}

	for (int i = 0; i < N; i++)
	{
		newScore[i] = score[i] / (double)maxValue * 100;
		sum += newScore[i];
	}

	cout << sum / N;
}
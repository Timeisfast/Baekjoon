#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node;

struct edge {
	node* st;
	node* dt;
	int dis;
	edge(node* a, node* b, int c) {
		st = a;
		dt = b;
		dis = c;
	}
};

struct node {
	int num;
	vector<edge> e;
	bool isVisited = false;
	node(int n) {
		num = n;
	}
};

vector<node*> n;
int V, ans{ 0 };
node* v;

void f(node* s, int sum) {
	s->isVisited = true;
	for (int i = 0; i < s->e.size(); i++) {
		if (s->e[i].dt->isVisited) continue;
		sum += s->e[i].dis;
		f(s->e[i].dt, sum);
		sum -= s->e[i].dis;
	}
	s->isVisited = false;
	if (ans < sum) {
		ans = sum;
		v = s;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> V;
	for (int i = 0; i <= V; i++) {
		n.push_back(new node(i));
	}
	for (int i = 0; i < V; i++) {
		int a, b, c;
		cin >> a;
		cin >> b;
		while (b != -1) {
			cin >> c;
			edge E(n[a], n[b], c);
			n[a]->e.push_back(E);
			cin >> b;
		}
	}
	f(n[1], 0);
	f(v, 0);
	cout << ans;
}
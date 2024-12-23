#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B, C;

    cin >> A >> B >> C;

    int iA = stoi(A);
    int iB = stoi(B);
    int iC = stoi(C);

    cout << iA + iB - iC << "\n";
    cout << stoi(A + B) - iC;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B, C;
    cin >> A >> B >> C;

    int k;
    if (A != "Fizz" && A != "Buzz" && A != "FizzBuzz") {
        int tmp = stoi(A);
        k = tmp + 3;
    }
    else if (B != "Fizz" && B != "Buzz" && B != "FizzBuzz") {
        int tmp = stoi(B);
        k = tmp + 2;
    }
    else {
        int tmp = stoi(C);
        k = tmp + 1;
    }

    string ans;
    if (k % 15 == 0) ans = "FizzBuzz";
    else if (k % 3 == 0) ans = "Fizz";
    else if (k % 5 == 0) ans = "Buzz";
    else ans = to_string(k);

    cout << ans;
}
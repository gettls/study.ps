#include <string>
#include <vector>
#include <cmath>
using namespace std;

string num = "124";

string solution(int n) {
    string answer = "";
    int tmp = n;

    while (tmp > 0) {
        int x;
        if (tmp % 3 == 0) {
            x = 3;
            tmp = tmp / 3 - 1;
        }
        else {
            x = tmp % 3;
            tmp /= 3;
        }
        answer = num[x - 1] + answer;
    }
    return answer;
}
#include <string>
#include <vector>
using namespace std;

char alpha[] = { ' ', 'A','E','I','O','U' };
int list[6][6][6][6][6];

bool check(int a, int b, int c, int d, int e, string word) {
    string tmp;
    if (a != 0) tmp.push_back(alpha[a]);
    if (b != 0) tmp.push_back(alpha[b]);
    if (c != 0) tmp.push_back(alpha[c]);
    if (d != 0) tmp.push_back(alpha[d]);
    if (e != 0) tmp.push_back(alpha[e]);

    if (tmp == word) return true;
    return false;
}

int solution(string word) {
    int answer = 0;

    for (int a = 0; a <= 5; a++) {
        for (int b = 0; b <= 5 && !(a == 0 && b > 0); b++) {
            for (int c = 0; c <= 5 && !(b == 0 && c > 0); c++) {
                for (int d = 0; d <= 5 && !(c == 0 && d > 0); d++) {
                    for (int e = 0; e <= 5 && !(d == 0 && e > 0); e++) {
                        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0) continue;
                        answer++;
                        if (check(a, b, c, d, e, word)) return answer;
                    }
                }
            }
        }
    }
}
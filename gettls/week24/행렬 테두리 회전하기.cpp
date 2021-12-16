#include <string>
#include <vector>
#include <map>
using namespace std;

int arr[101][101];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    map<int, int> m;
    int n = 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            arr[i][j] = n++;
        }
    }

    for (int i = 0; i < queries.size(); i++) {
        int x1 = queries[i][0], y1 = queries[i][1];
        int x2 = queries[i][2], y2 = queries[i][3];
        int x = x1, y = y1;
        int start = arr[x][y], min = start;

        while (x < x2) {
            if (arr[x + 1][y] < min) min = arr[x + 1][y];
            arr[x][y] = arr[x + 1][y];
            x++;
        }
        while (y < y2) {
            if (arr[x][y + 1] < min) min = arr[x][y + 1];
            arr[x][y] = arr[x][y + 1];
            y++;
        }
        while (x > x1) {
            if (arr[x - 1][y] < min) min = arr[x - 1][y];
            arr[x][y] = arr[x - 1][y];
            x--;
        }
        while (y > y1) {
            if (arr[x][y - 1] < min) min = arr[x][y - 1];
            arr[x][y] = arr[x][y - 1];
            y--;
        }
        arr[x][y + 1] = start;
        answer.push_back(min);
    }

    return answer;
}
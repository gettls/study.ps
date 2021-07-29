#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int> arr[3][2][2][2];
    for (int i = 0; i < info.size(); i++) {
        int a, b, c, d, e;
        istringstream ss(info[i]);
        string buffer;
        while (getline(ss, buffer, ' ')) {
            if (buffer == "cpp") a = 0;
            else if (buffer == "java") a = 1;
            else if (buffer == "python") a = 2;

            else if (buffer == "backend") b = 0;
            else if (buffer == "frontend") b = 1;

            else if (buffer == "junior") c = 0;
            else if (buffer == "senior") c = 1;

            else if (buffer == "chicken") d = 0;
            else if (buffer == "pizza") d = 1;

            else e = stoi(buffer) ;
        }
        arr[a][b][c][d].push_back(e);
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    sort(arr[i][j][k][l].begin(), arr[i][j][k][l].end());
   
    for (int i = 0; i < query.size(); i++) {
        int a1, a2, b1, b2, c1, c2, d1, d2;
        int score;
        int index = 0;
        istringstream ss(query[i]);
        string buffer;
        while (getline(ss, buffer, ' ')) {
            if (buffer == "and") continue;
            switch (index) {
            case 0:
                if (buffer == "cpp") { a1 = 0; a2 = 0; }
                else if (buffer == "java") { a1 = 1; a2 = 1; }
                else if (buffer == "python") { a1 = 2; a2 = 2; }
                else { a1 = 0; a2 = 2; } break;
            case 1:
                if (buffer == "backend") { b1 = 0; b2 = 0; }
                else if (buffer == "frontend") { b1 = 1; b2 = 1; }
                else { b1 = 0; b2 = 1; } break;
            case 2:
                if (buffer == "junior") { c1 = 0; c2 = 0; }
                else if (buffer == "senior") { c1 = 1; c2 = 1; }
                else { c1 = 0; c2 = 1; } break;
            case 3:
                if (buffer == "chicken") { d1 = 0; d2 = 0; }
                else if (buffer == "pizza") { d1 = 1; d2 = 1; }
                else { d1 = 0; d2 = 1; } break;
            case 4:
                score = stoi(buffer);
            }
            index++;
        }

        int sum = 0;
        for (int i = a1; i <= a2; i++) 
            for (int j = b1; j <= b2; j++) 
                for (int k = c1; k <= c2; k++) 
                    for (int l = d1; l <= d2; l++) {
                        int size = arr[i][j][k][l].size();
                        if (!size) continue;
                        auto it = lower_bound(arr[i][j][k][l].begin(), arr[i][j][k][l].end(), score);
                        if (it == arr[i][j][k][l].end()) continue;
                        sum += size - (it - arr[i][j][k][l].begin());
                    }
        
        answer.push_back(sum);
    }
    return answer;
}
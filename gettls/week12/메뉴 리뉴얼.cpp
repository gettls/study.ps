#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include<iostream>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<vector<string>> arr(course.size());
    set<string> ans;
    for (int i = 0; i < course.size(); i++) {
        for (int j = 0; j < orders.size(); j++) {
            if (course[i] > orders[j].size()) continue;
            vector<int> rand(orders[j].size());
            for (int k = 0; k < course[i]; k++) rand[k] = 1;
            do {
                string str;
                for (int k = 0; k < rand.size(); k++) {
                    if (rand[k]) str += orders[j][k];
                }
                sort(str.begin(), str.end());
                arr[i].push_back(str);
            } while (prev_permutation(rand.begin(), rand.end()));
        }
    }
    for (int i = 0; i < arr.size(); i++) sort(arr[i].begin(), arr[i].end());

    for (int i = 0; i < arr.size(); i++) {
        int max = -1, cnt = 0;
        if (arr[i].size() == 0) continue;
        string str = arr[i][0];
        for (int j = 0; j < arr[i].size(); j++) {
            if (str == arr[i][j]) {
                cnt++;
                if (cnt > max) max = cnt;
            }
            else {
                if (cnt > max) max = cnt;
                str = arr[i][j];
                cnt = 1;
            }
        }
        if (max < 2) continue;
        str = arr[i][0];
        cnt = 0;
        for (int j = 0; j < arr[i].size(); j++) {
            if (str == arr[i][j]) {
                cnt++;
                if (cnt == max) {
                    ans.insert(str);
                }
            }
            else {
                if (cnt == max) {
                    ans.insert(str);
                }
                str = arr[i][j];
                cnt = 1;
            }
        }
    }
    answer.resize(ans.size());
    copy(ans.begin(), ans.end(), answer.begin());
    return answer;
}
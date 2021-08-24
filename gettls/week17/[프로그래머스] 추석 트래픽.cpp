#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double convertDouble(string str) {
    string hour = str.substr(0, 2);
    string min = str.substr(3, 2);
    string sec = str.substr(6);

    double h = stod(hour) * 3600;
    double m = stod(min) * 60;
    double s = stod(sec.substr(0, 2)) + stod(sec.substr(3)) / 1000.0;

    return h + m + s;
}
int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<double, double>> list;
    for (int i = 0; i < lines.size(); i++) {
        int cnt = 0;
        double s = 0, start, end;
        end = convertDouble(lines[i].substr(11, 12));

        s = stod(lines[i].substr(24, 5));
        start = end - s + 0.001;
        list.push_back({ start,end });
    }

    for (int i = 0; i < list.size(); i++) {
        if (list[i].first < list[0].first + 1) answer++;
    }

    for (int i = 0; i < list.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < list.size(); j++) {
            if (list[j].first < list[i].second + 1 && list[i].second <= list[j].second)
                cnt++;
        }
        answer = max(answer, cnt);
    }

    return answer;
}
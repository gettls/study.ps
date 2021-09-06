#include <string>
#include <vector>
#include <sstream>
using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    vector<int> point(5, 0);
    int max = -1;

    vector<vector<string>> table2(table.size());
    for (int i = 0; i < table.size(); i++) {
        string as = table[i];
        istringstream ss(as);
        string buffer;
        while (getline(ss, buffer, ' ')) {
            table2[i].push_back(buffer);
        }
    }

    for (int i = 0; i < 5; i++) { // SI-> CONTENTS-> H/W-> PORTAL-> GAME
        for (int j = 0; j < languages.size(); j++) {
            int constant = preference[j];
            string lang = languages[j];
            for (int k = 1; k < table2[i].size(); k++) {
                if (table2[i][k] == lang) {
                    point[i] += constant * (6 - k);
                    break;
                }
            }
        }
    }


    for (int i = 0; i < 5; i++) {
        if (point[i] > max) {
            max = point[i];
            answer = table2[i][0];
        }
        if (point[i] == max && answer > table2[i][0]) {
            answer = table2[i][0];
        }
    }

    return answer;
}
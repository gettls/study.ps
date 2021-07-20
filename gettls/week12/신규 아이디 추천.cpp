#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    for (int i = 0; i < new_id.size(); i++) {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z')
            || (new_id[i] >= '0' && new_id[i] <= '9')
            || new_id[i] == '-' || new_id[i] == '_' || new_id[i]=='.') continue;
        else if (new_id[i] >= 'A' && new_id[i] <= 'Z') new_id[i] = new_id[i] - 'A' + 'a';
        else {
            new_id.replace(i, 1, "");
            i--;
        }
    }

    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] == '.') {
            int j = 0;
            while (new_id[i+j] == '.') j++;
            if (j != 1) {
                new_id.replace(i, j, ".");
                i--;
            }
        }
    }
    if (new_id[0] == '.') new_id.replace(0, 1, "");
    if (new_id[new_id.size() - 1] == '.') new_id.replace(new_id.size() - 1, 1, "");

    answer = new_id;
    if (answer.size() >= 16) {
        answer = answer.substr(0, 15);
        while (answer[answer.size() - 1] == '.') answer.replace(answer.size() - 1, 1, "");
        while (answer[0] == '.') answer.replace(0, 1, "");
    }
    if (answer.size() <= 2) {
        if (answer.size() == 0) answer = "aaa";
        else while (answer.size() < 3) answer += answer[answer.size() - 1];
    }


    return answer;
}
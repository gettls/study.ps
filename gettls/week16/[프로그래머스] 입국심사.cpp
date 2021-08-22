#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long max = -1;
    for(int i=0;i<times.size();i++){
        if(times[i] > max) max = times[i];
    }
    sort(times.begin(), times.end());
    
    long long s=0, e= max*n;
    while(s<=e){
        long long mid = (s+e)/2;
        long long cnt = 0;
        if(mid!=0){
            for(int i=0;i<times.size();i++){
                cnt += (mid / times[i]);
            }
        }
        if(cnt>=n){
            answer = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return answer;
}
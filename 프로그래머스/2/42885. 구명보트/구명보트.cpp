#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> p, int limit) {
    int answer = 0;
    sort(p.begin(), p.end());
    int st = 0, ed = p.size() - 1;
    
    while(st <= ed) {                   
        if(p[st] + p[ed] <= limit)
            st++;
        
        ed--;        
        answer++;
    }
    
    return answer;
}
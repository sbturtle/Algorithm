#include <string>
#include <vector>

using namespace std;

// Two-Pointer GoGo
vector<int> solution(vector<int> seq, int k) {
    int s = seq.size();
    vector<int> answer(2);
    int r1 = 0, r2 = s;    
   
    int st = 0, ed = 0;
    int sum = seq[0];
    
    while(st <= ed) {
        if(ed == s)
            break;
        if(sum == k && (r2 - r1) > (ed - st)) {
            r1 = st;
            r2 = ed;
        }
        if(sum > k)
            sum -= seq[st++];        
        else
            sum += seq[++ed];
    }
    
    
    answer[0] = r1;
    answer[1] = r2;
    
    return answer;
}
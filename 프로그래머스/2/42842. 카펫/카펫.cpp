#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // 모서리 제외, 
    // 총합 개수 = (가로의 한쪽 면 + 세로의 한쪽 면) * 2
    int br = (brown - 4) / 2;
    
    int x = br - 1, y = 1;
    int c = x * y;
    while(c != yellow) {
        if(c < yellow) 
            c = --x * ++y;        
    }
    
    answer = { x + 2, y + 2 };
    
    
    
    return answer;
}
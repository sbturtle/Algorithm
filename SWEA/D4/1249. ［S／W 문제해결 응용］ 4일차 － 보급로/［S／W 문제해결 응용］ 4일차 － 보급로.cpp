#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define X first
#define Y second
#define INF 1e9 + 10
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int d[102][102];
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;	cin >> n;
        vector<string> m(n+1);
        for(int i = 0; i < n; i++)
            fill(d[i], d[i] + n + 1, INF);
        
        for(int i = 0; i < n; i++)
			cin >> m[i];
        
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;
        
        d[0][0] = 0;
        pq.push({d[0][0], {0, 0}});
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            if(d[cur.Y.X][cur.Y.Y] != cur.X)                continue;
            
            for(int i = 0; i < 4; i++) {
                int nx = dx[i] + cur.Y.X;
                int ny = dy[i] + cur.Y.Y;
                
                if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;
                int w = m[nx][ny] - '0';
                if(d[nx][ny] <= cur.X + w)
                    continue;
                d[nx][ny] = cur.X + w;
                pq.push({d[nx][ny], {nx, ny}});
            }
        }

		cout << '#' << test_case << ' '<< d[n-1][n-1] << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
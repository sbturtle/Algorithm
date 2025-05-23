#include <iostream>
using namespace std;

char arr[51][51];
char white_arr[8][8] = {
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W'
};

char black_arr[8][8] = {
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B'
};

int wb_first(int x, int y) {
	int white_result = 0;
	int black_result = 0;

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++){            
			if (arr[x + i][y + j] != white_arr[i][j])
				white_result++;
    			if (arr[x + i][y + j] != black_arr[i][j])
				black_result++; 
        }            

	return min(white_result, black_result);
}


int main() 
{
	int n, m, result = 64;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	int t_white, t_black;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
            result = min(result, wb_first(i, j));
		}
	}
	cout << result << endl;
}
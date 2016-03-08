#include <iostream>
using namespace std;

int dp[302][302]; 
int visit[302][302]; 


int max(int a, int b)
{
	return  a < b ? b : a;
}

void init()
{
	for (int i = 0; i < 302; i++)
	for (int j = 0; j < 302; j++)
		dp[i][j] = visit[i][j] = -999;
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	init();

	for (int i = 0; i < k; i++)  // 반복 횟수
	{
		int x, y, w; 
		cin >> x >> y >> w;
		visit[x][y] = max(visit[x][y], w);  // 같은 경로는 또 입력 될 수 있으므로 그중 최대값으로 
	}
	dp[1][0] = 0; // n이 1개인 경우

	/* dp[i][k] = (dp[i][k] ,dp[j][k-1]+visit[j][i] ) 중에서 큰 값으로 채움 */
	for (int i = 2; i <= n; i++)   // 각 노드의 시작에서,
		for (int j = i ; j >= 1 ; j--)  // 갈 수 있는 경로 확인 ( 1 -> 3, 1->2 ...) 시작점은 j ,끝점 i
			for (int k = 1; k < m ; k++)        // 카운트 만큼만 재면서 갈 수 있는 길인지,
				if (visit[j][i] != -999 && dp[j][k - 1] != -999 )        // 각 시작점에서 k번째 만에 갈 수 있는 배열에 값 저장 
					dp[i][k] = max(dp[i][k], dp[j][k - 1] + visit[j][i]); // 현재 저장된 값과 새로운 경로의 합 중에서 큰 값으로 해가면서
				                   // 횟수까지 올라가면서 






	/* 
	   채워진 값 중에서 제일 큰 수를 답 출력 
	   k번째의 값 중에서 최대값 찾으면 됨
	*/

	int result = -999999;
	
	for (int i = 1; i < m ; i++)
		result = max(result, dp[n][i]);  
	

	cout << result << endl;

	return 0;
}
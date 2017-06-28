#include <iostream>
using namespace std;

struct Point
{
    int x;
    int y;
};

Point queue[777777];
int rear;
int front;

int d[4][2] = { {0,1},{1,0},{-1,0},{0,-1} }; // 4방향

int map[102][102]; // 맵
int visit[102][102]; //방문 길이 저장용

int N,M; //도착 지점
int result; // 답 저장

void bfs(int x,int y)
{
    queue[rear].x = x;
    queue[rear].y = y;
    ++rear %= 777777;
    
    visit[x][y] = 1;
    map[x][y] = 0;
    
    while(rear != front ) // 큐에서 빌 때까지 ,
    {
            int sx = queue[front].x;   // 큐에서 끄내와서 ,
            int sy = queue[front].y;
            ++front %= 777777;
        
            if( sx == N && sy == M)
                break;
        
            for(int i = 0; i < 4 ; i++) // 4곳에서
            {
                if( map[ sx + d[i][0] ] [ sy + d[i][1] ] == 1 ) // 갈 수 있는 길이면 ,
                {
                    map[sx+d[i][0]][sy+d[i][1]] = 0;
                    
                    queue[rear].x = sx + d[i][0];
                    queue[rear].y = sy + d[i][1]; // 큐에 집어넣고
                    ++rear %= 777777;
                   
                    visit[ sx+d[i][0] ][ sy+d[i][1] ] = visit[sx][sy] + 1; // 길이를 1 늘려
                }
            }   
    }
}


void init()
{
    rear = front = 0;
    for(int i = 0 ; i < 102 ; i++)
        for(int j = 0 ; j < 102 ; j++)
                 map[i][j] = visit[i][j] = 0;
    for(int i = 0 ; i < 777777; i++)
        queue[i].x = queue[i].y = 0;
}

int main()
{
    init();
    cin>>N>>M;
    
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1; j <= M ; j++)
		{
			char s;

               cin>>s;
			   if( s =='1')
				   map[i][j] = 1;
			   else
					map[i][j] = 0;
		}    
    
    bfs(1,1);
    
    cout<<visit[N][M]<<endl;
    
    return 0;
}

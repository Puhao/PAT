#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
using namespace std;
#define INF 1000000
#define N 501

int graph[N][N];
bool visit[N];
int dist[N];
int RoadNum[N];
int RescueNum[N];
int SaveNum[N];

void dijkstra_emergency(int start, int end)
{
	visit[start] = true;
	for (int i=0; i<N; i++)
	{
		dist[i] = graph[start][i];
	}
	//把剩下的N-1个顶点依次加入
	for (int i=1; i<N; i++)
	{
		int MiniDst = INF;
		int index = -1;
		//每次加入的数为距离最短的那个
		for(int j=0; j<N; j++)
		{
			if(!visit[j] && (dist[j] < MiniDst))
			{
				MiniDst = dist[j];
				index = j;
			}
		}
		visit[index] = true;
		//加入一个顶点，然后更新到各个顶点的距离
		for (int j=0; j<N; j++)
		{
			if (!visit[j])
			{
				int RefDst = dist[index] + graph[index][j];
				if (RefDst < dist[j])
					dist[j] = RefDst;
			}
		}
	}

}

int main()
{
	memset(graph,INF,sizeof(graph));
	memset(visit,false,sizeof(visit));
	

}
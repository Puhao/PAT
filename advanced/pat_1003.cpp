#include <iostream>
#include <string>
#include <stack>
#include <cstring>
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
		//到每个点的路只有一条,无穷远也默认有一条
		RoadNum[i] = 1;
		SaveNum[i] = RescueNum[start]+RescueNum[i];
	}
	SaveNum[start] = RescueNum[start];

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
		if (index == end)
			return;
		//加入一个顶点，然后更新到各个顶点的距离
		for (int j=0; j<N; j++)
		{
			if (!visit[j])
			{
				int RefDst = dist[index] + graph[index][j];
				if (RefDst < dist[j]) 
				{
					dist[j] = RefDst;
					RoadNum[j] = RoadNum[index];
					SaveNum[j] = SaveNum[index] + RescueNum[j];
				}
				else if (RefDst == dist[j])
				{
					RoadNum[j] = RoadNum[index] + RoadNum[j];
					int CurrSave = SaveNum[index] + RescueNum[j];
					if (CurrSave > SaveNum[j])
						SaveNum[j] = CurrSave;
				}
			}
		}
	}
	return ;

}

int main()
{
	memset(graph,INF,sizeof(graph));
	memset(visit,false,sizeof(visit));
	int CityNum, CityRoad, StartCity, EndCity;
	cin >> CityNum >> CityRoad >> StartCity >> EndCity;
	cin.get();
	for (int i=0; i<CityNum; i++)
	{
		cin >> RescueNum[i];
	}
	cin.get();
	for (int j=0; j<CityRoad; j++)
	{
		int s, e, len;
		cin >> s >> e >> len;
		graph[s][e] = len;
		graph[e][s] = len;
		cin.get();
	}
	dijkstra_emergency(StartCity, EndCity);
	cout << RoadNum[EndCity] << " " << SaveNum[EndCity];
	return 0;
}
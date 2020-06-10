// BFS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <queue>
#include <iostream>

#define N 100

using namespace std;

void addEdge(int i, int j, int E[100][100])
{
	E[i][j] = 1;
}

void bfs(int u, int n, int E[N][N], int Trace[N])
{
	Trace[u] = u;

	queue<int> qu;
	qu.push(u);
	while (!qu.empty())
	{
		int dinh = qu.front();
		qu.pop();
		for (int i = 1; i <= n; ++i)
		{
			if (E[dinh][i] != 0 && Trace[i] == 0)
			{
				Trace[i] = dinh;
				qu.push(i);
			}
		}
	}
}

int main()
{
	int E[N][N] = {0};
	int Trace[N] = {0};

	int n = 8;
	int u = 1;
	

	addEdge(1, 2, E);
	addEdge(1, 3, E);
	addEdge(1, 4, E);
	addEdge(1, 5, E);
	addEdge(2, 6, E);
	addEdge(3, 4, E);
	addEdge(3, 8, E);
	addEdge(4, 8, E);
	addEdge(5, 8, E);
	addEdge(6, 7, E);
	addEdge(6, 8, E);

	bfs(u, n, E, Trace);

	for (int i = 1; i <= n; ++i)
	{
		cout << i << ": ";
		if (Trace[i] != -1)
		{
			cout << i << " ";
			int d = Trace[i];
			while (d != u)
			{
				cout << d << " ";
				d = Trace[d];
			}
			cout << d;
		}
		cout << endl;
	}

	system("pause");

    return 0;
}


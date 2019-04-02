#include <iostream>
#include <fstream>
using namespace std;

void dfs(int n, int d, int E[1000][1000], int Trace[1000])
{
    for(int i = 1; i <= n; ++i)
    {
       if(Trace[i] != -1 && E[d][i] != 0)
       {
           Trace[i] = d;
           dfs(n, i, E, Trace);
       }
    }
}

void addEdge(int i, int j, int E[1000][1000])
{
    E[i][j] = 1;
}

int main()
{
    int E[1000][1000];
    int Trace[1000] = {-1};
    int n = 8, u = 1;

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


    Trace[u] = u;
    dfs(n, u, E, Trace);
    for(int i = 1; i <= n; ++i)
    {
        if(Trace[i] != -1)
        {
            cout << i << " ";
            int d = Trace[i];
            while(d != u)
            {
                cout << d << " ";
                d = Trace[d];
            }
        }
        cout << endl;
    }


    return 0;
}

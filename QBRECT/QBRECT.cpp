// link: http://vnoi.info/problems/show/QBRECT/

#include <iostream>

using namespace std;

#define N 1024

int m, n, H[N];
int L[N], R[N];



int main()
{
	ios::sync_with_stdio(false);
	cin >> m >> n;
	int a, j, t;

	int rs = 0;
	for (int i = 0; i < m; ++i)
	{
		//tinh left
		for (j = 0; j < n; ++j)
		{
			cin >> a;
			H[j] = a ? H[j] + 1 : 0;

			t = j - 1;
			while (t >= 0 && H[t] >= H[j]) t = L[t];
			L[j] = t;			
		}

		//tinh right
		
		for (j = n - 1; j >= 0; --j)
		{
			t = j + 1;
			while (t < n && H[t] >= H[j]) t = R[t];
			R[j] = t;
			int tmp = (t - L[j] - 1)*(H[j]);
			if (rs < tmp) rs = tmp;
		}
	}

	cout << rs;

	system("pause");
	return 0;
}


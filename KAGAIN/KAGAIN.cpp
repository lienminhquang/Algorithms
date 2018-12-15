// KAGAIN.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define N 30000

int A[N], L[N], R[N], T, n, t;
int rs = 0;
int chiso = 0;


void solve()
{
	cin >> T;



	while (T--)
	{
		rs = 0;
		chiso = 0;
		cin >> n;
		L[0] = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> A[i];

			t = i - 1;
			while (t >= 0 && A[t] >= A[i])
				t = L[t] - 1;

			L[i] = t + 1 ;			
		}

		R[n - 1] = n - 1;
		for (int i = n - 1; i >= 0; --i)
		{
			t = i + 1;
			while (t < n && A[t] >= A[i])
				t = R[t] + 1;

			R[i] = t - 1;

			int sm = (R[i] - L[i] + 1) * A[i];
			if (sm > rs)
			{
				rs = sm;
				chiso = i;
			}
			else if (sm == rs && L[i] < L[chiso])
			{
				rs = sm;
				chiso = i;
			}
		}

		cout << rs << " " << L[chiso] + 1 << " " << R[chiso] + 1 << "\n";
	}
}



int main()
{
	ios::sync_with_stdio(false);
	solve();

	system("pause");
	return 0;
}


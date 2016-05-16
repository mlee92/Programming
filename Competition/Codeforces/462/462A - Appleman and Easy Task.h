#include<iostream>
#include<string>
using namespace std;

string gr[100];

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
int n;

bool valid(int x, int y)
{
	return 0 <= x && x < n && 0 <= y&&y < n;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> gr[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k], ny = j + dy[k];
				if (valid(nx, ny) && gr[nx][ny] == 'o')
					cnt++;
			}
			if (cnt % 2 != 0)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}

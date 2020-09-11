#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n;
int f(vector<int> v)
{
  int id = 0, M = v[0];
  for (int i = 0; i <n; i++)
  {
    if (v[i] > M)
    {
      id = i;
      M = v[i];
    }
  }
  return id;
}
int g(vector<int> v)
{
  int id = 0, M = v[0];
  for (int i = 0; i < n; i++)
  {
    if (v[i] < M)
    {
      id = i;
      M = v[i];
    }
  }
  return id;
}
using namespace std;
int main()
{
  int q;
  cin >> n >> q;
  vector<int> m;
  for (int i = 0; i < n; i++)
    m[i] = 0;
  while (q--)
  {
    int qu;
    cin >> qu;
    if (qu == 1)
    {
      int u, c;
      cin >> u >> c;
      m[c - 1] += u;
    }
    else if (qu == 2)
    {
      int u, c;
      cin >> u >> c;
      m[c - 1] -= u;
    }
    else if (qu == 3)
    {
      cout << f(m) << endl;
    }
    else if (qu == 4)
    {
      cout << g(m) << endl;
    }
  }
}
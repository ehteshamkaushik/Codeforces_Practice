#include <iostream>

using namespace std;

int parent[52], degree[52];

int n, m, maxdeg = 0, cycle = 0;

int find(int i)
{
    if(parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

void union_(int u, int v)
{
    parent[find(u)] = find(v);
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;

        if(find(u) == find(v))
            cycle++;
        else
            union_(u, v);
        maxdeg = max(maxdeg, max(degree[u], degree[v]));
    }

    if(maxdeg > 2)
    {
        cout << "NO\n";
        return 0;
    }
    if(cycle > 0)
    {
        if(maxdeg == 2 && m == n && cycle == 1)
        {
            cout << "YES\n0\n";
        }
        else
            cout << "NO\n";
        return 0;
    }

    cout << "YES\n" << n-m << "\n";
	for (int i=1;i<=n-1;i++)
		for (int j=i+1;j<=n;j++)
			if (degree[i]<2 && degree[j]<2 && find(i)!=find(j))
			{
				degree[i]++;
				degree[j]++;
				union_(i, j);
				cout << i << " " << j << endl;
			}
	for (int i=1;i<=n;i++)
		for (int j=n;j>=i;j--)
			if (degree[i]<2 && degree[j]<2)
			{
				degree[i]=degree[j]=2;
				union_(i, j);
				cout << i << " " << j << endl;
			}
    return 0;

}

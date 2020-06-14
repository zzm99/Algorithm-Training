class Solution {
public:
	int m, n;
	int longestIncreasingPath(vector<vector<int>>& arr) 
	{
		if (arr.empty() || arr.front().empty())return 0;
		m = arr.size();
		n = arr.front().size();
		vector<vector<int>>v(m, vector<int>(n, 1));
		int res = 1;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				dfs(i, j, arr, v);
				res = max(res, v[i][j]);
			}
		}
		return res;
	}
	void dfs(int i, int j, vector<vector<int>>& arr, vector<vector<int>>& v)
	{
		if (v[i][j] > 1)return;
		int t = 0;
		if (i > 0 && arr[i - 1][j] > arr[i][j]) dfs(i - 1, j, arr, v),t = max(t,v[i-1][j]);
		if (i < m-1 && arr[i + 1][j] > arr[i][j])dfs(i + 1, j, arr, v),t = max(t,v[i + 1][j]);
		if (j > 0 && arr[i][j - 1] > arr[i][j])dfs(i, j - 1, arr, v),t = max(t, v[i][j - 1]);
		if (j<n-1 && arr[i][j + 1] > arr[i][j])dfs(i, j + 1, arr, v),t = max(t, v[i][j + 1]);
		v[i][j] += t;
	}
};
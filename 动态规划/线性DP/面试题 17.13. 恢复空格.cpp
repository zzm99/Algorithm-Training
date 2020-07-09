class Solution {
	int N;
	int dp[1000+7];
	vector<int> pref[1000+7];
public:
    int respace(vector<string>& dictionary, string sentence) 
	{
		if( sentence.size() == 0) return 0;
		N = sentence.size();
        fill(dp, dp+N, INT_MAX), dp[0] = 0;
		sentence.insert(sentence.begin(), '\0');
		for(auto& str: dictionary)
		{
			int pos = 1;
			while( (pos=sentence.find(str, pos)) > 0)  {
				pref[pos+str.size()-1].push_back(pos);
				pos += str.size();
			}
		}
		for( int i = 1; i <= N; i++)
		{
			dp[i] = dp[i-1] +1;
			for(int st: pref[i]) 
				dp[i] = min(dp[i], dp[st-1]);
		}
		return dp[N];
    }
};
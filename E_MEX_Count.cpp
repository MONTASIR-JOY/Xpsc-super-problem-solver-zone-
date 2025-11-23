#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        map<long long, long long> mp;
		for(long long i = 0; i < n; i++)
        {
			long long x;
            cin >> x;
			mp[x]++;
		}
		map<long long, long long> freq;
		long long mex = 0;
		for(auto [x, y] : mp)
        {
			if(x==mex)
            {
				mex++;
				freq[y]++;
			}
		}

		vector<long long> v(n+1, 0);
		v[n] = 1;
		for(long long i = n-1; i > n - mex; i--)
        {
			v[i] = v[i+1] + 1;
		}

		v[0] = 1;
		for(long long i = 1; i < n; i++)
        {
			if(v[i]>0)
            {
                break;
            }
			v[i] = v[i-1] + freq[i];
		}

		for(long long i:v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
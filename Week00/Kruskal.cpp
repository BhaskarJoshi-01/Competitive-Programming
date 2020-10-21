#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<long long int,pair<long long int,long long int>>> v;
long long int P[1000006],S[1000006];

long long int dsu(long long int x,long long int y)
{
	long long int i,j;
	i=x;
	while(i!=P[i])
	{
		P[i]=P[P[i]];
		i=P[i];
	}

	j=y;
	while(j!=P[j])
	{
		P[j]=P[P[j]];
		j=P[j];
	}

	if(i==j)
		return 1;

	else
	{
		if(S[i]>S[j])
		{
			P[j]=P[i];
			S[i] += S[j];
		}
		else
		{
			P[i]=P[j];
			S[j] += S[i];
		}

		return 0;
	}
}

int main()
{
	long long int N,M,i,j,a,b,c,ans=0;
	cin>>N>>M;

	for(i=0;i<N;i++)
	{
		P[i]=i;
		S[i]=1;
	}
	for(i=0;i<M;i++)
	{
		cin>>a>>b>>c;
		v.push_back(make_pair(c,make_pair(a,b)));
	}

	sort(v.begin(),v.end());

	for(i=0;i<M;i++)
	{
		j = dsu(v[i].second.first,v[i].second.second);

		if(j==0)
			ans += v[i].first; 
	}

	cout<<ans<<endl;
	return 0;
}



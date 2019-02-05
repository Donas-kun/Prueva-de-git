#include<bits/stdc++.h>
#include<queue>
using namespace std;
struct node{
	int mo;
	int sum;
	string a;
};
int vis[505][5005];
int main()
{
	int a,b;
	cin>>a>>b;
	queue<node>q;
	q.push({0,0,""});
	vis[0][0]=1;
	while(!q.empty())
	{
		node u=q.front();
		q.pop();
		if(u.sum>b)continue;
		if(u.mo==0&&u.sum==b)
		{
			cout<<u.a<<endl;
			system("pause");
			return 0;
		}
		
		for(int i=0;i<=9;i++)
		{
			int aa=(u.mo*10+i)%a;
			int bb=u.sum+i;
			if(!vis[aa][bb])
			{
				vis[aa][bb]=1;
				q.push({aa,bb,u.a+(char)(i+'0')});
				cout << aa <<" "<< bb <<" "<< u.a+(char)(i+'0') << "\n";
			}	
		}
	 } 
cout<<-1<<endl;
	return 0;
	
 } 
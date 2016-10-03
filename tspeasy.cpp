#include<iostream>
using namespace std;
int main()
{
	int i,j,n,min,a[50][50],k,q,y=0,t[50][2],sum=0,cnt=0,src,u,v,h[50]={100},v1,cost=0,d[50],s[50],p[50],z,arr[50],o=0,brr[50][50];
	cout<<"Enter the number of nodes\n";
	cin>>n;
	cout<<"Enter the matrix\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{cin>>a[i][j];
		}
	}

for(i=0;i<n;i++)
for(j=0;j<n;j++)
brr[i][j]=a[i][j];

    min=999;src=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if((a[i][j]!=0)&&(a[i][j]<=min))
				{     min=a[i][j];
                      src=i;

				}
			}
		}
		for(i=0;i<n;i++)
        {
            d[i]=a[src][i];
            s[i]=0;
            p[i]=src;
        }
	s[src]=1;
	sum=0;
	k=0;
	for(i=1;i<n;i++)
    {
        min=999;
        u=-1;
        for(j=0;j<n;j++)
        {
            if(s[j]==0&&d[j]<min)
            {
                min=d[j];
                u=j;
            }
        }

        t[k][0]=u;
        t[k][1]=p[u];
        k++;
        sum+=a[u][p[u]];
        s[u]=1;

    for(v=0;v<n;v++)
    {
        if(s[v]==0&&a[u][v]<d[v])
        {
            d[v]=a[u][v];
            p[v]=u;
        }
    }
}

for(i=0;i<n;i++)
for(j=0;j<n;j++)
{a[i][j]=999;
}

if(sum>=999)
    {cout<<"Spanning tree does not exist\n";}

else{
     cout<<"Spanning tree exists and minimum spanning tree is\n";
         for(i=0;i<n-1;i++)
        {    cout<<t[i][0]<<"  "<<t[i][1]<<endl;
               a[t[i][0]][t[i][1]]=brr[t[i][0]][t[i][1]];
	       a[t[i][1]][t[i][0]]=brr[t[i][1]][t[i][0]];	
		//cout<<a[t[i][0]][t[i][1]]<<"  "<<brr[t[i][0]][t[i][1]]<<endl;
	}
         cout<<"The cost of minimum spanning tree is :"<<sum<<endl;
}

u=0;arr[o++]=u;
while(cnt<(2*(n-1)))
      {
    src=u;// cout<<src<<"   "<<endl;
    min=999;
    for(v=0;v<n;v++)
    {
        if((a[u][v]!=0)&&(a[u][v]<min))
        {
        min=a[u][v];//cout<<min<<"   ";
        v1=v;
        }
    }z=v1;
    //cout<<min<<u<<z<<endl;
    if(h[z]!=z)
      {
        h[z]=z;
	arr[o++]=z;
       // cost+=min;
      }
    a[u][z]=999;
    a[z][u]*=10;
    u=z;//cout<<u<<"   "<<endl;
    cnt++;
}
for(i=0;i<o;i++){
cout<<arr[i]<<"-->  ";
}
for(i=0;i<o-1;i++){
cost+=brr[arr[i]][arr[i+1]];
}
cout<<"minimum Distance to travel by the salesman : "<<cost<<endl;
return 0;
}


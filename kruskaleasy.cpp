#include<iostream>
using namespace std;
int main()
{
	int i,j,n,min,a[50][50],k,p,q,x[50]={100},y=0,t[50][2],sum=0;
	cout<<"Enter the number of nodes\n";
	cin>>n;
	cout<<"Enter the matrix\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{cin>>a[i][j];
		}
	}
	for(k=0;k<n-1;)					  //compute minimum edge n-1 times
	{
 		min=999;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if((a[i][j]!=0)&&(a[i][j]<min))
				{     min=a[i][j];
			              p=i;
				      q=j;
				}
			}
		}
	if(min==999)
	{ k--;
	  break;
	}
	if((x[p]!=p)&&(x[q]!=q))
	{
	  x[p]=p;
	  x[q]=q;
	  t[y][0]=p;
	  t[y][1]=q;
	  k++;
          y++;
         sum+=a[p][q];
	a[p][q]=a[p][q]=999;
	}

	if((x[p]!=p)&&(x[q]==q))
	{
	  x[p]=p;
	  t[y][0]=p;
	  t[y][1]=q;
	  k++;
          y++;
         sum+=a[p][q];
	}
	if((x[p]==p)&&(x[q]!=q))
	{
	  x[q]=q;
	  t[y][0]=p;
	  t[y][1]=q;
	  k++;
          y++;
         sum+=a[p][q];
     }
a[p][q]=a[p][q]=999;

     }
if(k==n-1)
{
	for(i=0;i<y;i++)
	{
		cout<<t[i][0]<<"  "<<t[i][1]<<endl;
    }
    cout<<sum;
}
else
{
	cout<<"Minimum spanning tree does not exist";
}
return 0;
}


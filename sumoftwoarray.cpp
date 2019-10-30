#include<iostream>
using namespace std;

int main()
{
    int n,m, carry=0;
    bool t=0, b=0;
    cin>>n;
    int ar[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    cin>>m;
    int ar1[m+1];
    for(int i=0;i<m;i++)
    {
        cin>>ar1[i];
    }
    if (m<n)
    {
		t=0;
		
        int j=m-1;
        for(int i=n-1;i>=0;i--)
        {
            ar[i]+=ar1[j];
            j--;
            if(ar[i]>9 && (i-1)>=0)
            {
                carry=ar[i]/10;
                ar[i]=ar[i]%10;
                ar[i-1]+=carry;
            }
            if (j<0)
            {
                break;
            }
        }
    }

    else
    {
        t=1;
        
        int j=n-1;
        //cout<<j<<endl;
        for(int i=m-1;i>=0;i--)
        {
            ar1[i]+=ar[j];
            j--;
            //cout<<i<<endl;
            if(ar1[i]>9 && (i-1)>=0)
            {
            	
                carry=ar1[i]/10;
                
                ar1[i]=ar1[i]%10;
                ar1[i-1]+=carry;
            }
            if (j<0)
            {
                break;
            }
        }
    }
    
    if(m<n && ar[0]>9)
    {
    	b=1;
    	for(int i=n-1;i>=0;i--)
    	{
    		ar[i+1]=ar[i];
		}
		             
        ar[0]=ar[0]/10;
        ar[1]=ar[1]%10;
	}
	if(n<=m && ar1[0]>9)
    {
    	b=1;
    	for(int i=m-1;i>=0;i--)
    	{
    		ar1[i+1]=ar1[i];
		}
		             
        ar1[0]=ar1[0]/10;
        ar1[1]=ar1[1]%10;
	}
    if(t==1 && b==0)
    {
        for(int i=0;i<m;i++)
    {
        cout<<ar1[i]<<", ";
    }
    }
    else if(t==0 && b==0)
    {
        for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<", ";
    }
    }
    if(t==1 && b==1)
    {
        for(int i=0;i<m+1;i++)
    {
        cout<<ar1[i]<<", ";
    }
    }
    else if(t==0 && b==1)
    {
        for(int i=0;i<n+1;i++)
    {
        cout<<ar[i]<<", ";
    }
    }
	cout<<"END";
	return 0;
}

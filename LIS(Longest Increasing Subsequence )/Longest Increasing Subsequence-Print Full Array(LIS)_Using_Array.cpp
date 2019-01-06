/**
    Array - 10, 20, 30, 1, 29, 40, 30, 5, 1
    Length of LIS : 4
    LIS : 10 20 29 40
*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 1, 29, 40, 30, 5, 1} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;

    int lis[n];
    for(int i = 0;i<n;i++) lis[i] = 1 ;
    int maxValue = 0 ;
    int index ;
    int length ;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if((arr[i] > arr[j]) && (lis[j]+1 > lis[i]))
            {
                lis[i] = lis[j]+1 ;
                if(maxValue < lis[i]) maxValue = lis[i] , index = i ;
            }
        }

    }
    cout<<"Length of LIS : "<<maxValue<<endl ;


    /// Printing LIS
    length = maxValue ;
    int ans[length] ;
    ans[length - 1] = arr[index] ;

    length-- ;

    while(index>0)
    {
        for(int i=index-1;i>=0;i--)
        {
            if((lis[i]+1 == lis[index]) && (arr[i]<arr[index]))
            {
                ans[length-1] = arr[i] ;
                index = i ;
                length-- ;
                break ;
            }
        }
    }

    cout<<"LIS : ";
    for(int i=0;i<maxValue;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl ;

    return 0 ;
}


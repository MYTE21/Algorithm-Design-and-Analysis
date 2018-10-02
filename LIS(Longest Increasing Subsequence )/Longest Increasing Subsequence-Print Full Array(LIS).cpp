#include<iostream>
#include<cstdio>
#include<vector>
using namespace std ;

void PrintLIS(vector<int> &longest)
{
    cout<<"The LIS is : ";
    for(int x : longest)
    {
        cout<<x<<" ";
    }
    cout<<endl ;
}

void CreateLIS(int arr[], int arrSize)
{
    vector<int> vec[arrSize] ;
    vec[0].push_back(arr[0]) ;

    for(int i=1;i<arrSize;i++)
    {
        for(int j=0;j<i;j++)
        {
            if((arr[i] > arr[j]) && (vec[i].size() < vec[j].size()+1))
            {
                vec[i] = vec[j] ;
            }
        }
        vec[i].push_back(arr[i]) ;
    }
    vector<int> longest = vec[0] ;

    for(vector<int> x : vec)
    {
        if(x.size() > longest.size())
        {
            longest = x ;
        }
    }

    PrintLIS(longest) ;

}

int main()
{
    int arr[] = {10, 20, 28, 1, 39, 30, 31, 5, 1} ;
    int arrSize = sizeof(arr)/sizeof(arr[0]) ;

    CreateLIS(arr, arrSize) ;

    return 0 ;
}


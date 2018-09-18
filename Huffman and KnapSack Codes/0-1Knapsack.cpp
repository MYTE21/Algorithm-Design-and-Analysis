#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define Max 10002
#define endl '\n'

int dp[Max][Max];
int weight[Max];
int prize[Max];

int KnapSack(int bagcapacity,int point)
{
    if(bagcapacity==0||point<1) return 0;

    if(dp[bagcapacity][point]!=-1) return dp[bagcapacity][point];

    int first = 0 , second = 0 ;

    if(weight[point]<=bagcapacity) first = prize[point]+KnapSack((bagcapacity-weight[point]),point-1);
    second = KnapSack(bagcapacity,point-1);

    dp[bagcapacity][point]=max(first , second);

    return dp[bagcapacity][point];
}



int main()
{
    int bagcapacity ,point;

    printf("Enter the bag capacity : ") ;
    scanf("%d",&bagcapacity);
    printf("Enter elements number : ") ;
    scanf("%d",&point) ;

    memset(dp,-1,sizeof(dp));

    printf("Enter elements weight - Prize : \n") ;
    for(int i=0;i<point;i++)
    {
        scanf("%d %d",&weight[i],&prize[i]);
    }

    int ans = KnapSack(bagcapacity,point);

    printf("Max profit can be : %d\n",ans);

    return 0;
}

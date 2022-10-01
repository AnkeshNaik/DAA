#include<stdio.h>
#include<stdlib.h>
int max(int i,int j){
 return i>j?i:j;
} 

int knap(int cap,int w[],int p[],int n){
    int v[n+1][cap+1];//imp
    for(int i=0;i<=n;i++){
        for(int j=0;j<=cap;j++)
        {
            if(i==0||j==0)
                v[i][j]=0;
            else if(j<w[i-1])
                v[i][j]=v[i-1][j];
            else
                v[i][j]=max(v[i-1][j],(v[i-1][j-w[i-1]])+p[i-1]);	
            
        }
    }
    
    printf("the knapsack\n");
    for(int i=0;i<=n;i++){
        for(int j=0;j<=cap;j++){
            printf("%d\t",v[i][j]);
        }
        printf("\n");
    }
    printf("the items");
    for(int i=n,j=cap;j>0&&i>0;i--){
        if(v[i][j]!=v[i-1][j]){
            printf("%d\t",i);
            j-=w[i-1];
        }
    
    }
    return v[n][cap];
}


int main(){
    int i,j,n,cap;
    printf("enter the capacity\n");
    scanf("%d",&cap);
    printf("enter the no of items\n");
    scanf("%d",&n);
    int w[n],p[n];
    printf("weights\n");
    for(i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    printf("value\n");
    for(j=0;j<n;j++){
        scanf("%d",&p[j]);
    }
    printf("the solution%d",knap(cap,w,p,n));
}

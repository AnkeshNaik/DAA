#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void display(int a[],int n){
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void quick(int a[],int l,int r){
    if(l<r){
        int i,p,j,temp;
        p=l;i=l;j=r;
        while(i<j){
            while(a[i]<=a[p])i++;
            while(a[j]>a[p])j--;
            if(i<j){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[j];
        a[j]=a[p];
        a[p]=temp;
        quick(a,l,j-1);
        quick(a,j+1,r);

    }

}

void main(){
    int n,a[10000];
    clock_t start,end;
    double timetaken;
    printf("enter the number of goods\n");
    scanf("%d",&n);
    printf("enter the labels of goods to be sorted\n");
    
    for(int i=0;i<n;i++){
       a[i]=rand();
    }
    display(a,n);
    start =clock();
    quick(a,0,n-1);
    end =clock();
    printf("the sorted list\n");
    display(a,n);
    timetaken =(double)(end-start)/CLOCKS_PER_SEC;
    printf("the timetaken is %lf",timetaken);
    

}
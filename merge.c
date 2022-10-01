#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void display(int a[],int n){
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

void merge(int a[],int l,int m, int r){
    int i,j,k,n1,n2;
    n1=m-l+1;
    n2=r-m;
    int A[n1];
    int B[n2];
    for(i=0;i<n1;i++) 
       A[i]=a[l+i];
    for(j=0;j<n2;j++) 
       B[j]=a[m+1+j];//

    i=0,j=0,k=l;
    while(i<n1 && j<n2){//
        if(A[i]<=B[j]) {
            a[k]=A[i];
            i++;
        }
        else{
            a[k]=B[j];
            j++;
        }
        k++;
    }

    while(i<n1){//
        a[k]=A[i];
        i++;
        k++;
        
    }
    while(j<n2){//
        a[k]=B[j];
        j++;
        k++;
    }
}

void mergeSort(int a[],int l,int r){
    if(l<r){
        int m =l+(r-1)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
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
    mergeSort(a,0,n-1);
    end =clock();
    printf("the sorted list\n");
    display(a,n);
    timetaken =(double)(end-start)/CLOCKS_PER_SEC;
    printf("the timetaken is %lf",timetaken);
    

}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void display(int a[],int n){
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}



void selection(int a[],int n){
    int temp;
    for(int i=0;i<n;i++){
        int min =i;
        for(int j=i+1;j<n;j++){
            if(a[min]>a[j]) min=j;
        }/////////////////////////imp
                temp=a[i];
                a[i]=a[min];
                a[min]=temp;
                
            
        
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
    selection(a,n);
    end =clock();
    printf("the sorted list\n");
    display(a,n);
    timetaken =(double)(end-start)/CLOCKS_PER_SEC;
    printf("the timetaken is %lf",timetaken);
    

}
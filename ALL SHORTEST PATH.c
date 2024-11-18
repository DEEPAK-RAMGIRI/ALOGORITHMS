#include<stdio.h>
#include<stdlib.h>

struct interval{
    int start;
    int end;
};

int sort(struct interval t[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(t[j].end < t[j+1].end){
                struct interval s = t[j];
                t[j] = t[j+1];
                t[j+1] = s;
            }
        }
    }
}

int function1(struct interval t[],int n){
    
    int j=1,count=1;
    for(int i=1;i<n;i++){
        if(t[j].end <= t[i].start){
            count++;
            j=i;
        }
    }
    return count;
    
}

void main(){

    int n=5;
    struct interval t[n];
    
    for(int i=0;i<n;i++)
        scanf("%d",&t[i].start);
        
    for(int i=0;i<n;i++)
        scanf("%d",&t[i].end);
        
    printf("%d",function1(t,n));
    // 1 3 0 5 8
    // 4 5 6 7 9
}
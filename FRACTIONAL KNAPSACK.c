#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return (a > b) ? a:b;
}


int knapsack(int wt[],int pt[],int w, int p){
    int val[p+1][w+1];
    
    for(int i=0;i<=p;i++){
        for(int j=0;j<=w;j++){
            if(i == 0 || j ==0)
                val[i][j] = 0;
            else if(j >= wt[i-1])
                val[i][j] = max(pt[i-1]+val[i-1][j-wt[i-1]],val[i-1][j]);
            else
                val[i][j] = val[i-1][j];
        }
    }
    return val[p][w];
}

void main(){
    
    int w = 10,p = 4;
    int wt[] ={2,3,5,7};
    int pt[] = {1,4,5,7};
    printf("%d",knapsack(wt,pt,w,p));   
}
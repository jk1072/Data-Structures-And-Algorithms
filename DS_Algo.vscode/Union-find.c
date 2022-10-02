#include<stdio.h>
int Parent[10]={0,1,2,3,4,5,6,7,8,9};
int rank[10]={0,0,0,0,0,0,0,0,0};
int findParent(int x){
    // with path compression !!!
    if (x!=Parent[x]){
        Parent[x]=find(Parent[x]);
    }
    return Parent[x];

    // without path compression !!!
    // if(x==Parent[x]){
    //     return x;
    // }
    // return find(Parent[x]);
}
void isFriend(int x,int y){
    if(findParent(x)==findParent(y)){
        printf("They are friends");
    }
    else{
        printf("They are not friends");
    }
}

void makeFriend(int x,int y){
    // with time compression !!!
    int xRoot =findParent(x),yRoot=findParent(y);
    if(xRoot==yRoot){
        return;
    }
    if(rank[xRoot]>rank[yRoot]){
        Parent[xRoot]=yRoot;
    }
    else if(rank[xRoot]<rank[yRoot]){
        Parent[yRoot]=xRoot;
    }
    else
    {
        Parent[yRoot]=xRoot;
        rank[xRoot]=rank[xRoot]+1;
    }
    // without time compression !!!
    // int xRoot =find(x);
    // int yRoot =find(y);
    // if(xRoot==yRoot) return;
    // Parent[yRoot]=xRoot;-
}
int main(){
    makeFriend(1,2);
    makeFriend(2,3);
    makeFriend(4,7);
    isFriend(1,3);
    
    return 0;
}
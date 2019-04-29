#include <iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
const int maxn1=100,maxn2=140;  
struct node{  
    int from,to,w;  
}edge[maxn2];  
int n,m;  
int father[maxn1];  //two sets are different collections(wards), set[i]=0 means point in A,set[i]=-1 means point in B.  
bool cmp(node a,node b){  //由于要交换边排序，所以不能用链式前向星  
    return a.w<b.w;  
}  
int find(int a){  
    return father[a]==a?a:find(father[a]);  
}  
void kruskal(){  
    int i,j;  
    for(i=1;i<=n;i++){  
        father[i]=i;  
    }  
    int top=0;  //write down amount of chosen edges  
    for(i=0;i<m;i++){  
        if(top==n-1)break;  
        int q1=find(edge[i].from),q2=find(edge[i].to);  
        if(q1!=q2){  
            father[q1]=q2;  
            printf("(%d,%d) ",edge[i].from,edge[i].to);  
            top++;  
        }  
    }  
}  
void travel(){  
    for(int i=0;i<m;i++){  
        printf("%d %d %d\n",edge[i].from,edge[i].to,edge[i].w);  
    }  
}  
int main(int argc, char *argv[]) {  
    freopen("cin.txt","r",stdin);  
    freopen("cout.txt","w",stdout);  
    int i;  
    while(cin>>n>>m){  
        for(i=0;i<m;i++){  
            int a,b,c;  
            scanf("%d%d%d",&a,&b,&c);  
            edge[i].to=b;  
            edge[i].w=c;  
            edge[i].from=a;  
        }  
        sort(edge,edge+m,cmp);  
        travel();  
        kruskal();  
    }  
    return 0;  
} 
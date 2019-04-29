#include <iostream>  
#include<cstdio>   
#include<cstring>  
using namespace std;  
const int maxn1=100,maxn2=140,mmax=0x3f3f3f3f;  
struct node{  
    int to,w,next;  
}edge[maxn2];  
int head[maxn1],n,m; //n points, m edges.  
bool p[maxn1];  //p=1 means chosen, p=0 means not chosen   
int dist[maxn2]; //dist means shortest distance between tow points which one has been chosen but other one not    
void prim(){  
    int i,j;  
    for(i=head[1];i>0;i=edge[i].next){  
        dist[edge[i].to]=edge[i].w;  
    }  
    dist[1]=0;  p[1]=1;   
    cout<<"chosen: 1"<<endl;  
    for(i=1;i<n;i++){  
        int mmin=mmax,k=0;  
        for(j=1;j<=n;j++){  
            if(!p[j]&&mmin>dist[j]){  
                mmin=dist[j];  
                k=j;  
            }  
        }  
        if(k==0)return ;  
        p[k]=1;  
        cout<<"chosen: "<<k<<endl;  
        for(j=head[k];j>0;j=edge[j].next)//更新选中的点和未选中区域的最短距离。  
           if(!p[edge[j].to]&&edge[j].w<dist[edge[j].to]){  
               dist[edge[j].to]=edge[j].w;  
           }  
    }  
}  
void initaldis(){  
    for(int i=1;i<=n;i++)dist[i]=mmax;  
}  
void travel(){  
    for(int i=1;i<=n;i++){  
        for(int j=head[i];j>0;j=edge[j].next){  
            printf("%d %d %d\n",i,edge[j].to,edge[j].w);  
        }  
    }  
}  
int main(int argc, char *argv[]) {  
    freopen("cin.txt","r",stdin);  
    int i;  
    while(cin>>n>>m){  
        memset(head,0,sizeof(head));  
        memset(edge,0,sizeof(edge));  
        memset(p,0,sizeof(p));  
        initaldis();  
        for(i=1;i<=m;i++){  
            int a,b,c;  
            scanf("%d%d%d",&a,&b,&c);  
            edge[i].to=b;  
            edge[i].w=c;  
            edge[i].next=head[a];  
            head[a]=i; //head dex means start peak point, head val means edges.  
        }  
        travel();  
        prim();  
    }  
    return 0;  
} 
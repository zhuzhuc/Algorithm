#include<cstdio>
using namespace std;
int read(){//没啥用的快读
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
int a[15][15];//记录输出的数组
int pos[4][2]={0,1,1,0,0,-1,-1,0};//改变位置的数组
int main(){//主函数
    int n=read(),x=1,y=1,d=0;//初始化
    for(int i=1;i<=n*n;i++){//遍历
        a[x][y]=i;//赋值
        int tx=x+pos[d][0],ty=y+pos[d][1];//核心代码，解释见上
        if(tx<1||tx>n||ty<1||ty>n||a[tx][ty]) d=(d+1)%4;
        x+=pos[d][0],y+=pos[d][1];
    }
    for(int i=1;i<=n;i++){//输出
        for(int j=1;j<=n;j++) printf("%3d",a[i][j]);//注意%3d
        if(i<n) printf("\n");
    }
    return 0;//华丽结束
}


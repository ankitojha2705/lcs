
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
void lcs(int A[],int B[],int n,int m){
    int l[n+1][m+1];
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(i==0||j==0)
                l[i][j]=0;
            else if(A[i-1]==B[j-1])
                l[i][j]=1+l[i-1][j-1];
            else
                l[i][j]=max(l[i-1][j],l[i][j-1]);
        }
    }
    int index= l[n][m];
    int index1=index;
    i=n;
    j=m;
    int lcs[index+1];
    lcs[index]='\0';
    while(i>0&&j>0){
        if(A[i-1]==B[j-1]){
            lcs[index-1]=A[i-1];
            i--;j--;
            index--;
        }
        else if(l[i-1][j]>l[i][j-1])
            i--;
        else
            j--;
    }
    for(i=0;i<index1;i++)
        cout<<lcs[i]<<" ";
}
int main(){
    int n,m,i,A[1000],B[1000];
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>A[i];
    for(i=0;i<m;i++)
        cin>>B[i];
    lcs(A,B,n,m);
}

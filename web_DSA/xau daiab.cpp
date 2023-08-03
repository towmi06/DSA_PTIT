
#include <bits/stdc++.h>

using namespace std;
int n;
char a[15];
bool stop=false;
void sinh(){
    int i=n-1;
    while(i>=0&&a[i]=='B')
    i--;
    if (i<0){
        stop=true;
        return;
    }
    else{
       a[i]='B';
       for (int j=i+1; j<n; j++) a[j]='A';
    }
}
void in(){
    for (int j=0; j<n; j++) cout<<a[j];
    cout<<" ";

}


int main()
{
   int t;
   cin>>t;
   while(t--){
       cin>>n;
       for (int i=0; i<n; i++)
       a[i]='A';
       stop=false;
       while(!stop){
           in();
           sinh();
       }
       cout<<endl;
       }
     
   }


#include <iostream>
using namespace std;

int main(){
    int n, size;
    cin>>size>>n;
    int table[size];
    for(int i=0;i<size;i++) table[i]=-1;
    while(n--){
        int x; cin>>x;
        int h=x%size;
        while(table[h]!=-1) h=(h+1)%size;
        table[h]=x;
    }
    for(int i=0;i<size;i++) cout<<i<<" -> "<<table[i]<<endl;
}

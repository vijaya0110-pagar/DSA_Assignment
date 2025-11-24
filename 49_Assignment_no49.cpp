#include <iostream>
#include <list>
using namespace std;

int main(){
    int size,n;
    cin>>size>>n;
    list<int> table[size];
    while(n--){
        int x; cin>>x;
        table[x%size].push_back(x);
    }
    for(int i=0;i<size;i++){
        cout<<i<<" -> ";
        for(int x:table[i]) cout<<x<<" ";
        cout<<endl;
    }
}

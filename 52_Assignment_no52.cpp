#include <iostream>
#include <list>
using namespace std;

int main(){
    int size,n;
    cin>>size>>n;
    list<pair<int,string>> table[size];
    while(n--){
        int id; string name; cin>>id>>name;
        int h=id/size;
        table[h%size].push_back({id,name});
    }
    int search; cin>>search;
    int h=search/size%size;
    bool found=false;
    for(auto x: table[h]){
        if(x.first==search){ cout<<x.second<<endl; found=true; break;}
    }
    if(!found) cout<<"Not Found"<<endl;
}

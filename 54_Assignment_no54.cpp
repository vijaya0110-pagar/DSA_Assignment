#include <iostream>
using namespace std;

int midSquare(int x, int size){
    int sq = x*x;
    string s = to_string(sq);
    int mid = s.size()/2;
    int val = stoi(s.substr(mid,1));
    return val%size;
}

struct Employee{ int id; string name; };

int main(){
    int size,n; cin>>size>>n;
    Employee table[size];
    for(int i=0;i<size;i++) table[i].id=-1;
    while(n--){
        int id; string name; cin>>id>>name;
        int h=midSquare(id,size);
        while(table[h].id!=-1) h=(h+1)%size;
        table[h].id=id; table[h].name=name;
    }
    int search; cin>>search;
    int h=midSquare(search,size);
    while(table[h].id!=-1 && table[h].id!=search) h=(h+1)%size;
    if(table[h].id==search) cout<<table[h].name<<endl;
    else cout<<"Not Found"<<endl;
}

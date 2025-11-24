#include <iostream>
using namespace std;

struct Faculty{ int id; string name; };

int main(){
    int size,n;
    cin>>size>>n;
    Faculty table[size];
    for(int i=0;i<size;i++) table[i].id=-1;
    while(n--){
        int id; string name;
        cin>>id>>name;
        int h=id%size;
        while(table[h].id!=-1) h=(h+1)%size;
        table[h].id=id; table[h].name=name;
    }
    int search; cin>>search;
    int h=search%size;
    while(table[h].id!=-1 && table[h].id!=search) h=(h+1)%size;
    if(table[h].id==search) cout<<table[h].name<<endl;
    else cout<<"Not Found"<<endl;
}

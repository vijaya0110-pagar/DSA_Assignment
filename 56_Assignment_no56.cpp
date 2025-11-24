#include <iostream>
#include <list>
using namespace std;

struct Student{ int id; string name; string company; };

int main(){
    int size,n; cin>>size>>n;
    list<Student> table[size];
    while(n--){
        int id; string name,company;
        cin>>id>>name>>company;
        table[id%size].push_back({id,name,company});
    }
    int search; cin>>search;
    int h=search%size;
    bool found=false;
    for(auto s: table[h]){
        if(s.id==search){ cout<<s.name<<" "<<s.company<<endl; found=true; break;}
    }
    if(!found) cout<<"Not Found"<<endl;
}

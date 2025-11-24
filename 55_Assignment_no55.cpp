#include <iostream>
using namespace std;

struct Student{ int roll; string name; };

int main(){
    int size,n; cin>>size>>n;
    Student table[size];
    for(int i=0;i<size;i++) table[i].roll=-1;
    while(n--){
        int r; string name; cin>>r>>name;
        int h=r%size;
        while(table[h].roll!=-1) h=(h+1)%size;
        table[h].roll=r; table[h].name=name;
    }
    int search; cin>>search;
    int h=search%size;
    while(table[h].roll!=-1 && table[h].roll!=search) h=(h+1)%size;
    if(table[h].roll==search) cout<<table[h].name<<endl;
    else cout<<"Not Found"<<endl;
}

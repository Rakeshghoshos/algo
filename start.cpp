#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v;
    vector<int> tar;
    int n,x,t,c;
    cout<<"enter the number of elements"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<n;i++){
        c = count(v.begin(),v.end(),v[i]);
        if(c == 1){
            tar.push_back(v[i]);
        }
    }
    cout<<endl;
    for(auto i=0;i <tar.size();i++){
        cout<<tar[i]<<" ";
    }
    cout<<endl;
    return 0;
}
# include <bits/stdc++.h>
using namespace std;
int main(){
vector <int> vect ={1,2,4,8,9,12};
int k;
cin>>k;
auto e= vect.end();
auto ret = (k<vect.size())? e-k+1:vect.begin();
vector<int> rem;
for(auto i=ret;i<vect.end();i++)
{
    rem.push_back(*i);
}
for(int i=0;i<rem.size();i++)
{
    cout<< rem[i] << endl;
}



}
# include <bits/stdc++.h>
using namespace std;
int main(){
vector <int> vect={4,68,2,5,56,9,8,2,12};
int k;
cin>>k;
for(int i=0;i<k;i++)
{
    for(int j=0;j<k-1;j++)
    {
        if(vect[j]>vect[j+1])
        {
            int temp =vect[j];
            vect[j]=vect[j+1];
            vect[j+1]=temp;
        }
    }
}
for(int i=0;i<vect.size();i++)
{
    cout<< vect[i]<<endl;
}
}

#include<iostream>
#include<vector>
using namespace std;

//odd 奇数 even 偶数
void solution(vector<int>& data){

    int odd=0,even=data.size()-1;
    while(odd<even){
        while(odd<data.size()&&data[odd]%2==1)odd++;
        while(even>=0&&data[even]%2==0)even--;
        if(odd<even) swap(data[even--],data[odd++]);
    }
}


int main(){
    vector<int> testData ={2,4,3,6,2,3,1,2,4,5,7};
    solution(testData);
    for(auto d:testData){
        cout<<d<<" ";
    }
}
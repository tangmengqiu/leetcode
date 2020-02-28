#include <iostream>
#include<vector>
using namespace std;

template<class T>
class topk{
private:
    int k;
    int len;
    T* data;
    void AdjustDown(int start ,int len);
    void BuildHeap(int len);
public:
    topk(int k);
    ~topk();
    void AddItem(T in);
    vector<T> GetTopKItems();
};

template<class T>
topk<T>::topk(int _k){
    k=_k;
    len=0;
    data= new T[_k];
}

template<class T>
topk<T>::~topk(){
    if(data!=NULL)
        delete [] data;
}

template<class T>
vector<T> topk<T>::GetTopKItems(){
    vector<T> ret;
    for(int i=0;i<len;i++){
        ret.push_back(data[i]);
    }
    return ret;
}

template<class T>
void topk<T>::AddItem(T in){
    if(len<k){
        data[len++]=in;
        if(len==k){
            BuildHeap(len);
        }
    }else if(in> data[0]){
        data[0]=in;
        AdjustDown(0,k);
    }
}
template<class T>
void topk<T>::AdjustDown(int spos,int len){
    
    while(2*spos+1<len){
        int left =2*spos+1,right=2*spos+2;
        int minSubNode =left;
        if(right<len&&data[right]<data[left]) minSubNode=right;
        if(data[spos]>data[minSubNode]){
            swap(data[spos],data[minSubNode]);
            spos = minSubNode;
        }else break;
    }
    return;
}

template<class T>
void topk<T>::BuildHeap(int len){
    for(int i= len/2-1;i>=0;i--){
        AdjustDown(i,len);
    }
}


int main(){
    topk<int> TopK(8);
    for(int i=0;i<10;i++){
        TopK.AddItem(i);
    }
    vector<int> out =TopK.GetTopKItems();
    for(auto o: out){
        cout<< o<<" ";
    }
    cout<<endl;
    return 0;
}
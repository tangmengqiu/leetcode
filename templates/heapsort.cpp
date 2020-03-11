#include<iostream>
#include<vector>

using namespace std;


// 小根堆
template <typename T>
class m_heap{
public:
    m_heap(vector<T> _data,int l):data(_data),len(l){
        buildHeap();
    }
    void print(){
        while(len>0){
            cout<<data.front()<<" ";
            data[0]=data[len-1];
            len--;
            if(len)
                 adjustDown(0);
        }
        cout<<endl;
    }
private:
    vector<T> data;
    int len;
    void adjustDown(int root){
        while(2*root<len){
            int left =2*root+1;
            int minSubNode =left;
            int right =2*root+2;
            if(right<len&&data[right]<data[left]) minSubNode=right;
            if(data[root]>data[minSubNode]){
                swap(data[root],data[minSubNode]);
                root=minSubNode;
            }else break;
        }
    }
    void buildHeap(){
        int start = len/2-1;
        for(int i=start;i>=0;i--){
            adjustDown(i);
        }
    }

};

int main(){
    vector<int> testData = {3,2,1,5,3,2,6,8};
    m_heap<int> h(testData,testData.size());
    h.print();
    return 0;
}
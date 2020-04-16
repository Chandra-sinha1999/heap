#include <bits/stdc++.h>
using namespace std;
class minheap{
  int *a;
  int capicity;
  int heapsize;
  public:
  minheap(int cap){
      capicity = cap;
      heapsize = 0;
      a = new int[cap];
  }
  int parent(int i){
      return (i - 1)/2;
  }
  int left(int i) {
      return ((2*i) + 1);
  }
  int right(int i){
      return ((2*i) + 2);
  }
  int getmin(){
      return a[0];
  }
  void insert(int k){
      if(heapsize == capicity){
          cout<<"Index full";
          return;
      }
      heapsize++;
      int i = heapsize - 1;
      a[i] = k;
      // now fixing min heap property
      while(i != 0 && a[parent(i)] > a[i]){
          swap(a[parent(i)],a[i]);
          i = parent(i);
      }
  }
  void minheapify(int i){
      int l = left(i);
      int r = right(i);
      int small = i;
      if(l < heapsize && a[l] < a[small]) {
          small = l;
      }
      if(r < heapsize && a[r] < a[small]) {
          small = r;
      }
      if(small != i){
          swap(a[i],a[small]);
          minheapify(small);
      }
  }
  int extractmin(){
      if(heapsize == 1){
          heapsize--;
          return a[0];
      }
      int k = a[0];
      a[0] = a[heapsize - 1];
      heapsize--;
      minheapify(0);
      return k;
  }
  void decreasekey(int i, int val){
      //assuming it is smaller than it's original value
      a[i] = val; 
      while(i != 0 && a[parent(i) > a[i]]){
          swap(a[parent(i)],a[i]);
          i = parent(i);
      }
  }
  void deletekey(int i){
      decreasekey(i,INT_MIN);
      extractmin();
  }
};
int main() {
	minheap h(11); 
    h.insert(3); 
    h.insert(2); 
    h.deletekey(1); 
    h.insert(15); 
    h.insert(5); 
    h.insert(4); 
    h.insert(45); 
    cout << h.extractmin() << " "; 
    cout << h.getmin() << " "; 
    h.decreasekey(2, 1); 
    cout << h.getmin(); 
}

#include<iostream>
using namespace std;

void merge(int X[], int Y[], int N) {
  int i=N-1;
  int j=N-1;
  int k = 2*N-1;
  while ( k>=0 ) {
    if(X[i] > Y[j]){
      Y[k] = X[i];
      k--;
      i--;
    } else if(X[i] < Y[j]){
      Y[k] = Y[j];
      k--;
      j--;
    } else {
      Y[k] = Y[j];
      k--;
      j--;
      Y[k] = X[i];
      k--;
      i--;
    }
  }
}
// Merge 2 sorted arrays of length N and 2N(1st N valid elements)
// without using extra space
int main(){
   const int N=6;
   int X[N] = { 1,3, 5,7,9,11};
   int Y[2*N] = {2,3,6,8,10,12,0,0,0,0,0,0};
   int i;
   cout<<"X"<<endl;
   for(i=0; i< N ; i++){
     cout<<X[i]<<" ";
   }
   cout<<endl<<"Y"<<endl;
   for(i=0; i< 2*N ; i++){
     cout<<Y[i]<<" ";
   }
   cout<<endl<<"Merge"<<endl;
   merge(X,Y,N);
   for(i=0; i< 2*N ; i++){
     cout<<Y[i]<<" ";
   }
   cout<<endl;
   return 0;
}

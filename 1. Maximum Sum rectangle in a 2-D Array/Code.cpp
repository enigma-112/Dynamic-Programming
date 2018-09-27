/* Program to find Maximum sum rectangle in a 2D array (or matrix) .
 OR Given a 2D array, find the maximum sum subarray in it .
------------------------------------------------------------------------------ */



#include <bits/stdc++.h>
using namespace std;

// Kadane's Algorithm to get maximum sum subarray in 1-D array
int max_sum_rectangle_kadane(int *sum_arr,int r){
  int c_sum=0,flag=0,max=INT_MIN; 	//c_sum = current sum , max = max sum , flag is used to check if all the elements are negative or not. 
                                    // If flag = 0 , then all elements ar negative . 
  								
  for(int i=0;i<=r-1;i++){
    if(sum_arr[i]>=0)
      flag=1;
    c_sum=c_sum+sum_arr[i];
    if(c_sum<0)
      c_sum=0;
    if(c_sum>max)
      max=c_sum;
  }
  //Case when all the elements in the array are negative.
  //In this case just find the maximum no. and return it.
  if(flag==0){
      max=INT_MIN;
      for(int i=0;i<=r-1;i++){
        if(max<sum_arr[i])
          max=sum_arr[i];
      }
    }
  
  return max;
  
}
// Main Function
int main()
{
  int r,c,sum_arr[101]={0},input_arr[101][101],max_sum=INT_MIN; // input_arr is the given 2-D array.
  cin>>r>>c;				// r = row , c = column of the 2-D input array. 
  for(int i=0;i<=r-1;i++)
    for(int j=0;j<=c-1;j++)
      cin>>input_arr[i][j];
  
  int c1,c2;				// c1,c2 are the left and right columns of the partitioned 2-D array.
  for(c1=0;c1<=c-1;c1++){
    for(int i=0;i<=100;i++)
      sum_arr[i]=0;
    for(c2=c1;c2<=c-1;c2++){
      
      for(int i=0;i<=r-1;i++){
        sum_arr[i]=sum_arr[i]+input_arr[i][c2];
      }
      
     int max=max_sum_rectangle_kadane(sum_arr,r);
      if(max_sum<max)
        max_sum=max;
    }  
    
  }
  cout<<max_sum<<endl;
  
    return 0;
}

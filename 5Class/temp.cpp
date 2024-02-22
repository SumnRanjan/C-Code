// First Occurance of a number in a sorted array...
#include <iostream>
#include<algorithm>
using namespace std;

int FirstOccurance(int arr[], int n, int target)
{
    int s = 0;
    int e = n - 1;
    int mid = (s + e) / 2;
    // int mid = s + (e-s) / 2 -- no overflow -- Best Practise
    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == target)
        {
           
            if(arr[mid-1]!=target){

            ans = mid;
            return ans;
            }else{
                e=mid-1;
            }
        }
            else if (target > arr[mid])
            {
                s = mid + 1;
            }
            else if (target < arr[mid])
            {
                e = mid - 1;
            }

            // update mid
            mid = (s + e) / 2;
        }
        return ans;
    }

    int main()
    {
        int arr[] = {1, 4, 3, 8, 3, 32, 24, 1, 23, 8};
        int n = 10;
        int target = 8;
        std::sort(arr,arr+n);
        int ans = FirstOccurance(arr, n, target);
        cout<<ans;

        return 0;
    }

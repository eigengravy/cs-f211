#include <bits/stdc++.h>
using namespace std;

///////DO NOT CHANGE THIS///////////////////
void print(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
///////DO NOT CHANGE THIS///////////////////

int partition(vector<int> &arr, int start, int end){
    int pivot = arr[end];
    int i = start - 1;
    for(int j = start; j < end; j++){
        if (arr[j] <= pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
    return i+1;
}

void quicksort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int partitionIdx = partition(arr, start, end);
        print(arr);
        quicksort(arr, start, partitionIdx - 1);
        quicksort(arr, partitionIdx + 1, end);
    }
}

void solve(vector<int> arr)
{
    quicksort(arr, 0, arr.size() - 1);
}


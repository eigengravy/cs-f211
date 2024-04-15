// Write the O(lg n) time algorithm for Question 1 in this file. You can declare your own functions and classes.

int solve(DSA_Vector &v)
{

    int n = v.Size(), peak = -1, peakElem = INT_MIN;

    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int leftElem = v.GetElement(left);
        int rightElem = v.GetElement(right);
        int midElem = v.GetElement(mid);
        if (midElem > peakElem){
            peak = mid;
            peakElem = midElem;
        }
        if (leftElem >= midElem){
            right = mid - 1;
        } else if (rightElem <= midElem){
            left = mid + 1;
        } 
    }
    return peak;
}

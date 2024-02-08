#include <iostream>
#include <vector>

void printElements(std::vector<int> &array, int left, int right)
{
    for (int i = left; i <= right; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void merge(std::vector<int> &array, int left, int middle, int right)
{

    // Declare two vector objects for leftArray and rightArray
    std::vector<int> leftArray;
    std::vector<int> rightArray;

    for (auto l = left; l < middle + 1; l++)
    {
        leftArray.push_back(array[l]);
    }

    for (auto r = middle + 1; r <= right; r++)
    {
        rightArray.push_back(array[r]);
    }

    // Implement the merge procedure
    int i = 0, j = 0, k = left;

    while (i < leftArray.size() && j < rightArray.size())
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftArray.size())
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightArray.size())
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int> &array, int left, int right)
{
    if (left < right)
    {

        // Fill in the details so as to generate the correct output for each testcase
        int middle = (left + right) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);

        printElements(array, left, right); // Prints all the elements in the subproblem after the merge procedure completes
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> array(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }

    int size = array.size();

    mergeSort(array, 0, size - 1);

    return 0;
}

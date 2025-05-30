// Function prototypes
int binarySearch(int array[], int length, int searchValue);
int linearSearch(int array[], int length, int searchValue);

int main()
{
    int exampleArray[] = {1, 2, 3, 4, 5, 6, 7};
    int searchValue = 2;

    int result = binarySearch(exampleArray, 7, searchValue);

    if (result == 1)
    {
        printf("Successful search!\n");
    }
    else
    {
        printf("Unsuccessful search!\n");
    }

    return 0;
}

int binarySearch(int array[], int length, int searchValue)
{
    /**
     * index of the first value in the array
     * first index = 0
     * first value = 1
     */
    int leftIndex = 0;
    /**
     * represents the index of the last value in the array
     * last index = 6
     * last value = 7
     */
    int rightIndex = length - 1;

    // loop that runs as long as left index is less than, or equal to, the right index.
    while (leftIndex <= rightIndex)
    {
        /** 0+6/2 = 3 is the first index to check if the middle value (4) is equal to the target value 2 */
        int middleIndex = (leftIndex + rightIndex) / 2;

        if (array[middleIndex] == searchValue)
        {
            return 1;
        }
        else if (array[middleIndex] < searchValue)
        {
            leftIndex = middleIndex + 1;
        }
        else
        {
            rightIndex = middleIndex - 1;
        }
    }
    return -1;
}

// Function definition
int linearSearch(int array[], int length, int searchValue)
{
    int index;

    for (int index = 0; index < length; index++)
    {
        if (array[index] == searchValue)
        {
            return 1; // Found value
        }
    }
    return 0; // Not found after scanning all elements
}
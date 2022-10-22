// C++ code to implement priority-queue using array implementation of binary heap
#include <iostream>
using namespace std;
int H[50];
int size = -1;

// Function to return the index of the parent node of a given node
int parent(int i)
{
    return (i - 1) / 2;
}

// Function to return the index of the left child of the given node
int leftChild(int i)
{
    return ((2 * i) + 1);
}

// Function to return the index of the right child of the given node
int rightChild(int i)
{
    return ((2 * i) + 2);
}

// Function to shift up the node in order to maintain the heap property
void shiftUp(int i)
{
    while (i > 0 && H[parent(i)] < H[i])
    {
        // Swap parent and current node
        swap(H[parent(i)], H[i]);

        // Update i to parent of i
        i = parent(i);
    }
}

// Function to shift down the node in order to maintain the heap property
void shiftDown(int i)
{
    int maxIndex = i;
    // Left Child
    int l = leftChild(i);
    if (l <= size && H[l] > H[maxIndex])
    {
        maxIndex = l;
    }
    // Right Child
    int r = rightChild(i);

    if (r <= size && H[r] > H[maxIndex])
    {
        maxIndex = r;
    }
    // If i not same as maxIndex
    if (i != maxIndex)
    {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

// Function to insert a new element in the Binary Heap
void insert(int p)
{
    size = size + 1;
    H[size] = p;

    // Shift Up to maintain heap property
    shiftUp(size);
}

// Function to extract the element with
// maximum priority
int extractMax()
{
    int result = H[0];
    // Replace the value at the root with the last leaf
    H[0] = H[size];
    size = size - 1;

    // Shift down the replaced element to maintain the heap property
    shiftDown(0);
    return result;
}

// Function to change the priority of an element
void changePriority(int i, int p)
{
    int oldp = H[i];
    H[i] = p;

    if (p > oldp)
    {
        shiftUp(i);
    }
    else
    {
        shiftDown(i);
    }
}

// Function to get value of the current maximum element
int getMax()
{
    return H[0];
}

// Function to remove the element located at given index
void remove(int i)
{
    H[i] = getMax() + 1;

    // Shift the node to the root of the heap
    shiftUp(i);
    // Extract the node
    extractMax();
}

int main()
{

    insert(444);
    insert(3);
    insert(1);
    insert(12);
    insert(331);
    insert(100);
    insert(11);
    insert(13);
    insert(71);

    int i = 0;

    // Priority queue before extracting max
    cout << "Priority Queue : ";
    while (i <= size)
    {
        cout << H[i] << " ";
        i++;
    }

    cout << "\n";

    // Node with maximum priority
    cout << "Node with maximum priority : "
         << extractMax() << "\n";

    // Priority queue after extracting max
    cout << "Priority queue after "
         << "extracting maximum : ";
    int j = 0;
    while (j <= size)
    {
        cout << H[j] << " ";
        j++;
    }

    cout << "\n";

    // Change the priority of element
    // present at index 2 to 49
    changePriority(2, 49);
    cout << "Priority queue after "
         << "priority change : ";
    int k = 0;
    while (k <= size)
    {
        cout << H[k] << " ";
        k++;
    }

    cout << "\n";

    // Remove element at index 3
    remove(3);
    cout << "Priority queue after "
         << "removing the element : ";
    int l = 0;
    while (l <= size)
    {
        cout << H[l] << " ";
        l++;
    }
    return 0;
}

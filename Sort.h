///Kenny R. - Graphical Sorting Algorithm - Ms. Cullum
#include <iostream>
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

class Sort
{
public:

    Sort();

    //Prints unSortedArray
    int printArray();

    //Figures out the numbers needed to make any number fit into the given window
    void windowSize();

    //Generates "random" numbers
    int randomNumberGen(int numLength, int numRange);

    //Grabs numbers from a text file
    int fileSteal();

    //Gets the number of comparisons
    int getNumComp();

    //Gets the number of moves
    int getNumMove();

    //Sets the Array from main equal to the unSortedArray
    int getArray(vector<int> &Array);

    //Gets high
    int getHigh();

    //Gets the width
    float getWidth();

    //Gets the height
    float getHeight();

    //Sets high
    void setHigh();

    //Sets unSortedArray equal to the Array from main
    int setArray(vector<int> &Array);



    //Main part of quicksort
    void Quicksort(vector<int> &v, int start, int end);

    //Pivots and partitions
    int Partition(vector<int> &v, int start, int end);

    //Selection sort
    void selectionSort();

    //Insertion Sort
    void insertionSort();

private:
    vector<int> unSortedArray;
    float width;
    float height;
    int low;
    int high;
    int mRow;
    int numComp;
    int numMove;
};

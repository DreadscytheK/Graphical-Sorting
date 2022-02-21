///Kenny R. - Graphical Sorting Algorithm - Ms. Cullum
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "Sort.h"

using namespace std;

Sort::Sort()
{
    mRow = 0;
    low = 0;
    numComp = 0;
    numMove = 0;
}

void Sort::setHigh()
{
    //Sets high equal to the size of the array minus one
    high = unSortedArray.size()-1;
}

int Sort::getNumMove()
{
    return numMove;
}

int Sort::getNumComp()
{
    return numComp;
}

float Sort::getWidth()
{
    return width;
}

float Sort::getHeight()
{
    return height;
}

int Sort::getHigh()
{
    return high;
}

int Sort::setArray(vector<int> &Array)
{
    unSortedArray = Array;
}

int Sort::getArray(vector<int> &Array)
{
    Array = unSortedArray;
}

int Sort::Partition(vector<int> &Array, int start, int end)
{
    //Declaring variables
    int pivot = end;
    int j = start;

    //For statements activates and runs as for the whole length of the array
    for(int i=start; i<end; ++i) {
        //If statement activates if the v[pivot] is larger than v[i]
        if(Array[i]<Array[pivot]) {

            //Stores v[i] in the temp variable
            int temp = Array[i];

            //Makes v[i] equal to v[j]
            Array[i] = Array[j];

            //Makes the slot look like the background then makes it look like the new rectangle
            al_draw_filled_rectangle(i*width,0,i*width+width,500, al_map_rgb(255,255,255));
            al_draw_filled_rectangle(i*width,0,i*width+width,500-(Array[j]*height), al_map_rgb(0,0,0));

            //Makes v[j] equal to the temp variable
            Array[j] = temp;

            //Makes the slot look like the background then makes it look like the new rectangle
            al_draw_filled_rectangle(i*width,0,i*width+width,500, al_map_rgb(255,255,255));
            al_draw_filled_rectangle(i*width,0,i*width+width,500-(temp*height), al_map_rgb(0,0,0));

            numMove++;

            ++j;
        }
        numComp++;
    }

    //Stores v[j] in the temp variable
    int temp = Array[j];

    //Makes v[j] equal to v[pivot]
    Array[j] = Array[pivot];

    //Makes the slot look like the background then makes it look like the new rectangle
    al_draw_filled_rectangle(j*width,0,j*width+width,500, al_map_rgb(255,255,255));
    al_draw_filled_rectangle(j*width,0,j*width+width,500-(Array[pivot]*height), al_map_rgb(0,0,0));

    //Makes v[pivot] equal to the temp variable
    Array[pivot] = temp;

    //Makes the slot look like the background then makes it look like the new rectangle
    al_draw_filled_rectangle(j*width,0,j*width+width,500, al_map_rgb(255,255,255));
    al_draw_filled_rectangle(j*width,0,j*width+width,500-(temp*height), al_map_rgb(0,0,0));

    numMove++;

    return j;

}

void Sort::Quicksort(vector<int> &Array, int start, int end )
{
    //If statement checks if there is more than one number in the given array
    if(start<end) {

        //Finds the pivot
        int p = Partition(Array,start,end);

        //Clears the screen
        al_clear_to_color(al_map_rgb(255,255,255));

        //For statement runs through each number in the array and prints it to the allegro window
        for (int j=0; j<Array.size(); j++) {
            al_draw_filled_rectangle(j*width,0,j*width+width,500-(Array[j]*height), al_map_rgb(0,0,0));
        }

        //Runs through the function again
        Quicksort(Array,start,p-1);
        Quicksort(Array,p+1,end);

            al_flip_display();

    }
}

///Decides the numbers for the allegro window
void Sort::windowSize()
{
    //This section decides the factor by which the numbers in the allegro window later will be multiplied by, to fill the space given.
    //It does this for the width here
    float w = high;
    width = 1000/w;

    //This also figures out the factor by which the numbers will be multiplied, but for the height
    float temp = unSortedArray[0];

    //For loop runs through every number in the array to figure out the biggest one
    for(int i=0; i<high; i++) {
        if(unSortedArray[i]>temp) {
            temp = unSortedArray[i];
        }
    }

    height = 500/temp;
}

///This function uses insertion sort to sort a given array
void Sort::insertionSort()
{
    //Declaring variables
    int j, temp;

    //For statement runs through each number in the array and prints it to the allegro window
    for (int j=0; j<unSortedArray.size(); j++) {
        al_draw_filled_rectangle(j*width,0,j*width+width,500-(unSortedArray[j]*height), al_map_rgb(0,0,0));
    }

    //Sends the allegro to the window
    al_flip_display();

    //For statement activates and does not stop until it reaches the last number in the array
    for(int i=0; i<unSortedArray.size(); i++) {
        //Sets the temp variable equal to the current entry in the array
        temp = unSortedArray[i];

        //Sets j equal to i as to not mess with the for loop
        j = i;

        //While loop backtracks until it finds a number smaller than the current number
        while(temp<unSortedArray[j-1] && j>0) {

            //If it does find one, it swaps them
            unSortedArray[j]=unSortedArray[j-1];
            j--;

            //Adds one to this every time the while statement runs
            numComp++;

            //Makes the slot look like the background then makes it look like the new rectangle
            al_draw_filled_rectangle(j*width,0,j*width+width,500, al_map_rgb(255,255,255));
            al_draw_filled_rectangle(j*width,0,j*width+width,500-(unSortedArray[j-1]*height), al_map_rgb(0,0,0));


        }

        al_flip_display();

        //Sets current entry to temp
        unSortedArray[j]=temp;

        //Adds one to this every time a variable is swapped
        numMove++;
    }

    //Sends the allegro to the window
    al_flip_display();
}

///This function uses selection sort to sort a given array
void Sort::selectionSort()
{
    //Declaring variables
    size_t min = 0;

    //For loop activates and does not stop until i equals the size of the vector minus 1
    for (size_t i=0; i<unSortedArray.size()-1; i++) {
        min = i;

        //For loop activates and does not stop until i equals the size of the vector
        for(size_t j=i+1; j<unSortedArray.size(); j++) {

            //If statement activates if the current unSortedArray[j] is less than the variable min, which is just the current index of outer for loop
            //If it is smaller, it assigns j to min, this basically goes through every number after i and finds the smallest one
            if (unSortedArray[j]<unSortedArray[min]) {
                min = j;
            }
            //Adds 1 to this each time there's a comparison
            numComp++;
        }

        //Stores the unSortedArray[i] in a temporary variable t
        int t = unSortedArray[i];

        //Swaps i for min
        unSortedArray[i] = unSortedArray[min];

        //Makes the slot look like the background then makes it look like the new rectangle
        al_draw_filled_rectangle(i*width,0,i*width+width,500, al_map_rgb(255,255,255));
        al_draw_filled_rectangle(i*width,0,i*width+width,500-(unSortedArray[min]*height), al_map_rgb(0,0,0));

        //Swaps min for i
        unSortedArray[min] = t;

        //Adds 1 each time numbers are swapped
        numMove++;

        //Makes the slot look like the background then makes it look like the new rectangle
        al_draw_filled_rectangle(min*width,0,min*width+width,500, al_map_rgb(255,255,255));
        al_draw_filled_rectangle(min*width,0,min*width+width,500-(t*height), al_map_rgb(0,0,0));
        al_flip_display();
    }

    //Resets the window colour
    al_clear_to_color(al_map_rgb(255,255,255));

    //For statement runs through each number in the array and prints it to the allegro window
    for (int j=0; j<unSortedArray.size(); j++) {
        al_draw_filled_rectangle(j*width,0,j*width+width,500-(unSortedArray[j]*height), al_map_rgb(30,218,6));
    }

    //Sends the allegro to the window
    al_flip_display();

}

int Sort::printArray()
{
    for (int i=0; i<mRow; i++) {
        cout << unSortedArray[i] << endl;
    }
}

int Sort::fileSteal()
{
    //Declaring variables
    int endOfFileCheck = 0;
    string row;

    //Opens RandomNumbers.txt, putting its contents into an array and closing it
    fstream RandomNumbers;
    RandomNumbers.open ("RandomNumbers.txt");

    //Error checking
    if (RandomNumbers.fail()) {
        cout << "Error with RandomNumbers.txt";
        RandomNumbers.clear( );
    }

    //Find out the size
    while (!RandomNumbers.eof()) {
        RandomNumbers >> row;
        mRow++;
    }

    //Go to beginning of file
    RandomNumbers.clear(); //Clear bad state after eof
    RandomNumbers.seekg( 0 );

    //Resize Array
    unSortedArray.resize(mRow);

    for (int i=0; i<mRow; i++) {
        RandomNumbers >> unSortedArray[i];
    }

    RandomNumbers.close();
}

int Sort::randomNumberGen(int numLength, int numRange)
{
    //Declaring variables
    int endOfFileCheck = 0;
    string row;

    //Makes things random
    srand (time(NULL));

    //Opens RandomNumbers.txt and closes it, this deletes all numbers that were in there
    fstream RandomNumbersDelete;
    RandomNumbersDelete.open ("RandomNumbers.txt", ofstream::out | ofstream::trunc);

    RandomNumbersDelete.close();

    endOfFileCheck = 0;

    //Opens RandomNumbers.txt, putting its contents into an array and closing it
    fstream RandomNumbers;
    RandomNumbers.open ("RandomNumbers.txt");

    if (RandomNumbers.fail()) {
        cout << "Error with RandomNumbers.txt";
        RandomNumbers.clear();
    }

    for (int i=0; i<numLength; i++) {
        RandomNumbers << rand() % numRange + 1;
        RandomNumbers << endl;
    }

    RandomNumbers.close();
}

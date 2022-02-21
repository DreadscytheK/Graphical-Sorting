///Kenny R. - Graphical Sorting Algorithm - Ms. Cullum
//This program sorts given numbers or its own number using different sorting methods and it displays the sorting as it happens
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "Sort.h"

using namespace std;

int main()
{
    //Declaring variables
    vector<int> Array;
    string sortingMethod = " ";
    string ranNumChoice = " ";
    int ranNumRange = 100;
    int ranNumLength = 200;

    Sort sort1;

    //Explains the program to the user
    cout << "Hello and welcome to my sorting program!\nThis program can use (i)nsertion sort, (s)election sort or (q)uick sort\n";

    //While statements exits if the user enters i, s or q
    while(sortingMethod.compare("i")!=0&&sortingMethod.compare("s")!=0&&sortingMethod.compare("q")!=0)
    {
        cout << "Pick a sorting method (i/s/q) ";
        cin >> sortingMethod;
    }

    //While statements exits if the user enters i, s or q

    cout << "Would you like the program to make random numbers? (y/n) ";
    cin >> ranNumChoice;

    if(ranNumChoice.compare("y")==0)
    {
        cout << "What do you want the length of the array to be? (enter a positive number) ";
        cin >> ranNumLength;
        cout << "What do you want the range of those numbers to be? (enter a positive number) ";
        cin >> ranNumRange;

        sort1.randomNumberGen(ranNumLength-1, ranNumRange);
    }


    //These next sort1 methods set up the screen size and numbers
    sort1.fileSteal();

    sort1.setHigh();

    sort1.windowSize();

    //This sets the size of the array to be equal to the array from the Sort class
    Array.resize(sort1.getHigh());

    //This makes Array have the same numbers as the array from the Sort class
    sort1.getArray(Array);

    //Initializes libraries that are used
    al_init();
    al_init_image_addon();
    al_init_primitives_addon();

    //Creates display
    ALLEGRO_DISPLAY *display1 = nullptr;
    display1 = al_create_display(1000, 500);
    al_clear_to_color(al_map_rgb(255,255,255));

    //Sets window title
    al_set_window_title(display1, "Sorting Visualizer");

    //For statement runs through each number in the array and prints it to the allegro window
    for (int j=0; j<Array.size(); j++) {
        al_draw_filled_rectangle(j*sort1.getWidth(),0,j*sort1.getWidth()+sort1.getWidth(),500-(Array[j]*sort1.getHeight()), al_map_rgb(0,0,0));
    }

    al_flip_display();

    //If statements run a sorting method depending on which one was chosen at the start
    if(sortingMethod.compare("i")==0)
    {
        //Starts a timer
        const clock_t begin_time = clock();

        sort1.insertionSort();

        //This prints out the time up to now, the number of moves and the number of comparisons
        cout << "This took " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << " seconds to run, ";
        cout << "there were " << sort1.getNumComp() << " comparisons done and there were " << sort1.getNumMove() << " moves" << endl;

        //This makes Array have the same numbers as the array from the Sort class
        sort1.getArray(Array);
    }
    else if(sortingMethod.compare("s")==0)
    {
        //Starts a timer
        const clock_t begin_time = clock();

        sort1.selectionSort();

        //This prints out the time up to now, the number of moves and the number of comparisons
        cout << "This took " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << " seconds to run, ";
        cout << "there were " << sort1.getNumComp() << " comparisons done and there were " << sort1.getNumMove() << " moves" << endl;

        //This makes Array have the same numbers as the array from the Sort class
        sort1.getArray(Array);

    }
    else
    {
        //Starts a timer
        const clock_t begin_time = clock();

        sort1.Quicksort(Array, 0, Array.size());

        //This prints out the time up to now, the number of moves and the number of comparisons
        cout << "This took " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << " seconds to run, ";
        cout << "there were " << sort1.getNumComp() << " comparisons done and there were " << sort1.getNumMove() << " moves" << endl;
    }



    //Wipes the screen
    al_clear_to_color(al_map_rgb(255,255,255));

    //For statement runs through each number in the array and prints it to the allegro window
    for (int j=0; j<Array.size(); j++) {
        al_draw_filled_rectangle(j*sort1.getWidth(),0,j*sort1.getWidth()+sort1.getWidth(),500-(Array[j]*sort1.getHeight()), al_map_rgb(30,218,6));
    }

    //This copies the values of the Array here to the array in the Sort class
    sort1.setArray(Array);

    //sort1.printArray();

    al_flip_display();

    al_rest(2000);
    al_destroy_display(display1);

    return 0;
}

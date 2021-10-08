//Name: Aakarsh Koshti
//Net ID: Axk190128
//importing necessary headers
#include <iostream>
#include<fstream>
#include <string>
#include <cstring>
using namespace std;
//declaring methods
int sectorCheck(char *arr, string puzNum);
int rowCheck(char *arr, string puzNum);
int columnCheck(char *arr, string puzNum);
int main()
{
    //declaring variables to be used
    string name = "";
    string whichPuzzle = "";
    string line = "";
    int lineCounter = 0;
    char puzzle[81];
    //set the char array "ouzzle" to be only blank chars not random garbage characters
    memset(puzzle, 0, sizeof(puzzle));
    int sectorAnswer = 0;
    int rowAnswer = 0;
    int columnAnswer = 0;
    //get file name and read chars from file
    cout << "Enter file name >> ";
    cin >> name;
    ifstream infile(name, ios::in | ios::binary);
    if(infile)
    {
        while (infile.good())
        {
            getline(infile, line);
            //make sure puzzle number is not read as part of suduko numbers
            if(lineCounter % 11 == 0)
            {
                //set puzzle number to variable named "whichPuzle"
                whichPuzzle = line;
            }
            else
            {
                //adding line to char array puzzle
                strncat(puzzle, line.c_str(), 9);
            }
            //when puzzle char array is filled with 9 lines of file then run methods for validation
            if(lineCounter >= 8 && (lineCounter - 9) % 11 == 0)
            {
                //running methods
                sectorAnswer = sectorCheck(puzzle, whichPuzzle);
                cout << endl;
                rowAnswer = rowCheck(puzzle, whichPuzzle);
                cout << endl;
                columnAnswer = columnCheck(puzzle, whichPuzzle);
                if(sectorAnswer == 2 && rowAnswer == 2 && columnAnswer == 2)
                {
                    cout << "valid" << endl;
                }
                if(sectorAnswer == 3 && rowAnswer == 3 && columnAnswer == 3)
                {
                    cout << "solved" << endl;
                }
                //reset char array back to empty chars instead of garbage after validation to get new puzzle
                memset(puzzle, 0, sizeof(puzzle));
            }
            lineCounter++;
            cout << endl;
        }
    }
    //make sure file opens properly
    else
    {
        cout << "File did not open properly";
    }
    infile.close();
}

int sectorCheck(char *arr, string puzNum)
{
    cout << puzNum << '\t';
    //find length of pointer char array "arr" and set it equal to size
    int size = strlen(arr);
    //declare and initialize new char pointer and initialize its size to variable named "size"
    char *newarr;
    newarr = new char[size];
    //declare and initialize variables to be used in this function and big checker keeps track of number of line of suduko we have read
    int bigChecker = 1;
    int valid = 0;
    int error = 0;
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    int counter4 = 0;
    int counter5 = 0;
    int counter6 = 0;
    int counter7 = 0;
    int counter8 = 0;
    int counter9 = 0;
    //following 4 for loops go through all sectors of suduko
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                for(int m = 0; m < 3; m++)
                {
                    //make sure newarr pointer is at address of the beginning of arr pointer
                    newarr = arr;
                    //set newarr pointer to char that we want to point to and read
                    newarr += (9*(3*i + k) + (3*j + m));
                    //all following ifs check if the current char is a number 1-9 and iterates respective counter variable for each number found
                    //if any counter is found more than once in a row then error will equal that respective number
                    if (*newarr == '1')
                    {
                        counter1++;
                    }
                    if (counter1 > 1)
                    {
                        error = 1;
                    }

                    if (*newarr == '2')
                    {
                        counter2++;
                    }
                    if (counter2 > 1)
                    {
                        error = 2;
                    }

                    if (*newarr == '3')
                    {
                        counter3++;
                    }
                    if (counter3 > 1)
                    {
                        error = 3;
                    }

                    if (*newarr == '4')
                    {
                        counter4++;
                    }
                    if (counter4 > 1)
                    {
                        error = 4;
                    }

                    if (*newarr == '5')
                    {
                        counter5++;
                    }
                    if (counter5 > 1)
                    {
                        error = 5;
                    }

                    if (*newarr == '6')
                    {
                        counter6++;
                    }
                    if (counter6 > 1)
                    {
                        error = 6;
                    }

                    if (*newarr == '7')
                    {
                        counter7++;
                    }
                    if (counter7 > 1)
                    {
                        error = 7;
                    }

                    if (*newarr == '8')
                    {
                        counter8++;
                    }
                    if (counter8 > 1)
                    {
                        error = 8;
                    }

                    if (*newarr == '9')
                    {
                        counter9++;
                    }
                    if (counter9 > 1)
                    {
                        error = 9;
                    }
                }
            }
            //if any counter is 0 there must have been a blank
            if(counter1 == 0 || counter2 == 0 || counter3 == 0 || counter4 == 0 || counter5 == 0 || counter6 == 0 || counter7 == 0 || counter8 == 0 || counter9 == 0)
            {
                valid = 1;
            }
            //if any counter is more than 1 there must have been an error
            if(counter1 > 1 || counter2 > 1 || counter3 > 1 || counter4 > 1 || counter5 > 1 || counter6 > 1 || counter7 > 1 || counter8 > 1 || counter9 > 1)
            {
                cout << "invalid" << '\t';
                if(((3*i)+j+1)== 1)
                {
                    cout << "upper left has multiple " << error << "s" << endl;
                }
                if(((3*i)+j+1)== 2)
                {
                    cout << "upper has multiple " << error << "s" << endl;
                }
                if(((3*i)+j+1)== 3)
                {
                    cout << "upper right has multiple " << error << "s" << endl;
                }
                if(((3*i)+j+1)== 4)
                {
                    cout << "left has multiple " << error << "s" << endl;
                }
                if(((3*i)+j+1)== 5)
                {
                    cout << "middle has multiple " << error << "s" << endl;
                }
                if(((3*i)+j+1)== 6)
                {
                    cout << "right has multiple " << error << "s" << endl;
                }
                if(((3*i)+j+1)== 7)
                {
                    cout << "lower left has multiple " << error << "s" << endl;
                }
                if(((3*i)+j+1)== 8)
                {
                    cout << "bottom has multiple " << error << "s" << endl;
                }
                if(((3*i)+j+1)== 9)
                {
                    cout << "lower right has multiple " << error << "s" << endl;
                }
                return 1;
            }
            //if bigChecker is 9, function went through all lines of sudoku so either valid or solved
            if(bigChecker == 9 && valid == 1)
            {
                return 2;
            }
            if (bigChecker == 9 && valid == 0)
            {
                return 3;
            }
            bigChecker++;
            //set counters back to 0
            counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0, counter5 = 0, counter6 = 0, counter7 = 0, counter8 = 0, counter9 = 0;
        }
    }
}

//same as sector check except just different iteration through sudoku
int rowCheck(char *arr, string puzNum)
{
    cout << puzNum << '\t';
    int size = strlen(arr);
    char *newarr;
    newarr = new char[size];
    int bigChecker = 1;
    int valid = 0;
    int error = 0;
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    int counter4 = 0;
    int counter5 = 0;
    int counter6 = 0;
    int counter7 = 0;
    int counter8 = 0;
    int counter9 = 0;
    for(int i = 0; i < 9; i++)
    {
        for (int j = 9*i; j < ((i*9) + 9); j++)
        {
            newarr = arr;
            newarr += j;
            if (*newarr == '1')
            {
                counter1++;
            }
            if (counter1 > 1)
            {
                error = 1;
            }

            if (*newarr == '2')
            {
                counter2++;
            }
            if (counter2 > 1)
            {
                error = 2;
            }

            if (*newarr == '3')
            {
                counter3++;
            }
            if (counter3 > 1)
            {
                error = 3;
            }

            if (*newarr == '4')
            {
                counter4++;
            }
            if (counter4 > 1)
            {
                error = 4;
            }

            if (*newarr == '5')
            {
                counter5++;
            }
            if (counter5 > 1)
            {
                error = 5;
            }
            if (*newarr == '6')
            {
                counter6++;
            }
            if (counter6 > 1)
            {
                error = 6;
            }

            if (*newarr == '7')
            {
                counter7++;
            }
            if (counter7 > 1)
            {
                error = 7;
            }

            if (*newarr == '8')
            {
                counter8++;
            }
            if (counter8 > 1)
            {
                error = 8;
            }

            if (*newarr == '9')
            {
                counter9++;
            }
            if (counter9 > 1)
            {
                error = 9;
            }
        }
        if(counter1 == 0 || counter2 == 0 || counter3 == 0 || counter4 == 0 || counter5 == 0 || counter6 == 0 || counter7 == 0 || counter8 == 0 || counter9 == 0)
        {
            valid = 1;
        }
        if(counter1 > 1 || counter2 > 1 || counter3 > 1 || counter4 > 1 || counter5 > 1 || counter6 > 1 || counter7 > 1 || counter8 > 1 || counter9 > 1)
        {
            cout << "invalid" << '\t';
            cout << "row " << (i+1) << " has multiple " << error << "s" << endl;
            return 1;
        }
        if(bigChecker == 9 && valid == 1)
        {
            return 2;
        }
        if (bigChecker == 9 && valid == 0)
        {
            return 3;
        }
        counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0, counter5 = 0, counter6 = 0, counter7 = 0, counter8 = 0, counter9 = 0;
        bigChecker++;
    }
}

//same as sector check except just different iteration through sudoku
int columnCheck(char *arr, string puzNum)
{
    cout << puzNum << '\t';
    int size = strlen(arr);
    char *newarr;
    newarr = new char[size];
    int bigChecker = 0;
    int valid = 0;
    int error = 0;
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    int counter4 = 0;
    int counter5 = 0;
    int counter6 = 0;
    int counter7 = 0;
    int counter8 = 0;
    int counter9 = 0;
    for(int i = 0; i < 9; i++)
    {
        for (int j = i; j <= (81 - (9-i)); j = j+9)
        {
            newarr = arr;
            newarr += j;
            if (*newarr == '1')
            {
                counter1++;
            }
            if (counter1 > 1)
            {
                error = 1;
            }

            if (*newarr == '2')
            {
                counter2++;
            }
            if (counter2 > 1)
            {
                error = 2;
            }

            if (*newarr == '3')
            {
                counter3++;
            }
            if (counter3 > 1)
            {
                error = 3;
            }

            if (*newarr == '4')
            {
                counter4++;
            }
            if (counter4 > 1)
            {
                error = 4;
            }

            if (*newarr == '5')
            {
                counter5++;
            }
            if (counter5 > 1)
            {
                error = 5;
            }
            if (*newarr == '6')
            {
                counter6++;
            }
            if (counter6 > 1)
            {
                error = 6;
            }

            if (*newarr == '7')
            {
                counter7++;
            }
            if (counter7 > 1)
            {
                error = 7;
            }

            if (*newarr == '8')
            {
                counter8++;
            }
            if (counter8 > 1)
            {
                error = 8;
            }

            if (*newarr == '9')
            {
                counter9++;
            }
            if (counter9 > 1)
            {
                error = 9;
            }
        }
        bigChecker++;
        if(counter1 == 0 || counter2 == 0 || counter3 == 0 || counter4 == 0 || counter5 == 0 || counter6 == 0 || counter7 == 0 || counter8 == 0 || counter9 == 0)
        {
            valid = 1;
        }
        if(counter1 > 1 || counter2 > 1 || counter3 > 1 || counter4 > 1 || counter5 > 1 || counter6 > 1 || counter7 > 1 || counter8 > 1 || counter9 > 1)
        {
            cout << "invalid" << '\t';
            cout << "column " << (i+1) << " has multiple " << error << "s" << endl;
            return 1;
        }
        if(bigChecker == 9 && valid == 1)
        {
            return 2;
        }
        if (bigChecker == 9 && valid == 0)
        {
            return 3;
        }
        counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0, counter5 = 0, counter6 = 0, counter7 = 0, counter8 = 0, counter9 = 0;
    }
}

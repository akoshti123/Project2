//Aakarsh Koshti
//Axk190128
#include <iostream>
#include<fstream>
#include <string>
#include <cstring>
using namespace std;
int sectorCheck(int arr[], int puzNum);
int rowCheck(int arr[], int puzNum);
int columnCheck(int arr[], int puzNum);
//in order to show multiple error per fucntion chage int to void and get rid of return 1 statements
int main()
{
    string name = "";
    string whichPuzzle = "";
    string line = "";
    int lineCounter = 0;
    char puzzle[82];

    cout << "Enter file name >> ";
    cin >> name;
    ifstream infile(name, ios::in | ios::binary);
    if(infile)
    {
        while (infile.good())
        {
            getline(infile, line);
            if(lineCounter % 11 == 0)
            {
                whichPuzzle = line;
            }
            else
            {
                strncat(puzzle, line.c_str(), 9);
            }
            if(lineCounter >= 8 && (lineCounter - 9) % 11 == 0)
            {
                //run methods with parameters puzzle as the char array and whichPuzzle as the puznum string
                //Clear char array puzzle and
                memset(puzzle, 0, sizeof(puzzle));
            }
            lineCounter++;
        }
    }
    else
    {
        cout << "File did not open properly";
    }
    infile.close();


    //int test[81] = {8,2,7,1,5,4,3,9,6,9,6,5,3,2,7,1,4,8,3,4,1,6,8,9,7,5,2,5,9,3,4,6,8,2,7,1,4,7,2,5,1,3,6,8,9,6,1,8,9,7,2,4,3,5,7,8,6,2,3,5,9,1,4,1,5,4,7,9,6,8,2,3,2,3,9,8,4,1,5,6,7};
    //int tester = 3;
    //sectorCheck(test, tester);
}

int sectorCheck(int arr[], int puzNum)
{
    cout << puzNum << '\t';
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

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                for(int m = 0; m < 3; m++)
                {
                    cout << 9*(3*i + k) + (3*j + m) << endl;
                    if (arr[9*(3*i + k) + (3*j + m)] == 1)
                    {
                        counter1++;
                    }
                    if (counter1 > 1)
                    {
                        error = 1;
                    }

                    if (arr[9*(3*i + k) + (3*j + m)] == 2)
                    {
                        counter2++;
                    }
                    if (counter2 > 1)
                    {
                        error = 2;
                    }

                    if (arr[9*(3*i + k) + (3*j + m)] == 3)
                    {
                        counter3++;
                    }
                    if (counter3 > 1)
                    {
                        error = 3;
                    }

                    if (arr[9*(3*i + k) + (3*j + m)] == 4)
                    {
                        counter4++;
                    }
                    if (counter4 > 1)
                    {
                        error = 4;
                    }

                    if (arr[9*(3*i + k) + (3*j + m)] == 5)
                    {
                        counter5++;
                    }
                    if (counter5 > 1)
                    {
                        error = 5;
                    }

                    if (arr[9*(3*i + k) + (3*j + m)] == 6)
                    {
                        counter6++;
                    }
                    if (counter6 > 1)
                    {
                        error = 6;
                    }

                    if (arr[9*(3*i + k) + (3*j + m)] == 7)
                    {
                        counter7++;
                    }
                    if (counter7 > 1)
                    {
                        error = 7;
                    }

                    if (arr[9*(3*i + k) + (3*j + m)] == 8)
                    {
                        counter8++;
                    }
                    if (counter8 > 1)
                    {
                        error = 8;
                    }

                    if (arr[9*(3*i + k) + (3*j + m)] == 9)
                    {
                        counter9++;
                    }
                    if (counter9 > 1)
                    {
                        error = 9;
                    }
                }
            }
            if(counter1 == 0 || counter2 == 0 || counter3 == 0 || counter4 == 0 || counter5 == 0 || counter6 == 0 || counter7 == 0 || counter8 == 0 || counter9 == 0)
            {
                valid = 1;
            }
            if(counter1 > 1 || counter2 > 1 || counter3 > 1 || counter4 > 1 || counter5 > 1 || counter6 > 1 || counter7 > 1 || counter8 > 1 || counter9 > 1)
            {
                cout << "invalid - violates one or more of the sudoku rules" << '\t';
                cout << "sector " << ((3*i)+j+1) << " has multiple " << error << "s" << endl;
                return 1;
            }
            if(bigChecker == 9 && valid == 1)
            {
                cout << "valid - meets all rules for a sudoku puzzle (contains spaces)" << endl;
                return 1;
            }
            if (bigChecker == 9 && valid == 0)
            {
                cout << "solved - no spaces in the puzzle and valid" << endl;
                return 1;
            }
            bigChecker++;
            counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0, counter5 = 0, counter6 = 0, counter7 = 0, counter8 = 0, counter9 = 0;
        }
    }
}

int rowCheck(int arr[], int puzNum)
{
    cout << puzNum << '\t';
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
            if (arr[j] == 1)
            {
                counter1++;
            }
            if (counter1 > 1)
            {
                error = 1;
            }

            if (arr[j] == 2)
            {
                counter2++;
            }
            if (counter2 > 1)
            {
                error = 2;
            }

            if (arr[j] == 3)
            {
                counter3++;
            }
            if (counter3 > 1)
            {
                error = 3;
            }

            if (arr[j] == 4)
            {
                counter4++;
            }
            if (counter4 > 1)
            {
                error = 4;
            }

            if (arr[j] == 5)
            {
                counter5++;
            }
            if (counter5 > 1)
            {
                error = 5;
            }
            if (arr[j] == 6)
            {
                counter6++;
            }
            if (counter6 > 1)
            {
                error = 6;
            }

            if (arr[j] == 7)
            {
                counter7++;
            }
            if (counter7 > 1)
            {
                error = 7;
            }

            if (arr[j] == 8)
            {
                counter8++;
            }
            if (counter8 > 1)
            {
                error = 8;
            }

            if (arr[j] == 9)
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
            cout << "invalid - violates one or more of the sudoku rules" << '\t';
            cout << "row " << (i+1) << " has multiple " << error << "s" << endl;
            return 1;
        }
        if(bigChecker == 9 && valid == 1)
        {
            cout << "valid - meets all rules for a sudoku puzzle (contains spaces)" << endl;
            return 1;
        }
        if (bigChecker == 9 && valid == 0)
        {
            cout << "solved - no spaces in the puzzle and valid" << endl;
            return 1;
        }
        counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0, counter5 = 0, counter6 = 0, counter7 = 0, counter8 = 0, counter9 = 0;
    }
}

int columnCheck(int arr[], int puzNum)
{
    cout << puzNum << '\t';
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
            if (arr[j] == 1)
            {
                counter1++;
            }
            if (counter1 > 1)
            {
                error = 1;
            }

            if (arr[j] == 2)
            {
                counter2++;
            }
            if (counter2 > 1)
            {
                error = 2;
            }

            if (arr[j] == 3)
            {
                counter3++;
            }
            if (counter3 > 1)
            {
                error = 3;
            }

            if (arr[j] == 4)
            {
                counter4++;
            }
            if (counter4 > 1)
            {
                error = 4;
            }

            if (arr[j] == 5)
            {
                counter5++;
            }
            if (counter5 > 1)
            {
                error = 5;
            }
            if (arr[j] == 6)
            {
                counter6++;
            }
            if (counter6 > 1)
            {
                error = 6;
            }

            if (arr[j] == 7)
            {
                counter7++;
            }
            if (counter7 > 1)
            {
                error = 7;
            }

            if (arr[j] == 8)
            {
                counter8++;
            }
            if (counter8 > 1)
            {
                error = 8;
            }

            if (arr[j] == 9)
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
            cout << "invalid - violates one or more of the sudoku rules" << '\t';
            cout << "column " << (i+1) << " has multiple " << error << "s" << endl;
            return 1;
        }
        if(bigChecker == 9 && valid == 1)
        {
            cout << "valid - meets all rules for a sudoku puzzle (contains spaces)" << endl;
            return 1;
        }
        if (bigChecker == 9 && valid == 0)
        {
            cout << "solved - no spaces in the puzzle and valid" << endl;
            return 1;
        }
        counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0, counter5 = 0, counter6 = 0, counter7 = 0, counter8 = 0, counter9 = 0;
    }
}
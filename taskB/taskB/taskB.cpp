// B. Посадка в самолет
//

#include <iostream>
#include <fstream>

using namespace std;

int n;
string arr[100];

void success_message(int num, int row, bool is_left, bool is_aisle)
{
    cout << "Passengers can take seats: ";

    int seat = row + 1;
    
    if (is_left)
    {
        if (is_aisle)
        {
            if (num == 3)
            {
                cout << seat << "A ";
            }
            if (num >= 2)
            {
                cout << seat << "B ";
            }
            cout << seat << "C" << endl;
        }
        else
        {
            cout << seat << "A";
            if (num >= 2)
            {
                cout << " " << seat << "B";
            }
            if (num == 3)
            {
                cout << " " << seat << "C";
            }
            cout << endl;
        }
        
    }
    else
    {
        if (is_aisle)
        {
            cout << seat << "D";
            if (num >= 2)
            {
                cout << " " << seat << "E";
            }
            if (num == 3)
            {
                cout << " " << seat << "F";
            }
            cout << endl;
        }
        else
        {
            if (num == 3)
            {
                cout << seat << "D ";
            }
            if (num >= 2)
            {
                cout << seat << "E ";
            }
            cout << seat << "F" << endl;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (row == i)
        {
            if (is_left)
            {
                if (num == 3)
                {
                    cout << "XXX";
                }
                else if (is_aisle)
                {
                    if (num == 2)
                    {
                        cout << arr[i][0] << "XX";
                    }
                    if (num == 1)
                    {
                        cout << arr[i][0] << arr[i][1] << "X";
                    }
                }
                else
                {
                    if (num == 2)
                    {
                        cout << "XX" << arr[i][2];
                    }
                    if (num == 1)
                    {
                        cout << "X" << arr[i][1] << arr[i][2];
                    }
                }

                cout << arr[i].substr(3, 7) << endl;
            }
            else
            {
                cout << arr[i].substr(0, 4);
                if (num == 3)
                {
                    cout << "XXX" << endl;
                }
                if (is_aisle)
                {
                    if (num == 2)
                    {
                        cout << "XX" << arr[i][6] << endl;
                    }
                    if (num == 1)
                    {
                        cout << "X" << arr[i][5] << arr[i][6] << endl;
                    }
                }
                else
                {
                    if (num == 2)
                    {
                        cout << arr[i][4] << "XX" << endl;
                    }
                    if (num == 1)
                    {
                        cout << arr[i][4] << arr[i][5] << "X" << endl;
                    }
                }
            }
        }
        else
        {
            cout << arr[i] << endl;
        }
    }

}

void failure_message()
{
    cout << "Cannot fulfill passengers requirements" << endl;
}

int main()
{
    ifstream fin;
    fin.open("input.txt");
    

    fin >> n;
    
    //arr = new string[n];
    for (int i = 0; i < n; i++)
    {
        string s;
        fin >> s;
        arr[i] = s;
    }

    int m;

    fin >> m;


    for (int i = 0; i < m; i++)
    {
        int num;
        string side, position;
        fin >> num >> side >> position;

        bool is_fail = true;

        if ((side == "left") && (position == "aisle"))
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[j][2] != '.') continue;
                if (num == 1)
                {
                    arr[j][2] = '#';
                    is_fail = false;
                    success_message(num, j, true, true);
                    break;
                }
                if ((num == 2) && (arr[j][1] == '.'))
                {
                    arr[j][1] = '#';
                    arr[j][2] = '#';
                    is_fail = false;
                    success_message(num, j, true, true);
                    break;
                }

                if ((num == 3) && (arr[j][0] == '.') && (arr[j][1] == '.'))
                {
                    arr[j][0] = '#';
                    arr[j][1] = '#';
                    arr[j][2] = '#';
                    is_fail = false;
                    success_message(num, j, true, true);
                    break;
                }

            }
        }

        if ((side == "left") && (position == "window"))
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[j][0] != '.') continue;
                if (num == 1)
                {
                    arr[j][0] = '#';
                    is_fail = false;
                    success_message(num, j, true, false);
                    break;
                }
                if ((num == 2) && (arr[j][1] == '.'))
                {
                    arr[j][0] = '#';
                    arr[j][1] = '#';
                    is_fail = false;
                    success_message(num, j, true, false);
                    break;
                }
                if ((num == 3) && (arr[j][1] == '.') && (arr[j][2] == '.'))
                {
                    arr[j][0] = '#';
                    arr[j][1] = '#';
                    arr[j][2] = '#';
                    is_fail = false;
                    success_message(num, j, true, false);
                    break;
                }

            }
        }

        if ((side == "right") && (position == "aisle"))
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[j][4] != '.') continue;
                if (num == 1)
                {
                    arr[j][4] = '#';
                    is_fail = false;
                    success_message(num, j, false, true);
                    break;
                }
                if ((num == 2) && (arr[j][5] == '.'))
                {
                    arr[j][4] = '#';
                    arr[j][5] = '#';
                    is_fail = false;
                    success_message(num, j, false, true);
                    break;
                }
                if ((num == 3) && (arr[j][5] == '.') && (arr[j][6] == '.'))
                {
                    arr[j][4] = '#';
                    arr[j][5] = '#';
                    arr[j][6] = '#';
                    is_fail = false;
                    success_message(num, j, false, true);
                    break;
                }
            }
        }


        if ((side == "right") && (position == "window"))
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[j][6] != '.') continue;
                if (num == 1)
                {
                    arr[j][6] = '#';
                    is_fail = false;
                    success_message(num, j, false, false);
                    break;
                }
                if ((num == 2) && (arr[j][5] == '.'))
                {
                    arr[j][5] = '#';
                    arr[j][6] = '#';
                    is_fail = false;
                    success_message(num, j, false, false);
                    break;
                }
                if ((num == 3) && (arr[j][4] == '.') && (arr[j][5] == '.'))
                {
                    arr[j][4] = '#';
                    arr[j][5] = '#';
                    arr[j][6] = '#';
                    is_fail = false;
                    success_message(num, j, false, false);
                    break;
                }
            }
        }
        if (is_fail)
        {
            failure_message();
        }
    }
    fin.close();

    
}



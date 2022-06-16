// C. Расстояние
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>
#include <list>
#include <map>

using namespace std;

bool sorting(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

int main() // time limited on 15th test
{
    ifstream fin;
    fin.open("input.txt");

    int n, k;
    list<pair<int, int>> sorted_a;
    fin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int x;
        fin >> x;
        sorted_a.push_back({i, x});
    }
    fin.close();

    sorted_a.sort(sorting);
    
    map<int, int> ans;
    list<pair<int, int>>::iterator cur_it = sorted_a.begin();

    for (int i = 0; i < n; i++)
    {
        int cur_num = cur_it->second;
        int cur_index = cur_it->first;

        int s = 0;
        int from_left_side = 1;
        list<pair<int, int>>::iterator left_it = cur_it;
        int from_right_side = 1;
        list<pair<int, int>>::iterator right_it = cur_it;


        for (int j = 0; j < k; j++)
        {
            int modul;
            if ((i - from_left_side) < 0)
            {
                right_it++;
                modul = abs(cur_num - right_it->second);
                from_right_side++;
            }
            else if ((i + from_right_side) >= n)
            {
                left_it--;
                modul = abs(cur_num - left_it->second);
                from_left_side++;
            }
            else 
            {
                left_it--;
                right_it++;
                modul = abs(cur_num - left_it->second);
                int modul1 = abs(cur_num - right_it->second);
                if (modul > modul1)
                {
                    left_it++;
                    modul = modul1;
                    from_right_side++;
                }
                else 
                {
                    right_it--;
                    from_left_side++;
                }
                    
            }
            s += modul;
            
        }

        ans.insert({cur_index, s});
        cur_it++;
    }


    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }


}


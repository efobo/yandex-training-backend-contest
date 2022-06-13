// A. Андрей и кислота
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<int> arr;
    cin >> n;

    int prev_x;
    cin >> prev_x;
    arr.push_back(prev_x);

    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;

        if (prev_x > x)
        {
            cout << -1;
            return 0;
        }
        
        arr.push_back(x);
        prev_x = x;
    }

    int ans = arr[n-1] - arr[0];

    cout << ans;
}



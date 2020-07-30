

#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;
int own_count = 0;
int all_count = 0;

//vector<int> own_card;

const int MAX_COUNT = 500001;
int own_card[MAX_COUNT];
int all_card[MAX_COUNT];
int searchCount = 0;

int main()
{
    scanf("%d", &own_count);
    for (int i = 0; i < own_count; i++)
    {
        int temp = 0;
        scanf("%d", &temp);
        own_card[i] = temp;
        //cin >> own_card[i];     
    }

    sort(own_card, own_card + own_count);

    scanf("%d", &all_count);
    //cin >> all_count;
    for (int i = 0; i < all_count; i++)
    {
        //    cin >> all_card[i];
        int temp = 0;
        scanf("%d", &temp);
        //cin >> temp;
        //bool bSearch = binary_search(own_card, own_card + own_count, temp);
        bool bSearch = false;
        int nSearch = 0;
        searchCount = 0;

        int low = 0;
        int high = own_count - 1;

        /*
        int retVal = 0;
        if (bSearch)
            retVal = 1;
            */
        cout << upper_bound(own_card, own_card + own_count, temp) - lower_bound(own_card, own_card + own_count, temp) << " ";

    }
}


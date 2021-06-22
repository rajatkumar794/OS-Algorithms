#include<iostream>
#include<unordered_set>
using namespace std;
  
int predict(int pages[], unordered_set<int> mem, int n, int index)
{
    int res = -1, farthest = index;
    unordered_set<int>::iterator itr;
    for(itr=mem.begin(); itr!=mem.end(); ++itr)
    {
        int j;
        for (j = index; j < n; j++)
        {
            if (*itr == pages[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    res = *itr;
                }
                break;
            }
        }
        if(j==n)
            return *itr;
    }
    return res;
}
  
void optimalPage(int pages[], int pn, int capacity)
{
    unordered_set<int> mem;
    int page_faults = 0;
    for (int i = 0; i < pn; i++)
    {
        if (mem.find(pages[i])!=mem.end())
            continue;

        ++page_faults;
        if (mem.size() < capacity)
            mem.insert(pages[i]);
        else
        {
            int lastUsedPage = predict(pages, mem, pn, i + 1);
            mem.erase(lastUsedPage);
            mem.insert(pages[i]);
        }
    }
    cout << "\nTotal Page Faults using Optimal = " << page_faults << endl;
}
  

int main()
{
    int pg[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 };
    int pn = sizeof(pg) / sizeof(pg[0]);
    int capacity = 4;
    optimalPage(pg, pn, capacity);
    return 0;
}
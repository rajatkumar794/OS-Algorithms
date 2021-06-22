#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
  
int pageFaults(int pages[], int n, int capacity)
{
    unordered_set<int> mem;
    unordered_map<int, int> history;
  
    int page_faults = 0;
    for (int i=0; i<n; i++)
    {
        if (mem.size() < capacity)
        {
            if (mem.find(pages[i])==mem.end())
            {
                mem.insert(pages[i]);
                page_faults++;
            }
            history[pages[i]] = i;
        }
  
        else
        {
            if(mem.find(pages[i])==mem.end())
            {
                int lruPage=-1, lastUsedIdx=INT_MAX;
                unordered_set<int>::iterator itr;
                for(itr=mem.begin(); itr!=mem.end(); ++itr)
                {
                    if(history[*itr]<lastUsedIdx)
                    {
                        lastUsedIdx=history[*itr];
                        lruPage=*itr;
                    }
                }
                mem.erase(lruPage);
                mem.insert(pages[i]);
                ++page_faults;
            }
            history[pages[i]]=i;
        }
    }
  
    return page_faults;
}
  
int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 4;
    cout <<"\nTotal page faults using LRU: "<<pageFaults(pages, n, capacity)<<"\n";
    return 0;
}
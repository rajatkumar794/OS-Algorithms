#include<iostream>
#include<vector>
using namespace std;
  
void firstFit(vector<int> blockSize, int m, vector<int> processSize, int n)
{
    vector<int> allocation(n,-1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i+1 << "\t\t" 
             << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

void bestFit(vector<int> blockSize, int m, vector<int> processSize, int n)
{
    vector<int> allocation(n,-1);
  
    for (int i=0; i<n; i++)
    {
        int bestIdx = -1;
        for (int j=0; j<m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }
  
        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
  
            blockSize[bestIdx] -= processSize[i];
        }
    }
  
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i+1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}
  
void worstFit(vector<int> blockSize, int m, vector<int> processSize, int n)
{
    vector<int> allocation(n,-1);
 
    for (int i=0; i<n; i++)
    {
        int wstIdx = -1;
        for (int j=0; j<m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (wstIdx == -1)
                    wstIdx = j;
                else if (blockSize[wstIdx] < blockSize[j])
                    wstIdx = j;
            }
        }
 
        if (wstIdx != -1)
        {
            allocation[i] = wstIdx;
 
            blockSize[wstIdx] -= processSize[i];
        }
    }
 
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i+1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main()
{
    vector<int> blockSize{100, 500, 200, 300, 600};
    vector<int> processSize{212, 417, 112, 426};

    int m = 5;
    int n = 4;
    
    cout<<"First Fit";
    firstFit(blockSize, m, processSize, n);
    cout<<"\nBest Fit";
    bestFit(blockSize, m, processSize, n);
    cout<<"\nWorst Fit";
    worstFit(blockSize, m, processSize, n);
    return 0 ;
}
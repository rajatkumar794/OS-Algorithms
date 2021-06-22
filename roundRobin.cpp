#include<iostream>
#include<vector>
using namespace std;
  

void findWaitingTime(vector<vector<int>> processes, int n, vector<int> &wt, int quantum)
{
    vector<int> rem_bt(n);
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] =  processes[i][2];
  
    int t = 0; 
    while (1)
    {
        bool done = true;
  
        for (int i = 0 ; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = false;
  
                if (rem_bt[i] > quantum)
                {
                    t += quantum;
  
                    rem_bt[i] -= quantum;
                }
  
                else
                {
                    t = t + rem_bt[i];
  
                    wt[i] = t - processes[i][2];
  
                    rem_bt[i] = 0;
                }
            }
        }
  
        if (done == true)
          break;
    }
}
  

void findTurnAroundTime(vector<vector<int>> processes, int n, vector<int> wt, vector<int> &tat)
{
    for(int i = 0; i < n ; i++)
        tat[i] = processes[i][2] + wt[i];
}
  

void findavgTime(vector<vector<int>> processes, int n, int quantum)
{
    vector<int> wt(n), tat(n);
    int total_wt = 0, total_tat = 0;
  
    findWaitingTime(processes, n, wt, quantum);
  
    findTurnAroundTime(processes, n, wt, tat);
  
    cout << "Processes "<< " Burst time "
         << " Waiting time " << " Turn around time\n";
  
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i+1 << "\t\t" << processes[i][2] <<"\t "
             << wt[i] <<"\t\t " << tat[i] <<endl;
    }
  
    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}
  
int main()
{
    vector<vector<int>> processes = {{1, 0, 6}, {2, 2, 4}, {3, 3, 8}, {4, 5, 3}};
    int n = processes.size();  
    int quantum = 2;
    findavgTime(processes, n, quantum);
    return 0;
}
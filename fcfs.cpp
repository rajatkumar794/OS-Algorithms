#include<iostream>
#include<vector>
using namespace std;
 
void findWaitingTime(int n, int bt[], vector<int> &wt, int at[])
{
    int time=0;
    for (int i = 0; i<n; i++)
    {       
        wt[i] = time - at[i];
        time+=bt[i];
    }
}
 

void findTurnAroundTime(int n, int bt[],vector<int> wt, vector<int> &tat)
{
   
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
 

void findavgTime(int processes[], int n, int bt[], int at[])
{
    vector<int> wt(n), tat(n);
    findWaitingTime(n, bt, wt, at);
    findTurnAroundTime(n, bt, wt, tat);

    
    cout << "Processes " << " Burst Time " << " Arrival Time "<< " Waiting Time " << " Turn-Around Time \n";
    int total_wt = 0, total_tat = 0;
    for (int i = 0 ; i < n ; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i+1 << "\t\t" << bt[i] << "\t\t"<< at[i] << "\t\t" << wt[i] << "\t\t "<< tat[i]  <<  "\t\t " << endl;
    }
 
    cout << "Average waiting time = "<< (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;
}
 
int main()
{
    int processes[] = {1, 2, 3, 4};
    int n = sizeof(processes)/sizeof(processes[0]);
 
    int burst_time[] = {6, 4, 8, 3};
    int arrival_time[] = {0, 2, 3, 5};
    findavgTime(processes, n, burst_time, arrival_time);
    return 0;
}
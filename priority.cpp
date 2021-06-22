#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
  
bool comparison( const vector<int>& v1, const vector<int>& v2 )
{
    return v1[3] > v2[3];
}
 

void findWaitingTime(int n, vector<vector<int>> processes, vector<int> &wt)
{
    int time=0;
    for (int i = 0; i<n; i++)
    {       
        wt[i] = time - processes[i][1];
        time+=processes[i][2];
    }
}
 
void findTurnAroundTime(int n, vector<vector<int>> processes, vector<int> wt, vector<int> &tt)
{
    for (int i = 0; i < n ; i++)
        tt[i] = processes[i][2] + wt[i];
}

void findavgTime(vector<vector<int>> processes, int n)
{
    vector<int> wt(n), tat(n);
    int total_wt = 0, total_tat = 0;
 
    findWaitingTime(n, processes, wt);
    findTurnAroundTime(n, processes, wt, tat);
    
    cout << "\nProcesses  "<< " Burst time  " << " Waiting time  " << " Turn around time\n";
 
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << processes[i][0] << "\t\t"<< processes[i][2] << "\t    " << wt[i]<< "\t\t  " << tat[i] <<endl;
    }
 
    cout << "\nAverage waiting time = "<< (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;
}
 
void priorityScheduling(vector<vector<int>> processes, int n)
{   
    sort(processes.begin()+1, processes.end(), comparison);
    cout<< "Order in which processes gets executed \n";
    for (int  i = 0 ; i <  n; i++)
        cout << processes[i][0]<<" " ;
 
    findavgTime(processes, n);
}
 
int main()
{
    vector<vector<int>> processes = {{1, 0, 6, 2}, {2, 2, 4, 1}, {3, 3, 8, 4}, {4, 5, 3, 3}};
    const int n = processes.size();
    priorityScheduling(processes, n);
    return 0;
}
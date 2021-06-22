#include<iostream>
#include<vector>
using namespace std;


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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
 
void arrangeArrival(int num, vector<vector<int>> &processes)
{
    for(int i=1; i<num; i++)
    {   int minB=processes[i][2];
        int minBI=i;
        for(int j=i+1; j<num; j++)
        {
            if(processes[j][2]<minB)
            {
                minB=processes[j][2];
                minBI=j;
            }
        }
        if(minBI!=i)
        {
            for(int k=0; k<3; k++)
                swap(processes[i][k], processes[minBI][k]);
        }
    }
}
 

 
int main()
{
    int num, temp;
     
    cout<<"Enter number of Process: ";
    cin>>num;
    vector<vector<int>> processes(num, vector<int>(3));
    
    cout<<"...Enter the process ID...\n";
    for(int i=0; i<num; i++)
    {
        cout<<"...Process "<<i+1<<"...\n";
        cout<<"Enter Process Id: ";
        cin>>processes[i][0];
        cout<<"Enter Arrival Time: ";
        cin>>processes[i][1];
        cout<<"Enter Burst Time: ";
        cin>>processes[i][2];
    }
     
    cout<<"Before Arrange...\n";
    cout<<"Process ID\tArrival Time\tBurst Time\n";
    for(int i=0; i<num; i++)
    {
        cout<<processes[i][0]<<"\t\t"<<processes[i][1]<<"\t\t"<<processes[i][2]<<"\n";
    }
    
    vector<int> wt(num);
    vector<int> tt(num);
    arrangeArrival(num, processes);
    findWaitingTime(num, processes, wt);
    findTurnAroundTime(num, processes, wt, tt);

    int total_wt=0, total_tat=0;
    cout<<"\nFinal Result...\n";
    cout<<"Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for(int i=0; i<num; i++)
    {
        cout<<processes[i][0]<<"\t\t"<<processes[i][1]<<"\t\t"<<processes[i][2]<<"\t\t"<<wt[i]<<"\t\t"<<tt[i]<<"\n";
        total_wt+=wt[i];
        total_tat+=tt[i];
    }
    cout << "Average waiting time = "<< (float)total_wt / (float)num;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)num;
}
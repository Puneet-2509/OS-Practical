#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid;
    int bt;
    int priority;
};

bool comparison(Process a, Process b)
{
    return (a.priority > b.priority);
}

void findWaitingTime(Process proc[], int n, int wt[])
{
    wt[0] = 0;

    for (int  i = 1; i < n ; i++ )
        wt[i] =  proc[i-1].bt + wt[i-1] ;
}

void findTurnAroundTime( Process proc[], int n, int wt[], int tat[])
{
    for (int  i = 0; i < n ; i++)
        tat[i] = proc[i].bt + wt[i];
}

void findavgTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);

    cout << "\nProcesses  "<< " Burst time  " << " Waiting time  " << " Turn around time\n";

    for (int  i=0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << proc[i].pid << "\t\t" << proc[i].bt << "\t    " << wt[i] << "\t\t  " << tat[i] << endl;
    }

    cout << "\nAverage waiting time = " << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}

void priorityScheduling(Process proc[], int n)
{
    sort(proc, proc + n, comparison);

    cout<< "Order in which processes gets executed \n";
    for (int  i = 0 ; i <  n; i++)
        cout << proc[i].pid <<" " ;

    findavgTime(proc, n);
}

int main()
{
	int n;
    cout<<"\nPriority Scheduling\nEnter the Number of Processes=";
    cin>>n;
    Process *proc= new Process[n];
	
	for(int i=0; i < n; i++)
	{
        cout<<"\nEnter the Burst Time for Process "<< i+1<<"=";
        cin>>proc[i].bt;
        cout<<"\nEnter the Priority of Process "<< i+1<<"=";
        cin>>proc[i].priority;
        proc[i].pid=i+1;
    }
    priorityScheduling(proc, n);
    return 0;
}
/*
 * FCFS2.cpp
 *
 *  Created on: Nov 11, 2017
 *      Author: chivora
 */

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;

/*
 * Program for FCFS Scheduling | Set 2 (Processes with different arrival times)
2.5
We have already discussed FCFS Scheduling of processes with same arrival time.
In this post, scenario when processes have different arrival times are discussed.
Given n processes with their burst times and arrival times, the task is to find average waiting time and average
turn around time using FCFS scheduling algorithm.
FIFO simply queues processes in the order they arrive in the ready queue. Here, the process that comes first
will be executed first and next process will start only after the previous gets fully executed.

Completion Time: Time at which process completes its execution.
Turn Around Time: Time Difference between completion time and arrival time. Turn Around Time = Completion Time – Arrival Time
Waiting Time(W.T): Time Difference between turn around time and burst time.
Waiting Time = Turn Around Time – Burst Time

http://cdncontribute.geeksforgeeks.org/wp-content/uploads/ff2_.png
http://cdncontribute.geeksforgeeks.org/wp-content/uploads/ff23_.png

Process     Wait Time : Service Time - Arrival Time
   P0 	                   0 - 0   = 0
   P1 	                   5 - 1   = 4
   P2 	                   8 - 2   = 6
   P3 	                   16 - 3  = 13

Average Wait Time: (0 + 4 + 6 + 13) / 4 = 5.75
Service Time : Service time means amount of time after which a process can start execution.
It is summation of burst time of previous processes (Processes that came before)

Changes in code as compare to code of FCFS with same arrival time:
To find waiting time: Time taken by all processes before the current process to be started
(i.e. burst time of all previous processes) – arrival time of current process
wait_time[i] = (bt[0] + bt[1] +…… bt[i-1] ) – arrival_time[i]

Implementation:

1- Input the processes along with their burst time(bt)
   and arrival time(at)
2- Find waiting time for all other processes i.e. for
   a given process  i:
       wt[i] = (bt[0] + bt[1] +...... bt[i-1]) - at[i]
3- Now find turn around time
          = waiting_time + burst_time for all processes
4- Average waiting time =
                    total_waiting_time / no_of_processes
5- Average turn around time =
                 total_turn_around_time / no_of_processes

 */


// Function to find the waiting time for all
// processes
void findWaitingTime(int processes[], int n, int bt[],
                                   int wt[], int at[])
{
    int service_time[n];
    service_time[0] = 0;
    wt[0] = 0;

    // calculating waiting time
    for (int i = 1; i < n ; i++)
    {
        // Add burst time of previous processes
        service_time[i] = service_time[i-1] + bt[i-1];

        // Find waiting time for current process =
        // sum - at[i]
        wt[i] = service_time[i] - at[i];

        // If waiting time for a process is in negative
        // that means it is already in the ready queue
        // before CPU becomes idle so its waiting time is 0
        if (wt[i] < 0)
            wt[i] = 0;
    }
}

// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n, int bt[],
                                      int wt[], int tat[])
{
    // Calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average waiting and turn-around
// times.
void findavgTime(int processes[], int n, int bt[], int at[])
{
    int wt[n], tat[n];

    // Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt, at);

    // Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);

    // Display processes along with all details
    cout << "Processes " << " Burst Time " << " Arrival Time "
         << " Waiting Time " << " Turn-Around Time "
         << " Completion Time \n";
    int total_wt = 0, total_tat = 0;
    for (int i = 0 ; i < n ; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        int compl_time = tat[i] + at[i];
        cout << " " << i+1 << "\t\t" << bt[i] << "\t\t"
             << at[i] << "\t\t" << wt[i] << "\t\t "
             << tat[i]  <<  "\t\t " << compl_time << endl;
    }

    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}

// Driver code
int main()
{
    // Process id's
    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];

    // Burst time of all processes
    int burst_time[] = {5, 9, 6};

    // Arrival time of all processes
    int arrival_time[] = {3, 3, 6};

    findavgTime(processes, n, burst_time, arrival_time);

    return 0;
}


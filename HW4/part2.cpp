/*

Problem 2:
You work for a company that creates a process where n jobs have to
be sequenced. Let's number these jobs from 0 to n-1. There are de-
pendencies between these jobs, that is some jobs must be completed be-
fore other jobs can be started. 

The parameters to this problem are: 

n:
the number of jobs, then for every job: a tuple t(i,j) that species that
job i depends on job j. In other words, job(j) must be completed be-
fore job(i) can be started. There may be more that one tuple or depen-
dency relationship for any given job, that is a job may have more than
one dependency. Your task is to write a progam to schedule the execu-
tion of these jobs. In case of a tie, choose any jobs in the tie arbitrarily.



HINT: For each job i build a queue of jobs that depend on it, that is, jobs
that must be scheduled after job i. 

Then, for each job, count the number
of dependencies that job has. Then, create a queue the ready queue that
contains all jobs that have no dependencies. 

Select one job from this queue,
this is the current or active job, and remove 1 dependency from every job
that depends on this job. You can also delete this job. When the dependecy
count for any given job reaches 0, add that job to the ready queue. Proceed
until all jobs are executed. 

A tuple of the form (i,i) indicates that the job has no dependencies.


*/

#include <iostream>
#include <vector>
#include<queue>
#include <unordered_set>
using namespace std;



//graph set of number of tasks 
vector<unordered_set<int>> make_graph(int ntask,vector<pair<int,int>>& prereq)
{
    vector<unordered_set<int>> graph(ntask);
    for (auto pre : prereq)
    {
        graph[pre.second].insert(pre.first);
    }
    return graph;
}
 

//first visit a node, then a neighbor of it and etc
// an ALREADY visited node will diff by path and vis node will be yield false 
//VISITED Vs CURRENTLY VISITED
bool cycle_check(vector<unordered_set<int>>&graph,int node,vector<bool>&path,vector<bool>&vis)
{
    if (vis[node])
    {
        return false;
    }
    path[node]=vis[node]=true;
    for (int neighbor : graph[node])
    {
        if (path[neighbor]||cycle_check(graph, neighbor, path, vis))
        {
            return true;
        }

    }
    return path[node]=false;
}
 
//check if a job task is able to be completed based on the cycle check 
bool check_dependency(int ntask,vector<pair<int,int>>& preq)
{
    vector<unordered_set<int>>graph=make_graph(ntask, preq);
    vector<bool>path(ntask, false),vis(ntask, false);
    for (int jth = 0; jth < ntask; jth++)
        if (!vis[jth]&&cycle_check(graph, jth, path, vis))
        {
            return false;
        }
    return true;
}
 
int main()
{
    int ntask=2;
    vector<pair<int,int>>preq;
    preq.push_back(make_pair(1, 0));
    if (check_dependency(ntask, preq)) 
    {
        cout << "Finish tasks";
        cout <<"\n\n";
    }
    else 
    {
        cout << "Can't finish";
        cout <<"\n\n";
    }
 
    return 0;
}
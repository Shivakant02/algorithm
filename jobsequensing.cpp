#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int id;
    int dead;
    int profit;
};
void print(Job arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].id << "\t" << arr[i].dead << "\t\t" << arr[i].profit << endl;
    }
}
int maxdeadline(Job arr[], int n)
{
    int maxdeadline = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxdeadline = max(maxdeadline, arr[i].dead);
    }
    return maxdeadline;
}
static bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}
vector<int> JobScheduling(Job arr[], int n)
{

    sort(arr, arr + n, cmp);
    int maxdeadline = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxdeadline = max(maxdeadline, arr[i].dead);
    }

    vector<int> schedule(maxdeadline + 1, -1);

    int count = 0;
    int maxprofit = 0;

    for (int i = 0; i < n; i++)
    {
        int currprofit = arr[i].profit;
        int jobid = arr[i].id;
        int currdeadline = arr[i].dead;

        for (int k = currdeadline; k > 0; k--)
        {
            if (schedule[k] == -1)
            {
                count++;
                maxprofit += currprofit;
                schedule[k] = jobid;
                break;
            }
        }
    }
    vector<int> ans;
    ans.push_back(count);
    ans.push_back(maxprofit);
    return ans;
}
int main()
{
    Job jobs[] = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}};
    int n = 4;
    // vector<int> a = JobScheduling(jobs, n);

    cout << "job id \t"
         << "deadline \t"
         << "profit" << endl;
    print(jobs, n);
    cout << "maximum deadline:" << maxdeadline(jobs, n) << endl;
    cout << "max jobs done:" << JobScheduling(jobs, n).front() << endl;
    cout << "maxprofit:" << JobScheduling(jobs, n).back() << endl;
    return 0;
}
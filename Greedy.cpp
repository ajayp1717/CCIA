#include <iostream>
#include <vector>

using namespace std;

vector<int> selectionsort(vector<int> a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int min_indx = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[min_indx])
            {
                min_indx = j;
            }
        }
        swap(a[i], a[min_indx]);
    }
    return a;
}

int main()
{
    int n;
    cout << "Enter the number of elements: " << endl;
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Unsorted Array: " << endl;
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    a = selectionsort(a);
    cout << "Sorted Array: " << endl;
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;
}

// Job-Scheduling

// struct Job{
//     int st;
//     int d;
    
// };

// bool compare(Job &a, Job&b){
//     return a.st<b.st;
// }

// void JobSch(Job job[],int n){
//     sort(job,job+n,compare);
    
//     int ct=0;
//     int twt=0;
    
    
//     for(int i=0;i<n;++i){
        
//         int wt=max(0,ct-job[i].st);
//         ct+=job[i].d;
//         cout<<"job ("<<job[i].st<<", "<<job[i].d<<")- WT: "<<wt<<endl;
        
//         twt+=wt;
//     }
//     cout<<"The Total WT is: "<<twt<<endl;
// }

// int main(){

    
//         int n;
//         cout<<"No. of jobs: ";
//         cin>>n;
//         Job jobs[n];
//         cout<<"Enter the st and dur of jobs: "<<endl;
//         for(int i=0;i<n;i++){
            
//             cout<<"ST "<<endl;
//             cin>>jobs[i].st;
//             cout<<"dur "<<endl;
//             cin>>jobs[i].d;
//         }
//         cout<<endl;
//         JobSch(jobs,n);
//         return 0;    
        
// }

// The Greedy aspect of the algorithm lies in the fact that at each step, we make a locally optimal decision by scheduling the job with the earliest start time. By sorting the jobs based on their start times and scheduling them in this order, we aim to minimize the waiting time for the jobs. However, it's important to note that this Greedy approach may not always result in the globally optimal solution, and there can be cases where a different scheduling order would yield a better outcome.
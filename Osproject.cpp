#include <bits/stdc++.h> 
  
using namespace std; 
  
#define totprocess 5  
struct process 
{ 
int at,bt,pr,pno; 
}; 
  
process proc[50]; 
bool comp(process x,process y) 
{ 
if(x.at == y.at) 
{ 
return x.pr<y.pr; 
} 
else
{ 
    return x.at<y.at; 
} 
} 
void get_wt_time(int wt[]) 
{ 
int service[50]; 
service[0]=0; 
wt[0]=0; 
  
  
for(int i=1;i<totprocess;i++) 
{ 
service[i]=proc[i-1].bt+service[i-1]; 
  
wt[i]=service[i]-proc[i].at+1; 
    if(wt[i]<0) 
    { 
    wt[i]=0; 
    } 
} 
  
} 
  
void get_tat_time(int tat[],int wt[]) 
{ 
for(int i=0;i<totprocess;i++) 
{ 
    tat[i]=proc[i].bt+wt[i]; 
} 
      
} 
  
void findgc() 
{ 
int wt[50],tat[50];   
double wavg=0,tavg=0;  
get_wt_time(wt); 
get_tat_time(tat,wt); 
      
int s_time[50],c_time[50]; 
s_time[0]=1; 
c_time[0]=s_time[0]+tat[0]; 
for(int i=1;i<totprocess;i++) 
    { 
        s_time[i]=c_time[i-1]; 
        c_time[i]=s_time[i]+tat[i]-wt[i]; 
    } 
      
cout<<"Process_no\tStart_Time\tCompleteTime\tTurnAround_Time\tWaiting_Time"<<endl; 
for(int i=0;i<totprocess;i++) 
    { 
        wavg += wt[i]; 
        tavg += tat[i]; 
          
        cout<<proc[i].pno<<"\t\t"<< 
            s_time[i]<<"\t\t"<<c_time[i]<<"\t\t"<< 
            tat[i]<<"\t\t\t"<<wt[i]<<endl; 
    } 
    cout<<"Avg waiting time is : "; 
    cout<<wavg/(float)totprocess<<endl; 
    cout<<"Avg turnaround time is: "; 
    cout<<tavg/(float)totprocess<<endl; 
} 
  
int main() 
{ 
int arr_time[] = { 1, 2, 3, 4, 5 }; 
int burst__time[] = { 3, 7, 1, 9, 5 }; 
int priority[] = { 3, 4, 1, 7, 8 }; 
      
for(int i=0;i<totprocess;i++) 
{ 
    proc[i].at=arr_time[i]; 
    proc[i].bt=burst__time[i]; 
    proc[i].pr=priority[i]; 
    proc[i].pno=i+1; 
    }  
  sort(proc,proc+totprocess,comp);     
    findgc();  
    return 0; 
} 
  


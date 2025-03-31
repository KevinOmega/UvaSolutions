#include <cstdio>
#include <queue>
#include <vector>

using namespace std;


struct Task{ 
    int id;
    int period;
    int increment;
    bool operator>(const Task& other) const{
        if(period == other.period){
            return id > other.id;
        }else{
            return period > other.period;
        }
    }
};

int main(){
    char inst[10];
    int id,period;
    int k;
    Task current;
    priority_queue<Task, vector<Task>, greater<Task>> pq;

    while (scanf("%s",&inst) && inst[0] != '#')
    {
        scanf("%d %d",&id,&period);
        pq.push({id,period,period});
    }
    scanf("%d",&k);
    for (int i = 0; i < k; i++){
        current = pq.top();
        printf("%d\n",current.id);
        pq.pop();
        pq.push({current.id,current.period + current.increment, current.increment});
    }
}

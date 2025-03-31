#include <cstdio>
#include <stack>
#include <queue>

using namespace std;


void load(stack<int> &carrier, queue<int> &platform,int &minutes, int carrierCapacity);
void unload(stack<int> &carrier, queue<int> &platform, int &minutes, int queueCapacity, int stationNumber);


int main(){

    int sets;
    int nStations, carrierCapacity, queueCapacity;

   
    int totalMinutes;
    int carrierPos;

    int nCargos,currentCargo;    

    scanf("%d", &sets);

    for(int i = 0; i < sets; i++){
        totalMinutes = 0;
        carrierPos = 0;
        stack<int> carrier;
        queue<int> platformQueues[100];
        bool stationsDone[100] = {false};

        scanf("%d %d %d", &nStations, &carrierCapacity, &queueCapacity);

        for (int queueIndex = 0; queueIndex < nStations; queueIndex++)
        {
            scanf("%d", &nCargos );
            
            for (int k = 0; k < nCargos; k++)
            {
                scanf("%d", &currentCargo);
                platformQueues[queueIndex].push(currentCargo);
            }
        }
        bool keepGoing = true;
        int lastPlatform;
        int position = 0;
        while (keepGoing)
        {
            int carrierPosition = position % nStations;
            unload(carrier,platformQueues[carrierPosition],totalMinutes,queueCapacity,carrierPosition + 1);
            load(carrier,platformQueues[carrierPosition],totalMinutes, carrierCapacity);
            if(platformQueues[carrierPosition].empty()){
                stationsDone[carrierPosition] = true;
            }
            for (int i = 0; i < nStations; i++)
            {
                keepGoing = false;
                if(!stationsDone[i]){
                    keepGoing = true;
                    break;
                }
            }
            if(!keepGoing && !carrier.empty()){
                keepGoing = true;
            }
            totalMinutes+=2;
            position++;

            
           
        }

        printf("%d", totalMinutes - 2  );
        puts("");
    }

    return 0;
}

void load(stack<int> &carrier, queue<int> &platform,int &minutes, int carrierCapacity){
    int cargo;
    while (carrier.size() < carrierCapacity && !platform.empty())
    {
        cargo = platform.front();
        platform.pop();
        carrier.push(cargo);
        minutes++;
    }
}

void unload(stack<int> &carrier, queue<int> &platform, int &minutes, int queueCapacity, int stationNumber){
    int cargoDestination;
    
    if(!carrier.empty() && carrier.top()  == stationNumber){
        carrier.pop();
        minutes++;
    }
    
    while ((!carrier.empty() && platform.size() < queueCapacity) || (!carrier.empty() && carrier.top() == stationNumber))
    {
        cargoDestination = carrier.top();
        carrier.pop();
        if(cargoDestination != stationNumber){
            platform.push(cargoDestination);
        }
        minutes++;
    } 
}

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

/* ------------------------------
   GLOBAL STRUCTURES
--------------------------------*/
vector< pair<int,int> > graphEdges;   // (cost, edge)
priority_queue< pair<int,int> > emergencyPQ;
queue<string> alertQueue;
map<int,string> sensorMap;
vector<int> pressureLevels;

/* ------------------------------
   ADD PIPELINE
--------------------------------*/
void addPipeline() {
    int u,v,w;
    cout<<"Enter junction1 junction2 distance: ";
    cin>>u>>v>>w;

    graphEdges.push_back(make_pair(w, u*1000+v));
    cout<<"Pipeline added successfully.\n";
}

/* ------------------------------
   KRUSKAL DEMO
--------------------------------*/
void kruskalDemo() {
    if(graphEdges.size()==0){
        cout<<"No pipelines available.\n";
        return;
    }

    sort(graphEdges.begin(), graphEdges.end());

    cout<<"Minimum cost pipeline edges:\n";
    for(int i=0;i<graphEdges.size();i++){
        cout<<"Cost: "<<graphEdges[i].first<<endl;
    }
}

/* ------------------------------
   EMERGENCY PRIORITY QUEUE
--------------------------------*/
void addEmergency() {
    int zone,severity;
    cout<<"Enter zone and severity: ";
    cin>>zone>>severity;

    emergencyPQ.push(make_pair(severity,zone));
    cout<<"Emergency added.\n";
}

void handleEmergency() {
    if(emergencyPQ.empty()){
        cout<<"No emergency pending.\n";
        return;
    }

    cout<<"Handling emergency in zone "
        << emergencyPQ.top().second << endl;
    emergencyPQ.pop();
}

/* ------------------------------
   HASH TABLE (SENSORS)
--------------------------------*/
void addSensor() {
    int id;
    string zone;
    cout<<"Enter sensor ID and zone: ";
    cin>>id>>zone;

    sensorMap[id]=zone;
    cout<<"Sensor added.\n";
}

/* ------------------------------
   QUEUE (ALERTS)
--------------------------------*/
void addAlert() {
    string msg;
    cout<<"Enter alert message: ";
    cin>>msg;
    alertQueue.push(msg);
}

void processAlert() {
    if(alertQueue.empty()){
        cout<<"No alerts available.\n";
        return;
    }

    cout<<"Processing alert: "<<alertQueue.front()<<endl;
    alertQueue.pop();
}

/* ------------------------------
   SORTING (INTROSORT via std::sort)
--------------------------------*/
void sortPressure() {
    int n,x;
    cout<<"Enter number of zones: ";
    cin>>n;

    pressureLevels.clear();
    for(int i=0;i<n;i++){
        cin>>x;
        pressureLevels.push_back(x);
    }

    sort(pressureLevels.begin(), pressureLevels.end());

    cout<<"Sorted pressure levels:\n";
    for(int i=0;i<pressureLevels.size();i++){
        cout<<pressureLevels[i]<<" ";
    }
    cout<<endl;
}

/* ------------------------------
   MAIN MENU
--------------------------------*/
int main() {
    int ch;

    do{
        cout<<"\n--- Intelligent Water Flow Management System ---\n";
        cout<<"1. Add Pipeline\n";
        cout<<"2. Kruskal Minimum Cost\n";
        cout<<"3. Add Emergency\n";
        cout<<"4. Handle Emergency\n";
        cout<<"5. Add Sensor\n";
        cout<<"6. Add Alert\n";
        cout<<"7. Process Alert\n";
        cout<<"8. Sort Pressure Levels\n";
        cout<<"0. Exit\n";
        cout<<"Enter choice: ";
        cin>>ch;

        switch(ch){
            case 1: addPipeline(); break;
            case 2: kruskalDemo(); break;
            case 3: addEmergency(); break;
            case 4: handleEmergency(); break;
            case 5: addSensor(); break;
            case 6: addAlert(); break;
            case 7: processAlert(); break;
            case 8: sortPressure(); break;
            case 0: cout<<"Exiting...\n"; break;
            default: cout<<"Invalid choice!\n";
        }

    }while(ch!=0);

    return 0;
}

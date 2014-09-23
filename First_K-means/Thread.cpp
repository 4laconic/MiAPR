#ifndef unit2cpp
#define unit2cpp
#define sqr(x) (x)*(x)
#pragma hdrstop
#include "Thread.h"
#include "point.h"
#include <System.hpp>
#include <utility>
using namespace std;

//---------------------------------------------------------------------------

inline __fastcall ThreadSel::ThreadSel(bool Suspended): TThread(Suspended) {
    Priority = tpHighest;
}

inline void ThreadSel::InitCentroid(point *pCentr) {
    pCentroid = pCentr;
}

inline void ThreadSel::InitProcessedCluster(TCluster *cluster) {
    pProcessedCluster = cluster;
}

inline int ThreadSel::CalculateDistance(point &left, point &right) {
    int x1 = left.GetX(),  y1 = left.GetY();
    int x2 = right.GetX(), y2 = right.GetY();
    return sqr(x1 - x2) + sqr(y1 - y2);
}

inline void __fastcall ThreadSel::Execute() {
    ll x = 0, y = 0;
    TCluster::iterator it = (*pProcessedCluster).begin();
    for (;it != (*pProcessedCluster).end(); ++it) {
        x += it->GetX();
        y += it->GetY();
    }
    int n = (*pProcessedCluster).size();
    pCentroid->SetX(x / (n ? n : ++n));
    pCentroid->SetY(y / (n ? n : ++n));
}
//---------------------------------------------------------------------------
//desription ThreadGen
//---------------------------------------------------------------------------
__fastcall ThreadGen::ThreadGen(bool Suspended): ThreadSel(Suspended) {
    Priority = tpHighest;
}

inline short ThreadGen::SelectCluster(point &SelectPoint) {
    int index = 0, minDistance = INT_MAX, distance;
    for (int i = 0; i < (int)(*pNewClusters).size(); ++i) {
        distance = CalculateDistance((*pCentroids)[i], SelectPoint);
        if (distance < minDistance) {
            minDistance = distance;
            index = i;
        }
    }
    return index;
}

inline void __fastcall ThreadGen::Execute() {
    TCluster::iterator it = (*pProcessedCluster).begin();
    for (; it != (*pProcessedCluster).end(); ++it) {
        short indexOfCluster = SelectCluster(*it);
        (*pNewClusters)[indexOfCluster].push_back(*it);
    }
}

inline void ThreadGen::InitNewClusters(TClusters *NewClus) {
    pNewClusters = NewClus;
}

inline void ThreadGen::InitCentroids(TCentroids *pCentr) {
    pCentroids = pCentr;
}

#endif

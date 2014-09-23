//---------------------------------------------------------------------------

#ifndef ThreadH
#define ThreadH
#include "point.h"
#include <vector>
#include <list>
using namespace std;
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#define TCluster list<point>
#define TClusters vector<TCluster >
#define TCentroids vector<point>

//---------------------------------------------------------------------------
class ThreadSel: public TThread {
protected:
    point *pCentroid;
    TCluster *pProcessedCluster;
public:
    void __fastcall Execute();
    inline __fastcall ThreadSel(bool Suspended);
    inline int CalculateDistance(point &left, point &right);
    inline void InitCentroid(point *pCentr);
    inline void InitProcessedCluster(TCluster *cluster);
};
//---------------------------------------------------------------------------
class ThreadGen: public ThreadSel {
protected:
     TCentroids *pCentroids;
     TClusters *pNewClusters;
public:
    void __fastcall Execute();
    inline __fastcall ThreadGen(bool Suspended);
    inline void InitNewClusters(TClusters *NewClus);
    inline void InitCentroids(vector<point> *centroids);
    inline short SelectCluster(point &SelectPoint);
};

#endif

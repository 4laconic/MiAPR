#ifndef kmeansh
#define kmeansh
#include <vector>
#include <list>
#include <vcl.h>
#include "point.h"
#include "Thread.h"
#include "Thread.cpp"
#include <System.Classes.hpp>

#define TCluster list<point>
#define TClusters vector<TCluster >
#define TCentroids vector<point>

using namespace std;
class Kmeans {
private:
    TCentroids centroids;
    TClusters clusters;
    TImage *pImage;
    vector<ThreadSel *> selCentThread;
    vector<ThreadGen *> genClusThread;
    int n, k, width, height;
public:
    Kmeans(int n, int k, int w, int h, TImage *p);
    inline void ClearScreen(TCanvas *pCanvas);
    inline void DrawPoint();
    inline void GeneratePoints();
    inline void GenerateCentroids();
    inline void GenerateClusters();
    inline void FreeMemory();
    inline void Algorithm();
    inline bool ChangeCentroids(point &newCentroid, point &oldCentroid);
    inline bool CentroidWasChanged();
};
#endif

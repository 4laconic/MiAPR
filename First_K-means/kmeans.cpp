#ifndef kmeanscpp
#define kmeanscpp

#include "Kmeans.h"
#define sqr(x) (x)*(x)
#define TCluster list<point>
#define TClusters vector<TCluster >

Kmeans::Kmeans(int countPoint, int countClus, int w, int h, TImage *pImg) {
    n = countPoint;
    k = countClus;
    width = w;
    height = h;
    pImage = pImg;
}

inline void Kmeans::GenerateCentroids() {
    centroids.assign(k, 0);
    for (short i = 0; i < k; ++i) {
        centroids[i] = clusters[i].front();
        centroids[i].SetKernel();
   }
}

inline void Kmeans::GeneratePoints() {
    clusters.assign(k, TCluster());
    for (int i = 0; i < n; ++i) {
        int x = rand() % (width - 30) + 15;
        int y = rand() % (height - 30) + 15;
        point temp(x, y);
        clusters[i % k].push_back(temp);
    }
}

inline void Kmeans::GenerateClusters() {
    vector<TClusters > newClusters(k, TClusters(k, TCluster()));
    TClusters ResultCluster(k, TCluster());
    genClusThread.assign(k, 0);
    for (int i = 0; i < k; ++i) {
        genClusThread[i] = new ThreadGen(true);
        genClusThread[i]->InitNewClusters(&newClusters[i]);
        genClusThread[i]->InitCentroids(&centroids);
        genClusThread[i]->InitProcessedCluster(&clusters[i]);
        genClusThread[i]->Resume();
    }
    for (int i = 0; i < k; ++i) {
        genClusThread[i]->WaitFor();
        for (int j = 0; j < k; ++j)
            ResultCluster[j].insert(ResultCluster[j].begin(),
        newClusters[i][j].begin(), newClusters[i][j].end());
    }
    clusters.clear();
    clusters = ResultCluster;
}

inline bool Kmeans::ChangeCentroids(point &newCentroid, point &oldCentroid) {
    oldCentroid.UnsetKernel();
    newCentroid.SetKernel();
    return newCentroid != oldCentroid;
}

inline bool Kmeans::CentroidWasChanged() {
    TCentroids newCentroids(k, point());
    selCentThread.assign(k, 0);
    for (int i = 0; i < k; ++i) {
        selCentThread[i] = new ThreadSel(true);
        selCentThread[i]->InitProcessedCluster(&clusters[i]);
        selCentThread[i]->InitCentroid(&newCentroids[i]);
        selCentThread[i]->Resume();
    }
    bool centroidWasChanged = false;
    for (int i = 0; i < k; ++i) {
        selCentThread[i]->WaitFor();
        centroidWasChanged |= ChangeCentroids(newCentroids[i], centroids[i]);
        centroids[i] = newCentroids[i];
    }
    return centroidWasChanged;
}


inline void Kmeans::ClearScreen(TCanvas *pCanvas) {
    pCanvas->Brush->Color = clWhite;
    pCanvas->Pen->Color = clBlack;
    pCanvas->Rectangle(0, 0, width, height);
}

inline void Kmeans::DrawPoint() {
    ClearScreen(pImage->Canvas);
    for (int i = 0; i < k; ++i) {
        TCluster::iterator it;
        for (it = clusters[i].begin(); it != clusters[i].end(); ++it)
            it->Draw(pImage, i);
        centroids[i].Draw(pImage, i);
    }
}

inline void Kmeans::FreeMemory() {
    for (int i = 0; i < k; ++i) {
        if (!clusters[i].empty())
            clusters[i].clear();
    }
    clusters.clear();
}

inline void Kmeans::Algorithm() {
    GeneratePoints();
    GenerateCentroids();
    do  {
        GenerateClusters();
        DrawPoint();
        Sleep(100);
        pImage->Refresh();
    } while (CentroidWasChanged());
    DrawPoint();
    FreeMemory();
}
#endif

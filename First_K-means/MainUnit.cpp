//---------------------------------------------------------------------------
#pragma hdrstop
#define MAXTRACKBAR 25
#include <vcl.h>
#include "MainUnit.h"
#include <cstdlib>
#include <cwchar>
#include <ctime>
#include <cmath>
#include "point.h"
#include "kmeans.h"
#include "kmeans.cpp"

using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

int n, k, width, height;

TForm1 *Form1;
TCanvas *PCanvas;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner): TForm(Owner) { }
//---------------------------------------------------------------------------
void __fastcall TForm1::StartButtonClick(TObject *Sender) {
    int n = CountPoints->Text.ToInt();
    int k = CountClusters->Text.ToInt();
    Image1->Tag = RadiusOfPoints->Text.ToInt();
    if (k < 24 && k > 0) {
        Kmeans object(n, k, width, height, Image1);
        clock_t time = clock();
        object.Algorithm();
        time = clock() - time;
        ShowMessage(FloatToStrF(time/CLOCKS_PER_SEC, ffGeneral, 5, 3).c_str());
    } else
        ShowMessage(L"Введите K меньше 25");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender) {
    width = Form1->Image1->ClientWidth;
    height = Form1->Image1->ClientHeight;

    PCanvas = Form1->Image1->Canvas;
    PCanvas->Brush->Color = clWhite;
    PCanvas->Pen->Color = clBlack;
    PCanvas->Pen->Width = 3;
    PCanvas->Rectangle(0, 0, Form1->Image1->Width, Form1->Image1->Height);
}
//---------------------------------------------------------------------------

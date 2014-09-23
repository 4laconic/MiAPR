#ifndef pointh
#define pointh
#define ll long long
#include <utility>
#include <vcl.h>
class point {
private:
    int x, y;
    bool centroid;
public:
    point() {
        x = -1;
        y = -1;
    };
    point(int x) { }
    point(int l, int r) {
        x = l;
        y = r;
        this->centroid = false;
    }
    void SetKernel(){
        this->centroid = true;
    }
    void UnsetKernel() {
        this->centroid = false;
    }
    int GetX() { return x; }
    int GetY() { return y; }
    int SetX(int data) { x = data; }
    int SetY(int data) { y = data; }
    inline void Draw(TImage *pImage, char color);
    inline bool operator!=(point compared);
};

inline bool point::operator!=(point compared) {
    return x != compared.GetX() || y != compared.GetY();
}

inline void point::Draw(TImage *pImage, char color) {
    TColor tempColor;
    switch (color) {
        case 0: tempColor = clRed; break;
        case 1: tempColor = clGreen; break;
        case 2: tempColor = clBlue; break;
        case 3: tempColor = (TColor)0x3C14DC; break;
        case 4: tempColor = clMaroon; break;
        case 5: tempColor = clOlive; break;
        case 6: tempColor = clNavy; break;
        case 7: tempColor = clPurple; break;
        case 8: tempColor = clTeal; break;
        case 9: tempColor = clGray; break;
        case 10: tempColor = clFuchsia; break;
        case 11: tempColor = clAqua; break;
        case 12: tempColor = clSkyBlue; break;
        case 13: tempColor = (TColor)0xE22B8A; break;
        case 14: tempColor = (TColor)0x3C14DC; break;
        case 15: tempColor = clSilver; break;
        case 16: tempColor = (TColor)0x5EFF00; break;
        case 17: tempColor = (TColor)0xFF005E; break;
        case 18: tempColor = (TColor)0xDEFF00; break;
        case 19: tempColor = (TColor)0x00FFA2; break;
        case 20: tempColor = (TColor)0xD670DA ; break;
        case 21: tempColor = (TColor)0xBBBB38; break;
        case 22: tempColor = (TColor)0x79BB38; break;
        case 23: tempColor = (TColor)0xBA8F38; break;
        case 24: tempColor = (TColor)0xBB38B6; break;
        case 25: tempColor = (TColor)0xBB3875; break;
    }
    pImage->Canvas->Pen->Color = tempColor;
    pImage->Canvas->Brush->Color = tempColor;
    if (centroid) {
        pImage->Canvas->Pen->Color = (TColor)0x0053FF;
        pImage->Canvas->Brush->Color = (TColor)0x00ABFF;
        pImage->Canvas->Ellipse(x, y, x + 18, y + 18);
        pImage->Canvas->Brush->Style = bsClear;
        short deltaX = color < 10 ? x + 6 : x + 3;
        pImage->Canvas->TextOut(deltaX, y + 2, IntToStr(color + 1).c_str());
    } else
        pImage->Canvas->Ellipse(x, y, x + pImage->Tag, y + pImage->Tag);
}

#endif

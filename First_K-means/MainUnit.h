//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.XPMan.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TImage *Image1;
    TButton *StartButton;
    TXPManifest *XPManifest1;
    TGroupBox *GroupBox1;
    TLabel *Label1;
    TLabel *Label2;
    TEdit *CountPoints;
    TEdit *CountClusters;
    TLabel *Label3;
    TEdit *RadiusOfPoints;
    void __fastcall StartButtonClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

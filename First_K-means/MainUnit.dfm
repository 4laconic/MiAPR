object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 'K-means'
  ClientHeight = 656
  ClientWidth = 802
  Color = clBtnFace
  DefaultMonitor = dmMainForm
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = True
  Position = poDesigned
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 8
    Top = 72
    Width = 785
    Height = 575
  end
  object StartButton: TButton
    Left = 388
    Top = 12
    Width = 406
    Height = 52
    Caption = 'Start'
    TabOrder = 0
    OnClick = StartButtonClick
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 369
    Height = 58
    Caption = 'Settings'
    TabOrder = 1
    object Label1: TLabel
      Left = 16
      Top = 24
      Width = 21
      Height = 13
      Caption = 'N  ='
    end
    object Label2: TLabel
      Left = 138
      Top = 24
      Width = 17
      Height = 13
      Caption = 'K ='
    end
    object Label3: TLabel
      Left = 256
      Top = 24
      Width = 18
      Height = 13
      Caption = 'R ='
    end
    object CountPoints: TEdit
      Left = 43
      Top = 21
      Width = 73
      Height = 21
      NumbersOnly = True
      TabOrder = 0
      Text = '50'
    end
    object CountClusters: TEdit
      Left = 161
      Top = 21
      Width = 73
      Height = 21
      NumbersOnly = True
      TabOrder = 1
      Text = '3'
    end
    object RadiusOfPoints: TEdit
      Left = 280
      Top = 21
      Width = 73
      Height = 21
      MaxLength = 1
      NumbersOnly = True
      TabOrder = 2
      Text = '3'
    end
  end
  object XPManifest1: TXPManifest
    Left = 808
    Top = 16
  end
end

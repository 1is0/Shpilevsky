object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 241
  ClientWidth = 607
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Gauge1: TGauge
    Left = 438
    Top = 20
    Width = 161
    Height = 105
    Kind = gkPie
    Progress = 0
  end
  object Value: TLabel
    Left = 380
    Top = 63
    Width = 37
    Height = 22
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 312
    Top = 64
    Width = 46
    Height = 22
    Caption = 'Value'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Label1: TLabel
    Left = 72
    Top = 40
    Width = 72
    Height = 19
    Caption = 'Position:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 162
    Top = 37
    Width = 81
    Height = 22
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Button1: TButton
    Left = 63
    Top = 105
    Width = 161
    Height = 57
    Caption = 'Add sth in queue'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button3: TButton
    Left = 32
    Top = 168
    Width = 75
    Height = 25
    Caption = '<<<<<'
    TabOrder = 1
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 168
    Top = 168
    Width = 75
    Height = 25
    Caption = '>>>>>'
    TabOrder = 2
    OnClick = Button4Click
  end
  object ListBox1: TListBox
    Left = 272
    Top = 123
    Width = 121
    Height = 97
    BevelKind = bkFlat
    BevelOuter = bvRaised
    BorderStyle = bsNone
    DoubleBuffered = False
    ItemHeight = 13
    ParentDoubleBuffered = False
    TabOrder = 3
  end
end

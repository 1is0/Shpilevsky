object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 570
  ClientWidth = 796
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
  object Label1: TLabel
    Left = 84
    Top = 40
    Width = 44
    Height = 13
    Caption = #1060#1072#1084#1080#1083#1080#1103
  end
  object Label2: TLabel
    Left = 48
    Top = 75
    Width = 80
    Height = 13
    Caption = #1055#1088#1080#1079#1086#1074#1086#1077' '#1084#1077#1089#1090#1086
  end
  object Memo1: TMemo
    Left = 536
    Top = 376
    Width = 257
    Height = 185
    TabOrder = 0
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 376
    Width = 254
    Height = 185
    ColCount = 2
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 1
    ColWidths = (
      114
      133)
  end
  object Edit1: TEdit
    Left = 141
    Top = 37
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object Edit2: TEdit
    Left = 141
    Top = 72
    Width = 121
    Height = 21
    NumbersOnly = True
    TabOrder = 3
  end
  object TreeView1: TTreeView
    Left = 264
    Top = 376
    Width = 266
    Height = 185
    Indent = 19
    TabOrder = 4
  end
  object Button1: TButton
    Left = 88
    Top = 148
    Width = 121
    Height = 53
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 362
    Top = 148
    Width = 119
    Height = 53
    Caption = #1041#1072#1083#1072#1085#1089#1080#1088#1086#1074#1082#1072
    TabOrder = 6
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 224
    Top = 148
    Width = 121
    Height = 53
    Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1082#1083#1102#1095#1091
    TabOrder = 7
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 88
    Top = 236
    Width = 121
    Height = 55
    Caption = #1055#1088#1103#1084#1086#1081' '#1086#1073#1093#1086#1076
    TabOrder = 8
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 224
    Top = 236
    Width = 121
    Height = 55
    Caption = #1054#1073#1088#1072#1090#1085#1099#1081' '#1087#1086#1076#1093#1086#1076
    TabOrder = 9
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 362
    Top = 236
    Width = 121
    Height = 55
    Caption = #1055#1086' '#1074#1086#1079#1088#1072#1089#1090#1072#1085#1080#1102
    TabOrder = 10
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 487
    Top = 148
    Width = 121
    Height = 53
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1101#1083#1077#1084#1077#1085#1090
    TabOrder = 11
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 489
    Top = 236
    Width = 119
    Height = 55
    Caption = #1069#1083'-'#1086#1074' '#1074' '#1087#1088#1072#1074#1086#1081' '#1074#1077#1090#1082#1077
    TabOrder = 12
    OnClick = Button8Click
  end
end

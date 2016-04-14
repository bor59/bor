object Form1: TForm1
  Left = 192
  Top = 124
  Width = 886
  Height = 514
  Caption = #1042#1080#1079#1091#1072#1083#1100#1085#1072#1103' '#1082#1088#1080#1087#1090#1086#1075#1088#1072#1092#1080#1103
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 865
    Height = 401
    ActivePage = TabSheet4
    TabIndex = 2
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #1057#1087#1088#1103#1090#1072#1090#1100
      object Label1: TLabel
        Left = 660
        Top = 176
        Width = 3
        Height = 13
        Color = clBtnHighlight
        ParentColor = False
      end
      object Image1: TImage
        Left = 0
        Top = 0
        Width = 161
        Height = 121
        AutoSize = True
      end
      object Image3: TImage
        Left = 0
        Top = 0
        Width = 161
        Height = 121
        AutoSize = True
      end
      object Image2: TImage
        Left = 0
        Top = 0
        Width = 161
        Height = 121
        AutoSize = True
      end
      object Button4: TButton
        Left = 656
        Top = 268
        Width = 201
        Height = 41
        Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077
        TabOrder = 0
        OnClick = Button4Click
      end
      object Edit1: TEdit
        Left = 656
        Top = 240
        Width = 201
        Height = 21
        TabOrder = 1
      end
      object RadioButton1: TRadioButton
        Left = 488
        Top = 12
        Width = 161
        Height = 17
        Caption = #1048#1089#1093#1086#1076#1085#1086#1077' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077
        TabOrder = 2
        OnClick = RadioButton1Click
      end
      object RadioButton2: TRadioButton
        Left = 488
        Top = 36
        Width = 161
        Height = 17
        Caption = #1055#1086#1083#1091#1090#1086#1085#1086#1074#1086#1077' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077
        TabOrder = 3
        OnClick = RadioButton2Click
      end
      object RadioButton3: TRadioButton
        Left = 488
        Top = 60
        Width = 161
        Height = 17
        Caption = #1041#1080#1085#1072#1088#1085#1086#1077' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077
        TabOrder = 4
        OnClick = RadioButton3Click
      end
      object Button3: TButton
        Left = 656
        Top = 120
        Width = 201
        Height = 41
        Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100' '#1088#1072#1089#1089#1083#1072#1080#1074#1072#1085#1080#1077
        TabOrder = 5
        OnClick = Button3Click
      end
      object Button2: TButton
        Left = 656
        Top = 64
        Width = 201
        Height = 41
        Caption = #1055#1086#1083#1091#1095#1080#1090#1100' '#1073#1080#1085#1072#1088#1085#1086#1077' '#1080#1079#1086#1073#1072#1088#1078#1077#1085#1080#1077
        TabOrder = 6
        OnClick = Button2Click
      end
      object Button1: TButton
        Left = 656
        Top = 8
        Width = 201
        Height = 41
        Caption = #1055#1086#1083#1091#1095#1080#1090#1100' '#1087#1086#1083#1091#1090#1086#1085#1086#1074#1086#1077' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077
        TabOrder = 7
        OnClick = Button1Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1057#1077#1082#1088#1077#1090#1099
      ImageIndex = 1
      object Image4: TImage
        Left = 0
        Top = 0
        Width = 161
        Height = 121
        AutoSize = True
      end
      object Image5: TImage
        Left = 0
        Top = 0
        Width = 161
        Height = 121
        AutoSize = True
      end
    end
    object TabSheet4: TTabSheet
      Caption = #1057#1086#1074#1084#1077#1089#1090#1080#1090#1100
      ImageIndex = 3
      object Image6: TImage
        Left = 0
        Top = 0
        Width = 161
        Height = 121
        AutoSize = True
      end
      object Button5: TButton
        Left = 656
        Top = 32
        Width = 201
        Height = 41
        Caption = #1057#1086#1074#1084#1077#1089#1090#1080#1090#1100' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1103
        TabOrder = 0
        OnClick = Button5Click
      end
      object Button7: TButton
        Left = 656
        Top = 80
        Width = 201
        Height = 41
        Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1089#1077#1082#1088#1077#1090#1099
        TabOrder = 1
        OnClick = Button7Click
      end
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 437
    Width = 870
    Height = 19
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object Button6: TButton
    Left = 752
    Top = 408
    Width = 115
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 2
    OnClick = Button6Click
  end
  object OpenPictureDialog1: TOpenPictureDialog
    FileName = 'C:\Visual_Cript\Portal_2_STICKER_05.jpg'
    Left = 768
    Top = 24
  end
  object SavePictureDialog1: TSavePictureDialog
    Left = 800
    Top = 24
  end
  object MainMenu1: TMainMenu
    Left = 832
    Top = 24
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N3: TMenuItem
        Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077
        OnClick = Button4Click
      end
      object N4: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = N4Click
      end
    end
    object N2: TMenuItem
      Caption = #1042#1080#1079#1091#1072#1083#1080#1079#1072#1094#1080#1103
      object N5: TMenuItem
        Caption = #1055#1086#1083#1091#1090#1086#1085#1086#1074#1086#1077' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077
        OnClick = Button1Click
      end
      object N6: TMenuItem
        Caption = #1041#1080#1085#1072#1088#1085#1086#1077' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077
        OnClick = Button2Click
      end
      object N7: TMenuItem
        Caption = #1056#1072#1089#1089#1083#1072#1080#1074#1072#1085#1080#1077
        OnClick = Button3Click
      end
      object N8: TMenuItem
        Caption = #1057#1086#1074#1084#1077#1097#1077#1085#1080#1077
        OnClick = Button5Click
      end
    end
    object N9: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      OnClick = N9Click
    end
  end
end

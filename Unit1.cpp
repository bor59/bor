//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Iostream.h"
#include "Stdlib.h"
#include "Stdio.h"
#include "Conio.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Math.h"
#include "fstream.h"

int r1[2][2], r2[2][2], r3[2][2];
int r4[2][2], r5[2][2], r6[2][2];
int r[6][2][2];
//int *s1, *s2;
int s[1500][1500],s1[1500][1500], s2[1500][1500]; s3[1500][1500];
int m,n;
int k;
randomize();

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
 Button1->Enabled=false;
 Button2->Enabled=false;
 Button3->Enabled=false;
 Button5->Enabled=false;
 //заполнение двумерных массивов
  //0                           1
  r1[0][0]=1; r1[0][1]=0;       r2[0][0]=0; r2[0][1]=1;
  r1[1][0]=1; r1[1][1]=0;       r2[1][0]=0; r2[1][1]=1;
  //2                           3
  r3[0][0]=0; r3[0][1]=0;       r4[0][0]=1; r4[0][1]=1;
  r3[1][0]=1; r3[1][1]=1;       r4[1][0]=0; r4[1][1]=0;
  //4                           //5
  r5[0][0]=1; r5[0][1]=0;       r6[0][0]=0; r6[0][1]=1;
  r5[1][0]=0; r5[1][1]=1;       r6[1][0]=1; r6[1][1]=0;
  //объединение в 3-мерный массив 6х2х2
  r[0][0][0]=r1[0][0];  r[1][0][0]=r2[0][0];    r[2][0][0]=0;//r3[0][0];
  r[0][0][1]=r1[0][1];  r[1][0][1]=r2[0][1];    r[2][0][1]=0;//r3[0][1];
  r[0][1][0]=r1[1][0];  r[1][1][0]=r2[1][0];    r[2][1][0]=1;//r3[1][0];
  r[0][1][1]=r1[1][1];  r[1][1][1]=r2[1][1];    r[2][1][1]=1;//r3[1][1];

  r[3][0][0]=r4[0][0];  r[4][0][0]=r5[0][0];    r[5][0][0]=r6[0][0];
  r[3][0][1]=r4[0][1];  r[4][0][1]=r5[0][1];    r[5][0][1]=r6[0][1];
  r[3][1][0]=r4[1][0];  r[4][1][0]=r5[1][0];    r[5][1][0]=r6[1][0];
  r[3][1][1]=r4[1][1];  r[4][1][1]=r5[1][1];    r[5][1][1]=r6[1][1];
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
RadioButton1->Checked=true;
  Label1->Caption="";
  if ( OpenPictureDialog1->Execute() )
    {
     Image1->Picture->LoadFromFile( OpenPictureDialog1->FileName );
    }
  StatusBar1->Panels->Items[0]->Text="Открыт файл: "+
    OpenPictureDialog1->FileName+"  разрешение: "+
      Image1->Picture->Height+"x"+Image1->Picture->Width;
  Edit1->Text=OpenPictureDialog1->FileName;

  //имя файла из полного пути к файлу
  std::string s = Edit1->Text.c_str();
    std::string fileName;
    int i;
    for(i = s.length(); (s[i] != '\\') && (s[i] != '/') && i >= 0; --i)
    ;
    while (s[++i] != '\0')
        fileName += s[i];

    //вывод информации о файле
    Label1->Caption=Label1->Caption+"Имя файла: "+fileName.c_str()+"\n"+
      +"Разрешение: "+Image1->Picture->Height+"x"+Image1->Picture->Width;
    if( (Image1->Height >750)||(Image1->Height >750))
    {
      ShowMessage("Максимальный размер изображения должен быть 750х750px");
      Button1->Enabled=false;
    }
    else
    Button1->Enabled=true;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  RadioButton2->Checked=true;
  Image2->Picture->Bitmap->PixelFormat = pf24bit;
  Image2->Picture->Bitmap->Width = Image1->Width;
  Image2->Picture->Bitmap->Height = Image1->Height;
  Image1->Perform(WM_PAINT, (WPARAM)Image2->Picture->Bitmap->Canvas->Handle, 0);

  for (int y = Image2->Picture->Height - 1; y >= 0; --y)
  {
    TRGBTriple* scanLine = (TRGBTriple*)Image2->Picture->Bitmap->ScanLine[y];
    for (int x = Image2->Picture->Width - 1;  x >= 0; --x)
    {
      const BYTE gray = 0.222 * scanLine[x].rgbtRed +
                        0.707 * scanLine[x].rgbtGreen +
                        0.071 * scanLine[x].rgbtBlue;
      scanLine[x].rgbtGreen = gray;
      scanLine[x].rgbtRed = gray;
      scanLine[x].rgbtBlue = gray;
    }
  }
  Image2->Picture->SaveToFile("grey.jpg");
  Button2->Enabled=true; Button1->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 RadioButton3->Checked=true;
  Image3->Picture->Bitmap->PixelFormat = pf24bit;
  Image3->Picture->Bitmap->Width = Image2->Width;
  Image3->Picture->Bitmap->Height = Image2->Height;
  Image2->Perform(WM_PAINT, (WPARAM)Image3->Picture->Bitmap->Canvas->Handle, 0);
  BYTE  f;
  for (int y = Image3->Picture->Height - 1; y >= 0; --y)
  {
    TRGBTriple* scanLine = (TRGBTriple*)Image3->Picture->Bitmap->ScanLine[y];
    for (int x = Image3->Picture->Width - 1;  x >= 0; --x)
    {
      const BYTE gray = scanLine[x].rgbtRed + scanLine[x].rgbtGreen + scanLine[x].rgbtBlue;
      if (gray<128)
      f=0;
      else f=255;
      scanLine[x].rgbtGreen = f;
      scanLine[x].rgbtRed = f;
      scanLine[x].rgbtBlue = f;
    }
  }
  Image3->Picture->SaveToFile("bin.bmp");
  Button1->Enabled=false;
  Button2->Enabled=false;
  Button3->Enabled=true;;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  Button1->Enabled=false;
  Button2->Enabled=false;
  Button3->Enabled=false;
  Button5->Enabled=true;
   /*Graphics::TBitmap *bitmap=new Graphics::TBitmap;
   bitmap->LoadFromFile("bin.bmp");
   Image4->Canvas->Draw(20,0,bitmap);
   Image4->Picture->SaveToFile("layer1.bmp");  */

  Image3->Picture->Bitmap->PixelFormat = pf24bit;
  Image3->Picture->Bitmap->Width = Image2->Width;
  Image3->Picture->Bitmap->Height = Image2->Height;
  Image2->Perform(WM_PAINT, (WPARAM)Image3->Picture->Bitmap->Canvas->Handle, 0);

  for (int y = Image3->Picture->Height - 1; y >= 0; --y)
  {
    TRGBTriple* scanLine = (TRGBTriple*)Image3->Picture->Bitmap->ScanLine[y];
    for (int x = Image3->Picture->Width - 1;  x >= 0; --x)
    {
      const BYTE gray = scanLine[x].rgbtRed + scanLine[x].rgbtGreen + scanLine[x].rgbtBlue;
      if (gray > 128)
      {
        s[y][x]=0; //если белый, записываем 0
      }
      else s[y][x]=1; //иначе 1


      scanLine[x].rgbtGreen = gray;
      scanLine[x].rgbtRed = gray;
      scanLine[x].rgbtBlue = gray;
    }
  }

  ofstream t;  ofstream e;
  t.open("text.txt", ios::out);  e.open("text5.txt", ios::out);

  for(int i=0; i<Image3->Picture->Width; i++)
  {
    for(int j=0; j<Image3->Picture->Height; j++)
    {
      k=random(6);
      if(s[i][j]==0)
      {

        s1[2*i][2*j]=r[k][0][0];        s2[2*i][2*j] = r[k][0][0];
        s1[2*i][2*j+1]=r[k][0][1];      s2[2*i][2*j+1] = r[k][0][1];
        s1[2*i+1][2*j]=r[k][1][0];      s2[2*i+1][2*j] = r[k][1][0];
        s1[2*i+1][2*j+1]=r[k][1][1];    s2[2*i+1][2*j+1] = r[k][1][1];
      }
      else
      {
        if((k == 1)||(k == 3)||(k == 5))
        {
          s1[2*i][2*j]=r[k][0][0];        s2[2*i][2*j] = r[k-1][0][0];
          s1[2*i][2*j+1]=r[k][0][1];      s2[2*i][2*j+1] = r[k-1][0][1];
          s1[2*i+1][2*j]=r[k][1][0];      s2[2*i+1][2*j] = r[k-1][1][0];
          s1[2*i+1][2*j+1]=r[k][1][1];    s2[2*i+1][2*j+1] = r[k-1][1][1];
        }
        if((k == 0)||(k == 2)||(k == 4))
        {
          s1[2*i][2*j]=r[k][0][0];        s2[2*i][2*j] = r[k+1][0][0];
          s1[2*i][2*j+1]=r[k][0][1];      s2[2*i][2*j+1] = r[k+1][0][1];
          s1[2*i+1][2*j]=r[k][1][0];      s2[2*i+1][2*j] = r[k+1][1][0];
          s1[2*i+1][2*j+1]=r[k][1][1];    s2[2*i+1][2*j+1] = r[k+1][1][1];
        }
      }
      t<<s1[i][j]<<" ";
      e<<s2[i][j]<<" ";
    }
    t<<"\n";
    e<<"\n";
  }
  t.close();    e.close();

  Image4->Picture->Bitmap->PixelFormat = pf24bit;
  Image4->Picture->Bitmap->Width = Image3->Width*2;
  Image4->Picture->Bitmap->Height = Image3->Height*2;
  Image3->Perform(WM_PAINT, (WPARAM)Image4->Picture->Bitmap->Canvas->Handle, 0);
  BYTE  f;
  for (int y = Image4->Picture->Height - 1; y >= 0; --y)
  {
    TRGBTriple* scanLine = (TRGBTriple*)Image4->Picture->Bitmap->ScanLine[y];
    for (int x = Image4->Picture->Width - 1;  x >= 0; --x)
    {
    //  const BYTE gray = scanLine[x].rgbtRed + scanLine[x].rgbtGreen + scanLine[x].rgbtBlue;
      if (s1[y][x]==1)
        f=0;
      else f=255;
      scanLine[x].rgbtGreen = f;
      scanLine[x].rgbtRed = f;
      scanLine[x].rgbtBlue = f;
    }
  }
  Image4->Picture->SaveToFile("layer1.bmp");

  Image5->Picture->Bitmap->PixelFormat = pf24bit;
  Image5->Picture->Bitmap->Width = Image3->Width*2;
  Image5->Picture->Bitmap->Height = Image3->Height*2;
  Image3->Perform(WM_PAINT, (WPARAM)Image5->Picture->Bitmap->Canvas->Handle, 0);
  BYTE h;
  for (int y = Image5->Picture->Height - 1; y >= 0; --y)
  {
    TRGBTriple* scanLine = (TRGBTriple*)Image5->Picture->Bitmap->ScanLine[y];
    for (int x = Image5->Picture->Width - 1;  x >= 0; --x)
    {
    //  const BYTE gray = scanLine[x].rgbtRed + scanLine[x].rgbtGreen + scanLine[x].rgbtBlue;
      if (s2[y][x]==1)
        h=0;
      else h=255;
      scanLine[x].rgbtGreen = h;
      scanLine[x].rgbtRed = h;
      scanLine[x].rgbtBlue = h;
    }
  }
  Image5->Picture->SaveToFile("layer2.bmp");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
  Image1->Visible=true;
  Image2->Visible=false;
  Image3->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
  Image1->Visible=false;
  Image2->Visible=true;
  Image3->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
  Image1->Visible=false;
  Image2->Visible=false;
  Image3->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
Button5->Enabled=false;
  Image6->Picture->Bitmap->PixelFormat = pf24bit;
  Image6->Picture->Bitmap->Width = Image5->Width;
  Image6->Picture->Bitmap->Height = Image5->Height;
  Image5->Perform(WM_PAINT, (WPARAM)Image6->Picture->Bitmap->Canvas->Handle, 0);
  BYTE  f;
  for (int i = Image6->Picture->Height - 1; i >= 0; --i)
  {
    TRGBTriple* scanLine = (TRGBTriple*)Image6->Picture->Bitmap->ScanLine[i];
    for (int j = Image6->Picture->Width - 1;  j >= 0; --j)
    {
     // const BYTE gray = scanLine[j].rgbtRed + scanLine[j].rgbtGreen + scanLine[j].rgbtBlue;
      if (s1[i][j]==s2[i][j])
        s3[i][j] = 0;
      else s3[i][j]=1;
      if (s3[i][j]==1)
        f=0;
      else f=255;

      scanLine[j].rgbtGreen = f;
      scanLine[j].rgbtRed = f;
      scanLine[j].rgbtBlue = f;
    }
  }
  Image6->Picture->SaveToFile("resultat.bmp");
}
//---------------------------------------------------------------------------




void __fastcall TForm1::N4Click(TObject *Sender)
{
  Close();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N10Click(TObject *Sender)
{
  Form2->Show();
  
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N9Click(TObject *Sender)
{
 Form2->Show();        
}
//---------------------------------------------------------------------------


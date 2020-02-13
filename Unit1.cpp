//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int ballHorizontalMovement = -5;
int ballVerticalMovement = -5;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerBallTimer(TObject *Sender)
{
   ball->Left+= ballHorizontalMovement;
   ball->Top+=ballVerticalMovement;

   //bounce from the top
   if(ball->Top-5 <= background->Top) ballVerticalMovement = - ballVerticalMovement;
   //bounce from the bottom
   if(ball->Top+ball->Height+5 >= background->Height) ballVerticalMovement = -ballVerticalMovement;
   //fail
   if(ball->Left <= paddle1->Left-15 || ball->Left+ball->Width >= paddle2->Left+15)
   {
      timerBall->Enabled=false;
      ball->Visible=false;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(Key == VK_UP) paddle2up->Enabled = true;
   if(Key == VK_DOWN) paddle2down->Enabled = true;
   if(Key == 65) paddle1up->Enabled = true;
   if(Key == 90) paddle1down->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle1upTimer(TObject *Sender)
{
 if(paddle1->Top >= background->Top+10) paddle1->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle1downTimer(TObject *Sender)
{
  if(paddle1->Top+paddle1->Height <= background->Height-10) paddle1->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle2upTimer(TObject *Sender)
{
   if(paddle2->Top >= background->Top+10) paddle2->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle2downTimer(TObject *Sender)
{
  if(paddle1->Top+paddle1->Height <= background->Height-10) paddle2->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(Key == VK_UP) paddle2up->Enabled = false;
   if(Key == VK_DOWN) paddle2down->Enabled = false;
   if(Key == 65) paddle1up->Enabled = false;
   if(Key == 90) paddle1down->Enabled = false;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int ballHorizontalMovement = -6;
int ballVerticalMovement = -6;

int numberOfBouncesWithPaddles=0;
int player1points=0;
int player2points=0;
bool isFail=false;

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
   //player1 fail
   if(ball->Left <= paddle1->Left-15)
   {
      timerBall->Enabled=false;
      ball->Visible=false;
      player2points++;
      Label2->Caption="Punkt dla gracza prawego >";
      Label2->Visible=true;
      isFail=true;
   }
   //player2 fail
   if(ball->Left+ball->Width >= paddle2->Left+15)
   {
      timerBall->Enabled=false;
      ball->Visible=false;
      player1points++;
      Label2->Caption="< Punkt dla gracza lewego";
      Label2->Visible=true;
      isFail=true;
   }
   //bounce the ball with paddle1
   else if(ball->Top+ball->Height/2 > paddle1->Top && ball->Top < paddle1->Top+paddle1->Height &&
   ball->Left < paddle1->Left+paddle1->Width)
   {
       if(ballHorizontalMovement < 0) ballHorizontalMovement = - ballHorizontalMovement;

       numberOfBouncesWithPaddles++;
   }
   //bounce the ball with paddle2
   else if(ball->Top+ball->Height/2 > paddle2->Top &&
   ball->Top < paddle2->Top+paddle2->Height && ball->Left+ball->Width > paddle2->Left)
   {
       if(ballHorizontalMovement > 0) ballHorizontalMovement = - ballHorizontalMovement;

       numberOfBouncesWithPaddles++;
   }
      if(isFail)
   {
      Label3->Caption="Ilosc odbic: " + IntToStr(numberOfBouncesWithPaddles);
      Label3->Visible=true;
      scoreboard->Caption=IntToStr(player1points)+ ":" + IntToStr(player2points);
      scoreboard->Visible=true;
      Button1->Visible=true;
      Button2->Visible=true;
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
  if(paddle2->Top+paddle2->Height <= background->Height-10) paddle2->Top += 10;
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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  timerBall->Enabled=true;
  isFail=false;
  paddle1->Enabled=true;
  paddle2->Enabled=true;
  Button1->Visible=false;
  Label1->Visible=false;
  Label2->Visible=false;
  Label3->Visible=false;
  scoreboard->Visible=false;
  player1points=0;
  player2points=0;
  numberOfBouncesWithPaddles=0;
  ball->Top=224;
  ball->Left=536;
  ball->Visible=true;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
  timerBall->Enabled=true;
  isFail=false;
  paddle1->Enabled=true;
  paddle2->Enabled=true;
  Button1->Visible=false;
  Label1->Visible=false;
  Label2->Visible=false;
  Label3->Visible=false;
  scoreboard->Visible=false;
  numberOfBouncesWithPaddles=0;
  ball->Top=224;
  ball->Left=536;
  ball->Visible=true;
}
//---------------------------------------------------------------------------


#include <string>
#include "nonproperty.h"
#include "display.h"
#include "TimsLine.h"
#include <iostream>
#include "player.h"
using namespace std;

TimsLine:: TimsLine (Display *d, string name, int position): NonProperty{d, name, position} {}

void TimsLine:: canMove (Player * p, int d1, int d2) {
p->setNumInLine (p->getNumInLine () +1);
if (d1 == d2) {
p->setNumInLine(0);
p->changeInLine();
d->rollDouble();
d->outOfTimsLine();
//return true;
}
else if (p->getNumInLine() == 3) {
if (p->getSelfRollUp() == 0) {
d->mustPay50(); //not have rollup must pay 50 on third time 
p->changeInLine();
p->setNumInLine (0);
p->payMoney(50);

}
else {
d->howToGetOutMust(); //asked the player if want to pay 50 or use a rollupcup 
string n;
cin >> n;
if (n == "cup") {
p->removeSelfRollUp ();
p->changeInLine ();
p->setNumInLine (0);
d->usedCup(); //used a cup to get out of jail
d->outOfTimsLine();
}
else {
if (p->getCash() >= 50) {
p->setNumInLine (0);
p->changeInLine ();
p->payMoney (50);
d->outOfTimsLine();
}
else {
d->notEnoughCash ();
d->usedCup();
p->removeSelfRollUp ();
p->changeInLine();
p->setNumInLine(0);
d->outOfTimsLine();
}
}
}
}
else {
string n;
if (p->getSelfRollUp () == 0) {
d->noCups(); //no cups
d->doYouWannaPay50(); //ask if wanna pay 50
cin >> n;
if (n == "y" || n == "Y") {
if (p->getCash () >= 50) {
p->setNumInLine(0);
p->changeInLine();
p->payMoney(50);
d->outOfTimsLine();
}
else {
d->notEnoughCash();
//p->setNumInLine(p->getNumInLine () + 1);
d->stillInLine();
}
}
else {
d->stillInLine();
//p->setNumInLine(p->getNumInLine () + 1);
}
}
else {
d->howToGetOut ();
cin >> n;
if (n == "cup") {
p->removeSelfRollUp ();
p->changeInLine();
p->setNumInLine(0);
d->usedCup();
d->outOfTimsLine();
}
else if ( n == "pay") {
if (p->getCash() >= 50) {
p->setNumInLine(0);
p->changeInLine ();
p->payMoney(50);
d->outOfTimsLine();
}
else{
d->notEnoughCash();
//p->setNumInLine ( p->getNumInLine () + 1);
d->stillInLine(); //Still in tims line
}
}
else {
//p->setNumInLine (p->getNumInLine() + 1);
d->stillInLine();
}
}
}
}

TimsLine:: ~TimsLine () {};

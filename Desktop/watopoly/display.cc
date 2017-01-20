#include <string>
#include "display.h"
#include <iostream>
using namespace std;
void Display:: welcome () {cout<<"Welcome to Watopoly!!"<<endl;}
void Display:: askforrule() {cout <<"If you want to read the rules, enter Y or y."<<endl;}
void Display:: rule() {cout<<"A game of Watopoly consists of a board that has 40 squares. When a player moves, an action specific to the square they land on occurs. The goal of the game is to be the only player to not drop out of university (declare bankruptcy). Play proceeds as follows: players take turns moving around the board, buying and improving on-campus buildings (properties), and paying tuition (rent)."<<endl;
cout <<"The commands you can enter are as follow: "<<endl;
cout <<"roll (used if the player can roll): the player rolls two dice, moves the sum of the two dice and takes action on the square they landed on."<<endl;
cout<<"next (used if the player cannot roll): give control to the next player."<<endl;
cout<<"trade <name> <give> <receive>: offers a trade to name with the current player offering give and requesting receive, where give and receive are either amounts of money or a property name. Responses are accept and reject. For example,"<<endl;
cout<<"    trade Brad 500 DC indicates that the current player is willing to give Brad $500 in exchange for the DC building"<<endl;
cout<<"    trade Rob DC MC indicates that the current player is willing to give Rob DC in exchange for MC"<<endl;
cout<<"    trade Kevin MC 500 indicates that the current player is willing to give Kevin MC in exchange for $500"<<endl;
cout<<"improve <property> buy/sell: attempts to buy or sell an improvement for property."<<endl;
cout<<"mortgage <property>: attempts to mortgage property."<<endl;
cout<<"unmortgage <property>: attempts to unmortgage property."<<endl;
cout<<"bankrupt: player declares bankruptcy. This command is only available when a player must pay more money then they currently have."<<endl;
cout<<"assets: displays the assets of the current player. Does not work if the player is deciding how to pay Tuition."<<endl;
cout<<"all: displays the assets of every player. For verifying the correctness of your transactions. Does not work if a player is deciding how to pay Tuition."<<endl;
cout<<"save <filename>: saves the current state of the game (as per the description below) to the given file."<<endl;
cout<<"q: quit the game without save."<<endl;
cout<<"Now lets start!!!!!"<<endl;}

void Display:: noRent () {cout << "This building has been mortgaged, no rent needed." << endl;}
void Display:: nextTimeQ () {cout << "See You Next Time!!" << endl;}
void Display:: detachP (string name) {cout << name << " is out of the game." << endl;}
void Display:: cannotTradeM () {cout << "Cannot trade mortgaged building." << endl;}
void Display:: everyM () {cout << "Sold all improvements, and mortgaged all buildings." << endl;}
void Display:: raisedEnough () {cout << "Congratulations!!!!!!!! You raised enough money." <<endl;}
void Display:: cash (string name, int cash) {cout << name << " has $" << cash << "." << endl;}
void Display:: yourOwn () {cout << "You arrived at your own place." << endl;}
void Display:: sMortgage () {cout << "Successful Mortgage!" <<endl;}
void Display:: sUnmortgage () {cout << "Successful Unmortgage!" << endl;}
void Display:: printGymResM (string name, int price) {cout << name << ": $" << price << " (mortgaged)" <<endl;  }
void Display:: printGymRes (string name, int price) {cout << name << ": $" << price << endl;}
void Display:: printAcademicM (string name, int price, int im) {cout << name << ": $" << price << " improvement(" << im << ") (mortgaged)" << endl;}
void Display:: printAcademic (string name, int price, int im) {cout << name << ": $" << price << " improvement(" << im << ")" << endl;}

void Display:: enterPlayer () {cout << "Please enter player name:" << endl;}
void Display:: mortgageFirst () {cout << "This building is not mortgaged." << endl; }

void Display:: invalidTrade () {cout << "Trade cannot be made, either the building does not exist or you have no onwership over the building." << endl; }

void Display:: moneyToMoney () {cout << "Cannot trade Money for Money." << endl;}
void Display:: sTrade () {cout << "Successful Trade!!!!!!!!!!!!!" << endl; }

void Display:: wantBankrupt ()
 {cout << " You are facing Bankruptcy, do you want to declear Bankrupt? If so please enter Y, else enter N to sell all improvements and mortgage all properties to raise money" << endl; }

void Display:: askTrade (string name) {cout << name << " do you want to trade? If so enter Y, else enter anything else" << endl;}

void Display:: gooseAttack () {cout << "ATTACKED BY A GOOSE" << endl; }

void Display:: invalidAddImprovement () {cout << "Cannot have make more than five Improvement ona single building." << endl;}

void Display:: invalidInput() {cout<< "INVALID INPUT" << endl;}

void Display:: sAddImprovement () {cout << "Improvement has been successfully made" << endl;}

void Display:: invalidDeleteImprovement () {cout << "No improvement has been made to this building, so cannot be deleted" << endl;}

void Display:: payCoopFee () {cout << "Arrive on Coop Fee, must pay $50 COOP Fee" << endl;}

void Display:: sDeleteImprovement () {cout << "Improvement has been successfully removed" << endl;}

void Display:: goToTims () {cout << "Arrived at To Go Tims. Transfering to DC Tims line (must roll double or use Roll Up Cups on next turn in order to leave)" << endl;}

void Display:: invalidPlayer () {cout << "Player does not exist." << endl;}

void Display:: printAsset (int n, string name) {cout << name << " owns $" << n << endl;}

void Display:: notOwned (string s) {cout << "You do not own " << s << "." << endl;}

void Display:: cannotImprove (string s) {cout << "Cannot make Imrpovement on " << s << ". Either it is not an Academic Building or you must collect all monopoly first." << endl;  }

void Display:: OSAPCollection () {cout << "Passed over OSAP Collection, collect $200 of OSAP money." << endl;} 

void Display:: howToPayTuition () {cout << "Arrive at Pay Tuition." << endl; cout<< " How would you want to pay. Enter 300 or 10%. " <<endl; }

void Display:: sellFirst () {cout << "You must sell all Improvement first before trying to mortage." << endl; }

void Display:: alreadyMortgage () {cout << "Cannot mortage this building, it is already mortgaged." << endl;}

void Display:: gotACup () {cout << "Congratulation!! You recieved a Roll Up Cup!!!!!!" << endl;}

void Display:: gotMoney (int i) {cout << "Congratulation!! You hace received $" << i << " in NeedelsHall!!!" << endl; }

void Display:: lostMoney (int i) {cout << "You lost $" << i << " in NeedlesHall." << endl;}

void Display:: arriveSLC () {cout << "You have arrived at SLC." << endl;}

void Display:: arriveNeedles() {cout << "You have arrived at NeedlesHall." << endl;}

void Display:: goForward(int i) {cout << "You moved forward " << i << " steps." << endl; }

void Display:: goBack (int i) {cout << "You moved back " << i << " steps." << endl;}

void Display:: outOfTimsLine() {cout << "congratulation!!! You just got out of DC Tims Line. " << endl;}

void Display:: rollDouble () {cout << "WOW, rolled a Double." << endl;}

void Display:: notEnoughCash () {cout << "Sorry, you do not have enough cash." << endl;}

void Display:: failedAuction () {cout << "Auction failed! Building is back to the open market." << endl;}

void Display:: sAuction (string name) {cout <<"Congratulations!!!! " <<  name  << " win the Auction." << endl; }

void Display:: startAuction (string name) {cout << name << " will be Auctioned." << endl; }

void Display:: wantedPrice (string s) {cout << s  << ": Please enter the price you want to pay for the building." << " Enter 0 if you do not want the building." <<endl;}

void Display:: playerQuit (string name) {cout << name << " is out of the Auction." <<endl;}

void Display:: priceIsLow () {cout << "Sorry, you price is lower than the highest price so far." << endl;}

void Display:: playerAuction (string name, int price) {cout << name << "'s bidding price is $" << price << endl;}

void Display:: mustPay50 () {cout << "Your third time in DC Tims Line, and you don't have a cup so you must pay $50." << endl; }

void Display:: howToGetOutMust () {cout << "Your third time in DC Tims Line, enter cup if you to use your Roll Up Cups, or $50 will be automatically deducted" << endl;  } 

void Display:: howToGetOut () {cout << "If want to use you Roll Up cups, please enter cup:" << endl;
                               cout << "If want to pay $50, enter pay:" << endl;
                               cout << "(any other input will leave in DC Tims Line)" << endl; }

void Display:: usedCup () {cout <<"You used a Roll Up Cup." << endl;}

void Display:: noCups () {cout << "You have no Roll Up Cups." << endl;}

void Display:: doYouWannaPay50() {cout << "Do You want to pay $50 to get out of DC Tims Line? Enter Y if you want to." << endl;}

void Display:: stillInLine () {cout << "You remained in DC Tims Line." << endl; }


void Display:: enterNumPlayer () {cout << "Please enter the number of players." << endl;}

void Display:: tooMuchPlayer () {cout << "Cannot have a game with more than 8 people." << endl; }

void Display:: tooLessPlayer () {cout << "Cannot have a game with less then 6 people." << endl;}

void Display:: playerExist () {cout << " Player Name already exist please enter another name" << endl;}

void Display:: gameStart () {cout << "Game Starts!!!" << endl;}

void Display:: whoTurn (string name) {cout << name << "'s turn, please enter command: " << endl;}

void Display:: youWin() {cout << "You won!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;}

void Display:: alreadyRolled () {cout << "You have already rolled for this turn, please enter another command: " << endl;}

void Display:: cannotCheckAsset () {cout << "You have to pay Tuition, cannot check your asset." << endl;}

void Display:: arriveAt (string s) {cout << "You have arrived at " << s << endl;}

void Display:: wannaBuy (int i, string name) {cout << "Do You want to buy " << name << " for $" << i << "? Enter Y if you want to buy." << endl;}

void Display:: payRent (int i) {cout << "You need to pay $" << i << " as rent." << endl;}

void Display:: buildingDoesNotExist () {cout << "Building does not exist." << endl;}

void Display:: nextTime () { cout << " Game saved for next time." << endl;}

void Display:: invalidBankrupt () {cout <<" YOu have enough money, bankrupt cannot be decleared!" << endl;}

//void Display:: invalidBankrupt () {cout << "You have enough money, bankrupt cannot be decleared!" << endl;}

void Display:: needBuildingType () {cout << "You need to enter a Building Type" << endl;}

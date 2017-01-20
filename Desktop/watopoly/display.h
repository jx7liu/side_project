#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#include <string>

class Display{
public:
void welcome();
void askforrule();
void rule();
void noRent ();
void nextTimeQ ();
void detachP(std:: string name);
void everyM();
void cannotTradeM();
void raisedEnough();
void printGymResM (std::string name, int price);
void printGymRes (std:: string name, int price);
void printAcademicM (std:: string name, int price, int im);
void printAcademic (std:: string name, int price, int im);
void sMortgage ();
void sUnmortgage ();
void cash (std:: string name, int cash);
void yourOwn();
void moneyToMoney ();
void sTrade ();
void enterPlayer();
void invalidTrade();
void wantBankrupt();
void askTrade (std:: string name);
void gooseAttack();
void invalidAddImprovement();// call bu building, improvement reached limit cannot add
void invalidInput();//called player , if user entered invalid input (YN)
void sAddImprovement (); //successfully added improvement 
void payCoopFee (); // pay 150 copp fee
void sDeleteImprovement (); //delete on improvement
void invalidDeleteImprovement (); 
void goToTims();//go to dc tims
void invalidPlayer();
void printAsset(int n, std:: string name);//print all assets
void notOwned (std:: string s); //trying to make improvement, on building not owned 
void cannotImprove (std:: string s); //cannot improve because didnt collect buidling of same type 
void OSAPCollection (); //collected 200 osap
void howToPayTuition();//ask for 300 or 10%
void sellFirst();// sell improvement first then mortage 
void alreadyMortgage(); // builidng is already mortgaged
void mortgageFirst (); //the building is not mortgage, but try to unmortgage
void gotACup (); //got a cup in needles hall or SLC
void gotMoney (int n); // got money is needles hall
void lostMoney(int n); // lost mony in needles hall
void arriveSLC (); //arrive at slc
void arriveNeedles();//arrived at needleshall
void goForward(int i);//moving forward i step (slc)
void goBack(int i);// moving back i step (slc)
void outOfTimsLine(); //got out of tims line
void rollDouble (); //rolled a double of tims line
void notEnoughCash(); //do have enough cash

//Auction
void failedAuction();// no go the property, go back to selling 
void sAuction (std:: string name); // the person s got the property
void startAuction (std:: string name); // which building will be auctioned, name = building name 
void wantedPrice (std::string);// ask player to under a price of the building, 0 = out of auction
void playerQuit (std:: string name); //who is out of auction, name = player name
void priceIsLow (); // price is lower than than last player, you r auction of the auction
void playerAuction (std:: string name, int price); // name of player auction a nd give n amount

//timsline
void mustPay50 (); // third time in line, dont have cup, must pay 50
void howToGetOut(); //ask the player how want to get out, 50 or cup 
void howToGetOutMust ();// third time in, must get out
void usedCup(); //used a rollupcup to get out of line
void noCups(); //player dont have cups
void doYouWannaPay50(); // player has not cups, ask if they wanna pay fifty
void stillInLine (); // still in line, didnt leave
//main
void enterNumPlayer ();// enter the number of player
void tooMuchPlayer(); // entered a player number bigger than 8
void tooLessPlayer(); // entered a player number smaller than 6
void playerExist(); // player name already exist, please enter another name
void gameStart(); //start the game
void whoTurn (std:: string name); // display whose turn it is
void youWin ();// who won the game
void alreadyRolled (); //rolled for you turn, trying to roll again
void cannotCheckAsset(); // player is in Tuition, cannot check asset 
//board 
void arriveAt (std:: string s); //arrive at a building 
void wannaBuy (int i, std:: string name ); //do you wanna buy building with i amount of money
void payRent(int i); // player need to pay i
void buildingDoesNotExist (); //buidling does not exists
void nextTime (); // game saved, play next time
void invalidBankrupt ();
void needBuildingType ();
};




#endif

/*This is a garbage tier "game" I made to teach myself if and switch statement
Also, since I AM learning still, this code is going to be really unoptimized. Sorry if you got a stroke looking at it.*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int main()
{
	bool done = true;
	//user self inputs
	char userName[20];
	int userStrength, userStrengthH, userAgility, userAgilityH;
	
	//user choices
	int dragonColor;
	const char* dragonColorH[10];
	char exit[1], start[1];//start and stop command to be used outside the compiler
	int choice1, choice1H, choice2;
	
	printf("================================\n\tDragon's Tale\n================================\n");
	printf("Welcome to Dragon's Tale.\nA choose your own adventure type game\nWritten solely by me in my free time.\n");
	printf("\n\n\n\n");
	printf("This story is about YOU!\nYou are a wizard living in kingdom unknown!\n");
	printf("***Please note that if do not enter a number from (1-4) when asked for a choice, the application will reset.***\n");
	printf("To start, press the enter button.\n");
	gets(start);
	
	printf("Enter your name: "); //user's name
	gets(userName);
	printf("Enter your strength.(1-10): "); //user's strength
	scanf("%d", &userStrength);
	printf("Enter your agility(speed).(1-10): "); //user's agility
	scanf("%d", &userAgility);
	
	//Explains the user of their strenght stats.
	if(userStrength <= 3) { printf("%s is weak and ", userName);}
	else if(userStrength <= 7) { printf("%s is quite strong and", userName);}
	else {printf("%s is very strong and", userName);}
	
	//change the hidden strength stat
	if(userStrength <=3) {
		userStrengthH = 1;
	}
	else if(userStrength <=7){
		userStrengthH = 2;
	}
	else {
		userStrengthH = 3;
	}

	//explain user of their agility stats
	if (userAgility <= 3) {printf("they are slow.\n");}
	else if (userAgility <= 7) { printf(" they are quite speedy.\n");}
	else { printf(" they are very fast.\n\n\n\n");}
	
	//change the hidden agility stat
	if(userAgility <=3){
		userAgilityH = 1;
	}
	else if(userAgility <=7){
		userAgilityH = 2;
	}
	else {
		userAgilityH = 3;
	}
	
	//Potion color choice
	printf("%s is shopping. What color potion do you purchase?\n", userName);
	printf("Your options are:\n");
	printf("1. Red\n");
	printf("2. Green\n");
	printf("3. Blue\n");
	printf("4. Pink\n");
	printf("====================================\n");
	printf("Enter a number from above: ");
	scanf("%d", &dragonColor);	
	
	//utilizes switch case to select color. Also changes hidden dragon color string.
	switch(dragonColor) {
		case 1:
			printf("You picked RED potion\n");
			dragonColorH[10] = "RED";
			break;
		case 2:
			printf("You picked GREEN potion\n");
			dragonColorH[10] ="GREEN";
			break;
		case 3:
			printf("You picked BLUE potion\n");
			dragonColorH[10] = "BLUE";
			break;
		case 4:
			printf("You picked PINK potion\n");
			dragonColorH[10] = "PINK";
			break;
		default:
			printf("Please enter an integer from the list above.\n");
			system("pause");
			return 0;
	}
	
	//story elements
	printf("\n\n%s heads back to your home.\n", userName);
	printf("%s start mixing your final potion.\n", userName);
	printf("%s add the %s potion that you just bought from market to a pot.\n",userName, dragonColorH[10]);
	printf("Suddenly, the pot starts shaking. %s steps back.\nThe pot explodes!\nA creature starts coming out of pot.\n", userName);
	printf("It's a %s dragon!\n", dragonColorH[10]);
	printf("It looks angry. What would %s do?\n\n\n", userName);
	
	//Asks Choice 1
	printf("1. Hide under the table.\n");
	printf("2. Inspect the dragon.\n");
	
	//If user agility is higher than 1, a high agility question will appear.
	if ((userAgilityH == 2) || (userAgilityH == 3)){printf("3.[High Agility] Run towards the door.\n");}
	else { printf("3. Attempt to run away.\n"); } //if not, this question will appear
	
	//Similarly if user strength is 3, this would appear
	if(userStrengthH == 3) {printf("4.[High Strength] Kill the dragon.\n");}
	else {printf("4. Attempt to kill the dragon.\n");} //or else this will
	
	printf("================================\n");
	printf("Choose an option: ");
	scanf("%d", &choice1); 
	printf("\n\n\n");
	
	//choice 1
	switch(choice1)
	{
		case 1: //Hide under table
			printf("%s quickly runs to hide under the table. The dragon destroys the roof of the house and flys away.\n", userName);
			printf("%s sustains minor damage.", userName);
			printf("%s peeks out to see the dragon heading towards the mountain.\n", userName);
			printf("It is now %s job to stop the dragon.\n",userName);
			break;
		case 2: //Dragon approach
			printf("%s calmly approach the dragon. Dragon dislikes that and destroys the roof of the house and flys away.\n",userName);
			printf("%s sustains moderate damage.\n", userName);	
			printf("%s gets up to see the dragon flying towards the mountain.\n",userName);
			printf("%s decides to take it on themselves to kill the dragon\n",userName);
			break;
		case 3: //
			if ((userAgilityH == 2) || (userAgilityH == 3)){ 
				printf("%s run as fast as they can and manage to get out of the house.\n", userName); //High agility
				printf("%s sustains no damage.\n", userName);
				printf("%s looks at the dragon as it flys towards the mountain.\n", userName);
				printf("Everyone is looking at %s.\n",userName);
				printf("%s has to find a way to stop the dragon!\n",userName);
				choice1H = 1;
				break;
			}
			else{
				printf("%s runs as fast as they can.\n",userName); //Low agility
				printf("Dragon notices that.\n");
				printf("Dragon whips it's tail and smacks %s.\n", userName);
				printf("%s sustains major damage.\n", userName);
				printf("Dragon then breaks the roof and flys away.\n");
				printf("%s gets up to see the dragon flying towards the mountain.\n",userName);
				printf("It's now on %s to find a way to stop the dragon.\n",userName);
				break;
			}
			break;
		case 4:
			if(userStrengthH == 3) {
				printf("%s picks up the sword and runs toward the dragon.\n", userName); //high strength
				printf("%s leaps into air and strikes dragon's head; killing the dragon.\n",userName);
				printf("The guards take a note of this and reports to the king.\nThe king summons %s to their castle and grants %s the rank of knight!\n", userName, userName);
				printf("From that day onwards, %s pledged to protect the city and decided to never mix two unknown chemicals together.\n", userName);
				system("pause");
				return 0;
				break;
			}
			else{
				printf("%s picks up the sword and runs toward the dragon.\n", userName); //low strength
				printf("%s leaps into air to strike dragon's heart but the dragon was agile. \nIt bit off %s's hand; killing %s.\n", userName,userName,userName);
				printf("The dragon was then unleashed upon the city and it destroyed everything in it's path.\n");
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf("Thanks for playing. \nThere are other choices that leads to other endings.\n");
				break;
			}
			break;
		default:
			printf("Please enter a number between 1-4 to convay choices."); //did not pick from 1-4
			system("pause");
			return 0;
	}
	
	printf("%s sits outside on a bench to think", userName);
	printf("\nWhat would %s do?\n\n",userName);
	printf("1. Go Directly to the mountain.\n");
	printf("2. Go to the king\n");
	printf("3. Go to the master wizard\n");
	printf("4. Do... nothing. \n");
	printf("====================\nSelect an option: ");
	scanf("%d", &choice2);
	
	switch(choice2){
		
		case 1:
			printf("%s head directly towards the mountain.\n",userName);
			printf("%s sees the dragon. It is angry and appears to be in pain.\n", userName);
			printf("%s approaches the dragon and sees a huge splinter stuck in it's wing.", userName);
			printf("%s removes the splinter and gives a health potion to the dragon.\n",userName);
			printf("%s and become good friends and %s uses The dragons breadth to brew potions.", userName, userName);
			break;
			
		case 2:
			printf("%s heads directly towards the castle.\n%s informs the guards and the king.\nThe king sends 200 soldiers to the mountain.\nThe soldiers bring back the heard of the dragon and just like that the village was saved.", userName, userName);
			break;
			
		case 3:
			printf("%s heads toward the wizard building.\n%s tells everything to master wizard.\n", userName, userName);
			printf("Master wizard goes to the king to explain everything.\nThe king sends 200 soldiers to the mountain.\nThe soldiers bring back the heard of the dragon and just like that the village was saved.");
			break;
			
		case 4:
			printf("%s goes back to their house, makes their bed and goes to sleep not caring anything about the dragon.\n",userName, userName);
			printf("%s is then awakened by guards who came to arrest %s.", userName, userName);
			printf("%s spends their entire remaining life in prison.", userName);
			printf("Meanwhile, King's soldiers killed the dragon and bought back it's heart as proof.");
			break;
	}
	
	printf("\nAnd that is the end of this game.\nThanks for playing!");
	printf("Special thanks to YOU(%s)", userName);
	system("pause");
	
return 0;	
}
/*This game was ended abruptly becasue I did not want to work on it anymore. */

/* 
	Written by:Önder Polat Gümüs
	date : 07.12.2023
*/

#include <stdio.h>
#include <windows.h>

char I,V,X,L,C,D,M;
// I = 1,V = 5,X = 10,L = 50,C = 100,D = 500,M = 1000.
char RomeArray[45];
int RomeArrayCounter[45];
char SumRomeArray[45];

int Number1,Number2,number;

int error = 0,negativeC = 0,difference = 0,differenceNumber1 = 0,differenceNumber2 = 0;

void takeNumber();
void reset();
void adder();
void substract();
void multiply();
void divide();
void notPositive1();
void notPositive2();
void numbertoRome(int a);
void zeroCounterReseter();

int IC,VC,XC,LC,CC,DC,MC;
int IZC,VZC,XZC,LZC,CZC,DZC,MZC;

int a,i,j,helper,add,locater,removes;
float sum;
/*	HATALI YAZISLAR ÖRNEK
https://www.dictionary.com/e/roman-numerals/

	XIIIIIV
	IIIII
	XIVIV
	
	0x000001 = 4 TANE AYNI KARAKTERDEN BULUNUYOR
	0x000002 = I ,V ,X ,L ,C ,D ,M DIÞINDA BÝR KARAKTER GÝRÝLMÝÞ
	0x000003 = Yanlýþ karakter dizilimi ( 3 == III , 3 != IIV)
	0x000004 = For instance, a numeral can only be placed in front of the two numerals that are closest to it in the Roman numeral system.
			   That is, I can only be placed before V ( e.g. IV, or 4) and X (e.g. IX, or 9). It can’t be placed before L, C, D, or M.
			   For example, in Roman numerals, 49 would be XLIX (50 – 10 = 40 and 10 – 1 = 9), not IL.
	0x000005 =
*/
int main(){	//******************************************************************************************************************************
	locater = -1;
	while(locater != 0){
		system("cls");
		printf("I = 1  V = 5  X = 10  L = 50  C = 100  D = 500  M = 1000");
		printf("\n\n\t[1]Add\n\t[2]Subs\n\t[3]Multiply\n\t[4]Divide\n\t[0]Exit\t:");
		scanf("%d",&locater);
		if(locater == 1){
			adder();	
		}
		if(locater == 2){
			substract();
		}
		if(locater == 3){
			multiply();
		}
		if(locater == 4){
			divide();
		}
		if(locater == 0){
			//exit
		}
		printf("\n  wait 2 seconds.\n  ");
		sleep(2);
	}

}// ***********************************************************************        MAIN          *************************************************************************************
void takeNumber(){
		/*	for(i = 0;i < 30;i++){
			if(RomeArray[i] != NULL){
				printf("%c\n",RomeArray[i]);
			}
			if(RomeArray[i] == NULL){
				printf("NULL\n");
			}
		}*/
		scanf("%s",&RomeArray);
		printf("\n");
		i = 0;
		for(i = 0;i < 45;i++){
			if(RomeArray[i] == 'I'){
				RomeArrayCounter[i] = 1;
			}
			if(RomeArray[i] == 'V'){
				RomeArrayCounter[i] = 5;
			}
			if(RomeArray[i] == 'X'){
				RomeArrayCounter[i] = 10;	
			}
			if(RomeArray[i] == 'L'){
				RomeArrayCounter[i] = 50;
			}
			if(RomeArray[i] == 'C'){
				RomeArrayCounter[i] = 100;
			}								
			if(RomeArray[i] == 'D'){
				RomeArrayCounter[i] = 500;
			}
			if(RomeArray[i] == 'M'){
				RomeArrayCounter[i] = 1000;
			}	
			if(RomeArray[i] != 'I' && RomeArray[i] != 'V' && RomeArray[i] != 'X' && RomeArray[i] != 'L'&& RomeArray[i] != 'C' && RomeArray[i] != 'D' && RomeArray[i] != 'M' && RomeArray[i] != NULL){
				printf("\n0x000002\n");
				error++;
			}
			if(RomeArray[i] == NULL){
				RomeArrayCounter[i] = 0;
			}
		}
		for(i=0;i<45;i++){
			if (RomeArrayCounter[i] == RomeArrayCounter[i+1] && RomeArrayCounter[i+1] == RomeArrayCounter[i+2] && RomeArrayCounter[i+2] == RomeArrayCounter[i+3] && RomeArrayCounter[i] != 0){
			    printf("\n0x000001\n");
			}			
		}
		add = 0;
		removes = 0;
		sum = 0;
		for(i = 0;i < 45;i++){
			helper = 0;
			for(j = i;j < 45;j++){
				if(RomeArrayCounter[i] < RomeArrayCounter[j]){
					helper++;	
				}
			}
			if(helper > 0){
				removes += RomeArrayCounter[i];
				negativeC++;
				
			}
			if(helper <= 0){
				add += RomeArrayCounter[i];
				negativeC = 0;
			}
			if(negativeC > 1){
				printf("\n0x000003\n");
				error++;
			}
		}
		// I = 1,V = 5,X = 10,L = 50,C = 100,D = 500,M = 1000.
		for(i = 0 ; i < 45 ; i++){
			for(j = i ; j < 45 ; j++){
				if(RomeArray[i] == 'I'){
					differenceNumber1 = 1;
				}
				if(RomeArray[i] == 'V'){
					differenceNumber1 = 2;
				}
				if(RomeArray[i] == 'X'){
					differenceNumber1 = 3;
				}
				if(RomeArray[i] == 'L'){
					differenceNumber1 = 4;
				}
				if(RomeArray[i] == 'C'){
					differenceNumber1 = 5;
				}
				if(RomeArray[i] == 'D'){
					differenceNumber1 = 6;
				}
				if(RomeArray[i] == 'M'){
					differenceNumber1 = 7;
				}
				if(RomeArray[j] == 'I'){
					differenceNumber2 = 1; //
				}
				if(RomeArray[j] == 'V'){
					differenceNumber2 = 2; //
				}
				if(RomeArray[j] == 'X'){
					differenceNumber2 = 3; //
				}
				if(RomeArray[j] == 'L'){
					differenceNumber2 = 4; //
				}
				if(RomeArray[j] == 'C'){
					differenceNumber2 = 5; //
				}
				if(RomeArray[j] == 'D'){
					differenceNumber2 = 6; //
				}
				if(RomeArray[j] == 'M'){
					differenceNumber2 = 7; //
				}
				difference = differenceNumber2 - differenceNumber1;
				if(difference > 2 && error == 0){
					printf("0x000004");
					error++;
				}
			}
		}
		sum = add - removes;
		number = sum;
		printf("\n  :%d\n",number);
	}
void reset(){
	for(i = 0;i < 45;i++){
		RomeArray[i] = 0;	
	}
	for(i = 0;i<45;i++){
		RomeArrayCounter[i] = 0;
	}
	for(i = 0;i<45;i++){
		SumRomeArray[i] = 0;
	}
	//********************************
	helper = 0;	add = 0;	sum = 0;	locater = -1;	removes = 0;	number = 0;	error = 0;	negativeC = 0; a = 0;i = 0;j = 0;helper = 0;add = 0;differenceNumber2 = 0;differenceNumber1 = 0;difference = 0;
	//********************************
}
void adder(){
	takeNumber();
	if(error != 1){
		Number1 = number;
		notPositive1();
		reset();
		takeNumber();
		if(error != 1){
			Number2 = number;
			notPositive2();
			sum = Number1 + Number2;
			printf("Sum = ");
			printf("%.3f\t",sum);
			numbertoRome(sum);
		}	
	}
	reset();
}
void substract(){
	takeNumber();
	if(error != 1){
		Number1 = number;
		notPositive1();
		reset();
		takeNumber();
		if(error != 1){
			Number2 = number;
			notPositive2();
			sum = Number1 - Number2;
			printf("Sum = ");
			printf("%.3f\t",sum);
			numbertoRome(sum);
		}	
	}
	reset();
}
void multiply(){
	takeNumber();
	if(error != 1){
		Number1 = number;
		notPositive1();
		reset();
		takeNumber();
		if(error != 1){
			Number2 = number;
			notPositive2();
			sum = Number1 * Number2;
			printf("Sum = ");
			printf("%.3f\t",sum);
			numbertoRome(sum);
		}	
	}
	reset();
}
void divide(){
	takeNumber();
	if(error != 1){
		Number1 = number;
		notPositive1();
		reset();
		takeNumber();
		if(error != 1){
			Number2 = number;
			notPositive2();
			sum = Number1 / Number2;
			printf("Sum = ");
			printf("%.3f\t",sum);
			numbertoRome(sum);
		}	
	}
	reset();
}
void notPositive1(){
	if(Number1 <= 0){
		printf("Yanlis Roma rakami tusladiniz.");		
	}
}
void notPositive2(){
	if( Number2 <= 0){
		printf("Yanlis Roma rakami tusladiniz.");		
	}
}
void numbertoRome(int a){ 
	for(i = 0;i < 45;i++){		
		if(a >= 1000){  //M
			a = a - 1000;
			SumRomeArray[i] = 'M';
			continue;
		}
		if(a >= 500){   //D
			a = a - 500;
			SumRomeArray[i] = 'D';
			continue;
		}
		if(a >= 100){   //C
			a = a - 100;
			SumRomeArray[i] = 'C';
			continue;
		}
		if(a >= 50){   //L
			a = a - 50;
			SumRomeArray[i] = 'L';
			continue;
		}
		if(a >= 10){   //X
			a = a - 10;
			SumRomeArray[i] = 'X';
			continue;
		}
		if(a >= 5){   //V
			a = a - 5;
			SumRomeArray[i] = 'V';
			continue;
		}
		if(a >= 1){   //I
			a = a - 1;
			SumRomeArray[i] = 'I';
			continue;
		}
		if(a < 1){
			SumRomeArray[i] = 'Z';
		}
		
	}
	for(i = 0;i < 45;i++){
		if(SumRomeArray[i] != 'Z'){
			printf("%c",SumRomeArray[i]);
		}
		if(SumRomeArray[i] == 'Z'){
			break;
		}
	}
}

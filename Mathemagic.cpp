#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;
class Majic{
	int Array[10][10], SymbArray[10][10];
	char specific;
	public:
		Majic(){
			for(int i=0,count=0;i<10;++i)
				for (int x=0;x<10;++x){
					Array[i][x]=count++;
					SymbArray[i][x]=0;
				}
		}
	void Randomize(){
			srand(time(NULL));
		    specific=rand()%26;
			for(int i=0;i<10;++i)
				for (int x=0;x<10;++x){				
					if (Array[i][x]%9!=0)
						SymbArray[i][x]=rand()%26;
					else
						SymbArray[i][x]=specific;
				}
	}
	void Display(){
		for (int i=0;i<10;++i){
			for (int x=0;x<10;++x){
				if (Array[i][x]%10==Array[i][x])
					cout<<Array[i][x]<<" :{"<<(char)(SymbArray[i][x]+65)<<"} ";
				else		
					cout<<Array[i][x]<<":{"<<(char)(SymbArray[i][x]+65)<<"} ";
			}
			cout<<endl;
		}
	}
	char throwNine(){
		return specific+65;
	}
};
int main(){
	Majic Obj;
	char x;
	do {
	Obj.Randomize();
	Obj.Display();
	cout<<"\nHello.\nThink of a Number in your Mind.\n"
		<<"Then:\n1.Add the Digits of the Number.\n"
		<<"2.Subtract this Number from your Original Number\n"
		<<"3.Check for the Symbol of the Answer.\n";	
	cout<<"Press to Know the Symbol.";
	getch();
	cout<<"\n\nYour Symbol is: "<<Obj.throwNine()<<endl;
	cout<<"Surpise!!!\n\n";
	cout<<"Want to try again?, type y or Y:";
	cin>>x;
	}while (x=='y' || x=='Y');
}

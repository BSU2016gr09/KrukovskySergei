#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <time.h>
using namespace std;

string userName;
int scoreCommputer=0;
int scoreUser=0;
//
bool countScore(int , int);
bool drawBlock(int );
bool drawThrow(int , int );
int getRandomNumber(int );
int throwBlocksByCommputer();
int throwBlocksByUser();
void printScore();
void startGames();
void getWiner();
int main(){
    setlocale(LC_ALL, "rus");
    //drawThrow();
    startGames();

}

//
bool drawBlock (int a)
{
    bool result = false;
    switch(a)
    {
        case 1:
            cout<<"+---+ \n"<<"|   |\n"<<"| O |\n"<< "|   | \n"<< "+---+\n";
            result = true;
            break;
        case 2:
            cout<<"+---+ \n"<<"| O |\n"<<"| O |\n"<< "|   | \n"<< "+---+\n";
            result = true;
            break;
        case 3:
            cout<<"+---+ \n"<<"| O |\n"<<"| O |\n"<< "| O | \n"<< "+---+\n";
            result = true;
            break;
        case 4:
            cout<<"+---+ \n"<<"|O O|\n"<<"|   |\n"<< "|O O| \n"<< "+---+\n";
            result = true;
            break;
        case 5:
            cout<<"+---+ \n"<<"|O O|\n"<<"| O |\n"<< "|O O| \n"<< "+---+\n";
            result = true;
            break;
        case 6:
            cout<<"+---+ \n"<<"|O O|\n"<<"|O O|\n"<< "|O O| \n"<< "+---+\n";
            result = true;
            break;
        default:
            cout<<"Bad!!"<<endl;
    }

    return result;

}

bool drawThrow(int a, int b)
{
    return drawBlock(a) == true && drawBlock(b) == true;

}

int getRandomNumber(int a)
{
    time_t t;
	time(&t);
	srand((unsigned int) t);
    int result;
    result = ((rand()*a + rand()%a)*a)%6 + 1;
    return result;
}

int throwBlocksByCommputer()
{
    int number1=0, number2=0;
    number1 = getRandomNumber(17);//Вообще не понял!!!! Подойди-объясни....
    number2 = getRandomNumber(19);//Вообще не понял!!!! Подойди-объясни....
    drawThrow(number1,number2);
    return number1 + number2;
}

int throwBlocksByUser()
{
    int number1=0, number2=0;
    number1 = getRandomNumber(23+userName.size());//Вообще не понял!!!! Подойди-объясни....
    number2 = getRandomNumber(29+userName.size());//Вообще не понял!!!! Подойди-объясни....
    drawThrow(number1,number2);
    return number1 + number2;
}

bool countScore(int id, int score)
{
    int result = false;
    switch(id){
        case 1:
            scoreUser += score;
            result = true;
            break;
        case 2:
            scoreCommputer += score;
            result = true;
            break;
        default:;

    }
    return result;
}

void printScore()
{
    cout<<"Ñ÷¸ò êîìïþòåðà: " << scoreCommputer<< endl;
    cout<< "Ñ÷¸ò èãðîêà: " << scoreUser<< endl;
}

void getWiner()
{
    if(scoreCommputer > scoreUser){
        cout<<"Win computer"<<endl;
    }else{
        if(scoreCommputer == scoreUser){
            cout<<"Nobody win"<<endl;
        }
        else{
            cout<<"Win user"<<endl;
        }
    }
}
void startGames()
{
    cout<< "Ââåäèòå ëþáîé ñèìâîë äëÿ íà÷àëà èãðû.";
            string k;
            cin >> k;
    while(scoreCommputer < 50 && scoreUser < 50){

            cout<< "Áðîñîê êîìïüþòåðà: \n";
        int scoreComp = throwBlocksByCommputer();
        countScore(2, scoreComp);
        cout<<"__________"<<endl;
        cout << "Áðîñîê èãðîêà : \n";
        int scoreUs = throwBlocksByUser();
        countScore(1, scoreUs);
        cout<<"__________"<<endl;
        printScore();
        cout<<"Ââåäèòå ëþáîé ñèìâîëûäëÿ ïðîäîëæåíèÿ èãðû."<<endl;
        cin>>k;
    }
    getWiner();
}


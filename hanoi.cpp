#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void hanoi(int,int,int,int,int);
void hanoi(int,int,int,int);

int counter = 0;
ofstream file;

int main() {
    int diskCount, pegsCount;
    cout<<"Podaj ilosc krazkow: ";
    cin>>diskCount;
    cout<<"Podaj ilosc wiez: ";
    cin>>pegsCount;

    file.open("output.txt");

    if(!file.is_open()) {
        return 1;
    }

    system("cls");
    cout<<"Trwa generowanie ruchow..."<<endl;
    system("cls");
    hanoi(diskCount,1,2,3,pegsCount);

    cout<<"Liczba wykonanych ruchow: "<<counter;
    file.close();

    return 0;
}

/**
* @diskCount liczba krazkow
* @sourcePeg poczatkowa wiezyczka, na ktorej znajduja sie na poczatku wszystkie krazki
* @destiantionPeg wynikowa wiezyczna na ktorej maja znalezc sie wszystkie krazki
* @tempPeg tymczasowa wiezyczka potrzebna do przelozenia krazkow
* @pegsCount liczba wszytskich wiezyczek
*/
void hanoi(int diskCount, int sourcePeg, int destinationPeg, int tempPeg, int pegsCount) {
    if(diskCount>0) {
        if(pegsCount==3) {
            hanoi(diskCount,sourcePeg,destinationPeg,tempPeg);
        } else if(pegsCount==4) {
            hanoi(diskCount/2,sourcePeg,tempPeg,destinationPeg,4);
            hanoi((diskCount-(diskCount/2)),sourcePeg,destinationPeg,4);
            hanoi(diskCount/2,tempPeg,destinationPeg,sourcePeg,4);
        } else if(pegsCount>4) {
            counter+=2;
            file<<sourcePeg<<" "<<pegsCount<<"\n";
            hanoi(diskCount-1,sourcePeg,destinationPeg,tempPeg, pegsCount-1);
            file<<pegsCount<<" "<<destinationPeg<<"\n";
        }
    }
}

void hanoi(int diskCount, int sourcePeg, int destinationPeg,int tempPeg) {
    if(diskCount>0) {
        counter++;
        hanoi(diskCount-1,sourcePeg, tempPeg, destinationPeg);
        file<<sourcePeg<<" "<<destinationPeg<<'\n';
        hanoi(diskCount-1,tempPeg, destinationPeg, sourcePeg);
    }
}

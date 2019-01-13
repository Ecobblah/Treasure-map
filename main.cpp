
#include<iostream>
#include<string>
using namespace std;
int  const CAPACITY = 11;
void menu(char maps[][CAPACITY], int size, int x, int y);
void Display(char a[][CAPACITY], int size);
void Create(char a[][CAPACITY], int size, int x, int y);
void setX(int& x, int& y, int size);
void setcol(int& y, int size);
void setrow(int& x, int size);

int main(){
int x;
int y;
int size;
char maps [CAPACITY][CAPACITY];

    do{
cout<<"Treasure Map\n";
cout<<"------------\n";
cout<<"Enter a map size: ";
cin>>size;
size++;
if(size>CAPACITY)//Determines if size is less than 11.
    cout<<"The size of the map is too big.\n\n";
else
    break;
    }
    while(true);
do{
cout<<"\nInitial location of X (row column): ";
cin>>x>>y;
y++;//the col value was off by one.

if(x>=size || x<0 || y>=size || y<0)
    cout<<"Invalid coordinates.\n\n";
else
    break;
}
while(true);

cout<<endl;
Create(maps, size,x, y);//creates the map with the initial X marl.
Display(maps, size);//This function Displays it.

menu(maps,size,x,y);//Gives the user the option.

return 0;
}

void Create(char a[][CAPACITY], int size,int x, int y){
	int inR = 3;
	int inC = 3;
	for (int i = 0; i<size;i++){
    //Rows
        for (int j = 0; j<size;j++){
            if (i==x&&j==y)
                a[i][j] = 'x';

            else
            {a[i][j]='-';//Had to make the map all "-" first before i add the numbers.

                    if (i==size-1&&j==0)
                        a[i][j] = ' ';

                    else if(i==size-1){
                        a[i][j] = static_cast<int>(a[i][j]+inR);//change char to int, then add by 3
                        inR++;

                    }
                    else if(j==0){
                        a[i][j] = static_cast<int>(a[i][j]+inC);////change char to int, then add by 3
                        inC++;

                    }
            }
        }
}
cout<<endl;
}

void Display(char a[][CAPACITY], int size){
	for (int i = 0; i<size;i++){//row
        for (int j = 0; j<size;j++){//column
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void setX(int& x, int& y, int size){//this function depends on other functions setcol and setrow.
setcol(y, size);
setrow(x, size);

}
void setcol( int& y, int size){
    int newy;
    do{
    cout<<"Shift X left or right (negative values left, positive values right): ";
    cin>>newy;

    if(y+newy >0 && y+newy<size){
        y=y+newy;
    break;
    }
    else
        cout<<"Treasure location must be within the confines of the map.\n\n";
}
while(true);

}
void setrow(int& x, int size){
int newx;
    do{
    cout<<"Shift X up or down (negative values left, positive values right): ";
    cin>>newx;

    if(x+newx >-1 && x+newx<size){//had to set the -1 because it wouldnt let x be put on the last row.
        x=x+newx;
    break;
    }
    else
        cout<<"Treasure location must be within the confines of the map.\n\n";
}
while(true);
}

void menu(char maps[][CAPACITY], int size, int x, int y){//main menu.
    int option;
    do{//the do while loop will repeat till option =4.
    cout<<"1) Update treasure coordinates (row/column).\n";
    cout<<"2) Shift X left or right.\n";
    cout<<"3) Shift X up or down.\n";
    cout<<"4) Exit Program.\n\n";
    cout<<"Enter your option: ";
    cin>>option;
    cout<<endl;

    switch(option){

case 1:
    {
        setX(x, y, size);
        Create(maps, size,x, y);
        Display(maps, size);

        break;
    }
case 2:
    {
        setcol( y,size);
        Create(maps, size,x, y);
        Display(maps, size);
        break;
    }
case 3:
    {
        setrow(x,size);
        Create(maps, size,x, y);
        Display(maps, size);
        break;
    }
case 4:
    {
        cout<<"Exiting Program.\n\n";
        break;
    }
default://incase invalid input.
    {
        cout<<"Invalid input.\n\n";
    }
}


}
while(option!=4);
}

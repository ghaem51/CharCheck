#include <iostream>
#include <stdio.h>

using namespace std;
void push(char a,char p[20],int &top){
    top++;
    p[top]=a;
};
char pop(char p[20],int &top,char a){//pop with search option
    char temp;
    for(int i=0;i<20;i++){
        if (p[i]==a){
            temp=p[i];
            while(i<top)
            {
                p[i]=p[i+1];
                i++;
            }
            p[top]=NULL;
            top--;
            return temp;
        }
    }
    return '$';
};
int main() {
    int NumberOfAlfba;
    bool error1=1;
    cout <<"Enter Number of alfba (how many?):\n";
    cin >> NumberOfAlfba; //daryaft tedad horuf alfba
    char *Alfba = new char [NumberOfAlfba+1];
    for (int i=1;i<=NumberOfAlfba;i++) {
        cout << "Enter Your Alfba:(" << i << ")\n";
        cin >> Alfba[i]; //daryaft horuf alfba
    }
    int stateNumber;
    cout <<"Enter Number of state (how many?):\n";
    cin >> stateNumber; //daryaft tedad horuf alfba
    int F_State_Number;
    while(error1==1) {
        cout <<"Enter Number of finish state (how many?):\n";
        cin >> F_State_Number; //daryaft tedad state payany
        if (F_State_Number <= stateNumber) {
            error1 = 0;
        } else
            cout<<"Error Check Your Input Parameter.\n";
    }

    char *F_state = new char [F_State_Number+1];
    for (int i=1;i<=F_State_Number;i++) {
        cout << "Enter Finesh state Number\n";
        cin >> F_state[i]; //daryaft horuf alfba
    }
    int NumberOfRelashion;
    cout <<"Enter Number of relashion (how many?):\n";
    cin >> NumberOfRelashion; //daryaft tedad horuf alfba
    char **RelashionTable= new char *[NumberOfRelashion+1];
    for (int i=1;i<=NumberOfRelashion;i++) {
        cout << "Enter Relashion ("<<i<<") Info\n";
        RelashionTable[i]=new char [6];
        cout << "Enter Start State:\n";
        cin >> RelashionTable[i][1];
        cout << "Read Alfba(For ℷ Enter #):\n";
        cin >> RelashionTable[i][2];
        cout << "State End to:\n";
        cin >> RelashionTable[i][3];
        cout << "Pop(For ℷ Enter #):\n";
        cin >> RelashionTable[i][4];
        cout << "Push(For ℷ Enter #):\n";
        cin >> RelashionTable[i][5];
    }
    bool loop1=1;
    while(loop1==1) {
        cout << "All Parameter OK\n";
        error1 = 1;
        int counter = 0;
        char charecter[20];
        while (error1 == 1) {//get true charecter
            cout << "Enter Your charecter For Test!!!\n";
            cin >> charecter;
            for (int i = 0; i < strlen(charecter);) {
                counter++;
                for (int j = 1; j <= NumberOfAlfba; j++) {
                    if (charecter[i] == Alfba[j]) {
                        i++;
                        if (i == strlen(charecter))
                            error1 = 0;
                        counter = 0;
                    }
                }
                if (counter > strlen(charecter)) {
                    cout << "charecter alfba not in alfba!!! Charecter Not Acepet\n";
                    break;
                }
            }
        }
        int charsize;
        char Location = '1';
        int chlocation = 0;
        int top = -1;
        int counter1=0;
        char pushte[20];
        char popitem;
        int cheker = 0, tempc;
        charsize = strlen(charecter);
        while (top!=-1|charsize > chlocation) {
            counter1++;
            if(counter1>100)//Exit In Loop
                break;
            tempc = cheker;
            for (int i = 1; i <= NumberOfRelashion; i++) {
                if (Location == RelashionTable[i][1])
                    if (charecter[chlocation] == RelashionTable[i][2]) {
                        if (RelashionTable[i][4] == '#' && RelashionTable[i][5] != '#') {
                            push(RelashionTable[i][5], pushte, top);
                            Location = RelashionTable[i][3];
                            chlocation++;
                            cheker++;
                            counter1=0;
                            break;
                        } else if (RelashionTable[i][4] != '#' && RelashionTable[i][5] == '#') {
                            popitem = pop(pushte, top, RelashionTable[i][4]);
                            if (popitem == '$');
                            else if (popitem == RelashionTable[i][4]) {
                                Location = RelashionTable[i][3];
                                chlocation++;
                                cheker++;
                                counter1=0;
                                break;
                            }
                        } else if (RelashionTable[i][4] != '#' && RelashionTable[i][5] != '#') {
                            popitem = pop(pushte, top, RelashionTable[i][4]);
                            if (popitem == '$');
                            else if (popitem == RelashionTable[i][4]) {
                                Location = RelashionTable[i][3];
                                push(RelashionTable[i][5], pushte, top);
                                chlocation++;
                                cheker++;
                                counter1=0;
                                break;
                            }
                        } else if (RelashionTable[i][4] == '#' && RelashionTable[i][5] == '#' &&
                                   top == -1) {//normal ckeck
                            Location = RelashionTable[i][3];
                            chlocation++;
                            cheker++;
                            counter1=0;
                            break;
                        }
                    }
            }
            if (tempc >= cheker)//use landa or use without pop&push
            {
                bool orrr = 0;//run just 1 loop of for
                for (int i = 1; i <= NumberOfRelashion; i++) {
                    if (Location == RelashionTable[i][1]) {//move #
                        if (RelashionTable[i][2] == charecter[chlocation]) {
                            Location = RelashionTable[i][3];
                            chlocation++;
                            orrr = 1;
                            counter1=0;
                            break;
                        }
                    }
                }
                if (orrr == 0) {
                    for (int i = 1; i <= NumberOfRelashion; i++) {
                        if (Location == RelashionTable[i][1]) {
                            if (RelashionTable[i][2] == '#') {
                                if(RelashionTable[i][4]!='#') {
                                    popitem = pop(pushte, top, RelashionTable[i][4]);
                                    if (popitem == '$');
                                    else {
                                        Location = RelashionTable[i][3];
                                        break;
                                    }
                                }
                                else if(RelashionTable[i][5]!='#') {
                                    push(RelashionTable[i][5], pushte, top);
                                    Location = RelashionTable[i][3];
                                    break;
                                }
                                counter1=0;
                                Location = RelashionTable[i][3];
                                break;
                            }
                        }
                    }
                }
            }

        }
        bool error3=1;
        for(int i=1;i<=F_State_Number;i++)
            if (Location == F_state[i])
                if (top == -1) {
                    error3 = 0;
                    break;
                }
        if (error3==0)
            cout << "Charecter Acepet!!!:)\n";
        else
            cout << "Charecter Not Acepet!!!:(\n";
        char E;
        bool error2=1;
        while (error2==1) {
            cout << "Do You Want Enter New Charecter?!(Y)(N)";
            cin >> E;
            if (E == 'Y' || E == 'y'){
                loop1 = 1;
                error2=0;}
            else if (E == 'N' || E == 'n'){
                loop1 = 0;
                error2=0;}
            else
                cout << "Please Enter (Y) Yes/ (N) NO\n";
        }
    }
    return 0;
}

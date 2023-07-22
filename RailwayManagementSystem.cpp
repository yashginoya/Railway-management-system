/*
        DSA INNOVATIVE ASSIGNMENT
        Team Members: Yash Ginoya (20BCE075)
                      Devasy Patel(20BCE057)
                      Ayush Thakkar(20BCE025)

*/

#include <bits/stdc++.h>
using namespace std;

void viewinfo();
void bookticket();
void cancelticket();
void admin();
void password();
void viewpassenger();
void addtrain();
void dlttrain();

struct adddata // Structure for Train Details
{
    string si;
    string train_number;
    string train_name;
    string start;
    string destination;
    string price;
    string time;
} add[1000] = {   {"111","101","Rajdhani","Delhi","Surat","3999","7:30"} ,
                  {"222","102","Karnavati","Mumbai","Surat","2999","5:45"} ,
                  {"333","103","Rajdhani2","Chennai","Surat","4599","2:15"}   };

class node{   // Linked List Node for bookticket
    public:
        string train_number;
        string name; 
        string phone;
        int seat;
        node* next;
        node(string train_number1, string name1, string phone1){
            train_number = train_number1;
            name = name1;
            phone = phone1;
            next = NULL;
        }
};

// -------------------------Global Variables --------------------------------
node* book = NULL;
int k = 3, u = 0;
char trn_nmbr[100], name[100], phn[100];

// ------------------------Linked List Functions-----------------------------
void insertAtHead(node* &head,string train_number1, string name1, string phone1){
    node* n = new node(train_number1,name1,phone1);
    n->next = head;
    head = n;
    return;
}

void insertAtTail(node* &head,string train_number1, string name1, string phone1){
    
    node* n = new node(train_number1,name1,phone1);
    if(head==NULL){ 
        head = n; 
        return;
    }
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* head){
    node* temp = head;

    cout<<"\n\t\t\t**********************************************************";
    cout<<"\n\t\t\t***************RAILWAY RESERVATION SYSTEM*****************";
    cout<<"\n\t\t\t**********************************************************";
    cout<<"\n\n\t\t\ttrain number\t\tname\t\tphone number\n";
    cout<<"\n\t\t\t**********************************************************\n";
    while(temp != NULL){
        cout<<"\n\t\t\t"<<temp->train_number<<"\t\t\t"<<temp->name<<"\t\t"<<temp->phone;
        temp = temp->next;
    }
    cout<<"\n\t\t\t**********************************************************\n";
}

void deleteAtHead(node* &head){
    node* toDelete = head;
    head = head->next;
    delete toDelete; 
}

void deletionOfNode(node* &head,string phone1){

    if(head == NULL){ 
        return;
    }

    if(head->next == NULL || head->phone.compare(phone1) == 0){ 
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    while(temp->next->phone.compare(phone1) != 0){
        temp = temp->next;
    }
    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// -----------------------------Main Function--------------------------------
int main()
{
    static int defaultNode=1;
    if(defaultNode==1){
        insertAtTail(book,"101","yash","1234567890");
        insertAtTail(book,"102","meet","9876543210");
        defaultNode++;
    }
    
    int ch;
    system("cls");
    cout << "\n\t\t\t******************************************\n";
    cout << "\t\t\t******* RAILWAY RESERVATION SYSTEM *******\n";
    cout << "\t\t\t******************************************\n";
    cout << "\n\t\t\t   <<<<<<<<<<WELCOME USERS>>>>>>>>>>\n";
    cout << "\n\n\t\t\t\t         MENU\n";
    cout << "\t\t\t                ******";
    cout << "\n\t\t\t[1] VIEW INFORMATION\n";
    cout << "\n\t\t\t[2] BOOK TICKET\n";
    cout << "\n\t\t\t[3] CANCEL TICKET\n";
    cout << "\n\t\t\t[4] ADMIN";
    cout << "\n\n\t\t\t[5] EXIT\n";
    cout << "\n\t\t\t********************************";
    cout << "\n\t\t\t********************************";
    cout << "\n\t\t\tENTER YOUR CHOICE: ";

    cin >> ch;

    switch (ch)
    {
    case 1:
        viewinfo();
        break;
    case 2:
        bookticket();
        break;
    case 3:
        cancelticket();
        break;
    case 4:
        password();
        break;
    case 5:
        system("cls");
        cout<<"\n\t\t\t =========================================\n";
        cout<<"\t\t\t ********RAILWAY RESERVATION SYSTEM********\n";
        cout<<"\t\t\t ===============================================\n";
        exit(0);
        break;
    default:
        system("cls");
        cout<<"\n\t\t\t==============================================\n";
        cout<<"\t\t\t   *******RAILWAY RESERVATION SYSTEM*******\n";
        cout<<"\t\t\t   ==============================================\n";
        cout<<"\n\n\t\t\t<<<<<<<<YOU ENTERED WRONG CHOICE>>>>>>>>\n";
        cout<<"\t\t\t<<<<<<<<PLEASE ENTER RIGHT THING>>>>>>>>\n";
        system("cls");
        main();
    }
    return 0;
}

//---------------------------------------book ticket function-----------------------------------------------
void bookticket()
{
    int c, j, n, i, found = -1;
    char v, train_number[10];
    system("cls");
    cout<<"\n\n\t\t\t============================================";
    cout<<"\n\t\t\t**********RAILWAY RESERVATION SYSTEM**********\n";
    cout<<"\t\t\t==================================================";
    cout<<"\n\n\t\t\thow many ticket do you want to buy: ";
    cin>>n;
    for (j = u; j < u + n; j++)
    {
        string temp_train_number;
        cout<<"\n\n\t\t\tEnter train number: ";
        cin>>temp_train_number;
        for (i = 0; i < k; i++)
        {
            if (temp_train_number.compare(add[i].train_number) == 0)
            {
                    found = 1;
                    string temp_name;
                    string temp_phone;
                    cout<<"\n\t\t\tenter book ticket no :  "<<j + 1;
                    cout<<"\n\t\t\tenter your name: ";
                    cin>>temp_name;
                    cout<<"\n\t\t\tenter your phone number: ";
                    cin>>temp_phone;
                    insertAtTail(book,temp_train_number,temp_name,temp_phone);
            }
        }
        if (found == -1)
        {
            cout<<"\n\n\t\t\ttrain not found!!!";
            system("cls");
            main();
        }
    }
    u = j;
    cout<<"\n\n\t\t\tenter '1' for main menu & press any key to exit: ";
    cin>>c;
    if (c == 1)
    {
        system("cls");
        main();
    }
    if (c != 1)
    {
        exit;
    }
}

//---------------------------------------cancel ticket function---------------------------------------------
void cancelticket()
{
    string cancle_phone;
    int location = -1, e;
    cout<<"\n\n\t\t\tenter phone number: ";
    cin>>cancle_phone;

    deletionOfNode(book,cancle_phone);
        u--;
        printf("\n\n\t\t\t<<<<<<<<<<<<<<<ticket cancelled successfully>>>>>>>>>>>>");
        getchar();
        getchar();
        system("cls");
        main();
}

//-------------------------------------admin portal function----------------------------------------
void admin()
{
    int chhh;
    system("cls");

    cout<<"\n     ==================================================================";
    cout<<"\n     ********************RAILWAY RESERVATION SYSTEM********************";
    cout<<"\n     ==================================================================";
    cout<<"\n\n";
    cout<<"           <<<<<<<<<<<<<<<WELCOME_ADMIN>>>>>>>>>>>>>>>\n";
    cout<<"\n\n";
    cout<<"              ************************************\n";
    cout<<"              ||      CHOOSE YOUR OPERATION     ||\n";
    cout<<"              ||--------------------------------||\n";
    cout<<"              ||      [1] VIEW PASSENGERS       ||\n";
    cout<<"              ||      [2] ADD TRAIN             ||\n";
    cout<<"              ||      [3] DELETE TRAIN          ||\n";
    cout<<"              ||      [4] BACK                  ||\n";
    cout<<"              ||                                ||\n";
    cout<<"              ************************************\n\n";
    cout<<"     **********************************************************\n";
    cout<<"\n\t\tENTER YOUR CHOICE: ";
    cin>>chhh;

    switch (chhh)
    {
    case 1:
        viewpassenger();
        break;
    case 2:
        addtrain();
        break;
    case 3:
        dlttrain();
        break;
    case 4:
        system("cls");
        main();
        break;
    default:
        cout<<"\n\t\t\tyou entered wrong KEY!!!!";
        system("cls");
        main();
    }
}

//-----------------------------password function----------------------------------
void password()
{
    int number = 12345678;
    int pass;
    cout<<"\n\t\t\tenter password: ";
    cin>>pass;
    if (pass == number)
    {
        cout<<"\n\n\t\t\t<<<<<login successfully>>>>>";
        system("cls");
        admin();
    }
    else
    {
        cout<<"\n\n\t\t\t\t   ERROR!!!!!";
        cout<<"\n\n\t\t\t<<<<<<<<wrong password>>>>>>>>";
        system("cls");
        main();
    }
}

//--------------------------------------view passengers function----------------------------------------
void viewpassenger()
{
    int a;
    system("cls");
    display(book); // display all nodes of book (linked list)
    cout<<"\n\n\t\t\tenter '1' for main menu & enter '0' for back: ";
    cin>>a;
    if (a == 1)
    {
        system("cls");
        main();
    }
    if (a == 0)
    {
        system("cls");
        admin();
    }
}

//--------------------------------------add train function--------------------------------------------
void addtrain()
{
    system("cls");
    int ch;
    int i, a;
    cout<<"\n\t\t     **********************************************************";
    cout<<"\n\t\t     ********************RAILWAY RESERVATION SYSTEM********************";
    cout<<"\n\t\t     **********************************************************";
    cout<<"\n\n\t\t\thow many trains do you want to add: ";
    cin>>a;
    for (i = k; i < k + a; i++)
    {
        cout<<"\n\t\t\tenter details of train no : "<< i + 1 ;
        cout<<"\n\t\t\tenter serial number: ";
        cin>>add[i].si;
        cout<<"\n\t\t\tenter train number: ";
        cin>>add[i].train_number;
        cout<<"\n\t\t\tenter train name: ";
        cin>>add[i].train_name;
        cout<<"\n\t\t\tenter start place: ";
        cin>>add[i].start;
        cout<<"\n\t\t\tenter destination place: ";
        cin>>add[i].destination;
        cout<<"\n\t\t\t enter price: ";
        cin>>add[i].price;
        cout<<"\n\t\t\t enter time: ";
        cin>>add[i].time;
    }

    cout<<"\n\n\t\t\tconfirm train: (y=1/n=0):- ";
    cin>>ch;
    if (ch == 1)
    {
        k = i;
        system("cls");
        cout<<"\n\n\t\t\t**********************************************************";
        cout<<"\n\t\t\t********************RAILWAY RESERVATION SYSTEM********************";
        cout<<"\n\t\t\t**********************************************************";
        cout<<"\n\n";
        cout<<"\n\t\t\t\t   **********************************";
        cout<<"\n\t\t\t\t   *<<<<<train add successfully>>>>>*";
        cout<<"\n\t\t\t\t   **********************************";
        system("cls");
        main();
    }
    if (ch == 0)
    {
        system("cls");
        admin();
    }
    if ((ch != 1) && (ch != 0))
    {
        system("cls");
        main();
    }
}

//-----------------------------------view information function--------------------------------------
void viewinfo()
{
    int ch, i;
    system("cls");
    cout<<"\n\t\t     ******************************************************************";
    cout<<"\n\t\t     ********************RAILWAY RESERVATION SYSTEM********************";
    cout<<"\n\t\t     ******************************************************************";
    cout<<"\n\n\n    SI\ttrain number\ttrain name\tstart place\tdestination place\tprice\ttime\n\n";
    for (i = 0; i < k; i++)
    {
        cout<<"    "<<add[i].si<<"\t\t"<<add[i].train_number<<"\t"<<add[i].train_name<<"\t\t"<<add[i].start<<"\t\t"<<add[i].destination<<"\t\t"<<add[i].price<<"\t"<<add[i].time<<"\n";
    }
    cout<<"    ***********************************************************************************************\n";
    cout<<"\n\t\t\tpress '1' for main menu & press any key for exit:  ";
    cin>>ch;
    switch (ch)
    {
    case 1:
        system("cls");
        main();
        break;
    default:
        exit(0);
    }
}

//------------------------------------delete train function----------------------------------------------
void dlttrain()
{
    string train;
    int location = -1, f;
    cout<<"\n\n\tenter train number: ";
    cin>>train;
    for (f = 0; f < k; f++)
    {
        if (train.compare(add[f].train_number) == 0)
        {
            location = f;
            break;
        }
    }
    if (location == -1)
    {
        cout<<"\n\n\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n";
        system("cls");
        admin();
    }
    else
    {
        for (f = location; f < k; f++)
        {
            add[f].si.assign(add[f + 1].si);
            add[f].train_number.assign(add[f + 1].train_number);
            add[f].train_name.assign(add[f + 1].train_name);
            add[f].start.assign(add[f + 1].start);
            add[f].destination.assign(add[f + 1].destination);
            add[f].price.assign(add[f + 1].price);
            add[f].time.assign(add[f + 1].time);
        }
        k--;
        cout<<"\n\n\t<<<<<<<<<<<<<train deleted successfully>>>>>>>>>>>>>";
        system("cls");
        admin();
    }
}
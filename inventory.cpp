#include<iostream>
#include<fstream> //file opertions

using namespace std;

class shopping
{
    private:
       int pcode;
       float price;
       float dis;
       string pname;

       public:
          void menu();
          void administrator();
          void buyer();
          void add();
          void edit();
          void rem();
          void list();
          void receipt();
};

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t____________________________________________\n";
    cout<<"\t\t\t\t                                            \n";
    cout<<"\t\t\t\t    SuperMarket Main Menu                   \n";
    cout<<"\t\t\t\t                                            \n";
    cout<<"\t\t\t\t____________________________________________\n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t   1) Administrator               \n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t   2) Buyer                       \n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t   3) Exit                        \n";
    cout<<"\t\t\t\t                                  \n";
    cin>>choice;

    switch (choice)
    {
    case 1:
        /* code */
        cout<<"\t\t\t Please Login \n";
        cout<<"\t\t\t Enter Email  \n";
        cin>>email;
        cout<<"\t\t\t Enter Password \n";
        cin>>password;

        if (email=="p@email.com" && password=="1234")
        {
            /* code */
            administrator();
        }
        else
        {
            cout<<"Invalid User or Password";
        }

        break;
    

    case 2:
        {
            buyer();
        }

    case 3:
        {
            exit(0);
        }

        default :
            {
                cout<<"Please Select from the given option";
            }
    }
    goto m;        

}




void shopping:: administrator()
{
    m: 
    int choice;
    cout<<"\n\n\n\t\t\t  Administrator Menu";
    cout<<"\n\t\t\t|____1) Add the Product_____";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|____2) Modify the Product_|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|____3) Delete the Product_|";        
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|____4) Back To Main menu_ |";

    cout<<"\n\\n\t Please enter your choice";
    cin>>choice;

    switch (choice)
    {
    case 1:
        /* code */
        add();
        break;
    case 2:
        edit();
        break;
    case 3: 
        rem();
        break;
    case 4: 
        menu();
        break;    

    default:
        cout<<"Invalid Choice";
        break;
    }
    goto m;    
}

void shopping:: buyer()
{
    m: 
    int choice;
    cout<<"\t\t\t  Buyer Menu    \n";
    cout<<"\t\t\t________________\n";
    cout<<"\t\t\t 1) Buy Product \n";
    cout<<"                      \n";
    cout<<"\t\t\t 2) Go Back     \n";
    cout<<"\t\t\t Enter your choice : ";
    cin>>choice;

    switch(choice):
    {
        case 1:
            receipt();
            break;

        case 2:
            menu();
            break;

        default :
            cout<<"Invalid Choice";

    }
    goto m;

}
void shopping ::add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add New Product";
    cout<<"\n\n\t Product code of the product";
    cin>>pcode;
    cout<<"\n\n\t Name of the Product";
    cin>>price;
    cout<<"\n\n\t Discount on product";
    cin>>dis;

    data.open("database.txt", ios::in);

    if(!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while (!data.eof())
        {
            /* code */
            if (c ==pcode)
            {
                token++;
            }
            
        }
        data.close();    
    
    if(token=1)
        goto m;
    else{
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
}
    cout<<"\n\n\t\t Record Inserted !";    
}

void shopping ::edit()
{
    fstream, data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    
    cout<<"\n\t\t\t Modify the Record";
    cout<<"\n\t\t\t Product Code:";
    cin>>pkey;

    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"\n\n File Doesn't Exist!";
    }
    else{
        data1.open("Database1.txt", ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product New Code:";
                cin>>c;
                cout<<"\n\t\t Name of the Product";
                cin>>n;
                cout<<"\n\t\t Price: ";
                cin>>p;
                cout<<"\n\t\t Discount : ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record Edited";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token==0)
        {
            cout<<"\n\n Sorry, record not found!";
        }

    }
}
void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Product Code :";
    cin>>pkey;
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"File does not exist";
    }
    else
    {
        data1.open("database1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if (pcode=pkey)
            {
                cout<<"\n\n\t Product deleted successfully";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if (token==0)
        {
            cout<<"\n\n\t Record not found";
        }       
    }
}
void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout<<"\n\n|_________________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|_________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();

}

void shopping::receipt()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t Receipt";
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database";
    }
    else
    {
        data.close();
        list();
        cout<<"\n_______________________________\n";
        cout<<"\n                               \n";
        cout<<"\n     Please place the order    \n";
        cout<<"\n                               \n";
        cout<<"\n_______________________________\n";
        do
        {
            m:
            cout<<"\n\nEnter Product Code :";
            cin>>arrc[c];
            cout<<"\n\nEnter the product quality :";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\nDuplicate Product code, please try again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another produc? if yes then press y else no";
            cin>>choice; 
        }
        while(choice=="y");
        cout<<"\n\n\t\t\t___________RECEIPT___________\n";
        cout<<"\nProduct No\t Product Name\t Product Quantity\t Price\tAmount\t Amount with discount\n";

        for(int i=0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount= price*arrq[i];
                    dis= amount - (amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();    
    }
    cout<<"\n\n_______________________________________________";
    cout<<"\n Total Amount : "<<total;
}
int main()
{
    shopping s;
    s.menu();
}
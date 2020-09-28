#include<iostream>
#include<fstream>
#include<windows.h>
#include<iomanip>
using namespace std;
class pizza
{
 private:
   char name[20];
   int salary;
public:
   int id;
   void read_data()
   {
     cout<<"\n\n Enter the employee id:";
     cin>>id;
     fflush(stdin);
     cout<<"\n\n Enter the name of the employee:";
     cin>>name;
     cout<<"\n\n Enter salary:";
     cin>>salary;
   }
   void show_data()
   {
     cout<<setw(10)<<id;
     cout<<setw(10)<<name;
     cout<<setw(10)<<salary<<endl;
   }
};
int main()
{
   fstream FILE,TEMP;
   pizza e;
   int no,c,d;
   ofstream obj("pizza.txt",ios::app);
     obj.close();


   while(1)
   {
    cout<<"1 Display\n";
    cout<<"2 Insert\n";
    cout<<"3 Delete\n";
    cout<<"4 Update\n";
    cout<<"5 Exit\n";
    cout<<"Enter choice: "; cin>>c;
    switch(c)
    {
    case 1:
        FILE.open("pizza.txt",ios::ate|ios::in|ios::out|ios::binary);
        FILE.seekg(0);
        FILE.read((char*)&e,sizeof(e));

        cout<<endl;
        cout<<setw(10)<<"EMP ID:"<<setw(10)<<"NAME:"<<setw(10)<<"SALARY:"<<endl;

        while(FILE.eof()==0)
        {
            e.show_data();
         FILE.read((char*)&e,sizeof(e));
        }
        FILE.close();
        break;
    case 2:
        e.read_data();
        FILE.open("pizza.txt",ios::app|ios::binary);
        FILE.write((char*)&e,sizeof(e));
        FILE.close();
        break;
    case 3:
        cout<<"Enter the Id to delete: ";
        cin>>d;
        FILE.open("pizza.txt",ios::in|ios::binary);
        TEMP.open("temp.txt",ios::out|ios::binary);
        FILE.seekg(0);
        FILE.read((char*)&e,sizeof(e));
        while(FILE.eof()==0)
        {
            if(e.id!=d)
         TEMP.write((char*)&e,sizeof(e));
         FILE.read((char*)&e,sizeof(e));

        }
        FILE.close(); TEMP.close();
        remove("pizza.txt"); rename("temp.txt","pizza.txt");
        break;
    case 4:
        cout<<"Enter the Id to update: ";
        cin>>d;
        FILE.open("pizza.txt",ios::in|ios::binary);
        TEMP.open("temp.txt",ios::out|ios::binary);
        FILE.seekg(0);
        FILE.read((char*)&e,sizeof(e));
        while(FILE.eof()==0)
        {
            if(e.id!=d)
         TEMP.write((char*)&e,sizeof(e)); else break;
         FILE.read((char*)&e,sizeof(e));

        }
        e.read_data();
        TEMP.write((char*)&e,sizeof(e));

        FILE.read((char*)&e,sizeof(e));
        while(FILE.eof()==0)
        {
         TEMP.write((char*)&e,sizeof(e));
         FILE.read((char*)&e,sizeof(e));

        }

        FILE.close(); TEMP.close();
        remove("pizza.txt"); rename("temp.txt","pizza.txt");
        break;
    case 5:
        exit(0);
    }
   }
    return 0;


}

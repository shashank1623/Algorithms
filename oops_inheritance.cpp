#include<iostream>
using namespace std;

class student
{
    protected:
         string name;
         char gender;
         int age;
    public:
        void getData()
        {
            cout<<"enter your name ";
            //cin>>name;
            getline(cin,name);
            cout<<"enter your gender ";
            cin>>gender;
            cout<<"enetr your age ";
            cin>>age;
        }
        void showData()
        {
            cout<<"Name - "<<name<<"\ngender - "<<gender<<"\nAge - "<<age<<endl;
        }
};


class marks: public student
{
    protected: 
          int m1,m2,m3;
    public:
          void getData()
          {
              student::getData();
              cout<<"Enter your marks of three subjects ";
              cin>>m1>>m2>>m3;
          }
          void showData()
          {
              student::showData();
              cout<<"total marks "<<m1+m2+m3<<endl;
          }
};

class sports: public marks
{
    protected:
        string Sname;
        int Smarks,total;
    public:
        void getData()
        {
            marks::getData();
            cout<<"Enter your sports name ";
            cin>>Sname;
            cout<<"Enter your sports marks ";
            cin>>Smarks;
            total = m1+m2+m3+Smarks;
        }
        void showData()
        {
            marks::showData();
            cout<<"sports name "<<Sname<<endl;
            cout<<"total marks in all subjects + sports marks "<<total;
        }
};


int main()
{
    sports S1;
    S1.getData();
    S1.showData();
}
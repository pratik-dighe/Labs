#include<iostream>
#include<fstream>
using namespace std;
int count;
class student
{
    public:
    int r;
    char name[50];
    char add[50];
    char div;
    void input()
    {
        cout<<"\nEnter Roll No. : ";
        cin>>r;
        cout<<"\nEnter Name : ";
        cin>>name;
        cout<<"\nEnter division : ";
        cin>>div;
        cout<<"\nEnter Address : ";
        cin>>add;
    }
    void show()
    {
        // cout<<"\n"<<"Roll No."<<"\t"<<"Name"<<"\t"<<"Division"<<"\t"<<"Address";
        cout<<"\n"<<r<<"\t"<<name<<"\t"<<div<<"\t"<<add;
    }
};
int main()
{
    int ch,count;
    char w;
    do
    {
        cout<<"\n1.Add Data\n2.Search Data\n3.OverWrite Data\n4.Delete Data\n5.Display Data";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                int n,i;
                cout<<"\nHow many Students data you want to add : ";
                cin>>n;
                student s1[10];
                ofstream out("Student.txt",ios::app);
                for(i = 0;i < n;i++)
                {
                    s1[i].input();
                    out.write((char*) &s1[i], sizeof(s1[i]));
                    count++;
                }
                out.close();
                break;
            }
            case 2:
            {
                int n,i;
                cout<<"\nEnter Roll No. you want to search : ";
                cin>>n;
                student s;
                int f = 0;
                ifstream in("Student.txt",ios::in);
                while(in.read((char*) &s,sizeof(s)))
                {
                	if(s.r == n)
                    	{
                        	s.show();
                        	f = 1;
                        	break;
               		}
                }
                if(f==0)
                {
                    cout<<"\nData Not Available !!!! ";
                }
                in.close();
                break;
            }
            /*case 3:
            {
                int n,i;
                cout<<"\nHow many Students data you want to add : ";
                cin>>n;
                student s1[10];
                ofstream out("Student.txt");
                for(i = 0;i < n;i++)
                {
                    s1[i].input();
                    out.write((char*) &s1[i], sizeof(s1[i]));
                    count++;
                }
                out.close();
                break;
            }*/
            
            case 4:
            {
            	student s;
            	int n;
            	cout<<"\nEnter the Roll No. you want to delete : ";
            	cin>>n;
            	ifstream in("Student.txt");
            	ofstream fout("temp.txt",ios :: app);
            	while(in.read((char*) &s,sizeof(s)))
            	{
            		if(s.r != n)
            		{
            			fout.write((char*) &s, sizeof(s));
            		}
            	}
            	remove("Student.txt");
            	rename("temp.txt","Student.txt");
            	break;
            }
            case 5:
            {
                student s;
                ifstream in("Student.txt",ios::in);
                while(in.read((char*) &s,sizeof(s)))
                {
                	s.show();
                }
            	break;
            }
        }
        cout<<"\nDo you want to continue ? (y/n) : ";
        cin>>w;
    }while(w == 'y');
}
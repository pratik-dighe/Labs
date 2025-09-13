#include<iostream>
#include<queue>
#include<string>

using namespace std;

int n;
int **path;
void initial()
{
    cout<<"enter no of cities";
    cin>>n;
    path=new int*[n];
    for(int i=0;i<n;i++)
    {
        path[i]=new int[n];
    }
}
class flight
{
    public:
    flight()
    {
        initial();
    }
    string *city=new string[10];
    void initialise();
    void create();
    void search();
};

void flight::initialise()
{
    for(int i=0;i<n;i++)
    {   
        for(int j=0;j<n;j++)
        {
            path[i][j]=0;
        }
    }

}

void flight::create()
{
    int si,di;
    char c[10],ch;
    
    for(int i=0;i<n;i++)
    {
        cout<<"enter city name";
        cin>>city[i];
    }

    do{
    cout<<"enter the starting city";
    cin>>c;
    int i=0;
    while(city[i]!=c)
    {
        i++;
    }
    si=i;

    cout<<"enter the destination city";
    cin>>c;
     i=0;
    while(city[i]!=c)
    {
        i++;
    }
    di=i;

    cout<<"enter amount of fuel required";
    cin>>path[si][di];
    path[di][si]=path[si][di];
    cout<<"enter y for adding weight for more city";
    cin>>ch;
    cout<<"\n";
    }while(ch=='y');
    int i=0;
    cout<<"  ";
     while(i<n)
    {   cout<<city[i]<<"  ";
        i++;
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {   cout<<city[i]<<"  ";
        for(int j=0;j<n;j++)
        {
            cout<<path[i][j]<<"  ";
        }
        cout<<"\n";
    }
}

void flight::search()
{  

     int *visited=new int(n);
     for(int i=0;i<n;i++)
     {
        visited[i]=0;
     }
     int v1,v2,count=0;
     queue<int>q1;
       v1=0;
     q1.push(v1);
     visited[v1]=1;
   
    while(!q1.empty())
    {   
        v1=q1.front();
        q1.pop();
        count++;
        
        for(v2=0;v2<n;v2++)
        {
            if(path[v1][v2]!=0 && visited[v2]==0)
            {
                q1.push(v2);
                visited[v2]=1;
            }
        }

    }

    if(count==n)
    {
        cout<<"conected";
    }
    else
    {
        cout<<"not conected";
    }

}

int main()
{
    flight ob;
    ob.initialise();
    ob.create();
    ob.search();
    return 0;
}
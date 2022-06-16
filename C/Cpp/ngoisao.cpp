#include <iostream>
using namespace std;

int main()
{
    int n = 10;
    cout<<"Vo Tan Tuyen";
    for (int i=1; i<=n; i++)
    {
        for(int j=1;i<2*(n+2);j++)
        {
            cout<<"  ";
        }
        for(int j=n; j>i;j--)
        {
            cout<<"   ";
        }
        for(int k =1; k<=i; k++)
        {
            cout<< endl;
        }
    }
    for(int i=1; i<=(n+3)/2; i++)
    {
        for(int j =1; j <=3*(i-1)+1;j++)
        {
            cout<< "*  ";
        }
        cout<< endl;
    }
    for(int i =1; i<=n/2-1; i++)
    
}
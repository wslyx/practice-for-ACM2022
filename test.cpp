#include<bits/stdc++.h>
using namespace std;
namespace MainDomain{
    int size;
    int count=0;
    int QueenPos[20]={0};
    bool check(int row,int column)
    {
        for (int i = 0; i < row; i++)
        {
            if(column==QueenPos[i]||abs(QueenPos[i]-column)==row-i)
                return false;
        }
        return true;
    }
    void queen(int row,int column)
    {
        if(row>size-1)
        {
            cout<<"解"<<++count<<": ";
            for (int i = 0; i < size; i++)
            {
                cout<<i+1<<","<<QueenPos[i]+1<<" ";
            }
            cout<<endl;
            queen(size-2,QueenPos[size-2]+1);
        }else if(row==0&&column>size-1)
        {
            return;
        }else if(column>size-1)
        {
            queen(row-1,QueenPos[row-1]+1);
        }else if(check(row,column))
        {
            QueenPos[row]=column;
            queen(++row,0);
        }else{
            queen(row,++column);
        }
    }
}
int main()
{
    cin>>MainDomain::size;
    // MainDomain::size=5;
    MainDomain::queen(0,0);
    return 0;
}
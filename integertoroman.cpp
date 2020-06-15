#include<bits/stdc++.h>
using namespace std;
int main()              //1,4,5,9,10,40,50,90,100,400,500,900,1000
{
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int input;
    cin >>input;
    int i=12;
    string result;
    while(input)
    {
        int div=input/num[i];
        input=input%num[i];
        while(div--)
        {
            //cout<<sym[i];
            result.append(sym[i]);
        }
        i--;
    }
    cout<<result;
}

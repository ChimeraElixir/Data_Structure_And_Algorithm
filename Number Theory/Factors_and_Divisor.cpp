#include <bits/stdc++.h>
using namespace std;

void factors_count_sum(int n)
{
    int ct = 0;
    int sum = 0;
    for (int i = 0; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i <<' '<< n / i<< endl;
            ct+=2;
            sum += i + n / i;
        }
    }
    cout<<ct<<' '<<sum<<endl;;
}

//O(sqrt(n))
void correct_factors_count_sum(int n)
{
    int ct = 0;
    int sum = 0;
    for (int i = 0; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i <<' '<< n / i<< endl;
            ct+=1;
            sum += i ;
            if(n / i != i){
                ct++;
                sum += n / i;
            }
        }
    }
    cout<<ct<<' '<<sum<<endl;;
}

int main(){

    correct_factors_count_sum(36);
    return 0;
}
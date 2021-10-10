#include<bits/stdc++.h>
using namespace  std;
#define MAXN 1000005
int lps[MAXN];
void SetLPS(string pat)
{
    int i=0,j=-1;
    lps[0]=-1;
    while(i<pat.length())
    {
        //Check
        while(j>=0 and pat[i]!=pat[j])
        {
            j=lps[j];
        }
        i++;
        j++;
        lps[i]=j;
    }
}

int KMP(string str,string pat)
{
    int count=0;
    SetLPS(pat);
    int i=0,j=0;
    while(i<str.length()) {
        while (j >= 0 and str[i] != pat[j])
            j = lps[j];
        i++;
        j++;
        if (j == pat.length()) {
            count++;
            j = lps[j];
        }
    }
    return count;
}

int main()
{
    for(int i=0;i<MAXN;i++)
        lps[i]=-1;
        int count=0;
    string str,pat;
    cin >> str >>pat;
    cout<< KMP(str,pat);
    return 0;
}
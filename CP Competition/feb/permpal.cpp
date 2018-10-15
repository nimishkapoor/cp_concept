#include <bits/stdc++.h>
using namespace std;
#define M 26
multimap<char,int> s;
int l,odd,i;
string rev,half,palin;
char oddC;
int freq[M];
map<char,int>::iterator it;
bool isPalin(string str, int* freq)
{
    
    memset(freq, 0, M * sizeof(int));
    l = str.length();
 
    
    for (i = 0; i < l; i++)
    {
     freq[str[i] - 'a']++;
     s.insert(pair<char,int>(str[i],i));
    }
    odd = 0;
 
    
    for (i = 0; i < M; i++)
        if (freq[i] % 2 == 1)
            odd++;
 
    if ((l % 2 == 1 && odd == 1 ) || (l %2 == 0 && odd == 0))
        return true;
    else
        return false;
}
 
string reverse(string str)
{
    rev = str;
    reverse(rev.begin(), rev.end());
    return rev;
}
 
int printAllPossiblePalindromes(string str)
{
    
 
   
    if (!isPalin(str, freq))
        return -1;
 
    l = str.length();
 
  
    half = "";
    for (i = 0; i < M; i++)
    {
        if(freq[i] % 2 == 1)
            oddC = i + 'a';
 
        half += string(freq[i] / 2, i + 'a');
    }
 
    

        palin = half;
        if (l % 2 == 1)
            palin += oddC;
        palin += reverse(half);
    for(i=0;i<str.size();i++)
    {
        it=s.find(palin[i]);
        cout<<it->second+1<<" ";
        it = s.erase(it);
     
    }
   cout<<'\n';
   return 1; 
}
int main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    string str;
    cin>>t;
    while(t--)
    {
     cin>>str;
     if(printAllPossiblePalindromes(str)==-1)
     {
      cout<<-1<<'\n';
      s.clear();
     }
    }
    return 0;
}

#include<stdio.h>
void duo(int n)
{ 
char one[20][12]={"","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ","Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};

char ten[10][9]={" "," ","Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};

(n>19)?printf("%s%s", ten[n/10], one[n%10]):printf("%s", one[n]); 

}
int main()
{ 
 int t;
 scanf("%d", &t);
 while(t--)
 { 

  long long int c[11], i=0;
  long long int a;
 char wor[4][10]={"Hundred ","Thousand ","Lakh ","Crore "};
 scanf("%lld", &a);
 if(a<1)
 printf("Zero ");
 else
 while(a>0)
 {
  i++;
  if(((i+2)%4)!=0)
  {
   c[i]=a%100;
   a=a/100; 
  }
  else
  {
   c[i]=a%10;
   a=a/10; 
  }
 }
 for( ;i>0;i--)
 { 
  if(c[i]!=0)
  { 
   duo(c[i]);
   if(i>1)
   if(c[i]<2)
   printf("%s", wor[(i+2)%4]);
   else
   printf("%s", wor[(i+2)%4]); 
  } 
 }
 printf("Only\n");
 return 0;
}


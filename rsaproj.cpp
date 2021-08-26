#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

class RSA
{
       public:
              long int p,q,n,t,flag,e[100],d[100],temp[100],j,m[100],en[100],i;
              string msg;
              RSA(long x, long y, string s)
              {
                     long i;
                     p = x;
                     q = y;
                     msg = s;
                     n=p*q;
                     t=(p-1)*(q-1);
                     for(i=0;i<msg.size();i++)
                     {
                           m[i] = msg[i];
                     }
              }
             
              int prime(long pr)
              {
                     int i;
                     j=sqrt(pr);
                     for (i=2;i<=j;i++) {
                           if(pr%i==0)
                               return 0;
                     }
                     return 1;
              }
              void ce()
              {
                     int k;
                     k=0;
                     for (i=2;i<t;i++)
                     {
                           if(t%i==0)
                               continue;
                           flag=prime(i);
                           if( flag==1 && i!=p && i!=q)
                           {
                                  e[k]=i;
                                  flag=cd(e[k]);
                                  if(flag>0) {
                                         d[k]=flag;
                                         k++;
                                  }
                                  if(k==99)
                                          break;
                           }
                     }
                     for (i=0;i<j-1;i++)
                     {
                           cout<<(i+1)<<"\t("<<e[i]<<","<<d[i]<<")"<<endl;
                     }
                     cout<<endl;
              }
              long int cd(long int x)
              {
                     long int k=1;
                     while(1) {
                           k=k+t;
                           if(k%x==0)
                               return(k/x);
                     }
              }
              void encrypt(int x)
              {
                     long int pt,ct,key=e[x-1],k,len;
                     cout<<"Value of e used is "<<key<<endl;
                     i=0;
                     len = msg.size();
                     while(i!=len)
                     {
                           pt=m[i];
                           pt=pt-96;
                           k=1;
                           for (j=0;j<key;j++)
                           {
                                  k=k*pt;
                                  k=k%n;
                           }
                           temp[i]=k;
                           ct=k+96;
                           en[i]=ct;
                           i++;
                     }
                     en[i]=-1;
                     cout<<"The Encrypted Message : "<<endl;
                     for (i=0;en[i]!=-1;i++)
                     cout<<(char)en[i];
                     cout<<endl;
              }
              void decrypt(int x)
              {
                     long int pt,ct,key=d[x-1],k;
                     cout<<"Value of d used is "<<key<<endl;
                     i=0;
                     while(en[i]!=-1)
                     {
                           ct=temp[i];
                           k=1;
                           for (j=0;j<key;j++) {
                                  k=k*ct;
                                  k=k%n;
                           }
                           pt=k+96;
                           m[i]=pt;
                           i++;
                     }
                     m[i]=-1;
                     cout<<"The Decrypted Message : "<<endl;
                     for (i=0;m[i]!=-1;i++)
                     cout<<(char)m[i];
                     cout<<endl;
              }
};


int main()
{
       long i,n,t,p,q,x;
       cout<<"Enter the Prime Numbers P & Q"<<endl;
       cin>>p>>q;
       cout<<"Enter the Message"<<endl;
       string msg;
       getchar();
       getline(cin,msg);
       RSA ob(p,q,msg);
       cout<<"Possible values of (e,d) are"<<endl;
       ob.ce();
       cout<<"Chose which values of (e,d) you want to use?"<<endl;
       cin>>x;
       cout<<endl;
       ob.encrypt(x);
       cout<<endl;
       ob.decrypt(x);
       return 0;
}

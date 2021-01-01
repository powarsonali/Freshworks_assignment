#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <array>
#include <list>
#include "json.hpp"

using namespace std;

using json = nlohmann::json;

int main()
{
string filePath="file.json";
json j;
ifstream check;
check.open(filePath);
if(check.is_open()) {
ifstream in("file.json");
{
        in >> j;
        in.close();
}
}



int choice,val,result=0,result1=0,sum,file_size;
string a,b,c,del,keyRead;
int n;
while (1)
{
cout<<"\n****JSON File Menu****\n1. Create\n2. Read\n3. Delete\n4. Safe & Exit file\n\nEnter your choice: ";
cin>>choice;
switch (choice) {
 case 1:
 ineligible:
 cout<<"Enter key name: ";
 cin>>a;
val=a.length();
if (val >33){  
        cout<<"Enter key less then 33 char"<<endl;
        goto ineligible;    
}  
if(j.contains(a))
{
        cout<<"key already exist"<<endl;
        goto ineligible;
}  
     
 cout<<"Enter total key_ value pair: "<<endl;
 cin>>n;
 forloop:
 for(int i=0;i<n;i++)
 {
 cout<<"Enter key: ";
 cin>>b;
 if(j.find(b)==j.end())
 {
        result=result+b.length();
 }
 cout<<"Enter value: ";  
 cin>>c;
 result1=result1+c.length();
 j[a][b]=c;
 }
 sum=result+result1;
 if(sum>16000)
 {
         cout<<"greater"<<endl;
         j.erase(a);
         result=0;
         result1=0;
         goto forloop;
 }
 break;
 case 2:
 cout <<"\n"<<j.dump(4) << std::endl;
 break;
 case 3:
 cout<<"Enter object name to delete: ";
 cin>>del;
 j.erase(del);
 break;
 default: cout<<"Please choose correct option: ";
 case 4:  if(!(j.dump(4)=="null"))
 {
check.open(filePath);
if(!check.is_open()) {
        cout << "There is no json file,creating file..."<<endl;
ofstream create(filePath);
create.close();
}
 }
 



   if(file_size<1073741824)
   {
          ofstream fout("file.json");
          fout<< j.dump(4)<<endl;
          fout.close();
          exit(0);
          }
          else
          {
          break;
          }
}
}
}
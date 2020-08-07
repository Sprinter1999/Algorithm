#include <iostream>
#include <map>
#include <vector>
#include <cstring>
 using namespace std;
 
 map<string, int> m1;
 map<string, int> m2;
 
 bool isnum(char c)
 {
    if(c>='0' && c<='9') return true;
    else return false;
 }
 
 bool isbig(char c)
  {
    if(c>='A' && c<='Z') return true;
    else return false;
  }
  
  
   void add(string s, bool flag, int index) // index 为下标， 必须为括号后的数字 
 {
    int i=0;
    int xs = 1; //系数
    string tmp = "";
    int tindex = 0; //下标  Cl2 中的 2 
//  int index = -1;  //下标 
    while(isnum(s[i]) && i<s.length())  //得到系数 
    {
        if(i == 0) xs = s[i] -'0';
        else xs = xs*10 + (s[i] -'0');
        i++;    
     }
     xs = xs * index; //得到系数 
     
     /*
        1. 遇到大写字母并且 tmp 不为空就要吧 tmp和 tindex * xs 存进 map 中
        2. 遇到数字，把数字记录下来，存进 tindex 中 
        3. 遇到括号，先把 tmp和 tindex进 map 中，再把号里的东西都存进tmp中并且记录index 递归一次
        4. 其他情况把遇到的字符先存进 tmp 中 
        5. 当存进map中时，若 tindex为 0，则存进去为 1 
     */ 
     
     for(; i<s.length(); i++)
       {
          if(isbig(s[i]) && tmp != "") //对应 1  
             {
                if(flag) 
                  {
                     if(tindex == 0) m1[tmp] += xs * 1; 
                     else   m1[tmp] += xs * tindex;
                     tindex = 0; //清零 
                     tmp = s[i];
                  } 
                else 
                  {
                     if(tindex == 0) m2[tmp] += xs * 1; 
                     else   m2[tmp] += xs * tindex;
                     tindex = 0; //清零 
                     tmp = s[i];
                  } 
             }
             
             
          else if(isnum(s[i]) && i<s.length())  //对应 2 
            {
                tindex = tindex *10 + (s[i] - '0');
            }
            
            
          else if(s[i] == '(')  //对应 3 
             {
                if(tmp != "")
                  {
                    if(flag) 
                     {
                        if(tindex == 0) m1[tmp] += xs * 1;
                        else    m1[tmp] += xs * tindex;
                     }
                    else 
                      {
                        if(tindex == 0) 
                           {
                              m2[tmp] += xs * 1;
//                            cout<<m2[tmp]<<endl;
                           }
                        else    m2[tmp] += xs * tindex;
                        
                       }
                    tmp = "";
                    tindex = 0;
                  }
                int x = 1;
                i++;
                for(int j=i; j<s.length(); j++)
                    {
                         if(s[j] == '(')  x++;
                         if(s[j] == ')')  x--;  
                         if(x == 0)
                          {
                            i = j+1;
                            break;
                          }
                          tmp += s[j];
                    }
                  
                  //找括号外边的数字
                    int index1 = 0; 
                  while(isnum(s[i]) && i<s.length()) 
                     {
                         index1 =index1 *10 + (s[i] - '0');
                         i++;
                     }
                   if(index1 == 0) index1 = 1;
                  add(tmp, flag, index1 * xs);
                  i--;// 因为等下还要i++ 
                  tindex = 0;
                  tmp="";
             }
            
            
            else // 对应 4 
            {
                tmp += s[i];
             } 
       } 
       
       if(tmp != "")
         {
            if(flag) 
                  {
                    
                     if(tindex == 0) 
                        {
                           m1[tmp] += xs * 1; 
//                         cout<<"tmp: "<<m1[tmp]<<endl;
                        }
                     else   m1[tmp] += xs * tindex;
                  } 
                else 
                  {
                     if(tindex == 0) m2[tmp] += xs * 1; 
                     else   m2[tmp] += xs * tindex;
                  } 
         }
 }
 
 
 bool isBan(string s)
 {
    
    vector<string> v1;
    vector<string> v2;
    string line;
    string line1;
    bool flag = false;
        for(int i=0; i<s.length(); i++)
         {
           if(s[i] == '=') 
            {
              flag = true;
              i++;
            }
            if(!flag) 
             {
               line += s[i];
             }
            else line1 += s[i];
        } 
        for(int t = line.find("+"); t != -1; t = line.find("+"))
          {
             v1.push_back(line.substr(0, t));
             line = line.substr(t+1);
          }
        v1.push_back(line);
       for(int t = line1.find("+"); t != -1; t = line1.find("+"))
         {
           v2.push_back(line1.substr(0, t));
           line1 = line1.substr(t+1); 
         }
        v2.push_back(line1);
//      cout<<v1.size()<<endl;
        
        for(int i=0; i<v1.size(); i++)
          {
//          cout<<"aaa"<<v1[i]<<endl;
            add(v1[i], true, 1);
          }
        for(int i=0; i<v2.size(); i++)
          {
//          cout<<"aaa"<<v2[i]<<endl;
            add(v2[i], false, 1);
          }
        
     map<string, int>::iterator it1;
     map<string, int>::iterator it2;
     it2 = m2.begin();
     bool flag1 = true;
//   cout<<"a"<<endl;
     for(it1 = m1.begin(); it1 != m1.end(); it1++)
     {
//      cout<<"a"<<endl;
//      cout<<it1 -> first<<" "<<it1 -> second<<endl;
//      cout<<it2 -> first<<" "<<it2 -> second<<endl; 
        if(it1 -> first == it2 -> first && it1 -> second == it2 -> second)
        {
            it2++;
         }
        else 
         {
            flag1 = false;
//          break;
         }
     }
     
     if(!flag1) return false;
     else return true;
 }
 
 
 int main()
 {
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    { 
      m1.clear();
      m2.clear();
      string s;
      cin>>s;
      if(isBan(s)) cout<<"Y"<<endl;
      else  cout<<"N"<<endl;
     }
 }
 
 
 /*
11
4Au+8NaCN+2H2O+O2=4Na(Au(CN)2)+4NaOH
4Zn+10HNO3=4Zn(NO3)2+NH4NO3+3H2O
H2+O2=H2O
2H2+O2=2H2O
H2+Cl2=2NaCl
H2+Cl2=2HCl
CH4+2O2=CO2+2H2O
CaCl2+2AgNO3=Ca(NO3)2+2AgCl
3Ba(OH)2+2H3PO4=6H2O+Ba3(PO4)2
3Ba(OH)2+2H3PO4=Ba3(PO4)2+6H2O
Cu+As=Cs+Au
*/
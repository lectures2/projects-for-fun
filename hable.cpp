#include <iostream>
using namespace std;

int main()
{
    
    string desc = "hello  and welcome in this game we will explore what is ur intersets please choose numer bassed on ur intersets" ;
    cout << desc  << endl;
    cout << "enter the same number 3 times which is (0) , (1) , (2) , (3) , (4) , (5) , (6) , (7) , (8) , (9) please choose number and type it on the console 3 times" << endl;
    float a,b,c;
    cin >> a >> b >> c;
    if (a==1){
        cout << "i love my self" << endl;
        cin >> a;
    } else if(a==2){
        cout << "i love to watch porn" << endl;
        
    } else if(a==3){
        cout << "im pro gamer" << endl;
        
    }else if (b==4){
        cout << "i do care that much" << endl;
       cin >> b;
    } else if(b==5){
        cout << "i do care that much" << endl;
        
    }else if (b==6){
        cout << "i hate cooking alone" << endl;
        
    }else if(c==7){
        cout << "i hate lving alone" << endl;
        cin >> c;
    } else if (c==8){
            cout << "i dont know what should i do in my life" << endl;
            
        }else if(c==9){
            cout << "in this case i will be using c++ for my entire life" << endl;
            
        }else if(c==0){
            cout << "i love it too" << endl;
            
        }
        
        return 0;
    }
    

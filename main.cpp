#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <chrono>
#include<ctime>
#include<cmath>
#include <vector>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

class Account{
   int NO= 0;
public:
       vector<int> acc_number =  vector<int>(10);
       friend class ATM;
   Account(int N){
        acc_number.push_back(N); 
        NO++;
    }
     vector<int> getacc() {
      return acc_number;
    }
     int getNO() {
      return NO;
    }
  
};

class ATM{  
        float amount;
     public:
     void balance(int n, float b[]){
          char str[40];   
         sprintf(str, "%.2f", b[n]);
         sscanf(str, "%f", &b[n]);
         std::cout<<"Main Window->Show balance\n";
         std::cout<<"=====================================\n";
         std::cout<<"Your current balance is:$";
         cout<<b[n]<< endl;
         std::cout<<"-------------------------------------\n";
         std::cout<<"Press enter to go back to the Main Window"<<flush;
          if( !cin ) cin.clear( );
          cin.ignore( numeric_limits<streamsize>::max( ), '\n' );
          cin.get( );
      };


         void deposit(int n, float b[], string type[], string time[], float amt[], int counter){
         std::cout<<"Main Window->Deposit(Enter the following information)\n";
         std::cout<<"========================================================\n";
         std::cout<<"The amount you want to deposit: ";
          while (!(std::cin>>setprecision(2)>>amount)) {
            std::cin.clear();
         std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
            std::cout << "Please input number for deposit\n";
        }
         while(amount<0){
           std::cin.clear();
        std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
            std::cout<<"Please input positive number for deposit\n";
             (std::cin)>>setprecision(2)>>amount;
         }
        b[n] += amount;
         amt[counter] = amount;
         type[counter] = string("deposit");
         auto now = std::chrono::system_clock::now();
         time_t now_time =std::chrono::system_clock::to_time_t(now);
         string s = string(ctime(&now_time));
         s.erase(s.length()-1);
         time[counter] = s;
         std::cout<<"--------------------------------------------\n";
         std::cout<<"Well done... This was added to your balance sucessfully. Press enter to go back to the Main Window"<<flush;
         if( !cin ) cin.clear( );
          cin.ignore( numeric_limits<streamsize>::max( ), '\n' );
          cin.get( );
      };

         void withdraw(int n, float b[], string type[], string time[], float amt[], int counter){
         std::string balance = to_string(b[n]);
         std::cout<<"Main Window->Withdraw(Enter the following information)\n";
         std::cout<<"===================================================\n";
         std::cout<<"The amount you want to withdraw: ";
          while (!(std::cin>>amount)) {
            std::cin.clear();
        std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
            std::cout << "Please input number for withdrawal\n";
        }
         while(amount<0){
           std::cin.clear();
            std::cin.ignore();
            std::cout << "Please input positive number for withdrawal\n";
           (std::cin)>>amount;
           amount = std::ceil(amount * 100.0) / 100.0;
         }
            while(amount>b[n]){
           std::cin.clear();
            std::cin.ignore();
            std::cout << "Please input lower number than existing balance for withdrawal\n";
           (std::cin)>>setprecision(2)>>amount;
         }    
         b[n] -= amount;
          amt[counter]=amount;
         type[counter] = string("withdraw");
         auto now = std::chrono::system_clock::now();
         time_t now_time =std::chrono::system_clock::to_time_t(now);
         string s = string(ctime(&now_time));
         s.erase(s.length()-1);
         time[counter] = s;
         std::cout<<"------------------------------------------\n";
         std::cout<<"Please take your money then.... Press enter to go back to the Main Window"<<flush;
        if( !cin ) cin.clear( );
          cin.ignore( numeric_limits<streamsize>::max( ), '\n' );
          cin.get( ); };

     void transaction(int n, string type[], string time[], float amt[], int counter){
         std::cout<<"Main Window->Show All Transactions\n";
         std::cout<<"=================================================\n";
         std::cout<<"\nAccount no:";
         std::cout<< to_string(n);
         std::cout<<"-------------------------------------------------\n";
         std::cout<<"Date                     |Type             |Amount\n";
       for(unsigned int i =0; i<counter; i++){
         std::cout << time[i]<<" |"<< type[i];
         if(type[i]=="withdraw"){
         std::cout<<"         |"<<setprecision(2)<<fixed<<amt[i]<<"\n";
         }else{
            std::cout<<"          |"<<setprecision(2)<<fixed<<amt[i]<<"\n";
         }
       }
         std::cout<<"----------------------------------------------------\n";
         std::cout<<"\nPress enter to go back to the Main Window"<<flush;
         if( !cin ) cin.clear( );
          cin.ignore( numeric_limits<streamsize>::max( ), '\n' );
          cin.get( );
      };
   
    
};



int main() {
        static int password[10];
        float balance[10];
        std::string type[2500];
        std::string time [2500];
        float amt[2500];
        for(int j=0; j<10;j++){
          password[j] = 123;
          balance[j] = 5000.00;
        }
      static bool logged = false;
      static int A;
        int P;
        std::cout<<"Login Window:\n";
        std::cout<<"=================\n";
        while(1){
           std::cout<<"Enter Your Account no: ";
        while (!(std::cin >> A)) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please input number for account\n";
        }
            std::cout<<"Enter your password: ";
        while (!(std::cin >> P)) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please input number for password\n";
        }
        for(int k=0; k< sizeof(password); k++){
          if(P!=password[k]){
                cout<<"Wrong password\n";
                break;}
          else{
              cout<<"Account created\n";
               logged = true;
                break;
             }
             
        }
        if(logged == true){
        break;
        }else{
        continue;
        }
        }
    
        while(1){
        int selector;
        std::cout<<"-----------------------------\n";
        std::cout<<"Main Window\n";
        std::cout<<"================\n";
        std::cout<<"Choose one of the following options:\n";
        std::cout<<"(1) Show balance\n";
        std::cout<<"(2) Deposit\n";
        std::cout<<"(3) Withdraw\n";
        std::cout<<"(4) Show All Transactions\n";
        std::cout<<"(5) Exit\n";
        std::cout<<"Enter your choice\n";
        while (!(std::cin >> selector)) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Please Enter a number for choice\n";
        }
        ATM a;
        Account acc(A);
        static int account_no = acc.getNO();
        static int counter =0 ;
        switch(selector){
         case 1:
             a.balance(account_no, balance);
             break;
         case 2:
            a.deposit(account_no, balance, type, time, amt, counter);
            counter++;
             break;
         case 3:
             a.withdraw(account_no, balance, type, time, amt, counter);
             counter++;
             break;     
         case 4:
             a.transaction(account_no, type, time, amt, counter);
             break;
          case 5:
              exit(-1);
              break;
         default:
           cout << "\nInvalid choice\n";
        }
        }
};

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Account{
    //account id
public:
        int id;
        //user name
        std:: string user_name;

        //password
        std:: string password;
        //min balance
        int min_balance;

};
std::vector<Account>account_list;
int z=1;
int Deposit(int id3,int Amount){
        account_list[id3].min_balance+=Amount;
        return account_list[id3].min_balance;
}
int Withdraw(int id3,int Amount){
        account_list[id3].min_balance-=Amount;
        return account_list[id3].min_balance;
}
void Show_current_balance(int id3){
        std::cout<<"\n"<<account_list[id3].user_name<<" : "<<"minimum balance : "<<account_list[id3].min_balance;
}
void create_Acc(){

        Account newacc;
        std::cout<<"Enter Username : ";
        std::cin>>newacc.user_name;
        std::cout<<"\nEnter password: ";
        std::cin>>newacc.password;
        std::cout<<"\nEnter min balance: ";
        std::cin>>newacc.min_balance;

        newacc.id=z;
        account_list.push_back(newacc);
        std::cout<<"\nYour account id is: "<<newacc.id<<endl;
        z++;
}
void Transfer_Money(int id3){
   int deposit_id,Amount;
   std::cout<<"Enter id to transfer money : ";
   std::cin>>deposit_id;
   std::cout<<"\nEnter amount to transfer : ";
   std::cin>>Amount;
   bool found=false;
   if(Amount<=account_list[id3].min_balance){
        account_list[id3].min_balance-=Amount;
        for(int i=0;i<account_list.size();i++ ){
             if(account_list[i].id==deposit_id){
         account_list[i].min_balance+=Amount;
         found=true;
        }
        }
       if(found){
        cout<<"transfered Amount successfullly....."<<endl;
       }
        else {
            std::cout<<"ID not found........."<<endl;
        }

   }
   else{
    std::cout<<"! Not enough money\n"<<endl;
   }

}


void use_Acc(){
        std::string Password;
        int id1,id3=0;
        std::cout<<"Enter your account id :";
        std::cin>>id1;
        std::cout<<"\nEnter password : ";
        std::cin>>Password;
        bool id2=false;
        bool pass=false;
        for(int i=0;i<account_list.size();i++){
           if(id1 ==account_list[i].id&&Password==account_list[i].password){
            id2=true;
            id3=i;
        }
        }
        if(id2){



           int n;
   do{
        std::cout<<"\n1.Transfer Money\n";
         std::cout<<"2.Deposit \n";
          std::cout<<"3.Withdraw\n";
           std::cout<<"4.Show current balance\n";
             std::cout<<"5.Quit\n";
             std::cin>>n;
             int Amount;
             switch(n){
             case 1:Transfer_Money(id3);
                    break;
             case 2:
                    std::cout<<"\nEnter the Amount : ";
                    std::cin>>Amount;

                 Deposit(id3,Amount);
                    break;
             case 3:
                    std::cout<<"\nEnter the Amount : ";
                    std::cin>>Amount;
                    Withdraw(id3,Amount);
                    break;

             case 4:Show_current_balance(id3);
                    break;
             case 5:std::cout<<"quiting the Account.......\n";
                    break;
             default :std::cout<<"invailed choice choose again";
             }



   }while(n!=5);

        }
        else{
            std::cout<<"\nnikal sade"<<endl;
        }



}
void update_Acc(){
    std::string Password;
        int id1,id3=0;
        std::cout<<"Enter your account id :";
        std::cin>>id1;
        std::cout<<"\nEnter password : ";
        std::cin>>Password;
        bool id2=false;
        bool pass=false;
        for(int i=0;i<account_list.size();i++){
           if(id1 ==account_list[i].id&&Password==account_list[i].password){
            id2=true;
            id3=i;
        }
        }
        if(id2){
                int n;
               do{std::cout<<"\n Id : "<<account_list[id3].id;
         std::cout<<"\n Username : "<<account_list[id3].user_name;
          std::cout<<"\n3.Password : "<<account_list[id3].password;
           std::cout<<"\n4.Balance : "<<account_list[id3].min_balance;
        std::cout<<"\n Enter the choice which you want to update"<<endl;


         std::cout<<"\n1.Update Username\n";
          std::cout<<"2.Update Password\n";
             std::cout<<"3.Quit\n";
             std::cin>>n;
             std::string user,paas;

             switch(n){

             case 1:cout<<"Enter the Username : ";
                    cin>>user;
                    account_list[id3].user_name=user;
                    break;
             case 2:cout<<"Enter the Password : ";
                    cin>>paas;
                    account_list[id3].password=paas;
                    break;


             case 3:std::cout<<"quiting the bank.......\n";
                    break;
             default :std::cout<<"invailed choice choose again";
             }



   }while(n!=3);
        }
        else{
            std::cout<<"nikal sade.........."<<endl;
        }

}
void delete_Acc(){
        std::string Password;
        int id1,id3=0;
        std::cout<<"Enter your account id :";
        std::cin>>id1;
        std::cout<<"\nEnter password : ";
        std::cin>>Password;
        bool id2=false;
        bool pass=false;

           auto it = std::find_if(account_list.begin(), account_list.end(), [&](const Account& acc) {
        return acc.id == id1 && acc.password == Password;
    });

    if (it != account_list.end()) {
        account_list.erase(it);
        std::cout << "Account Deleted.\n";
    } else {
        std::cout << "Account not found.\n";
    }

}
main(){
   int n;
   do{
        std::cout<<"*NOTE ID is always be a integer\n *Username&Password should be in english\n"<<endl;
        std::cout<<"\n1.Create Account\n";
         std::cout<<"2.Use Account \n";
          std::cout<<"3.Update Account\n";
           std::cout<<"4.Delete Account\n";
             std::cout<<"5.Quit\n";
             std::cin>>n;
             switch(n){
             case 1:create_Acc();
                    break;
             case 2:use_Acc();
                    break;
             case 3:update_Acc();
                    break;

             case 4:delete_Acc();
                    break;
             case 5:std::cout<<"quiting the bank.......\n";
                    break;
             default :std::cout<<"invailed choice choose again";
             }



   }while(n!=5);

}

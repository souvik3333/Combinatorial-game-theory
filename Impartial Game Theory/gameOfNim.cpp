/*
Game of nim
Souvik Mandal    160002056
T. Venkat Nikhil 160001058
*/

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

bool user_move(int *num_of_objects_in_piles,int num_of_piles){

    //--------------------variable declarations-------------------------

    int user_selected_pile=0;
    int user_selected_object_number=0;
    int total_object_count=0;

    //-------------------- Beginning of the user option loop -------------------

    while(true){
        cout<<"Please enter pile number you want to select"<<" : ";
        cin>>user_selected_pile;
        cout<<"Please enter number of object you want to remove"<<" : ";
        cin>>user_selected_object_number;
        if(num_of_objects_in_piles[user_selected_pile-1]-user_selected_object_number<0 || user_selected_object_number==0)
            cout<<"You made an invalid move,please check your inputs and try again"<<endl;
        else
            break;
    }
    num_of_objects_in_piles[user_selected_pile-1]=num_of_objects_in_piles[user_selected_pile-1]-user_selected_object_number;
    cout<<"You have selected "<<user_selected_pile<<" and removed "<<user_selected_object_number<<" objects from it."<<endl;
    cout<<"Remaining objects in piles"<<endl;
    rep(i,0,num_of_piles){
        cout<<"In "<<i+1<<" pile "<<num_of_objects_in_piles[i]<<" remaining."<<endl;
        total_object_count+=num_of_objects_in_piles[i];
    }
    
    if(total_object_count==0)
        return true;
    else
        return false;
}
int computer_move(int *num_of_objects_in_piles,int num_of_piles){

    //--------------------variable declarations-------------------------


    int nim_sum=0;
    int computers_pile;
    int computer_selected_object_number;
    int total_object_count=0;
    //-------------------- Beginning of the computer option loop -------------------
    rep(i,0,num_of_piles){
        nim_sum ^=num_of_objects_in_piles[i];
    }
    if( nim_sum ){
        rep(i,0,num_of_piles){
            if( (num_of_objects_in_piles[i] ^ nim_sum) < num_of_objects_in_piles[i] ){
                computer_selected_object_number=num_of_objects_in_piles[i]- ( num_of_objects_in_piles[i] ^ nim_sum );
                num_of_objects_in_piles[i]=num_of_objects_in_piles[i] ^ nim_sum ;
                computers_pile=i+1;
                break;
            }
        }
    }else{
        rep(i,0,num_of_piles){
            if (num_of_objects_in_piles[i]!=0)
            {
                computer_selected_object_number=num_of_objects_in_piles[i];
                computers_pile=i+1;
                num_of_objects_in_piles[i]=0;
                break;
            }
        }
    }
    cout<<"Computer selected pile "<<computers_pile<<" and removed "<<computer_selected_object_number<<" items from that pile."<<endl;
    cout<<"Remaining objects in piles"<<endl;
    rep(i,0,num_of_piles){
        cout<<"In "<<i+1<<" pile "<<num_of_objects_in_piles[i]<<" remaining."<<endl;
        total_object_count+=num_of_objects_in_piles[i];
    }
    if(total_object_count==0)
        return true;
    else
        return false;
}
int main(){
    //--------------------variable declarations-------------------------
    

    int num_of_piles;
    char first_player='c';
    int num_of_objects_in_piles[num_of_piles];
    char user_response;
    char user_conformation='y';
    
    

    //-------------------- Beginning of the game loop -------------------

    cout << "How to play NIM: " << endl;
    cout << "The traditional game of Nim is played with a number of objects arranged in piles: the number of objects and piles is up to you. " << endl;
    cout << " There are two players. When it's a player's move he or she can take any number of objects from a single heap. They have to take at least" << endl;
    cout << " one object, though, and they can't take objects from more than one heap. The winner is the player who makes the last move, so there are no" << endl;
    cout << "objects left after that move. (Some people play the game the other way around, with the last person to make a move losing the game, but we'll" << endl;
    cout << " ignore that version for the moment." << endl;
    cout<<"Start Game [Y/N] : ";
    cin>>user_response;
    while(user_response=='Y' || user_response=='y'){
        cout<<"Do you want to play first : ";
        cin>>first_player;
        if(first_player=='y' || first_player=='Y')
            first_player='u';
        else
            first_player='c';
        
        
        do{
            cout<<"Enter number of piles : ";
            cin>>num_of_piles;
            cout<<"Please enter the number of object in each piles"<<endl;

            rep(i,0,num_of_piles){
                cout<<"Enter the num of objects in pile no "<<i+1<<" : ";
                cin>>num_of_objects_in_piles[i];
            }
            rep(i,0,num_of_piles){
                cout<<"You have entered "<<num_of_objects_in_piles[i]<<" in "<<i+1<<" pile"<<endl;
            }
            cout<<"Do you want to change any input[Y/N]"<<" : ";
            cin>>user_conformation;
        }while(user_conformation=='y' || user_conformation=='Y');

        user_conformation='y';
        
        if(first_player=='c'){

            while(num_of_objects_in_piles[0]+num_of_objects_in_piles[1]+num_of_objects_in_piles[2]>0){
                if(computer_move(num_of_objects_in_piles,num_of_piles)){
                    cout<<"You lost"<<endl;
                    break;
                }
                if(user_move(num_of_objects_in_piles,num_of_piles)){
                    cout<<"You Won"<<endl;
                    break;
                }
            }
        
        }else{
            while(num_of_objects_in_piles[0]+num_of_objects_in_piles[1]+num_of_objects_in_piles[2]>0){
                if(user_move(num_of_objects_in_piles,num_of_piles)){
                    cout<<"You Won"<<endl;
                    break;
                }
                if(computer_move(num_of_objects_in_piles,num_of_piles)){
                    cout<<"You lost"<<endl;
                    break;
                }
            }
        }
        cout<<"Do you want to play again[Y/N]"<<" : ";
        cin>>user_response;
    }

    cout<<"Game Terminated"<<endl;
}
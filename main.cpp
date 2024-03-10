#include<bits/stdc++.h>

#define good ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long LL;
using namespace std;

void test(LL goout,string sentence);
bool checkspace(string s);

void encryption(string input,string keyword){
    LL i;
    
}
void decryption(string input,string keyword){
    
}
bool checkspace(string s){
    LL count;
    for(count = 0; count < s.size();count++){
        if(s[count] == ' ')
            break;
    }
    return (count != s.size());
}
void test(LL goout,string sentence){
    while(!(goout)){
        if(checkspace(sentence)){
            cout << "Wrong format! Please reinput the key." << endl;
            cin >> sentence;
        }
        else
            goout = 1;
    }
}
int main(){
    string origin,key;
    LL checkmode = 0,checkkey = 0;
    LL i;
    char mode;
    cout << "Please select the mode. (E for encryption, and D for decryption.)" << endl;
    cin >> mode;
    while (!(checkmode)){
        if(mode == 'E'){
            checkmode = 1;
            cout << "Please type a sentence you want to encrypt." << endl;
            cin >> origin;
            cout << "Please input your key to encrypt the sentence." << endl;
            cin >> key;
            test(0,key);
            encryption(origin,key);
        }
        else if(mode == 'D'){
            checkmode = 1;
            cout << "Please type a sentence you want to decrypt." << endl;
            cin >> origin;
            cout << "Please input the key to decrypt the sentence." << endl;
            cin >> key;
        }
        else{
            cout<< "Wrong format! Please select the mode. (E for encryption, and D for decryption.)" << endl;
            cin >> mode;
        }
    }
    return 0;
}
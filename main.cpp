#include <bits/stdc++.h>
#define good ios_base::sync_with_stdio(0);cin.tie(0)

typedef long long LL;
using namespace std;

void encryption(string input,string keyword){
    LL i,count = 0;
    cout << "The cipher text is:";
    for(i = 0; i < input.size(); i++){
        if(input[i] == ' '){
            cout << ' ';
            continue;
        }
        else{
            cout << (char)(input[i]+(keyword[count%5]-'a'));
            count++;
        }
    }
}
void decryption(string input,string keyword){
    
}

int main(){
    string origin,key;
    LL checkmode = 0;
    LL i;
    char mode;
    cout << "Please select the mode. (E for encryption, and D for decryption.)\n";
    cin >> mode;
    while (!(checkmode)){
        if(mode == 'E'){
            checkmode = 1;
            cout << "Please type a sentence you want to encrypt.\n";
            cin.ignore();
            getline(cin,origin);
            cout << "Please input your key to encrypt the sentence.(space is banned)\n";
            cin >> key;
            encryption(origin,key);
        }
        else if(mode == 'D'){
            checkmode = 1;
            cout << "Please type a sentence you want to decrypt.\n";
            getline(cin,origin);
            cout << "Please input the key to decrypt the sentence.(space is banned)\n";
            cin >> key;
            decryption(origin,key);
        }
        else{
            cout<< "Wrong format! Please select the mode. (E for encryption, and D for decryption.)\n";
            cin >> mode;
        }
    }
    return 0;
}
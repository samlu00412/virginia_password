#include <bits/stdc++.h>
#define good ios_base::sync_with_stdio(0);cin.tie(0)

typedef long long LL;
using namespace std;

void encryption(string& input,string& keyword){
    LL i,skip = 0;
    string ciphertext;
    char cipher,key_char;
    cin.ignore();
    cout.flush();
    cout << "The cipher text is:";

    for(i = 0; i < input.size(); i++){
        if(isalpha(input[i])){
            key_char = keyword[(i-skip) % keyword.size()];
            cipher = 'a' + ((tolower(input[i]) + key_char - 2 * 'a') % 26);
            ciphertext.push_back(cipher);
        }
        else{
            skip++;
            ciphertext.push_back(' ');
        }
    }

    cout << ciphertext << '\n';
}
void decryption(string& input,string& keyword){
    LL i,skip = 0;
    string plaintext;
    char plain,key_char;
    cin.ignore();
    cout.flush();
    cout << "The plain text is:";

    for(i = 0; i < input.size(); i++){
        if(isalpha(input[i])){
            key_char = keyword[(i-skip) % keyword.size()];
            plain = 'a' + (tolower(input[i]) - key_char + 26 ) % 26;
            plaintext.push_back(plain);
        }
        else{
            skip++;
            plaintext.push_back(' ');
        }
    }

    cout << plaintext << '\n';
}

int main(){
    string origin,key;
    LL checkmode = 0;
    LL i;
    char mode;
    cout << "Please select the mode. (e for encryption, and d for decryption.)\n";
    cin >> mode;
    while (!(checkmode)){
        if(mode == 'e'){
            checkmode = 1;
            cout << "Please type a sentence you want to encrypt.\n";
            cin.ignore();
            getline(cin,origin);
            cout << "Please input your key to encrypt the sentence.(space is banned)\n";
            cin >> key;
            cout.flush();
            encryption(origin,key);
        }
        else if(mode == 'd'){
            checkmode = 1;
            cout << "Please type a sentence you want to decrypt.\n";
            cin.ignore();
            getline(cin,origin);
            cout << "Please input the key to decrypt the sentence.(space is banned)\n";
            cin >> key;
            cout.flush();
            decryption(origin,key);
        }
        else{
            cout<< "Wrong format! Please select the mode. (E for encryption, and D for decryption.)\n";
            cin >> mode;
        }
    }
    return 0;
}
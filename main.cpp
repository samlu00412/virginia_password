#include <bits/stdc++.h>
typedef long long LL;

using namespace std;

void encryption(string& input,string& keyword){
    LL i,skip = 0;
    string ciphertext;
    char cipher,key_char;
    cout << "The cipher text is:";

    for(i = 0; i < input.size(); i++){
        if(isalpha(input[i])){
            key_char = keyword[(i-skip) % keyword.size()];
            cipher = 'a' + ((tolower(input[i]) + key_char - 2 * 'a') % 26);
            ciphertext.push_back(cipher);
        }
        else{
            skip++;
            ciphertext.push_back(input[i]);
        }
    }

    cout << ciphertext << '\n';
}
void decryption(string& input,string& keyword){
    LL i,skip = 0;
    string plaintext;
    char plain,key_char;
    cout << "The plain text is:";

    for(i = 0; i < input.size(); i++){
        if(isalpha(input[i])){
            key_char = keyword[(i-skip) % keyword.size()];
            plain = 'a' + (tolower(input[i]) - key_char + 26 ) % 26;
            plaintext.push_back(plain);
        }
        else{
            skip++;
            plaintext.push_back(input[i]);
        }
    }

    cout << plaintext << '\n';
}

int main(){
    string origin,key;
    char mode;
    cout << "Please select the mode. (e for encryption, d for decryption, or b for exit)\n";
    cin >> mode;
    while (mode != 'b'){
        if(mode == 'e'){
            cout << "Please type a sentence you want to encrypt.\n";
            cin.ignore();
            getline(cin,origin);
            cout << "Please input your key to encrypt the sentence.(space is banned)\n";
            cin >> key;
            encryption(origin,key);
            cout << "\nInput b for exit, or select the mode. (e for encryption, or d for decryption.)\n";
            cout.flush();
            cin >> mode;
        }
        else if(mode == 'd'){
            cout << "Please type a sentence you want to decrypt.\n";
            cin.ignore();
            getline(cin,origin);
            cout << "Please input the key to decrypt the sentence.(space is banned)\n";
            cin >> key;
            decryption(origin,key);
            cout << "\nInput b for exit, or select the mode. (e for encryption, or d for decryption.)\n";
            cout.flush();
            cin >> mode;
        }
        else{
            cout<< "Wrong format! Please select the mode. (e for encryption, d for decryption, or b for exit)\n";
            cin >> mode;
        }
    }
    return 0;
}
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

void usage() {
  std::cout << "USAGE: substitution [-ed] [key]\n";
}

string encryption(string sentence, string new_alph){
  string enc_str;
  string base;
  unsigned int length = new_alph.length();
  for(unsigned int i = 0; i < length; i++){
    base += tolower(new_alph[i]);
  }

  for(unsigned int i = 0; i < sentence.size(); i++){
    char letter = sentence[i];
    int num = tolower(letter) - 'a';
    if(num >= 0 && num < 26){
      if(isupper(letter)){
        enc_str += toupper(base[num]);
      }
      else{
        enc_str += base[num];
      }
    }
    else{
        enc_str += letter;
    }
  }
  return enc_str;
}

string decryption(string sentence, string new_alph){
  string dec_str;
  string base;
  string reg_alph = "abcdefghijklmnopqretuvwxyz";
  unsigned int length = new_alph.length();
  for(unsigned int i = 0; i < length; i++){
    base += tolower(new_alph[i]);
  }

  for(unsigned int i = 0; i < sentence.size(); i++){
    char letter = sentence[i];
    int num = tolower(letter) - 'a';

    if(num >= 0 && num < 26){
      for(unsigned int j = 0; j < length; i++){
        if(letter == new_alph[j]){
            if(isupper(sentence[i])){
                dec_str += toupper(reg_alph[j]);
            }
            else{
                dec_str += reg_alph[j];
            }
        }
      }
    }
    else{
      dec_str += sentence[i];
    }
  }
  return dec_str;
}

int main(int argc, char** argv) {
  if(argc != 3) {
    usage();
    return 1;
  }
  std::string mode;
  std::string new_alph;
  mode = argv[1];
  new_alph = (string)argv[2];

  if (new_alph.length() != 26){
    usage();
    return 1;
  }

  if (mode == "-e"){
    string message;
    while(getline(cin, message) && !message.empty()){
      cout << encryption(message, new_alph) << endl;
    }
  }
  else if (mode == "-d"){
    string message;
    while(std::getline(std::cin, message) && !message.empty()){
      cout << decryption(message, new_alph) << endl;
    }
  }
  return 0;
}

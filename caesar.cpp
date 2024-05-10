#include <cctype>
#include <iostream>
#include <string>
using namespace std;

void usage() {
  std::cout << "USAGE: caesar [-ed] [key]\n";
}

string encryption(string sentence, int shift){
  int sent_len = sentence.size();
  string enc_str = "";
  for (int i = 0; i < sent_len; i++){
    char letter = sentence[i];
    int char_num = int(letter);

    if(char_num >= 65 && char_num <= 90){ // capitals
      char_num += shift;
      if(char_num > 90){
        while(char_num > 90){
            char_num -= 26;
        }
      }
      if(char_num < 65){
        while(char_num < 65){
          char_num += 26;
        }
      }
    }

    if(char_num >= 97 && char_num <= 122){ // lowers
      char_num += shift;
      if(char_num > 122){
        while(char_num > 122){
          char_num -= 26;
        }
      }
      if(char_num < 97){
        while(char_num < 97){
          char_num += 26;
        }
      }
    }
    enc_str += static_cast<char>(char_num);
  }
  return enc_str;
}

string decryption(string sentence, int shift){
  int sent_len = sentence.size();
  string dec_str = "";
  for(int i = 0; i < sent_len; i++){
    char letter = sentence[i];
    int char_num = int(letter);
    
    if(char_num >= 65 && char_num  <= 90){ // capitals
      char_num = char_num - shift;
      if(char_num < 65){
        while(char_num < 65){
          char_num += 26;
        }
      }
      if(char_num >= 90){
        while(char_num > 90){
          char_num -= 26;
        }
      }
    }
   
    if(char_num >= 97 && char_num <= 122){ // lowers
      char_num = char_num - shift;
      if (char_num < 97){
        while(char_num < 97){
          char_num += 26;
        }
      }
      if(char_num > 122){
        while(char_num > 122){
          char_num -= 26;
        }
      }
    }
    dec_str += static_cast<char>(char_num);
  }
  return dec_str;
}


int main(int argc, char** argv) {
  if(argc != 3) {
    usage();
    return 1;
  }
  string mode;
  int shift;

  mode = argv[1];
  shift = atoi(argv[2]);

  if(mode == "-e"){
    string message;
    while(getline(cin, message)){
      cout << encryption(message, shift) << endl;
    }
  }

  else if(mode == "-d"){
    string message;
    while(getline(cin, message)){
      cout << decryption(message, shift) << endl;
    }
  }

  else{
    usage();
    return 1;
  }

  return 0;
  
}

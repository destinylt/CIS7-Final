// A C++ program to encrypt and decrypt a message from user
#include <iostream>
#include <string>
using namespace std;

//Encryption
string Encrypt(string text, string key)
{
  int plaintext;
  int keyword;
  int cipher;

  for(unsigned int i = 0; i < key.length(); i++)
    {
      if (text[i] != ' ') {
        plaintext = int(text[i]);
        keyword = int(key[i]);

        cipher = (plaintext + keyword) % 26;
          cipher += 'A';

        text[i] = char(cipher);
      }
    }
  return text;
}

//Decryption
string Decrypt(string secret, string key) 
{
  int cipher;
  int keyword;
  int original;

  for(unsigned i = 0; i < key.length(); i++)
    {
      if(secret[i] != ' ')
      {
        cipher = int(secret[i]);
        keyword = int(key[i]);

        original = (cipher - keyword + 26) % 26;
          original += 'A';

        secret[i] = char(original);
      }
    }
  return secret;
}

int main()
{
  string message = "";
  string originalkey = "";
  string matchkey = "";
  string ciphertext = "";

  bool validInput = false;
  while(!validInput)
    {
      cout << "This program provides Vigenere Cipher encryption and" << endl;
      cout << "decryption for a message entered by the user." << endl;
      cout << "Press enter after each input." << endl;
      cout << "\nEnter a message (no spaces or symbols please): ";
      getline(cin, message);
      cout << "Enter a keyword: ";
      getline(cin, originalkey);

      if(originalkey.length() > message.length())
      {
        cout << "Please try again. Keyword cannot exceed message length. \n";
      }
      else
      {
        validInput = true;
      }
    }
  
matchkey = originalkey;

if(originalkey.length() < message.length())
{
  int keylen = originalkey.length();
  for (unsigned int i = keylen; i < message.length(); i++)
    {
      matchkey += matchkey[i % keylen];
    }
}

//mesaage to uppercase
for (unsigned int i = 0; i < message.length(); i++)
  {
    message[i] = toupper(message[i]);
  }

//key to uppercase
for (unsigned int i = 0; i < matchkey.length(); i++)
  {
    matchkey[i] = toupper(matchkey[i]);
  }

cout << "\nMessage to encrypt: \n";
  cout << message << endl;
  
cout << "\nKeyword: \n";
  cout << originalkey << endl;
  
cout << "\nKeyword to match length of message: \n";
  cout << matchkey << endl;
  
ciphertext = Encrypt(message, matchkey);
cout << "\nEncrypted message: \n";
cout << ciphertext << endl;
  
cout << "\nDecrypted message: \n";
cout << Decrypt(ciphertext, matchkey) << endl;

return 0;
}

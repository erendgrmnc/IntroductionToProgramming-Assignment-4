#include "iostream"
#include "string.h"

using namespace std;

class Password //CLASS DECLERATION AND CLASS INFO .
{
private : //PRIVATE SECTION OF CLASS THAT CONTAINS DATA ACCESIBLE ONLY THROUGH CLASS.

	char* alphabet; 
	

	char code[10];

	
	char encryption_text[600];


	const int max_alphabet_lenght = 600;

	const int max_encryption_text_lenght = 600;

	const int max_code_lenght = 10;

public : //PUBLIC SECTION OF CLASS. CAN BE ACCESIBLE THROUGH EVERYWHERE.
	
	
	char* alphabet_p = alphabet;
	char* encryption_text_p = encryption_text;
	char* code_p = code;
	char default_alphabet[600] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	Password() // CONSTRUCTOR
	{
		alphabet_p = &default_alphabet[0];
	}
	
	Password(char* alphabet, char* encryption_text) //CONSTRUCTOR W�TH PARAMETERS
	{
		this->alphabet = alphabet;
		
	}
	


	void assign_encryption_info() // FUNCTION TO GET DATA  FROM USER.
	{
		cout << "Enter an alphabet : "; cin.getline(alphabet_p, max_alphabet_lenght);

		cout << "Enter the code : "; cin >> code_p;

		cout << "Enter the text that will be encrypted : ";  cin >> encryption_text_p;
	}

	char* encrypt(char* alphabet_p,char* code_p,char* encryption_text_p) //FUNCTION TO ENCRYPT THE TEXT GIVEN FROM USER ACCORDING TO VIGINERE CIPHER.
	{
		int encryption_text_length = strlen(encryption_text_p); // FOR CALCULATING ENCRYPTION TEXT LENGHT.
		int code_lenght = strlen(code_p); // FOR CALCULATING CODE LENGHT.
		int i, j;
		int alphabet_lenght = strlen(alphabet_p); // FOR CALCULATING ALPHABET LENGHT.

		char new_code[100] = { NULL }; char encrypted_text[600] = { NULL };

		for ( i = 0, j = 0; i < encryption_text_length; i++,j++) // FOR CALCULATING THE NEW CODE. REPLACING THE TEXT'S LETTERS TO OUR CODE LETTERS.
		{
			if (j == code_lenght)
				j = 0;

			new_code[i] = code_p[j];
		}

		
		for ( i = 0; i < encryption_text_length; i++) // FOR CALCULATING THE ENCRYPTED TEXT.
		{
			encrypted_text[i] = ((encryption_text_p[i] + new_code[i]) % alphabet_lenght) + alphabet_p[0]; // FOR CALCULAT�NG THE ENCRYPTED TEXT.ENCRYPTED TEXT'S LETTER'S ASCII CODDES + CODED TEXT MODE ALPHABET LENGHT PLUS ALPHABET'S FIRST LETTER GIVES US THE ENCRYPTED TEXT.
				   
		}

		
		
		char* return_p = { NULL };

		return_p = &encrypted_text[0];

		cout << " ENCRYPTED TEXT : " << return_p << endl;

		return return_p;

	}

	

	char* decrypt(char* alphabet_p, char* code_p, char* encryption_text_p) // FUNCTION TO DECRYPT THE ENCRYPTED TEXT.
	{	
		int encrypt_text_lenght = strlen(encryption_text_p);
		int code_lenght = strlen(code_p);
		int i, j;
		int alphabet_lenght = strlen(alphabet_p);

		char new_code[100] = { NULL }; char encrypted_text[600] = { NULL }; char decrypt_text[600] = { NULL };

		for (i = 0, j = 0; i < encrypt_text_lenght; i++, j++) // FOR GENERATING THE CODED TEXT. ENCRYPT TEXT'S LETTERS REPLACED BY CODES LETTERS.
		{
			if (j == code_lenght)
				j = 0;

			new_code[i] = code_p[j];
		}

		new_code[i] = '\0';

		for (i = 0; i < encrypt_text_lenght; i++) // FOR CALCULATING THE ENCRYPTED TEXT.
		{
			encrypted_text[i] = ((encryption_text_p[i] + new_code[i]) % alphabet_lenght) + alphabet_p[0]; // FOR CALCULAT�NG THE ENCRYPTED TEXT.ENCRYPTED TEXT'S LETTER'S ASCII CODDES + CODED TEXT MODE ALPHABET LENGHT PLUS ALPHABET'S FIRST LETTER GIVES US THE ENCRYPTED TEXT.

		}

		char* return_p = { NULL };

		return_p = &encrypted_text[0];

		for (i = 0; i < encrypt_text_lenght; i++) // FOR DECRYPTING THE ENCRYPTED TEXT ACCORDING TO VIGINERE CIPHER. ENCRYPTED TEXT'S LETTERS ASCII CODES MINUS CODE'S LETTER'S ASCII CODE MODE ALPHABET LENGHT PLUS ALPHABETS FIRST ELEMENT GIVES US THE DECRYPTED TEXT'S LETTERS ASCII CODES.
		{
			decrypt_text[i] = (((encrypted_text[i] - new_code[i]) + alphabet_lenght) % alphabet_lenght) + alphabet_p[0];

			
		}

		char* decrypt_return_p = { NULL };

		decrypt_return_p = &decrypt_text[0];

		cout << "DECRYPTED TEXT : " << decrypt_return_p << endl;

		return &decrypt_text[0];


	}

};

int main()

{
	Password p1;

	p1.assign_encryption_info(); // TO GETT�NG DATA FROM USER.

	

	*(p1.encrypt(p1.alphabet_p, p1.code_p, p1.encryption_text_p)); // PRINTITING THE ENCRYPTED TEXT.

		*(p1.decrypt(p1.alphabet_p, p1.code_p, p1.encryption_text_p)); // PRINTING THE DECRYPTED TEXT.

	
		system("pause");
	return 0;




}
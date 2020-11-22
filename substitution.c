//
//  CipherSubstitution
//
//  Enciphers a text according to your patter
//

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    if (argc != 2) //2 command line arguments
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26) // 26 letras
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (isalpha(argv[1][i]) == 0) //somente letras
        {
            printf("Key must only contain alphabetic characters.");
            return 1;
        }

        for (int j = 0; j < 26; j++) //verificar se tem letra igual
        {
            if (j != i)
            {
                if (argv[1][i] == argv[1][j])
                {
                    printf("Key must not contain repeated characters.");
                    return 1;
                }
            }
        }
    }

    string plaintext = get_string("plaintext: ");
    int n = strlen(plaintext); //tamanho do texto
    int index;

    for (int i = 0; i < n; i++)
    {
        if (isupper(plaintext[i]) != 0)
        {
            index = plaintext[i] - 65;
            plaintext[i] = toupper(argv[1][index]);

        }
        if (islower(plaintext[i]) != 0)
        {
            index = plaintext[i] - 97;
            plaintext[i] = tolower(argv[1][index]);
        }
        //como ele só pega upper e lower, vai ignorar todos os sinais e numeros.
    }

    printf("ciphertext: %s\n", plaintext);

    return 0;

}
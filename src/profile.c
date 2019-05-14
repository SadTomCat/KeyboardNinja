#include "include/profile.h"

char* create_nickname(uint8_t fail_name)
{   
    char choice;

    while (choice < '1' || choice > '3') {
        if (fail_name == 0) {
            system("clear");            
            fast_intro(1); 
            printf("\n                                          Choose one variant\n\n");
            printf("                    1.continue                    2.back                    3.close\n");
        }

        if (fail_name == 1) {
            system("clear");
            fast_intro(1);  
            printf("\n                                        You input correct nicknamen\n\n");
            printf("                                            Choose one variant\n\n");
            printf("                                    1.continue     2.back     3.exit\n");
        }

        scanf("%c", &choice);
        
        switch(choice) {
            case '1':
                system("clear");
                fast_intro(1);
                printf("\nPut your nickname: "); 
                while (getchar() != '\n');
                break;
            case '2':
                //back
                exit(1);
                break; 
            case '3': 
                exit(0);
        }
    }  
    
    uint8_t i = 0;
    char ch;
    char* nickname = malloc(sizeof(char) * NAME_SIZE);
    nickname[0] = '-'; 

    while ((ch = getchar()) != '\n'){
        if (((ch > 0 && ch < 48) || (ch > 57 && ch < 65) || (ch > 90 && ch < 97) || ch > 122) && ch != 95) {         
            free(nickname);
            char* nickname = malloc(sizeof(char));
            nickname[0] = '-';
            return nickname;
        }
        
        nickname[i] = ch;
        i++;

        if (i == 15) {
            nickname[i] = '\0';
            break;
        }
    }

    return nickname;
}

char* verification_name(char* name)
{   
    char choice = '0';

    while (name[0] == '-') {
        name = create_nickname(1);
    }

    while (choice != '1') {  
        system("clear");
        fast_intro(1);
        printf("\nYour nickname %s\n\n", name);
        printf("                                        Choose one action\n\n");
        printf("                               1.For continue       2.Change nickname\n");
        choice = getchar();

        if (choice == '2') {
            name = create_nickname(0);
        }

        while (name[0] == '-') {
            name = create_nickname(1);
        }
    }

    return name;
}

Profile* add_profile() 
{   
    uint8_t i = 0;
    Profile *new_profile = malloc(sizeof(*new_profile));

    new_profile->name = create_nickname(0);
    new_profile->name = verification_name(new_profile->name);
    new_profile->levels_passed = 0;
    new_profile->place_in_rating = 0;
    new_profile->point = 0;
    new_profile->interface = 1;

    return new_profile;
}
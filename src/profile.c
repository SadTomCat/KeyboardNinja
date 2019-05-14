#include "include/profile.h"

char* create_nickname(uint8_t fail_name)
{   
    system("clear");
    char choice;

    if (fail_name == 0) {
        //временное меню
        fast_intro(1);
        printf("\n                                        Choose one variant\n\n");
        printf("                 1.continue                    2.back                    3.close\n");
        
        while(choice = getchar()) {
            if (choice == '1') {
                while(getchar() != '\n');
                system("clear");
                fast_intro(1);
                printf("\nPut nickname: ");
                break;
            } else if (choice == '2') {
                //
            } else if (choice == '3') {
                exit(0);
            } else {
                system("clear");
                fast_intro(1);
                printf("\n                                        Choose one variant\n\n");
                printf("                 1.continue                    2.back                    3.close\n");
            }
        };
    } else {
        //вставить меню
        fast_intro(1);  
        printf("\n                                  You input correct nicknamen\n\n");
        printf("                                      Choose one variant\n\n");
        printf("                               1.continue     2.back     3.exit\n");

        while (choice = getchar()) {
            if (choice == '1') {
                while(getchar() != '\n');
                system("clear");
                fast_intro(1);
                printf("\nPut nickname: ");
                break;
            } else if (choice == '2') {
                //
            } else if (choice == '3') {
                exit(1);
            } else {
                system("clear");
                fast_intro(1);  
                printf("\n                                  You input correct nicknamen\n\n");
                printf("                                      Choose one variant\n\n");
                printf("                               1.continue     2.back     3.exit\n");
            }
        }
    }

    uint8_t i = 0;
    char ch;
    char* nickname = malloc(sizeof(char) * NAME_SIZE);
    nickname[0] = '1'; 

    ch = getchar();

    while (ch != '\n'){
        if (((ch > 0 && ch < 65) || (ch > 90 && ch < 97) || ch > 122) && ch != 95) {
            free(nickname);
            char* nickname = malloc(sizeof(char));
            nickname[0] = '1';
            break;
        }

        nickname[i] = ch;
        i++;

        if (i == 15) {
            nickname[i] = '\0';
            break;
        }

        ch = getchar();
    }

    return nickname;
}

char* verification_name(char* name)
{   
    char verification = '0';

    while (name[0] == '1') {
        name = create_nickname(1);
    }

    while (verification != '1') {  
        system("clear");
        fast_intro(1);
        printf("\nYour nickname %s\n\n", name);
        printf("                                        Choose one action\n\n");
        printf("                               1.For continue       2.Change nickname\n");
        verification = getchar();

        if (verification == '2') {
            name = create_nickname(0);
        }

        while (name[0] == '1') {
            name = create_nickname(1);
        }
    }

    return name;
}

Profile* add_profile() 
{   
    system("clear");
    //надо вставить интерфейс меню создания профиля
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
#include "include/profile.h"

char* create_nickname(uint8_t fail_name)
{   
    char choice = '0';

    while (choice < '1' || choice > '3') {
        if (fail_name == 0) {
            system("clear");            
            fast_intro(1); 
            printf("\n                                            Choose one variant\n\n");
            printf(KMAG9 "                    1.continue                    2.back                    3.close\n");
        }

        if (fail_name == 1) {
            system("clear");
            fast_intro(1);  
            printf(KMAG1 "\n                                      You input correct nicknamen\n\n");
            printf(KMAG9 "                                          Choose one variant\n\n");
            printf("                                   1.continue     2.back     3.exit\n");
        }

        scanf("%c", &choice);
        
        switch(choice) {
            case '1':
                system("clear");
                fast_intro(1);
                printf(KMAG4 "\nPut your nickname: "); 
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
        if (((ch > 0 && ch < 65) || (ch > 90 && ch < 97) || ch > 122) && ch != 95) {         
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
        printf(KMAG4 "\nYour nickname %s\n\n", name);
        printf(KMAG9 "                                        Choose one action\n\n");
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

Profile* find_profile()
{
    char find_name[16], profile_name[16];
    int levels, place, point, interface;

    Profile* find_profile = malloc(sizeof(*find_profile));

    printf("Enter your profile name: ");
    scanf("%s", find_name);

    FILE *f = fopen("data/PROFILES.txt", "r");

    while (fscanf(f, "%s %d %d %d %d", profile_name, &levels, &place, &point, &interface) != EOF) {
        if (strcmp(find_name, profile_name) == 0) {
	    fclose(f);

	    find_profile->name = profile_name;
	    find_profile->levels_passed = levels;
	    find_profile->place_in_rating = place;
	    find_profile->point = point;
	    find_profile->interface = interface;

	    return find_profile;
	}
    }
    fclose(f);

    printf("Profile not found\n");
    free(find_profile);

    return NULL;
}

void write_profile(Profile* profile)
{
    FILE *f = fopen("data/PROFILES.txt", "a");

    fprintf(f, "%s %d %d %d %d\r\n", profile->name, profile->levels_passed, profile->place_in_rating, profile->point, profile->interface);

    fclose(f);
}


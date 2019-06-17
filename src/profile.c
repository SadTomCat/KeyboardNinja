#include "include/profile.h"

char *create_nickname(uint8_t fail_name)
{
    char choice = '0';

    while (choice < '1' || choice > '2')
    {
        if (fail_name == 0)
        {
            system("clear");
            fast_intro(1);
            menu_equalization(1, "Choose one variant");
            menu_equalization(1, "                            1.continue              2.exit");
        }

        if (fail_name == 1)
        {
            system("clear");
            fast_intro(1);
            printf(KMAG1);
            menu_equalization(1, "You input correct nicknamen");
            printf(KMAG9);
            menu_equalization(1, "Choose one variant");
            menu_equalization(1, "                            1.continue              2.exit");
        }

        scanf("%c", &choice);

        switch (choice)
        {
        case '1':
            system("clear");
            fast_intro(1);
            printf(KMAG4 "\nPut your nickname: ");
            while (getchar() != '\n')
                ;
            break;
        case '2':
            exit(0);
        }
    }

    uint8_t i = 0;
    char ch;
    char *nickname = malloc(sizeof(char) * NAME_SIZE);
    nickname[0] = '-';

    while ((ch = getchar()) != '\n')
    {
        if (((ch > 0 && ch < 65) || (ch > 90 && ch < 97) || ch > 122) && ch != 95)
        {
            free(nickname);
            char *nickname = malloc(sizeof(char));
            nickname[0] = '-';
            return nickname;
        }

        nickname[i] = ch;
        i++;

        if (i == 15)
        {
            nickname[i] = '\0';
            break;
        }
    }

    return nickname;
}

char *verification_name(char *name)
{
    char choice = '0';

    while (name[0] == '-')
    {
        name = create_nickname(1);
    }

    while (choice != '1')
    {
        system("clear");
        fast_intro(1);
        printf(KMAG4 "\nYour nickname %s\n\n", name);
        printf(KMAG9);
        menu_equalization(0, "Choose one action");
        menu_equalization(1, "1.For continue       2.Change nickname");
        choice = getchar();

        if (choice == '2')
        {
            name = create_nickname(0);
        }

        while (name[0] == '-')
        {
            name = create_nickname(1);
        }
    }

    return name;
}

Profile *add_profile()
{
    Profile *new_profile = malloc(sizeof(*new_profile));

    new_profile->name = create_nickname(0);
    new_profile->name = verification_name(new_profile->name);
    new_profile->levels_passed = 0;
    new_profile->place_in_rating = 0;
    new_profile->point = 0;
    new_profile->interface = 1;
    write_profile(new_profile);

    return new_profile;
}

Profile* find_profile()
{
    fast_intro(1);
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

Profile* sing_in() 
{
    Profile *profile = NULL;
    char choice;

    while (profile == NULL) 
    {   
        fast_intro(1);
        printf("                                     1.sing in     2.sing up     3.exit\n");
        choice = getchar();
       
        while ((choice != '1') && (choice != '2') && (choice != '3'))
        {
            fast_intro(1);
            printf("                                     1.sing in     2.sing up     3.exit\n");
            choice = getchar();
        }

        switch (choice)
        {
        case '1':
            profile = find_profile();
            break;

        case '2':
            profile = add_profile();
            break;

        case '3':
            free(profile);
            exit(0);
        }
        
    } 

    return profile;
}


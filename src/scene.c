#include "include/scene.h"

void scene(Profile* profile)
{  
    system("clear");
    char choice; 
    fast_intro();
    printf("\n                                         choice one variant");
    printf("\n\n                    1.Easy      2.medium      3.insane      4.back      5.close\n");
    scanf("%hhd", &choice);

    if (choice == 1) {
        easy(profile);
    }

    if (choice == 2 && profile->levels_passed < 3) {
        system("clear");
        fast_intro();
        printf("\n                                   You cannot choice that level\n");
        printf("\n                               1.continue      2.back      3.close\n");
        scanf("%hhd", &choice);
        
        if (choice == 1) {
            scene(profile);
        }
        
        if (choice == 2) {
            system("clear");
            fast_intro();
            menu(profile);
        }

        if (choice == 3) {
            exit(0);
        }
    }

    if (choice == 2 && profile->levels_passed >= 3) {
        medium(profile);
    }

    if (choice == 3 && profile->levels_passed < 6) {
        system("clear");
        fast_intro();
        printf("\n                                   You cannot choice that level\n");
        printf("\n                               1.continue      2.back      3.close\n");
        scanf("%hhd", &choice);
        
        if (choice == 1) {
            scene(profile);
        }
        
        if (choice == 2) {
            system("clear");
            fast_intro();
            menu(profile);
        }

        if (choice == 3) {
            exit(0);
        }
    }

    if (choice == 2 && profile->levels_passed >= 6) {
        insane(profile);
    }

    if (choice == 4) {
        system("clear");
        fast_intro();
        menu(profile);
    }

    if (choice == 5) {
        exit(0);
    }
}

void easy(Profile* profile)
{
    char choice;

    while (choice = getchar()) {
        system("clear");
        fast_intro();
        printf("\n                                         choice one variant");
        printf("\n\n             1.first level      2.second level      3.third level      4.back      5.close\n");

        if (choice == '1') {
            system("clear");
            char* text = read_from_file("./data/LEVEL_1.txt");
            play_level(profile, text, 2, 100, 1);
            free(text);
        }

        if (choice == '2' && profile->levels_passed < 1) {
            //если есть ошибка вставь меню            
            while (choice = getchar()) {
                system("clear");
                fast_intro();
                printf("\n                                   You cannot choice that level\n");
                printf("\n                               1.continue      2.back      3.close\n");

                if (choice == '1') {
                    easy(profile);
                }

                if (choice == '2') {
                    scene(profile);
                }
                
                if (choice == '3') {
                    exit(0);
                }
            }
        }

        if (choice == '3' && profile->levels_passed < 2) {
                while (choice = getchar()) {
                system("clear");
                fast_intro();
                printf("\n                                   You cannot choice that level\n");
                printf("\n                               1.continue      2.back      3.close\n");

                if (choice == '1') {
                    easy(profile);
                }

                if (choice == '2') {
                    scene(profile);
                }
                
                if (choice == '3') {
                    exit(0);
                }
            }
        }   

        if (choice == '4') {
            system("clear");
            scene(profile);
        }

        if (choice == '5') {
            exit(0);
        }
    }
    
}

void medium(Profile* profile)
{
    system("clear");
    printf("We work for that level\n");
    sleep(3);
}

void insane(Profile* profile)
{
    system("clear");
    printf("We work for that level\n");
    sleep(3);
}

void play_level(Profile* profile, char* text, uint8_t max_mistake, long int max_time, uint8_t level_number)
{   
    if (max_mistake == 2) {
        system("clear");
        printf("Enter this text, you can make 2 mistake\n\n");
        printf("%s\n\n\n", text);
    }

    if (max_mistake == 1) {
        system("clear");
        printf("Enter this text, you can make 1 mistake\n\n");
        printf("%s\n\n\n", text);
    }

    if (max_mistake == 0) {
        system("clear");
        printf("Enter this text, you cannot make mistake\n\n");
        printf("%s\n\n\n", text);
    }
    
    char ch;
    int mistake = -1, i = 0;
    long int start_time, end_time;
    uint16_t text_size = sizeof(*text);
    ch = getchar();

    start_time = time(NULL);

    while ((text[i] != '\0') && (ch != 27) && (ch != '\b')) {
        ch = getchar();
        
        if (ch == '\n') {
            mistake = -1;
        }

        if (text[i] != ch && ch != '\n') {
            mistake++;
            
            if (mistake == max_mistake) {
                //сделать меню
                printf("\nYou made more mistake then was decide\n\n\n");    
                sleep(2);
                return;
                break;
            }
        }

        i++;
    }

    end_time = time(NULL);

    //доработать
    if ((end_time - start_time) > max_time) {
        //сделать варианты
        printf("\nYou did go beyond the time frame\n");
        sleep(5);
        return;
    }

    if (mistake != 2) {
        if (level_number >= profile->levels_passed) {
            profile->levels_passed = level_number + 1;
        }

        if (profile->levels_passed != 9) {
            printf("\nYou win, you make %d mistake, you open %d level\n", mistake + 1, profile->levels_passed);            
        } else {
            //встави особое меню и enter
            printf("Сongratulations! You passed game\n");            
        }
        sleep(5);
    }
}
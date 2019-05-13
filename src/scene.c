/*
    1.определить время для уровней
    2.доделать меню
    3.поревести окончательные тесты
*/
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
        cannot("complexity", profile, 0);
    }  
    
    if (choice == 2 && profile->levels_passed >= 3) {
        medium(profile);
    }  
    
    if (choice == 3 && profile->levels_passed < 6) {
        cannot("complexity", profile, 0);
    }  
    
    if (choice == 3 && profile->levels_passed >= 6) {
        insane(profile);
    }  
    
    if (choice == 4) {
        system("clear");
        fast_intro();
        menu(profile);
    }  
    
    if (choice == 5) {
        exit(0);
    } else {
        scanf("%*[^\n]");
        scene(profile);
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
            play_level(profile, text, 2, 100, 1, 157);
            free(text);
            easy(profile);
        }

        if (choice == '2' && profile->levels_passed < 1) {
            cannot("level", profile, 1);
        }

        if (choice == '2' && profile->levels_passed >= 1) {
            system("clear");
            char* text = read_from_file("./data/LEVEL_2.txt");
            play_level(profile, text, 2, 100, 2, 166);
            free(text);
            easy(profile);
        }  

        if (choice == '3' && profile->levels_passed < 2) {
            cannot("level", profile, 1);
        }

        if (choice == '3' && profile->levels_passed >= 2) {
            system("clear");
            char* text = read_from_file("./data/LEVEL_3.txt");
            play_level(profile, text, 2, 100, 3, 198);
            free(text);
            easy(profile);
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
    char choice;

    while (choice = getchar()) {
        system("clear");
        fast_intro();
        printf("\n                                         choice one variant");
        printf("\n\n             1.first level      2.second level      3.third level      4.back      5.close\n");

        if (choice == '1') {
            system("clear");
            char* text = read_from_file("./data/LEVEL_4.txt");
            play_level(profile, text, 2, 100, 4, 170);
            free(text);
            medium(profile);
        }

        if (choice == '2' && profile->levels_passed < 4) {
            //если есть ошибка вставь меню            
            cannot("level", profile, 2);
        }

        if (choice == '2' && profile->levels_passed >= 4) {
            system("clear");
            char* text = read_from_file("./data/LEVEL_5.txt");
            play_level(profile, text, 2, 100, 5, 188);
            free(text);
            medium(profile);
        }

        if (choice == '3' && profile->levels_passed < 5) {
            cannot("level", profile, 2);
        }

        if (choice == '3' && profile->levels_passed >= 5) {
            system("clear");
            char* text = read_from_file("./data/LEVEL_6.txt");
            play_level(profile, text, 2, 165, 6, 158);
            free(text);
            medium(profile);
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

void insane(Profile* profile)
{
    char choice;

    while (choice = getchar()) {
        system("clear");
        fast_intro();
        printf("\n                                         choice one variant");
        printf("\n\n             1.first level      2.second level      3.third level      4.back      5.close\n");

        if (choice == '1') {
            system("clear");
            char* text = read_from_file("./data/LEVEL_7.txt");
            play_level(profile, text, 2, 290, 7, 287);
            free(text);
            insane(profile);
        }

        if (choice == '2' && profile->levels_passed < 7) {
            //если есть ошибка вставь меню            
            cannot("level", profile, 2);
        }

        if (choice == '2' && profile->levels_passed >= 7) {
            system("clear");
            char* text = read_from_file("./data/LEVEL_8.txt");
            play_level(profile, text, 2, 290, 8, 283);
            free(text);
            insane(profile);
        }

        if (choice == '3' && profile->levels_passed < 8) {
            cannot("level", profile, 2);
        }

        if (choice == '3' && profile->levels_passed >= 8) {
            system("clear");
            char* text = read_from_file("./data/LEVEL_9.txt");
            play_level(profile, text, 2, 440, 9, 429);
            free(text);
            insane(profile);
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

void play_level(Profile* profile, char* text, uint8_t max_mistake, long int max_time, uint8_t level_number, uint16_t text_size)
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
    sleep(3);
    char ch;
    int mistake = -1, i = 0;
    long int start_time, end_time;
    scanf("%*[^\n]");
    ch = getchar();

    start_time = time(NULL);

    while ((text[i] != '\0') && (ch != 27) && (ch != '\b')) {
        ch = getchar();
        
        if (ch == '\n') {
            break;
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
    if ((end_time - start_time) >= max_time) {
        //сделать варианты
        printf("\nYou did go beyond the time frame\n");
        sleep(5);
        return;
    }
    
    mistake = mistake + (text_size - i); 

    if (mistake <= max_mistake) {
        if (level_number > profile->levels_passed && profile->levels_passed != 8) {
            profile->levels_passed = profile->levels_passed + 1;
            printf("\nYou win, you make %d mistake, you open %d level\n", mistake + 1, profile->levels_passed + 1);
            sleep(2);
            return;
        }

        if (profile->levels_passed != 8) {
            printf("\nYou win, you make %d mistake, you completed level\n", mistake + 1);
            sleep(5);
            return;       
        } else {
            //встави особое меню и enter
            printf("Сongratulations! You passed game\n");    
            sleep(5);
            return;        
        }
    } else {
        printf("\nYou made more mistake then was decide, \nput \"enter\" for continue\n\n\n");    
        return; 
    }
}

void cannot(char* current, Profile* profile, uint8_t complexity) 
{   
    char choice;

    if (strcmp(current, "complexity") == 0) {
        while (choice = getchar()) {
            system("clear");
            fast_intro();
            printf("\n                                   You cannot choice that level\n");
            printf("\n                               1.continue      2.menu      3.close\n");
            
            if (choice == '1') {
                scene(profile);
            }  
            
            if (choice == '2') {
                system("clear");
                fast_intro();
                menu(profile);
            }  
            
            if (choice == '3') {
                exit(0);
            } else {
                cannot("complexity", profile, 0);
            }
        }
        
        return;
    }

    if (strcmp(current, "level") == 0) {
        while (choice = getchar()) {
            system("clear");
            fast_intro();
            printf("\n                                   You cannot choice that level\n");
            printf("\n                                 1.back      2.menu      3.close\n");

            if (choice == '1') {
                if (complexity == 1) {
                   easy(profile); 
                }
                
                if (complexity == 2) {
                   medium(profile); 
                }

                if (complexity == 3) {
                   insane(profile); 
                }
            }

            if (choice == '2') {
                system("clear");
                fast_intro();
                menu(profile);
            }
            
            if (choice == '3') {
                exit(0);
            } else {
                cannot("level", profile, complexity);
            }
        }
    }
}
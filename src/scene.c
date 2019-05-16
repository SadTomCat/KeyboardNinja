/*
    1.определить время для уровней
    2.поревести окончательные тесты
*/
#include "include/scene.h"

void scene(Profile* profile)
{  
    fast_intro(profile->interface);
    char choice; 
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
        fast_intro(profile->interface);
        menu(profile, 1);
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
        fast_intro(profile->interface);
        printf("\n                                         choice one variant");
        printf("\n\n             1.first level      2.second level      3.third level      4.back      5.close\n");

        if (choice == '1') {
            char* text = read_from_file("./data/LEVEL_1.txt");
            play_level(profile, text, 2, 100, 1, 157);
            free(text);
            easy(profile);
        }

        if (choice == '2' && profile->levels_passed < 1) {
            cannot("level", profile, 1);
        }

        if (choice == '2' && profile->levels_passed >= 1) {
            char* text = read_from_file("./data/LEVEL_2.txt");
            play_level(profile, text, 2, 100, 2, 166);
            free(text);
            easy(profile);
        }  

        if (choice == '3' && profile->levels_passed < 2) {
            cannot("level", profile, 1);
        }

        if (choice == '3' && profile->levels_passed >= 2) {
            char* text = read_from_file("./data/LEVEL_3.txt");
            play_level(profile, text, 2, 100, 3, 198);
            free(text);
            easy(profile);
        }     

        if (choice == '4') {
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
        fast_intro(profile->interface);
        printf("\n                                         choice one variant");
        printf("\n\n             1.fourth level      2.fifth level      3.sixth level      4.back      5.close\n");

        if (choice == '1') {
            char* text = read_from_file("./data/LEVEL_4.txt");
            play_level(profile, text, 1, 100, 4, 170);
            free(text);
            medium(profile);
        }

        if (choice == '2' && profile->levels_passed < 4) {
            cannot("level", profile, 2);
        }

        if (choice == '2' && profile->levels_passed >= 4) {
            char* text = read_from_file("./data/LEVEL_5.txt");
            play_level(profile, text, 1, 100, 5, 188);
            free(text);
            medium(profile);
        }

        if (choice == '3' && profile->levels_passed < 5) {
            cannot("level", profile, 2);
        }

        if (choice == '3' && profile->levels_passed >= 5) {
            char* text = read_from_file("./data/LEVEL_6.txt");
            play_level(profile, text, 1, 165, 6, 158);
            free(text);
            medium(profile);
        }   

        if (choice == '4') {
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
        fast_intro(profile->interface);
        printf("\n                                         choice one variant");
        printf("\n\n             1.seventh level      2.eighth level      3.ninth level      4.back      5.close\n");

        if (choice == '1') {
            char* text = read_from_file("./data/LEVEL_7.txt");
            play_level(profile, text, 0, 290, 7, 287);
            free(text);
            insane(profile);
        }

        if (choice == '2' && profile->levels_passed < 7) {
            cannot("level", profile, 2);
        }

        if (choice == '2' && profile->levels_passed >= 7) {
            char* text = read_from_file("./data/LEVEL_8.txt");
            play_level(profile, text, 0, 290, 8, 283);
            free(text);
            insane(profile);
        }

        if (choice == '3' && profile->levels_passed < 8) {
            cannot("level", profile, 2);
        }

        if (choice == '3' && profile->levels_passed >= 8) {
            char* text = read_from_file("./data/LEVEL_9.txt");
            play_level(profile, text, 0, 440, 9, 429);
            free(text);
            insane(profile);
        }   

        if (choice == '4') {
            scene(profile);
        }

        if (choice == '5') {
            exit(0);
        }
    }
}

void play_level(Profile* profile, char* text, uint8_t max_mistake, long int max_time, uint8_t level_number, uint16_t text_size)
{       
    char choice;
    while (choice = getchar() != '1') {
        fast_intro(profile->interface);
        printf("\n");
        printf(KMAG4 "Enter text, new string equal space, so use space!\n");
    
        if (max_mistake == 2) {
            printf("You can make 2 mistake\n");        
        }

        if (max_mistake == 1) {
            printf("You can make 1 mistake\n");
        }

        if (max_mistake == 0) {
            printf("You cannot make mistake\n");
        }

        printf("Enter '1' for continue\n");
    }

    system("clear");
    fast_intro(profile->interface);
    scanf("%*[^\n]");
    write_text(text, text_size);
    char ch;
    int mistake = -1, i = 0;
    long int start_time, end_time;
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
                
                while (ch = getchar() != '1') {
                    fast_intro(profile->interface);
                    printf(KMAG4 "\nYou made more mistake then was decide\nPut \'1\' for continue\n\n");    
                }

                return;
            }
        }

        i++;
    }

    end_time = time(NULL);

    if ((end_time - start_time) >= max_time) {
       
        while (ch = getchar() != '1') {
            fast_intro(profile->interface);
            printf(KMAG4 "\nYou did go beyond the time frame\nPut \'1\' for continue\n");
        }

        return;
    }
    
    mistake = mistake + (text_size - i); 

    if (mistake <= max_mistake) {
        if (level_number > profile->levels_passed && profile->levels_passed != 8) {
            profile->levels_passed = profile->levels_passed + 1;
            ch = '0';
            ch = getchar();

            while (ch != '1') {
                fast_intro(profile->interface);
                printf(KMAG5 "\nYou win, you make %d mistake, you open %d level\nPut \'1\' for continue\n", mistake + 1, profile->levels_passed + 1);
                ch = getchar();
            }

            return;
        }

        if (level_number <= 9 && (profile->levels_passed != 8 && level_number != 9)) {
            fast_intro(profile->interface);
            ch = '0';
            ch = getchar();

            while (ch != '1') {
                fast_intro(profile->interface);
                printf(KMAG5 "\nYou win, you make %d mistake, you completed level\nPut \'1\' for continue\n", mistake + 1);
                ch = getchar();
            }

            return;       
        } else if (profile->levels_passed == 8 && level_number == 9) { 
            ch = '0';
            ch = getchar();

            while (ch != '1') {
                fast_intro(2);
                printf(KMAG5 "\nСongratulations you passed game!\nYou can use this menu\nPut \'1\' for continue");   
                ch = getchar();
            }

            return;        
        }
    } else {

        while (ch = getchar() != '1') {
            fast_intro(profile->interface);
            printf(KMAG4 "\nYou made more mistake then was decide, \nput \'1\' for continue\n\n\n"); 
        }

        return; 
    }
}

void cannot(char* current, Profile* profile, uint8_t complexity) 
{   
    char choice;

    if (strcmp(current, "complexity") == 0) {
        while (choice = getchar()) {
            fast_intro(profile->interface);
            printf(KMAG1 "\n                                   You cannot choice that level\n");
            printf(KMAG9 "\n                               1.continue      2.menu      3.close\n");
            
            if (choice == '1') {
                scene(profile);
            }  
            
            if (choice == '2') {
                fast_intro(profile->interface);
                menu(profile, 1);
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
            fast_intro(profile->interface);
            printf(KMAG1 "\n                                   You cannot choice that level\n");
            printf(KMAG9 "\n                                 1.back      2.menu      3.close\n");

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
                fast_intro(profile->interface);
                menu(profile, 1);
            }
            
            if (choice == '3') {
                exit(0);
            } else {
                cannot("level", profile, complexity);
            }
        }
    }
}

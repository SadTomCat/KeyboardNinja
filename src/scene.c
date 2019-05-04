#include "include/scene.h"

void scene(Profile profile)
{
    system("clear");
    char choise;
    fast_intro();
    printf("\n                                         Choise one variant");
    printf("\n\n                    1.Easy      2.medium      3.insane      4.back      5.close\n");

    scanf("%hhd", &choise);

    if (choise == 1) {
        //
    }

    if (choise == 2 && profile.levels_passed[0] < '3') {
        system("clear");
        fast_intro();
        printf("\n                                   You cannot choise that level\n");
        printf("\n                               1.continue      2.back      3.close\n");
        scanf("%hhd", &choise);
        
        if (choise == 1) {
            scene(profile);
        }
        
        if (choise == 2) {
            fast_intro();
            menu();
        }

        if (choise == 3) {
            exit(0);
        }
    }

    if (choise == 2 && profile.levels_passed[0] >= '3') {
        //
    }

    if (choise == 3 && profile.levels_passed[0] < '6') {
        system("clear");
        fast_intro();
        printf("\n                                   You cannot choise that level\n");
        printf("\n                               1.continue      2.back      3.close\n");
        scanf("%hhd", &choise);
        
        if (choise == 1) {
            scene(profile);
        }
        
        if (choise == 2) {
            fast_intro();
            menu();
        }

        if (choise == 3) {
            exit(0);
        }
    }

    if (choise == 2 && profile.levels_passed[0] >= '6') {
        //
    }

    if (choise == 4) {
        fast_intro();
        menu();
    }

    if (choise == 5) {
        exit(0);
    }
}
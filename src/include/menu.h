#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct_profile.h"
#include "scene.h"

static char keyboard[16][102] = {
    {"/////////////////////////////////////////////////////////////////////////////////////////////////////"},
    {"/////////////////////////////////////////////////////////////////////////////////////////////////////"},
    {"///KKK////KKK/EEEEEEEE/YYY///////YYY/BBBBBBBBB////OOOOOO/////////AAAA//////RRRRRRRRR///DDDDDD////////"},
    {"///KKK///KKK//EEEEEEEE//YYY/////YYY//BBB///BBB//OOO////OOO/////AAA//AAA////RRR/////RRR/DDD//DDD//////"},
    {"///KKK//KKK///EEE////////YYY///YYY///BBB///BBB//OOO////OOO///AAA//////AAA//RRR/////RRR/DDD////DDD////"},
    {"///KKK/KKK////EEE/////////YYY/YYY////BBB///BBB/OOO//////OOO/AAA////////AAA/RRR/////RRR/DDD/////DDD///"},
    {"///KKKKKK/////EEE///////////YYY//////BBB///BBB/OOO//////OOO/AAA////////AAA/RRR////RRR//DDD/////DDD///"},
    {"///KKKKKK/////EEEEEEEE//////YYY//////BBB/BBBB//OOO//////OOO/AAAAAAAAAAAAAA/RRRRRRRRR///DDD/////DDD///"},
    {"///KKKKKK/////EEEEEEEE//////YYY//////BBB/BBBB//OOO//////OOO/AAAAAAAAAAAAAA/RRRRRRRRR///DDD/////DDD///"},
    {"///KKKKKK/////EEE///////////YYY//////BBB///BBB/OOO//////OOO/AAA////////AAA/RRR///RRR///DDD/////DDD///"},
    {"///KKK/KKK////EEE///////////YYY//////BBB///BBB/OOO//////OOO/AAA////////AAA/RRR////RRR//DDD/////DDD///"},
    {"///KKK//KKK///EEE///////////YYY//////BBB///BBB//OOO////OOO//AAA////////AAA/RRR/////RRR/DDD////DDD////"},
    {"///KKK///KKK//EEEEEEEE//////YYY//////BBB///BBB//OOO////OOO//AAA////////AAA/RRR/////RRR/DDD//DDD//////"},
    {"///KKK////KKK/EEEEEEEE//////YYY//////BBBBBBBBB////OOOOOO////AAA////////AAA/RRR/////RRR/DDDDDD////////"},
    {"/////////////////////////////////////////////////////////////////////////////////////////////////////"},
    {"/////////////////////////////////////////////////////////////////////////////FROM NINJAS TO NINJAS///"},
};                                                                                                            
            
static char keyboard2[16][102] = {
    {"....................................................................................................."},
    {"....................................................................................................."},
    {"   NNNN     NNN  IIIIII  NNNN     NNN      JJJJJJ       AAAA                                         "},
    {"   NNNNN    NNN  IIIIII  NNNNN    NNN      JJJJJJ     AAA  AAA       *                *       |      "},
    {"   NNN NN   NNN          NNN NN   NNN      JJJJJJ   AAA      AAA      **            **       |||     "},
    {"   NNN NN   NNN  IIIIII  NNN NN   NNN      JJJJJJ  AAA        AAA      ***        ***    *   |||   * "},
    {"   NNN NN   NNN  IIIIII  NNN NN   NNN      JJJJJJ  AAA        AAA       ****    ****    *   |||||   *"},
    {"   NNN  NN  NNN  IIIIII  NNN  NN  NNN      JJJJJJ  AAAAAAAAAAAAAA        **********       * ||||| *  "},
    {"   NNN  NN  NNN  IIIIII  NNN  NN  NNN      JJJJJJ  AAAAAAAAAAAAAA         **    **        *********  "},
    {"   NNN  NN  NNN  IIIIII  NNN  NN  NNN      JJJJJJ  AAA        AAA        **********       **     **  "},
    {"   NNN  NN  NNN  IIIIII  NNN  NN  NNN      JJJJJJ  AAA        AAA       ****    ****      *********  "},
    {"   NNN  NN  NNN  IIIIII  NNN  NN  NNN      JJJJJJ  AAA        AAA      ***        ***     *********  "},
    {"   NNN   NN NNN  IIIIII  NNN   NN NNN     JJJJJJ   AAA        AAA     **            **    ***   ***  "},
    {"   NNN    NNNNN  IIIIII  NNN    NNNNN  JJJJJJ      AAA        AAA    *                *   ***   ***  "},
    {"....................................................................................................."},
    {".............................................................................FROM NINJAS TO NINJAS..."},
};

int choosen_action();
void intro(int intro_variant);
void fast_intro(int intro_variant);
int menu(Profile *profile, int intro_variant);

#endif //MENU_H_
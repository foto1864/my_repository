#include "../../include/Birthday_Notifications.h"

// Compare Function that arranges dates in chronological order
int compare_dates(DateInfo info_1, DateInfo info_2){

    DateInfo info_01 = info_1;
    DateInfo info_02 = info_2;

    // If the year of the first date is greater than the year of
    // the second date, then that means that the first date comes
    // after the second. Same thing happens the other way around.

    //if (info_01->year > info_02->year) 
      //  return 1;
    //else if (info_01->year < info_02->year) 
      //  return -1;

    // If the month of the first date is greater than the month of
    // the second date, then that means that the first date comes 
    // after the second. Same thing happens the other way around. 

    if (info_01->month > info_02->month) 
        return 1;
    else if (info_01->month < info_02->month)
        return -1;

    // If the control flow reaches this point, it means that both dates
    // are of the same month. This means that it depends on the day itself
    // to figure out what date between info_1, info_2 comes first.

    if (info_01->date > info_02->date)
        return 1;
    else if (info_01->date < info_02->date)
        return -1;
    else 
        return 0;    
}

// Loads the birthdays of the year when the program starts
Map load_birthdays(void) {

    Map birthdays = map_create((CompareFunc)compare_dates, free, NULL);
    
    DateInfo info_AK = malloc(sizeof(*info_AK));
    info_AK->date = 25;
    info_AK->month = 12;
    info_AK->year = 1998;
    map_insert(birthdays, info_AK, "Alice Kolaklidi");

    DateInfo info_CD = malloc(sizeof(*info_CD));
    info_CD->date = 24;
    info_CD->month = 6;
    info_CD->year = 2004;
    map_insert(birthdays, info_CD, "Cynthia Mpousiou 'Cidi Love'");

    DateInfo info_DS = malloc(sizeof(*info_DS));
    info_DS->date = 13;
    info_DS->month = 11;
    info_DS->year = 2004;
    map_insert(birthdays, info_DS, "Despina Stavrinou");

    DateInfo info_MAM = malloc(sizeof(*info_MAM));
    info_MAM->date = 22;
    info_MAM->month = 5;
    info_MAM->year = 2004;
    map_insert(birthdays, info_MAM, "Melina Amalia Mavroudi");

    DateInfo info_ADS = malloc(sizeof(*info_ADS));
    info_ADS->date = 11;
    info_ADS->month = 9;
    info_ADS->year = 2004;
    map_insert(birthdays, info_ADS, "Andrianna Kyriakou 'Andy Sunday'");

    DateInfo info_AMA = malloc(sizeof(*info_AMA));
    info_AMA->date = 20;
    info_AMA->month = 2;
    info_AMA->year = 2004;
    map_insert(birthdays, info_AMA, "Alexandra Mitta 'Amita'");

    DateInfo info_BA = malloc(sizeof(*info_BA));
    info_BA->date = 17;
    info_BA->month = 1;
    info_BA->year = 2004;
    map_insert(birthdays, info_BA, "Basilis Afentoulidis");

    DateInfo info_GM = malloc(sizeof(*info_GM));
    info_GM->date = 6;
    info_GM->month = 5;
    info_GM->year = 2004;
    map_insert(birthdays, info_GM, "George Melas");

    DateInfo info_MA = malloc(sizeof(*info_MA));
    info_MA->date = 22;
    info_MA->month = 9;
    info_MA->year = 2004;
    map_insert(birthdays, info_MA, "Maria Alexopoulou");

    DateInfo info_ESPO = malloc(sizeof(*info_ESPO));
    info_ESPO->date = 8;
    info_ESPO->month = 1;
    info_ESPO->year = 2004;
    map_insert(birthdays, info_ESPO, "Antonis Spyropoulos");

    DateInfo info_MK = malloc(sizeof(*info_MK));
    info_MK->date = 3;
    info_MK->month = 8;
    info_MK->year = 2004;
    map_insert(birthdays, info_MK, "Marilena Kastania");

    DateInfo info_AD = malloc(sizeof(*info_AD));
    info_AD->date = 7;
    info_AD->month = 7;
    info_AD->year = 2004;
    map_insert(birthdays, info_AD, "Anastasia Diamantakou");

    DateInfo info_JK = malloc(sizeof(*info_JK));
    info_JK->date = 13;
    info_JK->month = 3;
    info_JK->year = 2004;
    map_insert(birthdays, info_JK, "Jim Kontopidis");

    DateInfo info_AS = malloc(sizeof(*info_AS));
    info_AS->date = 25;
    info_AS->month = 2;
    info_AS->year = 2004;
    map_insert(birthdays, info_AS, "Anastasia Spaidioti");

    DateInfo info_GF = malloc(sizeof(*info_GF));
    info_GF->date = 6;
    info_GF->month = 1;
    info_GF->year = 2004;
    map_insert(birthdays, info_GF, "Giannis Foteinakis");

    DateInfo info_DF = malloc(sizeof(*info_DF));
    info_DF->date = 19;
    info_DF->month = 4;
    info_DF->year = 2005;
    map_insert(birthdays, info_DF, "Dimitris Foteinakis");

    DateInfo info_AF = malloc(sizeof(*info_AF));
    info_AF->date = 24;
    info_AF->month = 10;
    info_AF->year = 1966;
    map_insert(birthdays, info_AF, "Andreas Foteinakis");

    DateInfo info_ET = malloc(sizeof(*info_ET));
    info_ET->date = 23;
    info_ET->month = 10;
    info_ET->year = 1968;
    map_insert(birthdays, info_ET, "Eva Tasiou");
  
    return birthdays;
}
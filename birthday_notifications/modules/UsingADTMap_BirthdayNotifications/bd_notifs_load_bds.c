
Map load_birthdays(void) {

    Map birthdays = map_create((CompareFunc)compare_dates, free, NULL);

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

    DateInfo info_test = malloc(sizeof(*info_test));
    info_test->date = 4;
    info_test->month = 7;
    info_test->year = 2023;
    map_insert(birthdays, info_test, "TEST_DATE");
    
    return birthdays;
}
void rule_4(char ***board, int i, int j, int *posdir)
{
        char *cell;

        calc_posdir(i, j, posdir);
        cell = get_cell(board, posdir, 0);
        rm_from_cell(cell, "234");
        cell = get_cell(board, posdir, 1);
        rm_from_cell(cell, "134");
        cell = get_cell(board, posdir, 2);
        rm_from_cell(cell, "124");
        cell = get_cell(board, posdir, 3);
        rm_from_cell(cell, "123");
}

void rule_3(char ***board, int i, int j, int *posdir)
{
        char *cell;

        calc_posdir(i, j, posdir);
        cell = get_cell(board, posdir, 0);
        rm_from_cell(cell, "34");
        cell = get_cell(board, posdir, 1);
        rm_from_cell(cell, "4");
}

void rule_1(char ***board, int i, int j, int *posdir)
{
        char *cell;

        calc_posdir(i, j, posdir);
        cell = get_cell(board, posdir, 0);
        rm_from_cell(cell, "123");
}

void rule_1_2(char ***board, int i, int j, int *posdir)
{
        char *cell;

        calc_posdir(i, j, posdir);
        cell = get_cell(board, posdir, 3);
        rm_from_cell(cell, "124");
}

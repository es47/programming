#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int N[4][4];
void illustrate(void)
{
    printf("���k����:\n");
    printf("�C��J�@�ӭȡA�ЦA�� Enter �C\n");
    printf("�b4 x 4�j�p����l���A�C���@�}�l�|�X�{��ӼƦr�A\n");
    printf("����C�����ʳ��|�H���X�{�@�ӷs���Ʀr�C\n");
    printf("�o�ӼƦr�|�O2��4�C\n");
    printf("�A��ާ@���ﶵ�u��4�ءG�W�B�U�B���B�k\n");
    printf("(�W:�yw�z�B�U:�ys�z�B��:�ya�z�B�k:�yd�z)�A\n");
    printf("���ʮɡA�O���W�Ҧ��Ʀr���@�_�V���Ӥ�V���ʡC\n");
    printf("���ӬۦP���Ʀr�I�b�@�_�ɷ|�X�֡C\n");
    printf("��ӡu2�v�I�b�@�_�ɡA�|�ܦ��u4�v�C\n");
    printf("��J'e'�ɡA�C�������C\n");
    printf("�п�J'b'�}�l�C���C\n");
}
void up(int N[][4])
{
    int i, j, x;
    for (i = 0; i < 4; i++)
    {
        x = 5;
        for (j = 1; j < 4; j++)
        {
            if (j >= 1)
            {
                if (N[j][i] == N[j - 1][i] && x != j - 1 && N[j][i] != 0)
                {
                    N[j - 1][i] *= 2;
                    N[j][i] = 0;
                    x = j - 1;
                }
                else
                {
                    if(N[j][i] != 0 && N[j - 1][i] == 0)
                    {
                        N[j - 1][i] = N[j][i];
                        N[j][i] = 0;
                        j -= 2;
                    }
                }
            }
        }
    }
}
void down(int N[][4])
{
    int i, j, x;
    for (i = 0; i < 4; i++)
    {
        x = 5;
        for (j = 2; j >= 0; j--)
        {
            if (j <= 2)
            {
                if (N[j][i] == N[j + 1][i] && x != j + 1 && N[j][i] != 0)
                {
                    N[j + 1][i] *= 2;
                    N[j][i] = 0;
                    x = j + 1;
                }
                else
                {
                    if(N[j][i] != 0 && N[j + 1][i] == 0)
                    {
                        N[j + 1][i] = N[j][i];
                        N[j][i] = 0;
                        j += 2;
                    }
                }
            }
        }
    }
}
void left(int N[][4])
{
    int i, j, x;
    for (i = 0; i < 4; i++)
    {
        x = 5;
        for (j = 1; j < 4; j++)
            if (j >= 1)
            {
                if (N[i][j] == N[i][j - 1] && x != j - 1 && N[i][j] != 0)
                {
                    N[i][j - 1] *= 2;
                    N[i][j] = 0;
                    x = j - 1;
                }
                else
                {
                    if(N[i][j] != 0 && N[i][j - 1] == 0)
                    {
                        N[i][j - 1] = N[i][j];
                        N[i][j] = 0;
                        j -= 2;
                    }
                }
            }
    }
}
void right(int N[][4])
{
    int i, j, x;
    for (i = 0; i < 4; i++)
    {
        x = 5;
        for (j = 2; j >= 0; j--)
            if (j <= 2)
            {

                if (N[i][j] == N[i][j + 1] && x != j + 1 && N[i][j] != 0)
                {
                    N[i][j + 1] *= 2;
                    N[i][j] = 0;
                    x = j + 1;
                }
                else
                {
                    if(N[i][j] != 0 && N[i][j + 1] == 0)
                    {
                        N[i][j + 1] = N[i][j];
                        N[i][j] = 0;
                        j += 2;
                    }
                }
            }
    }
}
int none(int N[][4])
{
    int i, j, flag;
    flag = 1;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
        {
            if (N[i][j] == 0)
                flag = 0;
            if (flag == 0) break;
        }
    return flag;
}
int next(int N[][4], int flag)
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (N[i][j] == N[i + 1][j] || N[i][j] == N[i][j + 1])
                flag = 2;
            if (flag == 2) break;
        }
        if (flag == 2) break;
    }
    if (flag != 2)
    {
        j = 0;
        i = 3;
        while(j < 3)
        {
            for (j = 0; j < 3; j++)
            {
                if (N[i][j] == N[i][j + 1] || N[j][i] == N[j + 1][i])
                    flag = 2;
                if (flag == 2) break;
            }
            if (flag == 2) break;
        }
    }
    return flag;
}
int main()
{
    int i, j, flag, a, b, row, col, row2, col2;
    int move, fr;
    char x, y;
    illustrate();
    while (1)
    {
        scanf("%s", &y);
        if (y == 'b' || y == 'e') break;
        if (y != 'b' || y != 'e')
        {
            printf("Warning !!      ");
            printf("�ЦA����J���T�ȡC\n");
        }
    }
    if (y == 'e')
    {
        while (y != 'b')
        {
            printf("�O�_�n���}�C��?\n");
            printf("�}�l�C���п�J b �A�ë� Enter �C\n");
            printf("���}�C���п�J e �A�ë� Enter �C\n");
            scanf("%s", &y);
            if (y == 'e') break;
            if (y != 'b' && y != 'e')
            {
                printf("Warning !!      ");
                printf("�ЦA����J���T�ȡC\n");
            }
        }
        if (y == 'e')
            printf("�P�¶}��  ~  ~  (^_^)");
    }
    while(y != 'e')
    {
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
                N[i][j] = 0;
        move = 0;
        while (y == 'b')
        {
            srand(time(NULL));
            a = (rand() % 2) + 1;
            b = (rand() % 2) + 1;
            a *= 2;
            b *= 2;
            row = (rand() % 4);
            col = (rand() % 4);
            row2 = (rand() % 4);
            col2 = (rand() % 4);
            if (move == 0)
            {
                N[row][col] = a;
                N[row2][col2] = b;
                move++;
            }
            else
            {
                while (1)
                {
                    scanf("%s", &x);
                    if (x == 'w' || x == 's' || x == 'a' || x == 'd' || x == 'e') break;
                    if (x != 'w' || x != 's' || x != 'a' || x != 'd' || x != 'e')
                    {
                        printf("Warning !!      ");
                        printf("�ЦA����J���T�ȡC\n");
                    }
                }
                if (x == 'e')
                {
                    while (x != 'n')
                    {
                        printf("�O�_�n��������?\n");
                        printf("�T�w�п�J y �A�ë� Enter �C\n");
                        printf("�~��п�J n �A�ë� Enter �C\n");
                        scanf("%s", &x);
                        if (x == 'y') break;
                        if (x != 'y' && x != 'n')
                        {
                            printf("Warning !!      ");
                            printf("�ЦA����J���T�ȡC\n");
                        }
                    }
                }
                if (x == 'y') break;
                if (x == 'w')
                    up(N);
                if (x == 's')
                    down(N);
                if (x == 'a')
                    left(N);
                if (x == 'd')
                    right(N);
                fr = 0;
                flag = 0;
                if (x == 'w' || x == 's' || x == 'a' || x == 'd')
                {
                    while(fr == 0)
                    {
                        if (none(N) == 1) break;
                        if (N[row][col] == 0)
                        {
                            N[row][col] = a;
                            fr = 1;
                        }
                        else
                        {
                            row = (rand() % 4);
                            col = (rand() % 4);
                        }
                    }
                    move++;
                }
            }
            for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                {
                    if (N[i][j] >= 0 && N[i][j] <= 8)
                        printf("   %d   ", N[i][j]);
                    if (N[i][j] >= 16 && N[i][j] <= 64)
                        printf("  %d   ", N[i][j]);
                    if (N[i][j] >= 128 && N[i][j] <= 512)
                        printf("  %d  ", N[i][j]);
                    if (N[i][j] == 1024)
                        printf(" %d  ", N[i][j]);
                    if (j == 3 & i == 1)
                        printf("        ���� %d ��", move - 1);
                    if (j == 3)
                        printf("\n");
                }
            flag = 0;
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    if (N[i][j] == 2048)
                        flag = 1;
                    if(N[i][j] == 0)
                        flag = 2;
                    if(flag == 1) break;
                }
                if(flag == 1) break;
            }
            if(flag == 0)
                flag = next(N, flag);
            if(flag == 1)
            {
                printf("You win\n");
                printf("!!���߹F�� 2048 !!\n");
            }
            if(flag == 0)
            {
                printf("Game over\n");
                printf("�[�o!\n");
                printf("�п�J b ���s�}�l�A\n");
                printf("�ο�J e ���}�C���C\n");
            }
            if(flag != 2) break;
        }
        if (x == 'y')
        {
            while (y != 'e')
            {
                printf("�O�_�n�}�l�s���@��?\n");
                printf("�s���@���п�J b �A�ë� Enter �C\n");
                printf("���}�C���п�J e �A�ë� Enter �C\n");
                scanf("%s", &y);
                if (y == 'b') break;
                if (y != 'b' && y != 'e')
                {
                    printf("Warning !!      ");
                    printf("�ЦA����J���T�ȡC\n");
                }
            }
        }
        if (y == 'e')
            printf("�P�¹C��  ~  ~  (^///^)");
    }
}

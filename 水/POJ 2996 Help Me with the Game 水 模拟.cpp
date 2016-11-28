#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
char c[80][80], f[200];
int gow[10] = {'K', 'Q', 'R', 'B', 'N', 'P'};
int gob[10] = {'k', 'q', 'r', 'b', 'n', 'p'};
struct point
{
    int y;  char x;     int next;
}head[200][10];
int  num[200] = {0};

bool cmpmin(point a, point b)
{
    if(a.y == b.y)  return a.x < b.x;
    return a.y < b.y;
}
bool cmpmax(point a, point b)
{
    if(a.y == b.y)  return a.x < b.x;
    return a.y > b.y;
}

void getsort()
{
    sort(head['r'], head['r'] + num['r'], cmpmax);
    sort(head['p'], head['p'] + num['p'], cmpmax);
    sort(head['b'], head['b'] + num['b'], cmpmax);
    sort(head['R'], head['R']+ num['R'], cmpmin);
    sort(head['P'], head['P']+ num['P'], cmpmin);
    sort(head['B'], head['B']+ num['B'], cmpmin);
}
int main(void)
{
    int i, no = 0, t, a, b, j;
    memset(f, '\0', sizeof(f));
    memset(head, -1, sizeof(head));
    char gap[80], x, y;
    f[114] = 'r';   f[98] = 'b';    f[113] = 'q';   f[107] = 'k';   f[110] = 'n';   f[112] = 'p';
    f[82] = 'R';    f[78] = 'N';    f[66] = 'B';    f[81] = 'Q';    f[75] = 'K';    f[80] = 'P';
    for(i = 8; i >= 1; i--)
    {
        scanf("%s%s", gap, c[i]);
        for(j = 2, t = 1; c[i][j] != '\0'; j += 4, t++)
        {
            x = c[i][j];
            if(f[x] == '\0')    continue;
            else
            {
                head[x][num[x]].x = 'a'+t-1;
                head[x][num[x]++].y = i;
            }
        }
    }
    scanf("%s", gap);
    getsort();
    printf("White: K%c%d", head['K'][0].x,head['K'][0].y);
    for(i = 1; i <= 5; i++)
    {
        for(j = 0; j < num[gow[i]]; j ++)
        {
            if(i != 5)  printf(",%c",toupper(gow[i]));
            else printf(",");
            printf("%c%d",head[gow[i]][j].x, head[gow[i]][j].y);
        }

    }
    printf("\n");
    printf("Black: K%c%d", head['k'][0].x,head['k'][0].y);
    for(i = 1; i <= 5; i++)
    {
        for(j = 0; j < num[gob[i]]; j ++)
        {
            if(i != 5)  printf(",%c",toupper(gob[i]));
            else printf(",");
            printf("%c%d", head[gob[i]][j].x, head[gob[i]][j].y);
        }

    }
    printf("\n");
    return 0;
}

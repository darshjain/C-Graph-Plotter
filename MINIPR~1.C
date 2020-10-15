#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
int x, y;            //declared x and y a global
char labels[20][10]; //declared label as global
int coordinate_adjuster_y(int);
int coordinate_adjuster_x(int);
void sorter(int[], int[], int);
void swapper(int &, int &);
void y_plot(int);
void x_plot(int);
void bar_chart();
void line_chart();
void pie_chart();
int main()
{
    int graph_choice;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    printf("Select Graph Type:\n1:LINE GRAPH\n2:PIE CHART\n3:BAR GRAPH\n");
    scanf("%d", &graph_choice);
    switch (graph_choice)
    {
    case 1:
        line_chart();
        break;
    case 2:
        pie_chart();
        break;
    case 3:
        bar_chart();
        break;
    default:
        printf("ERROR: Choice Not Found");
        break;
    }
    //todo---Thank you screen
    getch();
    closegraph();
    return 0;
}
void bar_chart() //input is labels and numeric
{
    int n, i, a[10], b[10], x = 100, factor_y = 20, max_value_y = 0;
    cleardevice(); //clears screen it involves filling screen with background color
    printf("Program to Draw a Bar Chart in C Graphics");
    printf("\n\nEnter Number of values:\t");
    scanf("%d", &n);
    printf("\nEnter X values\n");
    for (i = 0; i < n; i++)
    { //max values are calculated for coordinate adjuster
        scanf("%d", &a[i]);
        if (a[i] > max_value_y)
            max_value_y = a[i];
    }
    printf("\nEnter Labels \n");
    for (i = 0; i < n; i++)
        scanf("%s", labels[i]);
    factor_y = coordinate_adjuster_y(max_value_y);

    cleardevice(); //clears screen it involves filling screen with background color
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(220, 10, "BAR CHART");
    settextstyle(2, 1, 0); // font adjustment for labels
    for (i = 0; i < n; i++)
    {
        printf(""); //null
        setfillstyle(i + 1, i + 1);
        bar(x + 10, 420 - a[i] * factor_y, x + 30, 419);
        setcolor(i + 1);
        outtextxy(x + 10, 425, labels[i]);
        x += 40;
    }
    setcolor(WHITE);
    //initilizing lines for x and y axis center at(100,420)
    line(100, 420, 100, 60);  //y axis
    line(100, 420, 700, 420); //x axis
    outtextxy(80, 420, "0");
    y_plot(max_value_y);
}
void line_chart() //input is both numeric
{
    int n, i, a[10], b[10], max_value_x = 0, max_value_y = 0, factor_x, factor_y;
    cleardevice(); //clears screen it involves filling screen with background color
    printf("Program to Draw a Line Graph in C Graphics");
    printf("\nEnter the no. of inputs\t");
    scanf("%d", &n);
    printf("\nEnter X values\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > max_value_x)
            max_value_x = a[i];
    }
    printf("\nEnter Y values\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
        if (b[i] > max_value_y)
            max_value_y = b[i];
    }
    //inputs till here for x and y coordinates
    cleardevice();
    sorter(a, b, n);
    factor_x = coordinate_adjuster_x(max_value_x);
    factor_y = coordinate_adjuster_y(max_value_y);

    for (i = 0; i < n - 1; i++)
    {
        line(100 + a[i] * factor_x - 20, 420 - b[i] * factor_y, 100 + a[i + 1] * factor_x - 20, 420 - b[i + 1] * factor_y);
    }

    setcolor(WHITE);
    //initilizing lines for x and y axis center at(100,420)
    line(100, 420, 100, 60);  //y axis
    line(100, 420, 700, 420); //x axis
    outtextxy(80, 420, "0");
    y_plot(max_value_y);
    x_plot(max_value_x);
    getch();
    cleardevice(); //clears screen it involves filling screen with background color
}
void pie_chart() //input is labels and numeric-WORKING CODE
{
    float end_angle, start_angle = 0;
    int x_center, y_center, total = 0, n, i, a[20], num, table_x = 20, table_y = 300;
    printf("\nEnter the no. of inputs\t");
    scanf("%d", &n);
    printf("\nEnter X values\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        total += a[i];
    }
    printf("\nEnter Labels \n");
    for (i = 0; i < n; i++)
        scanf("%s", labels[i]); //input labels

    cleardevice(); //clears screen it involves filling screen with background color
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(220, 10, "PIE CHART");
    /* Setting cordinate of center of circle */
    x_center = getmaxx() / 2;
    y_center = getmaxy() / 2;
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    for (i = 0; i < n; i++)
    {
        num = a[i];
        setfillstyle(SOLID_FILL, i + 2);
        end_angle = ((float)num * 360 / (float)total);
        printf("");
        //printf("%d\n", end_angle);
        //it prints end_angle as 0 but the very next lines execute perfectly in each loop
        end_angle += start_angle;
        pieslice(x_center, y_center, start_angle, end_angle, 120);
        start_angle = end_angle;
    }
    for (i = 0; i < n; i++)
    {
        setcolor(i + 2);
        outtextxy(table_x, table_y, labels[i]);
        table_y += 20;
    }
}

int coordinate_adjuster_y(int maximum) //adjusts the distribution of graph according to inputs
{
    int factor;
    factor = 340 / maximum;
    return factor;
}
int coordinate_adjuster_x(int maximum) //adjusts the distribution of graph according to inputs
{
    int factor;
    factor = 550 / maximum;
    return factor;
}
void y_plot(int max_val) //plot coordinates y axis
{
    int i;
    float factor, plot;
    char str[11];
    factor = (float)max_val / 10;

    settextstyle(2, 0, 0);
    for (i = 0; i < 10; i++)
    {
        plot = factor * (i + 1);
        gcvt(plot, 6, str);
        outtextxy(75, 420 - 34 * (i + 1), str);
    }
}
void x_plot(int max_val) //plot coordinates y axis
{
    int i;
    float factor, plot;
    char str[11];
    factor = (float)max_val / 10;

    settextstyle(2, 0, 0);
    for (i = 0; i < 10; i++)
    {
        plot = factor * (i + 1);
        gcvt(plot, 6, str);
        outtextxy(75 + 55 * (i + 1), 420, str);
    }
}
void sorter(int x[], int y[], int n) //for line graph
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (x[j] > x[j + 1])
            {
                swap(&x[j], &x[j + 1]);
                swap(&y[j], &y[j + 1]);
            }
}
void swapper(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
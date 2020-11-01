#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
int x, y;            //declared x and y a global
char labels[20][10]; //declared label as global
int coordinate_adjuster_y(int);
int coordinate_adjuster_x(int);
void openwindow();
void sorter(int[], int[], int);
void swapper(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void y_plot(int);
void x_plot(int);
void bar_chart();
void bar_3dchart();
void line_chart();
void pie_chart();
void close_window();
int main()
{
    int graph_choice;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    openwindow();
    cleardevice();
    setcolor(WHITE);
    setbkcolor(12);
    rectangle(100, 100, 460, 300);
    rectangle(110, 110, 450, 290);
    settextstyle(0, HORIZ_DIR, 0);
    outtextxy(230, 120, "SELECT GRAPH TYPE");
    outtextxy(130, 130, "1: LINE GRAPH");
    outtextxy(130, 140, "2: PIE CHART");
    outtextxy(130, 150, "3: BAR GRAPH");
    outtextxy(130, 160, "4: 3D BAR GRAPH");
    outtextxy(400, 400, "By");
    outtextxy(400, 420, "Darsh Jain - 17");
    outtextxy(400, 440, "Asjad Nirban - 36");
    scanf("%d", &graph_choice);
    setbkcolor(12);
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
    case 4:
        bar_3dchart();
        break;
    default:
        printf("ERROR: Choice Not Found");
        break;
    }

    close_window();
    closegraph();
    return 0;
}

void openwindow()
{
    int aa, bb, cc, dd, i = 10;
    aa = 250;
    bb = 400;
    cc = 260;
    for (dd = 250; dd < 350; dd += 20)
    {
        setfillstyle(1, 2);
        bar(dd, bb, cc, bb += 10);
        cc += 20;
    }
    aa = 250;
    bb = 400;
    cc = 260;
    while (!kbhit())
    {
        setcolor(11);
        rectangle(0, 0, 639, getmaxy());
        rectangle(10, 10, 629, getmaxy() - (10));
        floodfill(1, 1, 11);
        setcolor(10);
        settextstyle(1, 0, 4);
        outtextxy(200, 20, "GRAPH PLOTTER");
        outtextxy(20, 120, "BY: ");
        outtextxy(20, 180, "DARSH JAIN");
        outtextxy(20, 220, "ASJAD NIRBAN");
        outtextxy(20, 356, "Press any key to continue.....");
        settextstyle(1, 0, 2);
        if ((aa == 350) && (cc == 360))
        {
            aa = 250;
            cc = 260;
            continue;
        }
        else
        {
            setcolor(10);
            rectangle(aa, bb, cc, bb + 10);
            rectangle(aa - 1, bb - 1, cc + 1, bb + 11);
        }
        delay(300);
        setcolor(4);
        rectangle(aa - 1, bb - 1, cc + 1, bb + 11);
        aa += 20;
        cc += 20;
    }
}

void bar_3dchart() //input is labels and numeric
{
    int n, i, a[10], b[10], x = 100, factor_y = 20, max_value_y = 0;
    cleardevice(); //clears screen it involves filling screen with background color
    printf("Program to Draw a 3D Bar Chart in C Graphics");
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
    outtextxy(220, 10, "3D BAR CHART");
    settextstyle(2, 1, 0); // font adjustment for labels
    for (i = 0; i < n; i++)
    {
        printf(""); //null
        setfillstyle(i + 1, i + 1);
        bar3d(x + 10, 420 - a[i] * factor_y, x + 30, 419, 10, 1);
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
    setcolor(11);
    rectangle(0, 0, 639, getmaxy());
    rectangle(10, 10, 629, getmaxy() - (10));
    floodfill(1, 1, 11);
    getch();
    cleardevice();
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
    setcolor(11);
    rectangle(0, 0, 639, getmaxy());
    rectangle(10, 10, 629, getmaxy() - (10));
    floodfill(1, 1, 11);
    getch();
    cleardevice();
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
    setcolor(11);
    rectangle(0, 0, 639, getmaxy());
    rectangle(10, 10, 629, getmaxy() - (10));
    floodfill(1, 1, 11);
    getch();
    cleardevice(); //clears screen it involves filling screen with background color
}
void pie_chart() //input is labels and numeric-WORKING CODE
{
    char str[10]; //for label
    float plot, end_angle, start_angle = 0;
    int x_center, y_center, total = 0, n, i, a[20], num, table_x = 20, table_y = 300;
    cleardevice(); //clears screen it involves filling screen with background color
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
        end_angle += start_angle;
        pieslice(x_center, y_center, start_angle, end_angle, 120);
        start_angle = end_angle;
    }
    for (i = 0; i < n; i++)
    {
        setcolor(i + 2);
        plot = (float)a[i] * 100 / (float)total;
        gcvt(plot, 4, str);
        strcat(str, "% ");
        strcat(str, labels[i]);
        outtextxy(table_x, table_y, str);
        table_y += 20;
    }
    setcolor(11);
    rectangle(0, 0, 639, getmaxy());
    rectangle(10, 10, 629, getmaxy() - (10));
    floodfill(1, 1, 11);
    getch();
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
                swapper(&x[j], &x[j + 1]);
                swapper(&y[j], &y[j + 1]);
            }
}
void close_window()
{
    int i, j, k;
    cleardevice();
    rectangle(0, 0, 638, 478);
    k = 0;
    while (!kbhit())
    {
        setcolor(k);
        settextstyle(1, 0, 8);
        outtextxy(100, 150, "THANK YOU");
        line(90, 250, 580, 250);
        delay(200);
        k++;
        setcolor(11);
        rectangle(0, 0, 639, getmaxy());
        rectangle(10, 10, 629, getmaxy() - (10));
        floodfill(1, 1, 11);
    }
}

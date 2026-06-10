#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 30
#define COLS 60

char canvas[ROWS][COLS];

/* Initialize canvas */
void initializeCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

/* Display canvas */
void displayCanvas()
{
    int i, j;

    printf("\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(canvas[i][j] == '_')
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
}

/* Plot a point */
void plot(int x, int y)
{
    if(x >= 0 && x < ROWS && y >= 0 && y < COLS)
    {
        canvas[x][y] = '*';
    }
}

/* Draw Line (Bresenham Algorithm) */
void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while(1)
    {
        plot(x1, y1);

        if(x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if(e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if(e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

/* Draw Rectangle */
void drawRectangle()
{
    int r1, c1, r2, c2, i;

    printf("Enter Top Row Left Column: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter Bottom Row Right Column: ");
    scanf("%d%d", &r2, &c2);

    for(i = c1; i <= c2; i++)
    {
        plot(r1, i);
        plot(r2, i);
    }

    for(i = r1; i <= r2; i++)
    {
        plot(i, c1);
        plot(i, c2);
    }
}

/* Draw Triangle */
void drawTriangle()
{
    int x1, y1, x2, y2, x3, y3;

    printf("Enter Vertex 1 (row col): ");
    scanf("%d%d", &x1, &y1);

    printf("Enter Vertex 2 (row col): ");
    scanf("%d%d", &x2, &y2);

    printf("Enter Vertex 3 (row col): ");
    scanf("%d%d", &x3, &y3);

    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}

/* Draw Circle */
void drawCircle()
{
    int xc, yc, r;
    int x, y;

    printf("Enter Center Row Center Column Radius: ");
    scanf("%d%d%d", &xc, &yc, &r);

    for(x = 0; x < ROWS; x++)
    {
        for(y = 0; y < COLS; y++)
        {
            int d =
                (x - xc) * (x - xc) +
                (y - yc) * (y - yc);

            if(abs(d - r * r) <= r)
            {
                plot(x, y);
            }
        }
    }
}

/* Draw Line */
void drawLineMenu()
{
    int x1, y1, x2, y2;

    printf("Enter x1 y1: ");
    scanf("%d%d", &x1, &y1);

    printf("Enter x2 y2: ");
    scanf("%d%d", &x2, &y2);

    drawLine(x1, y1, x2, y2);
}

/* Delete Object Area */
void deleteArea()
{
    int r1, c1, r2, c2;
    int i, j;

    printf("Enter Top Row Left Column: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter Bottom Row Right Column: ");
    scanf("%d%d", &r2, &c2);

    for(i = r1; i <= r2; i++)
    {
        for(j = c1; j <= c2; j++)
        {
            if(i >= 0 && i < ROWS &&
               j >= 0 && j < COLS)
            {
                canvas[i][j] = '_';
            }
        }
    }
}

/* Main Program */
int main()
{
    int choice;

    initializeCanvas();

    while(1)
    {
        printf("\n");
        printf("===== MENU DRIVEN 2D GRAPHICS EDITOR =====\n");
        printf("1. Draw Line\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Delete Area\n");
        printf("6. Display Picture\n");
        printf("7. Clear Picture\n");
        printf("8. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                drawLineMenu();
                break;

            case 2:
                drawRectangle();
                break;

            case 3:
                drawTriangle();
                break;

            case 4:
                drawCircle();
                break;

            case 5:
                deleteArea();
                break;

            case 6:
                displayCanvas();
                break;

            case 7:
                initializeCanvas();
                printf("Canvas Cleared!\n");
                break;

            case 8:
                printf("Program Ended.\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
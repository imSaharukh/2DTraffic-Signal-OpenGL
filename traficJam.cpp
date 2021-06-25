// #include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <cmath>
/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void circle(int xx, int yy, float r)
{

    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        // glColor3ub(255, 215, 0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        // float r = 4.0f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + xx, y + yy);
    }
    glEnd();
}

void tree(int x, int y)
{
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-60 + x, -70 + y);
    glVertex2f(-55 + x, -70 + y);
    glVertex2f(-55 + x, -50 + y);
    glVertex2f(-60 + x, -50 + y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(-67 + x, -50 + y);
    glVertex2f(-48 + x, -50 + y);
    glVertex2f(-57.5 + x, -35 + y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(-65 + x, -41 + y);
    glVertex2f(-50 + x, -41 + y);
    glVertex2f(-57.5 + x, -26 + y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(-63 + x, -33 + y);
    glVertex2f(-52 + x, -33 + y);
    glVertex2f(-57.5 + x, -22 + y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(-62 + x, -27 + y);
    glVertex2f(-53 + x, -27 + y);
    glVertex2f(-57.5 + x, -20 + y);
    glEnd();
}
void Car(int x, int y)
{
    glBegin(GL_POLYGON);
    glVertex2f(10 + x, y + 65);
    glVertex2f(35 + x, y + 65);
    glVertex2f(35 + x, y + 58);
    glVertex2f(10 + x, y + 58);
    glEnd();
    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(14 + x, y + 65);
    glVertex2f(31 + x, y + 65);
    glVertex2f(28 + x, y + 70);
    glVertex2f(17 + x, y + 70);
    glEnd();
    glColor3ub(0, 0, 0);
    circle(17 + x, 58 + y, 2);
    glColor3ub(0, 0, 0);
    circle(27 + x, 58 + y, 2);
}

void road()
{
    glBegin(GL_QUADS);
    glColor3ub(153, 102, 102);
    glVertex2f(0, 25);
    glVertex2f(100, 25);
    glVertex2f(100, 50);
    glVertex2f(0, 50);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0, 37.5);
    glVertex2f(25, 37.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0 + 30, 37.5);
    glVertex2f(25 + 30, 37.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0 + 30 + 30, 37.5);
    glVertex2f(25 + 30 + 30, 37.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0 + 30, 37.5);
    glVertex2f(25 + 30, 37.5);
    glEnd();
}
void signalLight()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 51, 0);
    glVertex2f(40, 25);
    glVertex2f(42, 25);
    glVertex2f(42, 55);
    glVertex2f(40, 55);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 51, 0);
    glVertex2f(40 - 2, 55);
    glVertex2f(42 + 2, 55);
    glVertex2f(42 + 2, 55 + 20);
    glVertex2f(40 - 2, 55 + 20);
    glEnd();

    glColor3ub(255, 0, 0);
    circle(41, 58, 2);

    glColor3ub(102, 255, 51);
    circle(41, 58 + 6, 2);
    glColor3ub(255, 255, 153);
    circle(41, 58 + 12, 2);

    glEnd();
}
void display()
{
    glClearColor(0.8f, 0.8f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(2);
    tree(160, 120);
    tree(140, 120);
    tree(120, 120);
    tree(100, 120);
    tree(80, 120);
    tree(60, 120);
    road();
    signalLight();

    glColor3ub(255, 255, 0);
    Car(-5, -15);

    glColor3ub(255, 255, 0);
    Car(55, -25);

    // circle();
    glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char **argv)
{
    glutInit(&argc, argv);           // Initialize GLUT
    glutInitWindowSize(1080, 600);   // Set the window's initial width & height
    glutCreateWindow("Trafic Road"); // Create a window with the given title
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
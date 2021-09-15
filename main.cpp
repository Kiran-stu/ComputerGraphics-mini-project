#include<windows.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<iostream>

using namespace std;

GLfloat T=0,f=0,r=0,flag=0,temp=0,tem=0,reset=0,ex=0;



void trigger()
{
    r+=0.5;
    if(r>=5)
        r=0;

    glPushMatrix();
    glColor3f(0.3,0.3,0.3);
    if(flag==1)
        glTranslatef(r,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(144,107);
    glVertex2f(144,101);
    glVertex2f(148,101);
    glVertex2f(150,107);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(144,101);
    glVertex2f(140,95);
    glVertex2f(146,96);
    glVertex2f(148,101);
    glEnd();
    glFlush();
    glPopMatrix();
}


void bullet()
{

    f-=0.9;
    if(f==25)
        f=0;

    for(float i=0;i<=115;i+=10)
    {
        glPushMatrix();
        glColor3f(0,0,0.753);
        glTranslated(f,0,0);
        glBegin(GL_POLYGON);
        glVertex2f(73+i,126); //Bullets
        glVertex2f(73+i,122);
        glVertex2f(80+i,121);
        glVertex2f(80+i,127);
        glEnd();
        glFlush();
        glPopMatrix();
    }

}


void pol(GLfloat a[],GLfloat b[],GLfloat c[],GLfloat d[]) /*Translation functions for movable polygons
                                                             are defined here */
{
    T+=0.5;
    if(T>=15)
        T=0;

    glPushMatrix();
    //glColor3f(0.7,0.7,0.7);
    if(flag==1)
    {
        glTranslated(T,0,0);
    }
    glBegin(GL_POLYGON);
    glVertex2fv(a);
    glVertex2fv(b);  //Slide
    glVertex2fv(c);
    glVertex2fv(d);
    glEnd();



    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(170,130);
    glVertex2f(170,118);
    for(int i=0;i<=18;i+=2)
    {
        glVertex2f(173+i,130);  //Lines on the slide
        glVertex2f(173+i,118);
    }
    glEnd();
    glPopMatrix();
    glFlush();
}

void poly(GLfloat a[],GLfloat b[],GLfloat c[],GLfloat d[])//Function to draw polygons
{
    glBegin(GL_POLYGON);
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
    glVertex2fv(d);
    glEnd();
    glFlush();
}

void tri(GLfloat a[],GLfloat b[],GLfloat c[])//function to draw triangles
{
    glBegin(GL_POLYGON);
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
    glEnd();
    glFlush();
}

void lin(GLfloat a[],GLfloat b[],GLfloat c[],GLfloat d[])//Function to draw lines
{
    glBegin(GL_LINE_LOOP);
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
    glVertex2fv(d);
    glEnd();
    glFlush();
}

void key(unsigned char c,int x,int y)
{
    switch(c){
    case 'f':
        flag=1;
        break;
    case 's':
        temp=1;
        break;
    case 'r':
        reset=1;
        break;
    case 'x':
        ex=1;
        break;
    };
    glutPostRedisplay();
}


void draw()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,1,1,0);


    GLfloat v[][2] = {
                        {70,130},{70,118},{193,118},{193,130},//polygons data
                        {70,118},{70,107},{193,107},{193,118},
                        {153,107},{172,45},{199,55},{183,107},
                        {122,90},{122,88},{125,88},{125,92},
                        {125,93},{125,88},{153,88},{153,93},
                        {153,93},{153,88},{160,86},{157,95},
                        {170,54},{168,53},{169,49},{171,50},
                        {166,47},{167,43},{172,45},{171,51},
                        {197,61},{199,55},{201,59},{201,63},
                        {197,61},{201,63},{195,80},{191,79},
                        {193,118},{193,107},{195,108},{195,117},
                        {195,117},{195,108},{197,111},{197,115},
                        {70,128},{70,120},{120,120},{120,128},
                        {144,107},{144,101},{148,101},{150,107},
                        {144,101},{140,95},{146,96},{148,101},
                        {186,133},{185,130},{190,130},{189,133},
                        {73,130},{78,130},{77,133},{74,133},

                        };

    GLfloat k[][2] = {
                        {120,107},{127,96},{127,107}, //triangles data
                        {123,103},{125,92},{129,93},
                        {165,70},{163,66},{167,64},
                        {167,64},{166,52},{170,53},
                        {185,98},{191,79},{195,80},
                        {182,107},{184,103},{193,107},
                        {184,103},{185,100},{187,107},

                        };

    GLfloat l[][2] = {
                        {130,115},{128,113},{134,108},{136,110},//lines data
                        {160,118},{160,114},{165,114},{165,118},
                        {158,114},{160,112},{165,112},{167,114},

                        };

    trigger();

    if(flag==1)
        bullet();


    glColor3f(0.3,0.3,0.3);
    for(int i=4;i<=51;i+=4)
    {
        poly(v[i],v[i+1],v[i+2],v[i+3]);//calling poly function to draw polygon
    }

    for(int i=0;i<=20;i+=3)
    {
        tri(k[i],k[i+1],k[i+2]);//calling tri function to draw triangle
    }

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(166,52);  //idle parts of the handgun
    glVertex2f(190,61);
    glVertex2f(190,61);
    glVertex2f(198,55);
    glEnd();
    glFlush();

    for(int i=0;i<=11;i+=4)
    {
        lin(l[i],l[i+1],l[i+2],l[i+3]); //calling lin function to draw lines
    }

    glColor3f(0.7,0.7,0.7);
    pol(v[0],v[1],v[2],v[3]);    //calling pol function which transforms polygons
    glColor3f(0.3,0.3,0.3);
    pol(v[60],v[61],v[62],v[63]);
    glColor3f(0.3,0.3,0.3);
    pol(v[64],v[65],v[66],v[67]);


    glColor3f(0,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(120,118);    //idle parts of the handgun
    glVertex2f(122,120);
    glVertex2f(132,120);
    glVertex2f(134,118);
    glEnd();
    glFlush();
    glutSwapBuffers();
    if(temp!=1)
        glutPostRedisplay();
    if(reset==1)
        flag=0;
    if(ex==1)
        exit(0);

}

int main(int argC, char *argV[])
{
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInit(&argC,argV);
    glutInitWindowPosition(500,500);
    glutInitWindowSize(500,400);
    glutCreateWindow("Glock19");
    glutDisplayFunc(draw);
    glutKeyboardFunc(key);
    gluOrtho2D(0,250,0,200);
    glutMainLoop();
}



/* 
 * helicoid (gernalized torus) demo 
 *
 * FUNCTION:
 * This code provides a very simple example of the helicoid primitive.
 * Most of this code is required to set up OpenGL and GLUT, and very
 * very little to set up the helix drawer. Don't blink!
 *
 * =======> MOUSE HOOKED UP TO SWEEP, HEIGHT < ========
 *
 * HISTORY:
 * Written by Linas Vepstas, March 1995
 */

/* required include files */
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <GL/gl.h>
#include <GL/glut.h>
#ifdef HAVE_GLE3
#include <GL/gle.h>
#else
#include <GL/tube.h>
#endif

/*  most recent mouse postion */
extern float lastx;
extern float lasty;
extern float rot_x;
extern float rot_y;
extern float rot_z;

void InitStuff_helix3 (void) 
{
}

/* draw the helix shape */
void DrawStuff_helix3 (void) 
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor3f (0.8, 0.3, 0.6);

   /* set up some matrices so that the object spins with the mouse */
   glPushMatrix ();
   glTranslatef (0.0, 0.0, -80.0);
   glRotatef(rot_x, 1, 0, 0);
   glRotatef(rot_y, 0, 1, 0);
   glRotatef(rot_z, 0, 0, 1);
/*     glRotatef (220.0, 0.0, 1.0, 0.0); */
/*     glRotatef (65.0, 1.0, 0.0, 0.0); */

   /* Phew. FINALLY, Draw the helix  -- */
   gleSetJoinStyle (TUBE_NORM_EDGE | TUBE_JN_ANGLE | TUBE_JN_CAP);
   gleHelicoid (1.0, 6.0, -1.0, 
               0.0, (0.02*lasty-2.0), 0x0, 0x0, 0.0, 6.0*lastx);

   glPopMatrix ();

}
/* ------------------------- end of file ----------------- */
//#include <GL/glut.h>  // GLUT, include glu.h and gl.h
//
//float cubeX = 0.0f; // X positie van de kubus
//float cubeY = 0.0f; // Y positie van de kubus
//
//void keyboard(unsigned char key, int x, int y) {
//    switch (key) {
//    case 'w':
//        cubeY += 0.1f;
//        break;
//    case 's':
//        cubeY -= 0.1f;
//        break;
//    case 'a':
//        cubeX -= 0.1f;
//        break;
//    case 'd':
//        cubeX += 0.1f;
//        break;
//    }
//    glutPostRedisplay(); // Redraw the window
//}
//
///* Handler for window-repaint event. Call back when the window first appears and
//   whenever the window needs to be re-painted. */
//void display() {
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color buffer (background) and depth buffer
//
//    // Draw cube
//    glLoadIdentity();
//    glTranslatef(cubeX, cubeY, -10.0f); // verplaats de cube
//
//    glBegin(GL_QUADS); // Begin cube
//    //voorkant                      
//    glColor3f(1.0f, 1.0f, 1.0f); // (R B G) wit
//    glVertex3f(1.0f, 1.0f, 1.0f); // x y z  links onder
//    glVertex3f(-1.0f, 1.0f, 1.0f); //       rechts onder
//    glVertex3f(-1.0f, -1.0f, 1.0f); //      rechts boven
//    glVertex3f(1.0f, -1.0f, 1.0f); //       links boven
//
//    //achterkant (geen effect)
//    glColor3f(1.0f, 1.0f, 0.0f); // geel
//    glVertex3f(1.0f, 1.0f, -1.0f);
//    glVertex3f(-1.0f, 1.0f, -1.0f);
//    glVertex3f(-1.0f, -1.0f, -1.0f);
//    glVertex3f(1.0f, -1.0f, -1.0f);
//
//    //bovenkant
//    glColor3f(1.0f, 0.0f, 0.0f); // rood
//    glVertex3f(1.0f, 1.0f, 1.0f);
//    glVertex3f(-1.0f, 1.0f, 1.0f);
//    glVertex3f(-1.0f, 1.0f, -1.0f);
//    glVertex3f(1.0f, 1.0f, -1.0f);
//
//    //onderkant
//    glColor3f(1.0f, 0.5f, 0.0f); // oranje 
//    glVertex3f(1.0f, -1.0f, 1.0f);
//    glVertex3f(-1.0f, -1.0f, 1.0f);
//    glVertex3f(-1.0f, -1.0f, -1.0f);
//    glVertex3f(1.0f, -1.0f, -1.0f);
//
//    //rechterkant
//    glColor3f(0.0f, 1.0f, 0.0f); // groen
//    glVertex3f(1.0f, 1.0f, -1.0f);
//    glVertex3f(1.0f, 1.0f, 1.0f);
//    glVertex3f(1.0f, -1.0f, 1.0f);
//    glVertex3f(1.0f, -1.0f, -1.0f);
//
//    //linkerkant
//    glColor3f(0.0f, 0.0f, 1.0f); // blauw
//    glVertex3f(-1.0f, 1.0f, 1.0f);
//    glVertex3f(-1.0f, 1.0f, -1.0f);
//    glVertex3f(-1.0f, -1.0f, -1.0f);
//    glVertex3f(-1.0f, -1.0f, 1.0f);
//    glEnd();
//
//    glutSwapBuffers(); // Swap the front and back frame buffers (double buffering)
//}
//
//void reshape(int breedte, int hoogte) {
//    glViewport(0, 0, breedte, hoogte);  //zet de viewport op de grote van het volledige venster 
//    glMatrixMode(GL_PROJECTION);        // switch naar projectie modus, is nodig voor de matrixbewegingen hier onder
//    glLoadIdentity();                   // reset de matrix positie in projectie mode
//    gluPerspective(45.0f, (float)breedte / (float)hoogte, 0.1f, 100.0f);  //45.0f is de FoV, breedte / hoogte is de ratio, 0.1f afstand dichtbijzijnde Z, 100.0f afstand verste Z
//    glMatrixMode(GL_MODELVIEW);         // switch naar view modus voor de matrixbewegingen 
//    glLoadIdentity();                   // reset de matrix positie in view mode
//}
//
///* Main function: GLUT runs as a console application starting at main() */
//int main(int argc, char** argv) {
//    glutInit(&argc, argv); // Initialize GLUT
//    glutCreateWindow("cube"); // Create a window with the given title
//    glutInitWindowSize(320, 320); // Set the window's initial width & height
//    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
//    glutDisplayFunc(display); // Register display callback handler for window re-paint
//
//    glutReshapeFunc(reshape); // Register the reshape function
//
//    glutKeyboardFunc(keyboard); 
//    glEnable(GL_DEPTH_TEST); // zet diepte test aan, voor 3d objecten
//    glutMainLoop(); // Enter the event-processing loop
//    return 0;
//}

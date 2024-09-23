#include <GL/glut.h>
#include <iostream>

// 定义权重和阈值
GLfloat weight[3] = {1.75123f, 2.50435f, -0.336639f};
GLfloat theta = 0.0668295f;

// 定义训练数据
GLfloat train_data[][4] = {
    {1, 1, 5, 1},
    {1, 0, 5, 0},
    {0, 1, 5, 0},
    {0, 0, 5, 0}
};

// 渲染函数
void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // 绘制训练数据点
    glBegin(GL_POINTS);
    for (int i = 0; i < 4; ++i) {
        if (train_data[i][3] == 1) glColor3f(1.0f, 0.0f, 0.0f);
        else glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(train_data[i][0], train_data[i][1], train_data[i][2]);
    }
    glEnd();

    // 绘制超平面
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f); // 设置颜色为绿色
    glVertex3f(-1.0f, -1.0f, (-weight[0] * (-1.0f) - weight[1] * (-1.0f) - theta) / weight[2]);
    glVertex3f(1.0f, -1.0f, (-weight[0] * 1.0f - weight[1] * (-1.0f) - theta) / weight[2]);
    glVertex3f(1.0f, 1.0f, (-weight[0] * 1.0f - weight[1] * 1.0f - theta) / weight[2]);
    glVertex3f(-1.0f, 1.0f, (-weight[0] * (-1.0f) - weight[1] * 1.0f - theta) / weight[2]);
    glEnd();

    glutSwapBuffers();
}

// 初始化函数
void initGL(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Perceptron Decision Boundary");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(renderScene);
    glutMainLoop();
}

// 主函数
int main(int argc, char** argv) {
    initGL(argc, argv);
    return 0;
}

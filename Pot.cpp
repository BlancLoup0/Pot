#include <windows.h>
#include <GL/freeglut.h>

GLfloat angle = 0.0; // 회전 각도 변수

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // 배경색을 검은색으로 설정
    glShadeModel(GL_SMOOTH); // 그림자를 부드럽게 표현
    glClearDepth(1.0); // 깊이 버퍼 초기화
    glEnable(GL_DEPTH_TEST); // 깊이 버퍼 테스트 활성화
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 색상 버퍼와 깊이 버퍼 지움
    glLoadIdentity(); // 현재 변환 행렬을 단위행렬로 초기화

    glTranslatef(0.0f, 0.0f, -5.0f); // 원점에서 -5만큼 이동하여 시점 설정
    glRotatef(angle, 1.0f, 1.0f, 1.0f); // 주전자를 회전시키는 각도 설정

    glColor3f(1.0, 1.0, 1.0); // 주전자 색상을 흰색으로 설정

    // 주전자를 그림
    glutWireTeapot(1.0);

    glutSwapBuffers(); // 화면에 출력
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h); // 출력 창의 크기에 맞춰서 뷰포트 설정
    glMatrixMode(GL_PROJECTION); // 투영 행렬 모드로 설정
    glLoadIdentity(); // 현재 변환 행렬을 단위행렬로 초기화
    gluPerspective(45.0, (float)w / (float)h, 0.1, 100.0); // 원근 투영 설정
    glMatrixMode(GL_MODELVIEW); // 모델뷰 행렬 모드로 설정
    glLoadIdentity(); // 현재 변환 행렬을 단위행렬로 초기화
}

void idle() {
    angle += 0.1; // 회전 각도 증가
    if (angle > 360.0)
        angle -= 360.0; // 360도 이상이면 각도 초기화

    glutPostRedisplay(); // 화면 다시 그리기 요청
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // GLUT 초기화
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // 디스플레이 모드 초기화
    glutInitWindowSize(500, 500); // 윈도우 크기 설정
    glutCreateWindow("Rotating Teapot"); // 윈도우 생성, 타이틀 설정

    init(); // 초기화 함수 호출

    glutDisplayFunc(display); // 출력 콜백 함수 등록
    glutReshapeFunc(reshape); // 창 크기 변경 콜백 함수 등록
    glutIdleFunc(idle); // 이벤트 대기 중일 때 호출되는 콜백 함수 등록

    glutMainLoop(); // GLUT 이벤트 루프 진입

    return 0;
}

//#include<bits/stdc++.h>
//#include <GL/glut.h>
//using namespace std;
//const int width = 960, height = 600; // 窗口画幅大小
//int XL = 0, XR = 0, YB = 0, YT = 0;  //裁剪窗口的边界
//struct node {
//    int x,y;
//};
//struct edge//Edge边
//{
//    int bx, by, ex, ey;
//}LEFT,RIGHT,BOTTOM,TOP;      //上下左右四条边界
//vector<node>wPoints(2);   //记录窗口的对角点，用以绘制裁剪窗口
//vector<node>lPoints;         //记录最初输入的顶点，用于绘制初始图形
//vector<node>inPoints;        //记录输入的顶点，用于更新，每次计算outPoints
//vector<node>outPoints;       //记录输出的顶点，用于绘制裁剪后的图形
//bool displayFlag=false;      //展示标志位
//char flag='1';               //模式标志位
//int index=0;                 //修改端点在数组中的索引
////更新裁剪窗口边界
//void update_XL_XR_YB_YT(){
//    XL=min(wPoints[0].x,wPoints[1].x);
//    XR=max(wPoints[0].x,wPoints[1].x);
//    YB=min(wPoints[0].y,wPoints[1].y);
//    YT=max(wPoints[0].y,wPoints[1].y);
//    //顺时针输入
//    LEFT={XL, YT, XL, YB};
//    BOTTOM={XL, YB, XR, YB};
//    RIGHT={XR, YB, XR,YT };
//    TOP={XR, YT, XL, YT};
//}
////绘制裁剪窗口
//void DrawWindow(){
//    update_XL_XR_YB_YT();//更新边界参数
//    glClear(GL_COLOR_BUFFER_BIT); // 清除窗口内容
//    glColor3f(0.8, 0, 250.8); // 点颜色
//    glLineWidth(3.f);
//    glBegin(GL_LINES);
//    //底
//    glVertex2i(XL, YB);
//    glVertex2i(XR, YB);
//    //顶
//    glVertex2i(XL, YT);
//    glVertex2i(XR, YT);
//    //左
//    glVertex2i(XL, YB);
//    glVertex2i(XL, YT);
//    //右
//    glVertex2i(XR, YB);
//    glVertex2i(XR, YT);
//    glEnd();
//}
////判断点是否可见
//bool inside(node& pt, edge ClipBoundary){
//    if (ClipBoundary.ex > ClipBoundary.bx)
//    {
//        if (pt.y >= ClipBoundary.by)//裁剪边为窗口下边沿
//            return true;
//    }
//    else if (ClipBoundary.ex < ClipBoundary.bx)
//    {
//        if (pt.y <= ClipBoundary.by)//裁剪边为窗口上边沿
//            return true;
//    }
//    else if (ClipBoundary.ey > ClipBoundary.by)//裁剪边为窗口右边沿
//    {
//        if (pt.x <= ClipBoundary.bx)
//            return true;
//    }
//    else if (ClipBoundary.ey < ClipBoundary.by)//裁剪边为窗口左边沿
//    {
//        if (pt.x >= ClipBoundary.bx)
//            return true;
//    }
//    return false;
//}
////直线段SP和边界求交，返回交点
//void intersect(node& s, node& p, edge ClipBoundary, node& intersectPt){
//    if (ClipBoundary.by == ClipBoundary.ey)//水平裁剪边界
//    {
//        intersectPt.y = ClipBoundary.by;
//        //x=起点的横坐标+dy/sp斜率
//        intersectPt.x = s.x + (ClipBoundary.by - s.y) * (p.x - s.x) / (p.y - s.y);
//    }
//    else//垂直裁剪边界
//    {
//        intersectPt.x = ClipBoundary.bx;
//        intersectPt.y = s.y + (ClipBoundary.bx - s.x) * (p.y - s.y) / (p.x - s.x);
//    }
//}
//void SutherlandHodgmanClip(edge ClipBoundary)
//{
//    node s, p, ip;
//    outPoints.clear();
//    int n=inPoints.size();
//    s = inPoints[n- 1];//首尾
//
//    for (int j = 0; j < n; j++)
//    {
//        p = inPoints[j];
//        if (inside(p, ClipBoundary))//p在内
//        {
//            if (inside(s, ClipBoundary))//sp都在窗口内
//            {
//                outPoints.push_back(p);
//            }
//            else//p在里面 s不在
//            {
//                intersect(s, p, ClipBoundary, ip);
//                outPoints.push_back(ip);
//                outPoints.push_back(p);
//
//            }
//        }
//        else//p在外面
//        {
//            if (inside(s, ClipBoundary))//s在窗口内p在窗口外
//            {
//                intersect(s, p, ClipBoundary, ip);
//                outPoints.push_back(ip);
//            }
//            //sp都在外面则无输出
//        }
//        s = p;
//    }
//    inPoints = outPoints;//这次的输出作为下一次的输入，input_vertice和output_vertice是全局变量
//}
//
////绘制原始图形边线
//void DrawLine1(){
//    int n=lPoints.size();
//    if(n>=2){
//        glColor3f(0.f, 250.5f, 0.4f);
//        glLineWidth(3.0f);
//        glBegin(GL_LINE_STRIP);
//        for(int i=0;i<=n;i++){
//            int x=lPoints[i%n].x,y=lPoints[i%n].y;
//            glVertex2i(x, y);
//        }
//        glEnd();
//    }
//}
////绘制被裁剪图形边线
//void DrawLine2(){
//    int n=outPoints.size();
//    if(n>=2){
//        glColor3f(255.f, 0.f, 0.f);
//        glLineWidth(3.5f);
//        glBegin(GL_LINE_STRIP);
//        for(int i=0;i<=n;i++){
//            int x=outPoints[i%n].x,y=outPoints[i%n].y;
//            glVertex2i(x, y);
//        }
//        glEnd();
//    }
//}
//void setPoints(){
//    glColor3f(255.f, 0.f, 0.f);
//    glPointSize(3.0f); // 设置点的大小
//    glBegin(GL_POINTS);
//    for(auto &it:lPoints){
//        glVertex2i(it.x, it.y);
//    }
//    glEnd();
//}
//void display(){
//    //左上右下，顺时针输入
//    SutherlandHodgmanClip(LEFT);
//    SutherlandHodgmanClip(BOTTOM);
//    SutherlandHodgmanClip(RIGHT);
//    SutherlandHodgmanClip(TOP);
//    DrawLine2();
//}
//void dragMouse(int x,int y){
//    if(flag=='1'){//绘制窗口模式
//        wPoints[1].x = x;
//        wPoints[1].y = y;
//        DrawWindow();
//    }
//    if(flag=='3'|flag=='4'){//修改或者删点模式
//        if(lPoints.size()>0){
//            lPoints[index].x=x;
//            lPoints[index].y=y;
//            inPoints=lPoints;
//            DrawWindow();
//            DrawLine1();
//            display();
//        }
//    }
//    if(flag=='2'){//绘制多边形线条模式
//        lPoints.back().x=x;
//        lPoints.back().y=y;
//        inPoints=lPoints;
//        DrawWindow();
//        DrawLine1();
//        display();
//    }
//    glFlush();
//}
//// 鼠标监听，画点
//void myMouse(int button, int state, int x, int y) {
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
//        if(flag=='1'){//绘制窗口
//            wPoints[1].x=x;
//            wPoints[1].y=y;
//            DrawWindow();
//        }
//        if(flag=='2'){//绘制图形
//            lPoints.back().x=x;
//            lPoints.back().y=y;
//            inPoints=lPoints;
//            DrawLine1();
//            display();
//        }
//        if(flag=='3'){//修改模式
//            if(lPoints.size()>0) {
//                lPoints[index].x = x;
//                lPoints[index].y = y;
//                inPoints = lPoints;
//                DrawWindow();
//                DrawLine1();
//                display();
//            }
//        }
//        if(flag=='4'){//删点模式
//            int n=lPoints.size();
//            if(n > 1){
//                for(int i=index;i<n-1;i++){
//                    lPoints[i]=lPoints[i+1];
//                }
//                lPoints.resize(n-1);
//                inPoints=lPoints;
//                DrawWindow();
//                DrawLine1();
//                display();
//            }
//            else{
//                lPoints.clear();
//                inPoints.clear();
//                DrawWindow();
//            }
//        }
//        setPoints();
//        printf("%d %d\n", x,y); // 把两个坐标打印出来
//        glFlush();
//    }
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//        int dis=INT_MAX;
//        int n=lPoints.size();
//        index=n-1;
//        for(int i=0;i<n;i++){
//            int d=sqrt((x-lPoints[i].x)*(x-lPoints[i].x)+(y-lPoints[i].y)*(y-lPoints[i].y));
//            if(dis>d){
//                dis=d;
//                index=i;
//            }
//        }
//        if(flag=='1'){//绘制窗口
//            wPoints[0].x=x;
//            wPoints[0].y=y;
//        }
//        if(flag=='2'){//绘制图形
//            lPoints.push_back({x, y});
//            inPoints=lPoints;
//        }
//        printf("%d %d\n", x,y); // 把两个坐标打印出来
//        glFlush();
//    }
//    if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP){//绘制窗口标志位转换
//        displayFlag=!displayFlag;
//        if(flag!='1'){
//            if(!displayFlag){
//                DrawWindow();
//                inPoints=lPoints;
//                display();
//            }
//            else {
//                DrawLine1();
//            }
//        }
//        glFlush();
//    }
//}
////键盘监听
//void keyboard(unsigned char key, int a, int b){
//    int n=inPoints.size();
//    switch(key) {
//        case 27:
//            exit(0);
//        case ' '://清空除裁剪窗口外所有内容
//            lPoints.clear();  //清空线条
//            inPoints.clear(); //清空线条
//            outPoints.clear();//清空线条
//            DrawWindow();     //清空屏幕重新绘制裁剪窗口
//            glFlush();
//            break;
//        case '1'://绘制窗口模式
//            flag = '1';
//            break;
//        case '2'://绘制图形模式
//            flag = '2';
//            break;
//        case '3'://修改模式
//            flag = '3';
//            break;
//        case '4'://删点模式
//            flag = '4';
//            break;
//    }
//}
//void init(int argc, char** argv){
//    glutInit(&argc, argv); // 初始化
//
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // 设置绘制模式
//    glutInitWindowPosition(180, 50); // 设置窗口出现的位置
//    glutInitWindowSize(width, height); // 设置窗口大小
//    glutCreateWindow("PolygonClip"); // 创建窗口
//
//    glClearColor(1, 1, 1, 1); // 设置绘制窗口颜色为白色
//    glClear(GL_COLOR_BUFFER_BIT); // 清除窗口内容
//    glPointSize(3.0f); // 设置点的大小
//
//    glMatrixMode(GL_PROJECTION); /* 设置为投影类型模式和其他观察参数 */
//    glLoadIdentity(); /* 设置为投影类型模式和其他观察参数 */
//    gluOrtho2D(0, width, height, 0);
//}
//
//int main(int argc, char** argv){
//    init(argc, argv);
//
//    glutDisplayFunc(display);
//    glutDisplayFunc(setPoints);
//    glutDisplayFunc(DrawLine1);
//    glutDisplayFunc(DrawWindow); // 绘制回调函数,glut机制，它觉得需要重新绘制的时候就会执行
//    glutMouseFunc(myMouse); // 键盘监听回调函数
//    glutKeyboardFunc(keyboard);// 键盘监听回调函数
//    glutMotionFunc(dragMouse); // 鼠标拖动
//    glutMainLoop();
//}
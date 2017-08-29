#include "curve.h"
#include "ui_curve.h"

Curve::Curve(QGLWidget *parent) : //构造函数以及一些变量初始化
    QGLWidget(parent),
    ui(new Ui::Curve)
{
    tt = 0;
    tra = -0.1;
    xRot = 0;
    yRot = zRot = 0.0;
    flag = 0;
    info = NULL;
    oldPoint = QPoint(0, 0);
    isInputting = false;
    finishInputting = false;
    editBool = false;
    ui->setupUi(this);

}

Curve::~Curve()
{
    delete ui;
}

//获取主窗口的信息的方法
void Curve::getInfo(Info *i)
{
    info = i;
    if(i->le < pointVector.size() && i->le >= 0) { //判断输入的次数是否合理
        finishInputting = true;
        updateGL(); //每次调用这个函数将执行系统绘制的主函数paintALL函数
        return;
    }
    QMessageBox message(QMessageBox::Warning,"Attention","please input the reasonable number",QMessageBox::Yes,NULL);
    message.exec();
}

//清屏的函数
void Curve::clearAll() {
    pointVector.clear();
    list.clear();
    editBool = false;
    updateGL();
}

//编辑的槽函数
void Curve::editSlot()
{
    setCursor(Qt::OpenHandCursor);
    editBool = true;
}

//更新
void Curve::up()
{
    updateGL();
}

//初始化方法实现
void Curve::initializeGL() {
    glClearColor(1.0, 1.0, 1.0, 0.0); //用白色清屏
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
}

//自适应函数
void Curve::resizeGL(int width, int height) {
    glViewport( 0, 0, (GLint)width, (GLint)height ); //设置视口
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(0, 944, -556, 0); //平行投影，设置视景体前部和照相机的相对位置

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

void Curve::paintGL() {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();

    gluLookAt(0,0,0.0,0.0,0.0,1.0,0.0,-1.0,0.0); //更改照相机的位置以及观看的方向等

    glColor3f(0.0, 0.0, 0.0); //设置绘制颜色等
    glPointSize(5.0f); //设置点的大小

    //一下是在窗口里写字的代码
    QFont font;
    font.setPointSize(15);
    glColor3f(0.0, 0.0, 0.0);
    font.setFamily("MS Shell Dlg 2"); // Tahoma 宋体
    QString qst = "鼠标此时坐标:(    ,   )";
    renderText(10, 30, 0,qst, font);
    renderText(150, 30, 0,QString::number(oldPoint.x()), font);
    renderText(200, 30, 0,QString::number(oldPoint.y()), font);
    renderText(10, 60, 0,"控制顶点个数:", font);
    renderText(150, 60, 0,QString::number(pointVector.size()), font); //这里显示了当前多少个点
    renderText(350, 15, 0,"The inputWindows:", font);

    if(!pointVector.isEmpty()) { //只需要容器非空那么就把里面的点绘制出来
        for(int i=0; i<pointVector.size(); i++) {
            drawPoint(pointVector.at(i));
        }
        if(pointVector.size() > 1) { //大于等于一个点的时候绘制直线
            for(int i=0; i<pointVector.size() - 1; i++) {
                glColor3f(0.0, 1.0, 0.0);
                drawLine(pointVector.at(i), pointVector.at(i+1), 1);
            }
        }
        if((finishInputting == true) || (editBool == true)) { //绘制曲线
            if(info == NULL)
                return;
            info->num = pointVector.size();
            //如果曲线曲线类型是贝齐尔的话
            if(info->cb == 1) {
                int n = pointVector.size();
                double *a = new double[n];
                double *b = new double[n];
                for(int i=0; i<n; i++) {
                    a[i] = pointVector.at(i).x();
                    b[i] = pointVector.at(i).y();
                }
                glColor3f(0.0, 0.0, 0.0);
                tt = 0;
                QPoint tempPoint, tem;
                //贝齐尔绘制过程
                while(tt <= 1) {
                    tem = drawBezier(tt, a, b);
                    if(tt == 0) {
                        glPointSize(2.0f);
                        drawPoint(tem);
                    }
                    else {
                        drawLine(tempPoint, tem, 2);
                    }

                    tempPoint = tem;
                    tt += 0.01;
                }
            } else if(info->le != 0) { //是B样条的话而且次数不是0
                tt = 0;
                int n = pointVector.size();
                int k = info->le;
                int type = info->type;
                double s = 0;
                double *t = new double[n + k + 1];

                if(type == 0) { //B样条的准均匀类型
                    for(int i=0; i<n+k+1; i++) {
                        if(i < k+1)
                            t[i] = 0;
                        else if(i > n-1)
                            t[i] = 1;
                        else {
                            t[i] = 1.0 * (i - k) / (n-k);
                        }
                    }
                } else if(type == 1) { //均匀类型
                    s = 1.0 / (n - k);
                    t[0] = 0 - k * s;
                    for(int i = 1;i < n+k+1;i++) {
                        t[i] = t[0] + i * s;
                    }
                } else if(type == 2) { //非均匀类型1
                    int linesNum = n - 1;
                    double *l = new double[linesNum];
                    double count = 0;
                    for(int i=0; i<linesNum; i++) {
                        l[i] = getDistance(pointVector.at(i), pointVector.at(i + 1));
                        count += l[i];
                    }
                    if(k % 2 == 0) {
                        for(int i=0; i<=k; i++) {
                            t[i] = 0;
                            t[i+n] = 1;
                        }
                        for(int i=1; i<n-k; i++) {
                            s = 0;
                            for(int j=1; j<k/2+i; j++)
                                s += l[j];
                            t[k+i]=(s + l[k/2+i] / 2) / count;
                        }
                    } else {
                        for(int i=0; i<=k; i++) {
                            t[i] = 0;
                            t[i+n] = 1;
                        }
                        for(int i=1; i<n-k; i++) {
                            s=0;
                            for(int j=1; j<(k+1)/2+i; j++)
                                s += l[j];
                            t[k+i] = s/count;
                        }
                    }
                } else if(type == 3) { //非均匀类型2
                    int linesNum = n - 1;
                    double *l = new double[linesNum];
                    double count = 0;
                    for(int i=0; i<linesNum; i++) {
                        l[i] = getDistance(pointVector.at(i), pointVector.at(i + 1));
                        count += l[i];
                    }
                    for(int i=0; i<=k; i++)
                    {
                        t[i] = 0;
                        t[i+n] = 1;
                    }
                    s = 0;
                    for(int i=k+1; i<=n; i++)
                    {
                        for(int j=i-k; j<=i-1; j++)
                        {
                            s += l[j-1];
                        }
                    }
                    double li;
                    for(int i=k+1; i<n; i++)
                    {
                        li = 0;
                        for(int j=i-k; j<=i-1; j++)
                        {
                            li += l[j-1];
                        }
                        t[i] = li / s;
                        t[i] += t[i-1];
                    }
                } else if(type == 4) { //分段贝齐尔类型
                    for(int i=0; i<=n+k; i++) {
                        if(i <= k) {
                            t[i] = 0;
                        } else if(i >= n) {
                            t[i] = 1;
                        } else {
                            t[i] = ((i-1) / k) /double((n - 1)/k);
                        }
                    }
                }

                QPoint tempPoint, tem;

                while(tt <= 1) { //B样条绘制过程
                    tem = drawBcurves(tt, info->le, t);
                    if(inWhich(tt, t, n+k) % 2 == 0)
                        glColor3f(1.0, 0.0, 1.0);
                    else
                        glColor3f(0.0, 0.0, 0.0);
                    if(tt == 0) {
                        glPointSize(2.0f);
                        drawPoint(tem);
                    }
                    else {
                        drawLine(tempPoint, tem, 2);
                    }
                    tempPoint = tem;
                    tt += 0.001;
                }
            }

            info->qvp = &pointVector;
            emit messagesToBasic(info);//绘制完成发信号继续绘制基函数
            finishInputting = false;
        }
    }
}

//返回此时的U值位于哪两个节点矢量间
int Curve::inWhich(double tt, double *t, int n) {
    for(int i=0; i<n; i++) {
        if((tt >= t[i]) && (tt < t[i+1]))
            return i;
    }
    return 0;
}

//绘制贝齐尔函数的函数
QPoint Curve::drawBezier(double t, double *a, double *b) {
    int n = pointVector.size();
    QPoint *qp;
    for(int i=0; i<n; i++) {
        a[i] = pointVector.at(i).x();
        b[i] = pointVector.at(i).y();
    }
    while(n != 1) {
        for(int i=0; i<n-1; i++) {
            a[i] = a[i] * (1 - t) + a[i + 1] * t;
            b[i] = b[i] * (1 - t) + b[i + 1] * t;
        }
        n --;
    }
    qp = new QPoint(a[0], b[0]);
    return *qp;
}

//绘制B样条的函数
QPoint Curve::drawBcurves(double v, int k, double *t)
{
    int n = pointVector.size();

    double *a = new double[n];
    double *b = new double[n];

    int debuer = 0;
    double alpha=0;
    double denom=0;

    for(int i=k; i<=n+1; i++) {
        if((v>=t[i]) && (v<t[i+1])) {
            debuer = i;
        }
    }

    for(int ll=1; ll<=k; ll++) {
        for(int i=0; i<=k-ll; i++){
            if(ll == 1) {
                denom = t[debuer + i + 1] - t[debuer - k + ll + i];
                if(qFabs(denom) <= 1e-5)
                    alpha = 0.0;
                else
                    alpha = (v - t[debuer - k + ll + i])/denom;
                a[i] = pointVector.at(debuer+i-k).x() * (1-alpha) + pointVector.at(debuer+i-k+1).x() * alpha;
                b[i] = pointVector.at(debuer+i-k).y() * (1-alpha) + pointVector.at(debuer+i-k+1).y() * alpha;

            } else {
                denom = t[debuer+i+1]-t[debuer-k+ll+i];
                if(qFabs(denom) <= 1e-5)
                    alpha=0.0;
                else
                    alpha=(v - t[debuer-k+ll+i])/denom;
                a[i]=a[i] * (1-alpha) + a[i+1] * alpha;
                b[i]=b[i] * (1-alpha) + b[i+1] * alpha;
            }
        }
    }

    return QPoint(a[0], b[0]);
}

//获取距离的方法
double Curve::getDistance(QPoint a, QPoint b)
{
    return qSqrt(qPow(a.x() - b.x(), 2) + qPow(a.y() - b.y(), 2));
}

//键盘点击的事件
void Curve::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Plus:
        tra += 20;
        break;
    case Qt::Key_Minus:
        tra -= 20;
        if(tra < -1998)
            tra = -1998;
        break;
    case Qt::Key_1:
        xRot += 5;
        break;
    case Qt::Key_4:
        xRot -= 5;
        break;
    case Qt::Key_2:
        yRot += 5;
        break;
    case Qt::Key_5:
        yRot -= 5;
        break;
    case Qt::Key_3:
        zRot += 5;
        break;
    case Qt::Key_6:
        zRot -= 5;
        break;
    }
    updateGL();
}

//绘制点的方法
void Curve::drawPoint(double x, double y) {
    glBegin(GL_POINTS);
      glVertex2f(x, y);
    glEnd();
}

void Curve::drawPoint(QPoint a) {
    glBegin(GL_POINTS);
      glVertex2f(a.x(), a.y());
    glEnd();
}

void Curve::drawPoint(double x, double y, double z) {
    glBegin(GL_POINTS);
      glVertex3f(x, y, z);
    glEnd();
}

//绘制直线的方法
void Curve::drawLine(QPoint a, QPoint b, double h) {
    glLineWidth(h);
    glBegin(GL_LINES);
            glVertex2f(a.x(), a.y());
            glVertex2f(b.x(), b.y());
    glEnd();
}

//鼠标单击事件
void Curve::mousePressEvent(QMouseEvent *event) {
    if(event->buttons()==Qt::LeftButton) {
        if(editBool == true) {
            setCursor(Qt::ClosedHandCursor);
        }
        oldPoint = event->pos();
        if(editBool != true)
            pointVector.push_back(event->pos());
        isInputting = true;
        updateGL();
    } else if(event->buttons()==Qt::RightButton) {
        emit rightBtnClicked();
        if(editBool == true) {
            setCursor(Qt::ArrowCursor);
            editBool = false;
        }
    }
}

//鼠标移动事件
void Curve::mouseMoveEvent(QMouseEvent *e) {
    if(e->buttons()==Qt::LeftButton) {
        if(!pointVector.isEmpty() && editBool == true) {
            for(int i=0; i<pointVector.size(); i++) {
                if(getDistance(oldPoint, pointVector.at(i)) < 20) {
                    pointVector.replace(i, e->pos());
                    updateGL();
                    return;
                }
            }
        }
    }
}

//鼠标释放的事件
void Curve::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton) {
        if(editBool == true)
            setCursor(Qt::OpenHandCursor);
        else
            setCursor(Qt::ArrowCursor);
    }
}

//滚轮转动事件
void Curve::wheelEvent(QWheelEvent *) {
//    tra += e->delta();
//    updateGL();
}

